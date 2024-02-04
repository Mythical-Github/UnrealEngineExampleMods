#ifndef RC_UNREAL_CONTAINER_ALLOCATION_POLICIES_HPP
#define RC_UNREAL_CONTAINER_ALLOCATION_POLICIES_HPP

#include <Unreal/PrimitiveTypes.hpp>
#include <Unreal/FMemory.hpp>
#include <Unreal/TypeCompatibleBytes.hpp>

namespace RC::Unreal
{
    template<int IndexSize>
    class TSizedDefaultAllocator;

    using FDefaultAllocator = TSizedDefaultAllocator<32>;

    template<int IndexSize>
    struct TBitsToSizeType
    {
        static_assert(IndexSize, "Unsupported allocator index size.");
    };

    template<>
    struct TBitsToSizeType<8> { using Type = int8; };
    template<>
    struct TBitsToSizeType<16> { using Type = int16; };
    template<>
    struct TBitsToSizeType<32> { using Type = int32; };
    template<>
    struct TBitsToSizeType<64> { using Type = int64; };

    template<typename ReferencedType>
    ReferencedType* IfAThenAElseB(ReferencedType* A, ReferencedType* B)
    {
        if (A) return A;
        return B;
    }

    template <typename SizeType>
    SizeType DefaultCalculateSlackShrink(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T BytesPerElement, bool bAllowQuantize, uint32 Alignment = DEFAULT_ALIGNMENT)
    {
        SizeType Retval;

        // If the container has too much slack, shrink it to exactly fit the number of elements.
        const SizeType CurrentSlackElements = NumAllocatedElements - NumElements;
        const SIZE_T CurrentSlackBytes = (NumAllocatedElements - NumElements) * BytesPerElement;
        const bool bTooManySlackBytes = CurrentSlackBytes >= 16384;
        const bool bTooManySlackElements = 3 * NumElements < 2 * NumAllocatedElements;
        if ((bTooManySlackBytes || bTooManySlackElements) && (CurrentSlackElements > 64 || !NumElements)) //  hard coded 64 :-(
        {
            Retval = NumElements;
            if (Retval > 0)
            {
                if (bAllowQuantize)
                {
                    Retval = (SizeType)(FMemory::QuantizeSize(Retval * BytesPerElement, Alignment) / BytesPerElement);
                }
            }
        }
        else
        {
            Retval = NumAllocatedElements;
        }

        return Retval;
    }

    template <typename SizeType>
    SizeType DefaultCalculateSlackGrow(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T BytesPerElement, bool bAllowQuantize, uint32 Alignment = DEFAULT_ALIGNMENT)
    {
        // TODO: Implement this better
        return NumElements * 2;
    }

    template <typename SizeType>
    SizeType DefaultCalculateSlackReserve(SizeType NumElements, SIZE_T BytesPerElement, bool bAllowQuantize, uint32 Alignment = DEFAULT_ALIGNMENT)
    {
        // TODO: Implement this better
        return NumElements * 2;
    }

    /** A type which is used to represent a script type that is unknown at compile time. */
    struct FScriptContainerElement
    {
    };

    template<int IndexSize>
    class RC_UE_API TSizedHeapAllocator
    {
    public:
        using SizeType = typename TBitsToSizeType<IndexSize>::Type;

        enum { NeedsElementType = false };
        enum { RequireRangeCheck = true };

        class RC_UE_API ForAnyElementType
        {
            // Hack to allow the allocator to be set by the TArray constructor for when we want to interact with an already constucted TArray in memory
            template<typename T1, typename T2>
            friend class TArray;

            template <int>
            friend class TSizedHeapAllocator;

        public:
            /** Default constructor. */
            ForAnyElementType()
                    : Data(nullptr)
            {}

            /**
             * Moves the state of another allocator into this one.  The allocator can be different.
             *
             * Assumes that the allocator is currently empty, i.e. memory may be allocated but any existing elements have already been destructed (if necessary).
             * @param Other - The allocator to move the state from.  This allocator should be left in a valid empty state.
             */
            template <typename OtherAllocator>
            void MoveToEmptyFromOtherAllocator(typename OtherAllocator::ForAnyElementType& Other)
            {
                if (Data)
                {
                    FMemory::Free(Data);
                }

                Data = Other.Data;
                Other.Data = nullptr;
            }

            /**
             * Moves the state of another allocator into this one.
             * Moves the state of another allocator into this one.  The allocator can be different.
             *
             * Assumes that the allocator is currently empty, i.e. memory may be allocated but any existing elements have already been destructed (if necessary).
             * @param Other - The allocator to move the state from.  This allocator should be left in a valid empty state.
             */
            void MoveToEmpty(ForAnyElementType& Other)
            {
                this->MoveToEmptyFromOtherAllocator<TSizedHeapAllocator>(Other);
            }

            /** Destructor. */
            ~ForAnyElementType()
            {
                if(Data)
                {
                    FMemory::Free(Data);
                }
            }

            // FContainerAllocatorInterface
            FScriptContainerElement* GetAllocation() const
            {
                return Data;
            }
            void ResizeAllocation(SizeType PreviousNumElements, SizeType NumElements, SIZE_T NumBytesPerElement)
            {
                // Avoid calling FMemory::Realloc( nullptr, 0 ) as ANSI C mandates returning a valid pointer which is not what we want.
                if (Data || NumElements)
                {
                    //checkSlow(((uint64)NumElements*(uint64)ElementTypeInfo.GetSize() < (uint64)INT_MAX));
                    Data = (FScriptContainerElement*)FMemory::Realloc( Data, NumElements*NumBytesPerElement );
                }
            }
            void ResizeAllocation(SizeType PreviousNumElements, SizeType NumElements, SIZE_T NumBytesPerElement, uint32 AlignmentOfElement)
            {
                // Avoid calling FMemory::Realloc( nullptr, 0 ) as ANSI C mandates returning a valid pointer which is not what we want.
                if (Data || NumElements)
                {
                    //checkSlow(((uint64)NumElements*(uint64)ElementTypeInfo.GetSize() < (uint64)INT_MAX));
                    Data = (FScriptContainerElement*)FMemory::Realloc(Data, NumElements * NumBytesPerElement, AlignmentOfElement);
                }
            }
            SizeType CalculateSlackReserve(SizeType NumElements, SIZE_T NumBytesPerElement) const
            {
                return DefaultCalculateSlackReserve(NumElements, NumBytesPerElement, true);
            }
            SizeType CalculateSlackReserve(SizeType NumElements, SIZE_T NumBytesPerElement, uint32 AlignmentOfElement) const
            {
                return DefaultCalculateSlackReserve(NumElements, NumBytesPerElement, true, (uint32)AlignmentOfElement);
            }
            SizeType CalculateSlackShrink(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T NumBytesPerElement) const
            {
                return DefaultCalculateSlackShrink(NumElements, NumAllocatedElements, NumBytesPerElement, true);
            }
            SizeType CalculateSlackGrow(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T NumBytesPerElement) const
            {
                return DefaultCalculateSlackGrow(NumElements, NumAllocatedElements, NumBytesPerElement, true);
            }
            SizeType CalculateSlackGrow(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T NumBytesPerElement, uint32 AlignmentOfElement) const
            {
                return DefaultCalculateSlackGrow(NumElements, NumAllocatedElements, NumBytesPerElement, true, (uint32)AlignmentOfElement);
            }

            SIZE_T GetAllocatedSize(SizeType NumAllocatedElements, SIZE_T NumBytesPerElement) const
            {
                return NumAllocatedElements * NumBytesPerElement;
            }

            bool HasAllocation() const
            {
                return !!Data;
            }

            SizeType GetInitialCapacity() const
            {
                return 0;
            }

        private:
            ForAnyElementType(const ForAnyElementType&) = default;
            ForAnyElementType& operator=(const ForAnyElementType&) = default;

            /** A pointer to the container's elements. */
            FScriptContainerElement* Data;
        };

        template<typename ElementType>
        class ForElementType : public ForAnyElementType
        {
        public:

            /** Default constructor. */
            ForElementType()
            {}

            ElementType* GetAllocation() const
            {
                return (ElementType*)ForAnyElementType::GetAllocation();
            }
        };
    };

    template <uint32 NumInlineElements, typename SecondaryAllocator = FDefaultAllocator>
    class TInlineAllocator
    {
    public:
        using SizeType = int32;

        enum { NeedsElementType = true };
        enum { RequireRangeCheck = true };

        template<typename ElementType>
        class ForElementType
        {
            // Hack to allow the allocator to be set by the TArray constructor for when we want to interact with an already constucted TArray in memory
            template<typename T1, typename T2>
            friend class TArray;

        public:
            /** Default constructor. */
            ForElementType()
            {
            }

            /**
             * Moves the state of another allocator into this one.
             * Assumes that the allocator is currently empty, i.e. memory may be allocated but any existing elements have already been destructed (if necessary).
             * @param Other - The allocator to move the state from.  This allocator should be left in a valid empty state.
             */
            FORCEINLINE void MoveToEmpty(ForElementType& Other)
            {
                checkSlow(this != &Other);

                if (!Other.SecondaryData.GetAllocation())
                {
                    // Relocate objects from other inline storage only if it was stored inline in Other
                    RelocateConstructItems<ElementType>((void*)InlineData, Other.GetInlineElements(), NumInlineElements);
                }

                // Move secondary storage in any case.
                // This will move secondary storage if it exists but will also handle the case where secondary storage is used in Other but not in *this.
                SecondaryData.MoveToEmpty(Other.SecondaryData);
            }

            // FContainerAllocatorInterface
            FORCEINLINE ElementType* GetAllocation() const
            {
                //return IfAThenAElseB<ElementType>(SecondaryData.GetAllocation(),GetInlineElements());
                return SecondaryData.GetAllocation() ? SecondaryData.GetAllocation() : GetInlineElements();
            }

            void ResizeAllocation(SizeType PreviousNumElements, SizeType NumElements,SIZE_T NumBytesPerElement)
            {
                // Check if the new allocation will fit in the inline data area.
                if(NumElements <= NumInlineElements)
                {
                    // If the old allocation wasn't in the inline data area, relocate it into the inline data area.
                    if(SecondaryData.GetAllocation())
                    {
                        RelocateConstructItems<ElementType>((void*)InlineData, (ElementType*)SecondaryData.GetAllocation(), PreviousNumElements);

                        // Free the old indirect allocation.
                        SecondaryData.ResizeAllocation(0,0,NumBytesPerElement);
                    }
                }
                else
                {
                    if(!SecondaryData.GetAllocation())
                    {
                        // Allocate new indirect memory for the data.
                        SecondaryData.ResizeAllocation(0,NumElements,NumBytesPerElement);

                        // Move the data out of the inline data area into the new allocation.
                        RelocateConstructItems<ElementType>((void*)SecondaryData.GetAllocation(), GetInlineElements(), PreviousNumElements);
                    }
                    else
                    {
                        // Reallocate the indirect data for the new size.
                        SecondaryData.ResizeAllocation(PreviousNumElements, NumElements, NumBytesPerElement);
                    }
                }
            }

            FORCEINLINE SizeType CalculateSlackReserve(SizeType NumElements, SIZE_T NumBytesPerElement) const
            {
                // If the elements use less space than the inline allocation, only use the inline allocation as slack.
                return NumElements <= NumInlineElements ?
                       NumInlineElements :
                       SecondaryData.CalculateSlackReserve(NumElements, NumBytesPerElement);
            }
            FORCEINLINE SizeType CalculateSlackShrink(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T NumBytesPerElement) const
            {
                // If the elements use less space than the inline allocation, only use the inline allocation as slack.
                return NumElements <= NumInlineElements ?
                       NumInlineElements :
                       SecondaryData.CalculateSlackShrink(NumElements, NumAllocatedElements, NumBytesPerElement);
            }
            FORCEINLINE SizeType CalculateSlackGrow(SizeType NumElements, SizeType NumAllocatedElements, SIZE_T NumBytesPerElement) const
            {
                // If the elements use less space than the inline allocation, only use the inline allocation as slack.
                return NumElements <= NumInlineElements ?
                       NumInlineElements :
                       SecondaryData.CalculateSlackGrow(NumElements, NumAllocatedElements, NumBytesPerElement);
            }

            SIZE_T GetAllocatedSize(SizeType NumAllocatedElements, SIZE_T NumBytesPerElement) const
            {
                if (NumAllocatedElements > NumInlineElements)
                {
                    return SecondaryData.GetAllocatedSize(NumAllocatedElements, NumBytesPerElement);
                }
                return 0;
            }

            bool HasAllocation() const
            {
                return SecondaryData.HasAllocation();
            }

            SizeType GetInitialCapacity() const
            {
                return NumInlineElements;
            }

        private:
            ForElementType(const ForElementType&);
            ForElementType& operator=(const ForElementType&);

            /** The data is stored in this array if less than NumInlineElements is needed. */
            TTypeCompatibleBytes<ElementType> InlineData[NumInlineElements];

            /** The data is allocated through the indirect allocation policy if more than NumInlineElements is needed. */
            typename SecondaryAllocator::template ForElementType<ElementType> SecondaryData;

            /** @return the base of the aligned inline element data */
            ElementType* GetInlineElements() const
            {
                return (ElementType*)InlineData;
            }
        };

        typedef void ForAnyElementType;
    };

    // From: https://stackoverflow.com/a/22592618
    template<class Allocator>
    struct RC_UE_API IsTInlineAllocatorHelper
    {
    private:
#pragma warning(disable: 4068)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"
        template <uint32 NumInlineElements, typename SecondaryAllocator = FDefaultAllocator>
        static decltype(static_cast<const ::RC::Unreal::TInlineAllocator<NumInlineElements, SecondaryAllocator>&>(std::declval<Allocator>()), std::true_type{})
        test(const ::RC::Unreal::TInlineAllocator<NumInlineElements, SecondaryAllocator>&);

        static std::false_type test(...);
#pragma clang diagnostic pop
#pragma warning(default: 4068)
    public:
        static constexpr bool value = decltype(IsTInlineAllocatorHelper::test(std::declval<Allocator>()))::value;
    };
    template<class Allocator>
    inline constexpr bool IsTInlineAllocator = IsTInlineAllocatorHelper<Allocator>::value;

    template<int IndexSize>
    class RC_UE_API TSizedDefaultAllocator : public TSizedHeapAllocator<IndexSize>
    {
    public:
        using Typedef = TSizedHeapAllocator<IndexSize>;
    };

    using FHeapAllocator = TSizedHeapAllocator<32>;
}

#endif //RC_UNREAL_CONTAINER_ALLOCATION_POLICIES_HPP
