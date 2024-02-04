#ifndef RC_UNREAL_TARRAY_HPP
#define RC_UNREAL_TARRAY_HPP

#include <functional>
#include <stdexcept>
#include <type_traits>
#include <unordered_set>
#include <tuple>
#include <ranges>

#include <Constructs/Generator.hpp>
#include <Helpers/Format.hpp>
#include <Unreal/Common.hpp>
#include <Unreal/PrimitiveTypes.hpp>
#include <Unreal/TypeTraits.hpp>
#include <Unreal/ChooseClass.hpp>
#include <Unreal/ContainersFwd.hpp>
#include <Unreal/ContainerAllocationPolicies.hpp>
#include <Unreal/FMemory.hpp>
#include <Unreal/MemoryOps.hpp>
#include <Unreal/UnrealFlags.hpp>
#include <Unreal/TypeChecker.hpp>

namespace RC::Unreal
{
    class XStructData;

    // Redo or remove this, need to think about it
    template<typename ElementType>
    constexpr bool ArraySizeIsImplicit = !(std::is_same_v<ElementType, struct FAssetData> ||
                                           std::is_same_v<ElementType, struct FVector> ||
                                           std::is_same_v<ElementType, struct FQuat>);

    auto RC_UE_API GetStructDataAt(void* data_param, size_t index) -> XStructData*;

    /*
     * Problems with TArray:
     *
     * The TArray destructor doesn't call element destructors.
     *
     * You can't create a new TArray in the games memory.
     */
    template<typename InElementType, typename InAllocator>
    class RC_UE_API TArray
    {
    public:
        static constexpr InternalType internal_type = InternalType::Array;
        using SizeType = typename InAllocator::SizeType;
        using ElementType = InElementType;
        using Allocator = InAllocator;

        typedef typename TChooseClass<
                Allocator::NeedsElementType,
                typename Allocator::template ForElementType<ElementType>,
                typename Allocator::ForAnyElementType
        >::Result ElementAllocatorType;

    protected:
        ElementAllocatorType AllocatorInstance{};
        int32 ArrayNum{};
        int32 ArrayMax{};

    public:
        // Custom constructor for when we already have a TArray in memory, and we'd just like to take it over
        //TArray(ArrayInnerType* data_ptr, int32_t current_size, int32_t capacity) : data(data_ptr), ArrayNum(current_size),
        //                                                                           ArrayMax(capacity) {}

        TArray([[maybe_unused]]InElementType* data_ptr, int32_t current_size, int32_t capacity) : ArrayNum(current_size), ArrayMax(capacity)
        {
            // This is currently used in FString to allow construction of strings
            AllocatorInstance.Data = std::bit_cast<FScriptContainerElement*>(data_ptr);
        }

        // Constructor for when we want to allocate a new TArray in the games memory
        // The TArray itself is on the stack (or local heap) but the data pointer will be in the games own heap
        TArray() = default;

        // Problems with this copying:
        // The underlying data might get deallocated from the original TArray going out of scope
        // At that point, any access to the copied TArray is undefined
        // For now, delete the copy constructor & copy assignment operator to disallow copying
        TArray(const TArray& Other)
        {
            CopyFrom_Helper(Other);
        }

        TArray& operator=(const TArray& Other)
        {
            if (this != &Other)
            {
                CopyFrom_Helper(Other);
            }

            return *this;
        }

        TArray& operator=(TArray& Other)
        {
            if (this != &Other)
            {
                CopyFrom_Helper(Other);
            }

            return *this;
        }

        ~TArray()
        {
            if (ArrayNum)
            {
                DestructItems(GetData(), ArrayNum);
                ArrayNum = 0;
            }
        }

        // Memory related -> START
    private:
        SizeType GetElementSize()
        {
            if constexpr (!ArraySizeIsImplicit<ElementType>)
            {
                // Structs where the size is unknown to the compiler
                // This happens when a struct has had layout changes and now has different sizes in different engine versions
                return ElementType::StaticSize();
            }
            else
            {
                // Structs where the size is known to the compiler
                return sizeof(ElementType);
            }
        }

        SizeType GetElementSize() const
        {
            if constexpr (!ArraySizeIsImplicit<ElementType>)
            {
                // Structs where the size is unknown to the compiler
                // This happens when a struct has had layout changes and now has different sizes in different engine versions
                return ElementType::StaticSize();
            }
            else
            {
                // Structs where the size is known to the compiler
                return sizeof(ElementType);
            }
        }

        void CopyFrom_Helper(const TArray& Other)
        {
            if constexpr (IsTInlineAllocator<InAllocator>)
            {
                std::memcpy(&AllocatorInstance, &Other.AllocatorInstance, Other.AllocatorInstance.GetInitialCapacity() * GetElementSize());

                if (auto AllocatedSize = Other.AllocatorInstance.GetAllocatedSize(Other.ArrayNum, Other.GetElementSize()); AllocatedSize > 0)
                {
                    AllocatorInstance.SecondaryData.Data = static_cast<FScriptContainerElement*>(FMemory::Malloc(Other.ArrayMax * GetElementSize()));
                    std::memcpy(AllocatorInstance.SecondaryData.Data, Other.AllocatorInstance.SecondaryData.Data, AllocatedSize);
                }
                else
                {
                    AllocatorInstance.SecondaryData.Data = nullptr;
                }

                ArrayNum = Other.ArrayNum;
                ArrayMax = Other.ArrayMax;
            }
            else
            {
                if (Other.AllocatorInstance.GetAllocation())
                {
                    AllocatorInstance.Data = static_cast<FScriptContainerElement*>(FMemory::Malloc(Other.ArrayMax * GetElementSize()));
                    std::memcpy(AllocatorInstance.Data, Other.AllocatorInstance.Data, Other.ArrayNum * GetElementSize());
                    ArrayNum = Other.ArrayNum;
                    ArrayMax = Other.ArrayMax;
                }
                else
                {
                    AllocatorInstance.Data = nullptr;
                    ArrayNum = 0;
                    ArrayMax = 0;
                }
            }
        }

    public:
        void Reserve(SizeType Number)
        {
            if (Number <= 0) { throw std::runtime_error{"TArray::Reserve called with a Number <= 0"}; }

            if (Number > ArrayMax)
            {
                ResizeTo(Number);
            }
        }

        void ResizeTo(SizeType NewMax)
        {
            if (NewMax)
            {
                NewMax = AllocatorInstance.CalculateSlackReserve(NewMax, GetElementSize());
            }

            if (NewMax != ArrayMax)
            {
                ArrayMax = NewMax;
                AllocatorInstance.ResizeAllocation(ArrayNum, ArrayMax, GetElementSize());
            }
        }

        SizeType AddUninitialized(SizeType Count = 1)
        {
            const SizeType OldNum = ArrayNum;
            const SizeType NewNum = ArrayNum + Count;
            if (ArrayNum + Count > ArrayMax)
            {
                ResizeGrow(OldNum, NewNum);
            }
            ArrayNum = NewNum;
            return OldNum;
        }

        SizeType AddZeroed(SizeType Count = 1)
        {
            const SizeType Index = AddUninitialized(Count);
            FMemory::Memzero((uint8*)AllocatorInstance.GetAllocation() + Index*GetElementSize(), Count*GetElementSize());
            return Index;
        }

        void ResizeGrow(SizeType OldNum, SizeType NewNum)
        {
            ArrayMax = AllocatorInstance.CalculateSlackGrow(NewNum, ArrayMax, GetElementSize());
            AllocatorInstance.ResizeAllocation(OldNum, ArrayMax, GetElementSize());
        }

        void ResizeShrink()
        {
            const SizeType NewArrayMax = AllocatorInstance.CalculateSlackShrink(ArrayNum, ArrayMax, GetElementSize());
            if (NewArrayMax != ArrayMax)
            {
                ArrayMax = NewArrayMax;
                AllocatorInstance.ResizeAllocation(ArrayNum, ArrayMax, GetElementSize());
            }
        }
        // Memory related -> END

        void CheckInvariants() const
        {
        }

    private:
        void RemoveAtSwapImpl(SizeType Index, SizeType Count = 1, bool bAllowShrinking = true)
        {
            if (Count)
            {
                CheckInvariants();

                DestructItems(GetData() + Index, Count);

                // Replace the elements in the hole created by the removal with elements from the end of the array, so the range of indices used by the array is contiguous.
                const SizeType NumElementsInHole = Count;
                const SizeType NumElementsAfterHole = ArrayNum - (Index + Count);
                const SizeType NumElementsToMoveIntoHole = std::min(NumElementsInHole, NumElementsAfterHole);
                if (NumElementsToMoveIntoHole)
                {
                    FMemory::Memcpy(
                            (uint8*)AllocatorInstance.GetAllocation() + (Index) * GetElementSize(),
                            (uint8*)AllocatorInstance.GetAllocation() + (ArrayNum - NumElementsToMoveIntoHole) * GetElementSize(),
                            NumElementsToMoveIntoHole * GetElementSize()
                    );
                }
                ArrayNum -= Count;

                if (bAllowShrinking)
                {
                    ResizeShrink();
                }
            }
        }

    public:
        SizeType Find(const ElementType& Item) const
        {
            const ElementType* RESTRICT Start = GetData();
            for (const ElementType* RESTRICT Data = Start, * RESTRICT DataEnd = Data + ArrayNum; Data != DataEnd; ++Data)
            {
                if (*Data == Item)
                {
                    return static_cast<SizeType>(Data - Start);
                }
            }
            return INDEX_NONE;
        }

        template<typename... ArgsType>
        SizeType Emplace(ArgsType&&... Args)
        {
            const SizeType Index = AddUninitialized(1);
            new (GetData() + Index) ElementType(std::forward<ArgsType>(Args)...);
            return Index;
        }

        SizeType Add(const ElementType& Item)
        {
            return Emplace(Item);
        }

        template<typename ComparisonType>
        bool Contains(const ComparisonType& Item) const
        {
            for (const ElementType* RESTRICT Data = GetData(), * RESTRICT DataEnd = Data + ArrayNum; Data != DataEnd; ++Data)
            {
                if (*Data == Item)
                {
                    return true;
                }
            }
            return false;
        }

        template<typename CountType>
        void RemoveAtSwap(SizeType Index, CountType Count, bool bAllowShrinking = true)
        {
            static_assert(!TAreTypesEqual<CountType, bool>::Value, "TArray::RemoveAtSwap: unexpected bool passed as the Count argument");
            RemoveAtSwapImpl(Index, Count, bAllowShrinking);
        }

        SizeType RemoveSingleSwap(const ElementType& Item, bool bAllowShrinking = true)
        {
            SizeType Index = Find(Item);
            if (Index == INDEX_NONE)
            {
                return 0;
            }

            RemoveAtSwap(Index, 1, bAllowShrinking);

            // Removed one item
            return 1;
        }

        ElementType* GetData()
        {
            return std::bit_cast<ElementType*>(AllocatorInstance.GetAllocation());
        }

        const ElementType* GetData() const
        {
            return std::bit_cast<const ElementType*>(AllocatorInstance.GetAllocation());
        }

        auto GetDataPtr() const -> InElementType*
        {
            return std::bit_cast<InElementType*>(AllocatorInstance.GetAllocation());
        }

        auto SetDataPtr(InElementType* new_data_ptr) -> void
        {
            if constexpr (IsTInlineAllocator<InAllocator>)
            {
                throw std::runtime_error{"TArray::set_data_ptr cannot be used with TInlineAllocator"};
            }
            else
            {
                AllocatorInstance.Data = std::bit_cast<FScriptContainerElement*>(new_data_ptr);
            }
        }

        SizeType Num() const
        {
            return ArrayNum;
        }

        auto SetNum(int32_t new_array_num) -> void
        {
            ArrayNum = new_array_num;
        }

        SizeType Max() const
        {
            return ArrayMax;
        }

        auto SetMax(int32_t new_array_max) -> void
        {
            ArrayMax = new_array_max;
        }

        // Temporary function
        // Transfers ownership of another data ptr to this instance of TArray
        // The 'other' TArray becomes zeroed
        auto CopyFast(TArray<InElementType, Allocator>& other) -> void
        {
            if constexpr (IsTInlineAllocator<InAllocator>)
            {
                throw std::runtime_error{"TArray::copy_fast cannot be used with TInlineAllocator"};
            }

            AllocatorInstance.Data = other.AllocatorInstance.GetAllocation();
            ArrayNum = other.ArrayNum;
            ArrayMax = other.ArrayMax;

            // Hack to prevent deallocation when 'other' goes out of scope
            other.AllocatorInstance.Data = nullptr;
            other.ArrayNum = 0;
            other.ArrayMax = 0;
        }

        auto At(size_t Index) -> InElementType*
        {
            // Index is zero-based and the stored max is one-based
            // Anything after ArrayMax is uninitialized, but it must succeed still so that operator[] can be used to initialize the element
            if (Max() == 0 || Index > Max() - 1)
            {
                throw std::runtime_error{fmt("[TArray::at] out of range (num elements: %d | requested elem: %d)", (Num() - 1 < 0 ? 0 : Num() - 1), Index)};
            }

            // Need to know the type here so that we can calculate the location of each array element
            // TODO: Come up with a better solution. TArray shouldn't need to know about StructProperty or XStructData.
            // I've hardcoded the StructProperty implementation for now but at least it's constexpr.
            if constexpr (std::is_same_v<InElementType, class XStructData>)
            {
                return GetStructDataAt(GetDataPtr(), Index);
            }
            else
            {
                return std::bit_cast<InElementType*>(&AllocatorInstance.GetAllocation()[Index * GetElementSize()]);
            }
        }

        auto operator[](size_t Index) -> InElementType&
        {
            return *static_cast<InElementType*>(At(Index));
        }
    
    public:
        auto begin() -> InElementType*
        {
            return GetDataPtr();
        }

        auto end() -> InElementType*
        {
            return GetDataPtr() + Num();
        }
    };
}


#endif //RC_UNREAL_TARRAY_HPP
