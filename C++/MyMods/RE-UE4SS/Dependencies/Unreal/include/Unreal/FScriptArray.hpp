#ifndef RC_UNREAL_FSCRIPTARRAY_HPP
#define RC_UNREAL_FSCRIPTARRAY_HPP

#include <Unreal/PrimitiveTypes.hpp>
#include <Unreal/ContainerAllocationPolicies.hpp>
#include <Unreal/FMemory.hpp>

namespace RC::Unreal
{
    template<typename AllocatorType>
    class RC_UE_API TScriptArray : protected AllocatorType::ForAnyElementType
    {
    protected:
        int32 ArrayNum;
        int32 ArrayMax;

    public:
        void* GetData()
        {
            return this->GetAllocation();
        }

        const void* GetData() const
        {
            return this->GetAllocation();
        }

        bool IsValidIndex(int32 i) const
        {
            return i >= 0 && i < ArrayNum;
        }

        bool IsEmpty() const
        {
            return ArrayNum == 0;
        }

        int32 Num() const
        {
            return ArrayNum;
        }

        int32 Max() const
        {
            return ArrayMax;
        }

        void InsertZeroed(int32 Index, int32 Count, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            Insert(Index, Count, NumBytesPerElement, AlignmentOfElement);
            FMemory::Memzero((uint8*)this->GetAllocation() + Index * NumBytesPerElement, Count * NumBytesPerElement);
        }

        void Insert(int32 Index, int32 Count, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            const int32 OldNum = ArrayNum;
            if ((ArrayNum += Count) > ArrayMax)
            {
                ResizeGrow(OldNum, NumBytesPerElement, AlignmentOfElement);
            }
            FMemory::Memmove
                    (
                            (uint8*)this->GetAllocation() + (Index + Count) * NumBytesPerElement,
                            (uint8*)this->GetAllocation() + (Index) * NumBytesPerElement,
                            (OldNum - Index) * NumBytesPerElement
                    );
        }

        int32 Add(int32 Count, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            const int32 OldNum = ArrayNum;
            if ((ArrayNum += Count) > ArrayMax)
            {
                ResizeGrow(OldNum, NumBytesPerElement, AlignmentOfElement);
            }

            return OldNum;
        }

        int32 AddZeroed(int32 Count, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            const int32 Index = Add(Count, NumBytesPerElement, AlignmentOfElement);
            FMemory::Memzero((uint8*)this->GetAllocation() + Index * NumBytesPerElement, Count * NumBytesPerElement);
            return Index;
        }

        void Shrink(int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            if (ArrayNum != ArrayMax)
            {
                ResizeTo(ArrayNum, NumBytesPerElement, AlignmentOfElement);
            }
        }

        void MoveAssign(TScriptArray& Other, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            Empty(0, NumBytesPerElement, AlignmentOfElement);
            this->MoveToEmpty(Other);
            ArrayNum = Other.ArrayNum;
            Other.ArrayNum = 0;
            ArrayMax = Other.ArrayMax;
            Other.ArrayMax = 0;
        }

        void Empty(int32 Slack, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            ArrayNum = 0;
            if (Slack != ArrayMax)
            {
                ResizeTo(Slack, NumBytesPerElement, AlignmentOfElement);
            }
        }
        void SwapMemory(int32 A, int32 B, int32 NumBytesPerElement)
        {
            FMemory::Memswap(
                    (uint8*)this->GetAllocation() + (NumBytesPerElement * A),
                    (uint8*)this->GetAllocation() + (NumBytesPerElement * B),
                    NumBytesPerElement
            );
        }

        TScriptArray() : ArrayNum(0), ArrayMax(0) {}

        int32 GetSlack() const
        {
            return ArrayMax - ArrayNum;
        }

        void Remove(int32 Index, int32 Count, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            if (Count)
            {
                // Skip memmove in the common case that there is nothing to move.
                int32 NumToMove = ArrayNum - Index - Count;
                if (NumToMove)
                {
                    FMemory::Memmove
                            (
                                    (uint8*)this->GetAllocation() + (Index) * NumBytesPerElement,
                                    (uint8*)this->GetAllocation() + (Index + Count) * NumBytesPerElement,
                                    NumToMove * NumBytesPerElement
                            );
                }
                ArrayNum -= Count;

                ResizeShrink(NumBytesPerElement, AlignmentOfElement);
            }
        }

    protected:
        TScriptArray(int32 InNum, int32 NumBytesPerElement, uint32 AlignmentOfElement) : ArrayNum(0), ArrayMax(InNum)
        {
            if (ArrayMax)
            {
                ResizeInit(NumBytesPerElement, AlignmentOfElement);
            }
            ArrayNum = InNum;
        }

        void ResizeInit(int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            ArrayMax = this->CalculateSlackReserve(ArrayMax, NumBytesPerElement, AlignmentOfElement);
            this->ResizeAllocation(ArrayNum, ArrayMax, NumBytesPerElement, AlignmentOfElement);
        }

        void ResizeGrow(int32 OldNum, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            ArrayMax = this->CalculateSlackGrow(ArrayNum, ArrayMax, NumBytesPerElement, AlignmentOfElement);
            this->ResizeAllocation(OldNum, ArrayMax, NumBytesPerElement, AlignmentOfElement);
        }

        void ResizeShrink(int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            const int32 NewArrayMax = this->CalculateSlackShrink(ArrayNum, ArrayMax, NumBytesPerElement, AlignmentOfElement);
            if (NewArrayMax != ArrayMax)
            {
                ArrayMax = NewArrayMax;
                this->ResizeAllocation(ArrayNum, ArrayMax, NumBytesPerElement, AlignmentOfElement);
            }
        }

        void ResizeTo(int32 NewMax, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            if (NewMax)
            {
                NewMax = this->CalculateSlackReserve(NewMax, NumBytesPerElement);
            }
            if (NewMax != ArrayMax)
            {
                ArrayMax = NewMax;
                this->ResizeAllocation(ArrayNum, ArrayMax, NumBytesPerElement, AlignmentOfElement);
            }
        }
    };

    class RC_UE_API FScriptArray : public TScriptArray<FHeapAllocator>
    {
        using Super = TScriptArray<FHeapAllocator>;

    public:
        FScriptArray() = default;

        FScriptArray(FScriptArray&& From, int32 NumBytesPerElement, int32 AlignmentOfElement)
        {
            MoveAssign(From, NumBytesPerElement, AlignmentOfElement);
        }

        void MoveAssign(FScriptArray& Other, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            Super::MoveAssign(Other, NumBytesPerElement, AlignmentOfElement);
        }

        void Empty(int32 Slack, int32 NumBytesPerElement, uint32 AlignmentOfElement)
        {
            Super::Empty(Slack, NumBytesPerElement, AlignmentOfElement);
        }

    protected:
        FScriptArray(int32 InNum, int32 NumBytesPerElement, uint32 AlignmentOfElement) : TScriptArray<FHeapAllocator>(InNum, NumBytesPerElement, AlignmentOfElement) {}
    };
}

#endif //RC_UNREAL_FSCRIPTARRAY_HPP
