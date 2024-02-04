#ifndef RC_UNREAL_USTRUCT_HPP
#define RC_UNREAL_USTRUCT_HPP

#include <cstdint>
#include <stdexcept>
#include <functional>

#include <Constructs/Generator.hpp>
#include <Constructs/Loop.hpp>

#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UnrealCoreStructs.hpp>
#include <Unreal/FField.hpp>
#include <Unreal/UField.hpp>
#include <Unreal/Script.hpp>
#include <Unreal/FieldPath.hpp>
#include <Unreal/TPair.hpp>

namespace RC::Unreal
{
    class FProperty;

    class RC_UE_API UStruct : public UField
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UStruct, CoreUObject)

    public:
        using LinkSignature = void(UStruct* Context, FArchive& Ar, bool bRelinkExistingProperties);
        static Function<LinkSignature> LinkInternal;

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
#include <MemberVariableLayout_HeaderWrapper_UStruct.hpp>

    public:
        // Wrappers for virtual engine functions
        UStruct* GetInheritanceSuper() const;
        void Link(FArchive& Ar, bool bRelinkExistingProperties);
        void SerializeBin(FArchive& Ar, void* Data) const;
        struct FStructuredArchive { enum class FSlot {}; }; // Remove if/when we have a FStructuredArchive implementation, for now, probably a bad idea to call
        //void SerializeBin(FStructuredArchive::FSlot Slot, void* Data) const;
        void SerializeTaggedProperties(FArchive& Ar, uint8* Data, UStruct* DefaultsStruct, uint8* Defaults, const UObject* BreakRecursionIfFullyLoad = nullptr) const;
        //void SerializeTaggedProperties(FStructuredArchive::FSlot Slot, uint8* Data, UStruct* DefaultsStruct, uint8* Defaults, const UObject* BreakRecursionIfFullyLoad = nullptr) const;
        void InitializeStruct(void* Dest, int32 ArrayDim = 1) const;
        void DestroyStruct(void* Dest, int32 ArrayDim = 1) const;
        FProperty* CustomFindProperty(const FName InName) const;
        EExprToken SerializeExpr(int32& iCode, FArchive& Ar);
        const TCHAR* GetPrefixCPP() const;
        void SetSuperStruct(UStruct* NewSuperStruct);
        FString PropertyNameToDisplayName(FName InName) const;
        FString GetAuthoredNameForField(const UField* Field) const;
        //FString GetAuthoredNameForField(const FField* Field) const;
        bool IsStructTrashed() const;
        FName FindPropertyNameFromGuid(const FGuid& PropertyGuid) const;
        FGuid FindPropertyGuidFromName(const FName InName) const;
        bool ArePropertyGuidsAvailable() const;

    private:
        FORCEINLINE static bool IsChildOfInternal(const UStruct* This, const UStruct* Struct)
        {
            auto* CurrentStruct = This;
            do {
                if (CurrentStruct == Struct)
                {
                    return true;
                }
                CurrentStruct = CurrentStruct->GetSuperStruct();
            }
            while (CurrentStruct);
            return false;
        }

    public:
        /**
         * Checks if this struct is a child of the provided one
         */
        auto IsChildOf(UStruct* Struct) -> bool
        {
            return IsChildOfInternal(this, Struct);
        }

        auto IsChildOf(const UStruct* Struct) const -> bool
        {
            return IsChildOfInternal(this, Struct);
        }

        template<UObjectDerivative UObjectDerivedType>
        auto IsChildOf() const -> bool
        {
            return IsChildOf(UObjectDerivedType::StaticClass());
        }

        /**
         * Iterates properties of this object and calls the provided function on each of them
         * Will stop the iteration once the callable returns Break
         */
        auto ForEachProperty() -> Generator<FProperty*>;

        /**
         * Iterates the functions of the object and calls the provided function on each of them
         * Will stop the iteration once the callable returns Break
         */
        auto ForEachFunction() -> Generator<UFunction*>;

        /**
         * Iterates the super structs of this object and calls the provided function on each of them
         * Will stop the iteration once the callable returns Break
         */
        auto ForEachSuperStruct() -> Generator<UStruct*>;

        /**
         * Iterates every property in every super struct and calls the provided function on each of them
         * Will stop the iteration once the callable returns Break
         */
        auto ForEachPropertyInChain() -> Generator<FProperty*>;

        /**
         * Iterates every function in every super struct and calls the provided function on each of them
         * Will stop the iteration once the callable returns Break
         * @param Callable
         */
        auto ForEachFunctionInChain() -> Generator<UFunction*>;

        /**
         * Finds a property by FName
         * Returns the property or nullptr if one isn't found
         */
        FProperty* FindProperty(FName PropertyName);

        /**
         * Returns true if either 'ChildProperties' or 'Children' is non-nullptr
         */
        bool HasChildren();

        FProperty* GetFirstProperty();

        inline int32 GetStructureSize() const
        {
            // Temporary implementation of 'Align' from AlignmentTemplates.h.
            // Remove when/if we have a generic implementation.
            auto Align = [](int32 Val, uint64 Alignment) {
                return (int32)(((uint64)Val + Alignment - 1) & ~(Alignment - 1));
            };
            return Align(GetPropertiesSize(), GetMinAlignment());
        }
    };
}

#endif //RC_UNREAL_USTRUCT_HPP
