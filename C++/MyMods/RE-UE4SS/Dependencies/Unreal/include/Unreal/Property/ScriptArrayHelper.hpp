#ifndef RC_UNREAL_SCRIPTARRAYHELPER_H
#define RC_UNREAL_SCRIPTARRAYHELPER_H

#include <Unreal/Container/ScriptArray.h>
#include <Unreal/Property/XArrayProperty.hpp>

namespace RC::Unreal
{
    /**
     * FScriptArrayHelper: Pseudo dynamic array. Used to work with array properties in a sensible way.
     **/
    class FScriptArrayHelper
    {
        enum EInternal { Internal };

        template <typename CallableType>
        auto WithScriptArray(CallableType&& Callable) const
        {
            if (!!(ArrayFlags & EArrayPropertyFlags::UsesMemoryImageAllocator))
            {
                return Callable(FreezableArray);
            }
            else
            {
                return Callable(HeapArray);
            }
        }
    public:
        /**
         *	Constructor, brings together a property and an instance of the property located in memory
         *	@param	InProperty: the property associated with this memory
         *	@param	InArray: pointer to raw memory that corresponds to this array. This can be NULL, and sometimes is, but in that case almost all operations will crash.
        **/
        FORCEINLINE FScriptArrayHelper(const FArrayProperty* InProperty, const void* InArray)
                : FScriptArrayHelper(Internal, InProperty->Inner, InArray, InProperty->Inner->ElementSize, InProperty->ArrayFlags)
        {
        }

        /**
         *	Index range check
         *	@param	Index: Index to check
         *	@return true if accessing this element is legal.
        **/
        FORCEINLINE bool IsValidIndex( int32 Index ) const
        {
            return Index >= 0 && Index < Num();
        }
        /**
         *	Return the number of elements in the array.
         *	@return	The number of elements in the array.
        **/
        FORCEINLINE int32 Num() const
        {
            int32 Result = WithScriptArray([](auto* Array) { return Array->Num(); });
            checkSlow(Result >= 0);
            return Result;
        }
        /**
         *	Static version of Num() used when you don't need to bother to construct a FScriptArrayHelper. Returns the number of elements in the array.
         *	@param	Target: pointer to the raw memory associated with a FScriptArray
         *	@return The number of elements in the array.
        **/
        UE_DEPRECATED(4.25, "This shortcut is no longer valid - the Num() should be read from a proper array helper")
        static FORCEINLINE int32 Num(const void *Target)
        {
            checkSlow(((const FScriptArray*)Target)->Num() >= 0);
            return ((const FScriptArray*)Target)->Num();
        }
        /**
         *	Returns a uint8 pointer to an element in the array
         *	@param	Index: index of the item to return a pointer to.
         *	@return	Pointer to this element, or NULL if the array is empty
        **/
        FORCEINLINE uint8* GetRawPtr(int32 Index = 0)
        {
            if (!Num())
            {
                checkSlow(!Index);
                return NULL;
            }
            checkSlow(IsValidIndex(Index));
            return (uint8*)WithScriptArray([](auto* Array) { return Array->GetData(); }) + Index * ElementSize;
        }
        /**
        *	Empty the array, then add blank, constructed values to a given size.
        *	@param	Count: the number of items the array will have on completion.
        **/
        void EmptyAndAddValues(int32 Count)
        {
            check(Count>=0);
            checkSlow(Num() >= 0);
            EmptyValues(Count);
            if (Count)
            {
                AddValues(Count);
            }
        }
        /**
        *	Empty the array, then add uninitialized values to a given size.
        *	@param	Count: the number of items the array will have on completion.
        **/
        void EmptyAndAddUninitializedValues(int32 Count)
        {
            check(Count>=0);
            checkSlow(Num() >= 0);
            EmptyValues(Count);
            if (Count)
            {
                AddUninitializedValues(Count);
            }
        }
        /**
        *	Expand the array, if needed, so that the given index is valid
        *	@param	Index: index for the item that we want to ensure is valid
        *	@return true if expansion was necessary
        *	NOTE: This is not a count, it is an INDEX, so the final count will be at least Index+1 this matches the usage.
        **/
        bool ExpandForIndex(int32 Index)
        {
            check(Index>=0);
            checkSlow(Num() >= 0);
            if (Index >= Num())
            {
                AddValues(Index - Num() + 1);
                return true;
            }
            return false;
        }
        /**
        *	Add or remove elements to set the array to a given size.
        *	@param	Count: the number of items the array will have on completion.
        **/
        void Resize(int32 Count)
        {
            check(Count>=0);
            int32 OldNum = Num();
            if (Count > OldNum)
            {
                AddValues(Count - OldNum);
            }
            else if (Count < OldNum)
            {
                RemoveValues(Count, OldNum - Count);
            }
        }
        /**
        *	Add blank, constructed values to the end of the array.
        *	@param	Count: the number of items to insert.
        *	@return	the index of the first newly added item.
        **/
        int32 AddValues(int32 Count)
        {
            const int32 OldNum = AddUninitializedValues(Count);
            ConstructItems(OldNum, Count);
            return OldNum;
        }
        /**
        *	Add a blank, constructed values to the end of the array.
        *	@return	the index of the newly added item.
        **/
        FORCEINLINE int32 AddValue()
        {
            return AddValues(1);
        }
        /**
        *	Add uninitialized values to the end of the array.
        *	@param	Count: the number of items to insert.
        *	@return	the index of the first newly added item.
        **/
        int32 AddUninitializedValues(int32 Count)
        {
            check(Count>0);
            checkSlow(Num() >= 0);
            const int32 OldNum = WithScriptArray([this, Count](auto* Array) { return Array->Add(Count, ElementSize); });
            return OldNum;
        }
        /**
        *	Add an uninitialized value to the end of the array.
        *	@return	the index of the newly added item.
        **/
        FORCEINLINE int32 AddUninitializedValue()
        {
            return AddUninitializedValues(1);
        }
        /**
         *	Insert blank, constructed values into the array.
         *	@param	Index: index of the first inserted item after completion
         *	@param	Count: the number of items to insert.
        **/
        void InsertValues( int32 Index, int32 Count = 1)
        {
            check(Count>0);
            check(Index>=0 && Index <= Num());
            WithScriptArray([this, Index, Count](auto* Array) { Array->Insert(Index, Count, ElementSize); });
            ConstructItems(Index, Count);
        }
        /**
         *	Remove all values from the array, calling destructors, etc as appropriate.
         *	@param Slack: used to presize the array for a subsequent add, to avoid reallocation.
        **/
        void EmptyValues(int32 Slack = 0)
        {
            checkSlow(Slack>=0);
            const int32 OldNum = Num();
            if (OldNum)
            {
                DestructItems(0, OldNum);
            }
            if (OldNum || Slack)
            {
                WithScriptArray([this, Slack](auto* Array) { Array->Empty(Slack, ElementSize); });
            }
        }
        /**
         *	Remove values from the array, calling destructors, etc as appropriate.
         *	@param Index: first item to remove.
         *	@param Count: number of items to remove.
        **/
        void RemoveValues(int32 Index, int32 Count = 1)
        {
            check(Count>0);
            check(Index>=0 && Index + Count <= Num());
            DestructItems(Index, Count);
            WithScriptArray([this, Index, Count](auto* Array) { Array->Remove(Index, Count, ElementSize); });
        }

        /**
        *	Clear values in the array. The meaning of clear is defined by the property system.
        *	@param Index: first item to clear.
        *	@param Count: number of items to clear.
        **/
        void ClearValues(int32 Index, int32 Count = 1)
        {
            check(Count>0);
            check(Index>=0);
            ClearItems(Index, Count);
        }

        /**
         *	Swap two elements in the array, does not call constructors and destructors
         *	@param A index of one item to swap.
         *	@param B index of the other item to swap.
        **/
        void SwapValues(int32 A, int32 B)
        {
            WithScriptArray([this, A, B](auto* Array) { Array->SwapMemory(A, B, ElementSize); });
        }

        /**
         *	Move the allocation from another array and make it our own.
         *	@note The arrays MUST be of the same type, and this function will NOT validate that!
         *	@param InOtherArray The array to move the allocation from.
        **/
        void MoveAssign(void* InOtherArray)
        {
            checkSlow(InOtherArray);
            WithScriptArray([this, InOtherArray](auto* Array) { Array->MoveAssign(*static_cast<decltype(Array)>(InOtherArray), ElementSize); });
        }

        /**
         *	Used by memory counting archives to accumulate the size of this array.
         *	@param Ar archive to accumulate sizes
        **/
        void CountBytes( FArchive& Ar  ) const
        {
            WithScriptArray([this, &Ar](auto* Array) { Array->CountBytes(Ar, ElementSize); });
        }

        /**
         * Destroys the container object - THERE SHOULD BE NO MORE USE OF THIS HELPER AFTER THIS FUNCTION IS CALLED!
         */
        void DestroyContainer_Unsafe()
        {
            WithScriptArray([](auto* Array) { DestructItem(Array); });
        }

        static FScriptArrayHelper CreateHelperFormInnerProperty(const FProperty* InInnerProperty, const void *InArray, EArrayPropertyFlags InArrayFlags = EArrayPropertyFlags::None)
        {
            return FScriptArrayHelper(Internal, InInnerProperty, InArray, InInnerProperty->ElementSize, InArrayFlags);
        }

    private:
        FScriptArrayHelper(EInternal, const FProperty* InInnerProperty, const void* InArray, int32 InElementSize, EArrayPropertyFlags InArrayFlags)
                : InnerProperty(InInnerProperty)
                , ElementSize(InElementSize)
                , ArrayFlags(InArrayFlags)
        {
            //@todo, we are casting away the const here
            if (!!(InArrayFlags & EArrayPropertyFlags::UsesMemoryImageAllocator))
            {
                FreezableArray = (FFreezableScriptArray*)InArray;
            }
            else
            {
                HeapArray = (FScriptArray*)InArray;
            }

            check(ElementSize > 0);
            check(InnerProperty);
        }

        /**
         *	Internal function to call into the property system to construct / initialize elements.
         *	@param Index: first item to .
         *	@param Count: number of items to .
        **/
        void ConstructItems(int32 Index, int32 Count)
        {
            checkSlow(Count > 0);
            checkSlow(Index >= 0);
            checkSlow(Index <= Num());
            checkSlow(Index + Count <= Num());
            uint8 *Dest = GetRawPtr(Index);
            if (InnerProperty->PropertyFlags & CPF_ZeroConstructor)
            {
                FMemory::Memzero(Dest, Count * ElementSize);
            }
            else
            {
                for (int32 LoopIndex = 0 ; LoopIndex < Count; LoopIndex++, Dest += ElementSize)
                {
                    InnerProperty->InitializeValue(Dest);
                }
            }
        }
        /**
         *	Internal function to call into the property system to destruct elements.
         *	@param Index: first item to .
         *	@param Count: number of items to .
        **/
        void DestructItems(int32 Index, int32 Count)
        {
            if (!(InnerProperty->PropertyFlags & (CPF_IsPlainOldData | CPF_NoDestructor)))
            {
                checkSlow(Count > 0);
                checkSlow(Index >= 0);
                checkSlow(Index < Num());
                checkSlow(Index + Count <= Num());
                uint8 *Dest = GetRawPtr(Index);
                for (int32 LoopIndex = 0 ; LoopIndex < Count; LoopIndex++, Dest += ElementSize)
                {
                    InnerProperty->DestroyValue(Dest);
                }
            }
        }
        /**
         *	Internal function to call into the property system to clear elements.
         *	@param Index: first item to .
         *	@param Count: number of items to .
        **/
        void ClearItems(int32 Index, int32 Count)
        {
            checkSlow(Count > 0);
            checkSlow(Index >= 0);
            checkSlow(Index < Num());
            checkSlow(Index + Count <= Num());
            uint8 *Dest = GetRawPtr(Index);
            if ((InnerProperty->PropertyFlags & (CPF_ZeroConstructor | CPF_NoDestructor)) == (CPF_ZeroConstructor | CPF_NoDestructor))
            {
                FMemory::Memzero(Dest, Count * ElementSize);
            }
            else
            {
                for (int32 LoopIndex = 0; LoopIndex < Count; LoopIndex++, Dest += ElementSize)
                {
                    InnerProperty->ClearValue(Dest);
                }
            }
        }

        const FProperty* InnerProperty;
        union
        {
            FScriptArray* HeapArray;
            FFreezableScriptArray* FreezableArray;
        };
        int32 ElementSize;
        EArrayPropertyFlags ArrayFlags;
    };

    class FScriptArrayHelper_InContainer : public FScriptArrayHelper
    {
    public:
        FORCEINLINE FScriptArrayHelper_InContainer(const FArrayProperty* InProperty, const void* InContainer, int32 FixedArrayIndex=0)
                :FScriptArrayHelper(InProperty, InProperty->ContainerPtrToValuePtr<void>(InContainer, FixedArrayIndex))
        {
        }

        FORCEINLINE FScriptArrayHelper_InContainer(const FArrayProperty* InProperty, const UObject* InContainer, int32 FixedArrayIndex=0)
                :FScriptArrayHelper(InProperty, InProperty->ContainerPtrToValuePtr<void>(InContainer, FixedArrayIndex))
        {
        }
    };
}

#endif //RC_UNREAL_SCRIPTARRAYHELPER_H
