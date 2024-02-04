#include <Unreal/UStruct.hpp>
#include <Unreal/FField.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/FProperty.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UStruct);

    Function<UStruct::LinkSignature> UStruct::LinkInternal;
    std::unordered_map<File::StringType, uint32_t> UStruct::VTableLayoutMap;

#include <MemberVariableLayout_SrcWrapper_UStruct.hpp>

    UStruct* UStruct::GetInheritanceSuper() const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(UStruct, GetInheritanceSuper, UStruct*)
    }

    void UStruct::Link(FArchive& Ar, bool bRelinkExistingProperties)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, Link, void, PARAMS(bool), ARGS(bRelinkExistingProperties))
    }

    void UStruct::SerializeBin(FArchive& Ar, void* Data) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, SerializeBin, void, PARAMS(void*), ARGS(Data))

    }

    void UStruct::SerializeTaggedProperties(FArchive& Ar, uint8* Data, UStruct* DefaultsStruct, uint8* Defaults, const UObject* BreakRecursionIfFullyLoad) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct,
                                         SerializeTaggedProperties,
                                         void,
                                         PARAMS(FArchive&, uint8*, UStruct*, uint8*, const UObject*),
                                         ARGS(Ar, Data, DefaultsStruct, Defaults, BreakRecursionIfFullyLoad))
    }

    void UStruct::InitializeStruct(void* Dest, int32 ArrayDim) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, InitializeStruct, void, PARAMS(void*, int32), PARAMS(Dest, ArrayDim))
    }

    void UStruct::DestroyStruct(void* Dest, int32 ArrayDim) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, DestroyStruct, void, PARAMS(void*, int32), ARGS(Dest, ArrayDim))
    }

    FProperty* UStruct::CustomFindProperty(const FName InName) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, CustomFindProperty, FProperty*, PARAMS(const FName), ARGS(InName))
    }

    EExprToken UStruct::SerializeExpr(int32& iCode, FArchive& Ar)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, SerializeExpr, EExprToken, PARAMS(int32&, FArchive&), ARGS(iCode, Ar))
    }

    const TCHAR* UStruct::GetPrefixCPP() const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(UStruct, GetPrefixCPP, const TCHAR*)
    }

    void UStruct::SetSuperStruct(UStruct* NewSuperStruct)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, SetSuperStruct, void, PARAMS(UStruct*), ARGS(NewSuperStruct))
    }

    FString UStruct::PropertyNameToDisplayName(FName InName) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, PropertyNameToDisplayName, FString, PARAMS(FName), ARGS(InName))
    }

    FString UStruct::GetAuthoredNameForField(const UField* Field) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, GetAuthoredNameForField, FString, PARAMS(const UField*), ARGS(Field))
    }

    bool UStruct::IsStructTrashed() const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(UStruct, IsStructTrashed, bool)
    }

    FName UStruct::FindPropertyNameFromGuid(const FGuid& PropertyGuid) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, FindPropertyNameFromGuid, FName, PARAMS(const FGuid&), ARGS(PropertyGuid))
    }

    FGuid UStruct::FindPropertyGuidFromName(const FName InName) const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(UStruct, FindPropertyGuidFromName, FGuid, PARAMS(const FName), ARGS(InName))
    }

    bool UStruct::ArePropertyGuidsAvailable() const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(UStruct, ArePropertyGuidsAvailable, bool)
    }

    auto UStruct::ForEachFunction() -> Generator<UFunction*>
    {
        UField* CurrentField = GetChildren();

        while (CurrentField != nullptr) {
            //Only trigger the callable on UFunction objects
            if (UFunction* Function = Cast<UFunction>(CurrentField)) {
                co_yield Function;
            }
            CurrentField = CurrentField->GetNext();
        }
    }

    auto UStruct::ForEachProperty() -> Generator<FProperty*>
    {
        if (Version::IsBelow(4, 25))
        {
            UField* CurrentField = GetChildren();

            while (CurrentField != nullptr) {
                FField* CurrentFieldAsFField = CurrentField->AsFFieldUnsafe();

                //Only trigger the callable on UProperty objects
                if (FProperty* Property = CastField<FProperty>(CurrentFieldAsFField)) {
                    co_yield Property;
                }
                CurrentField = CurrentField->GetNext();
            }
        }
        else
        {
            FField* CurrentField = GetChildProperties();

            while (CurrentField != nullptr) {
                //Only trigger the callable on FProperty objects
                if (FProperty* Property = CastField<FProperty>(CurrentField)) {
                    co_yield Property;
                }
                CurrentField = CurrentField->GetNextFFieldUnsafe();
            }
        }
    }

    auto UStruct::ForEachSuperStruct() -> Generator<UStruct*>
    {
        UStruct* SuperStruct = GetSuperStruct();

        while (SuperStruct)
        {
            co_yield SuperStruct;
            SuperStruct = SuperStruct->GetSuperStruct();
        }
    }

    auto UStruct::ForEachPropertyInChain() -> Generator<FProperty*>
    {
        UStruct* Class = this;

        while (Class)
        {
            for (FProperty* Child : Class->ForEachProperty())
            {
                co_yield Child;
            }

            for (UStruct* SuperStruct : Class->ForEachSuperStruct())
            {
                if (!SuperStruct) continue;

                for (FProperty* Property : SuperStruct->ForEachProperty())
                {
                    co_yield Property;
                }
            }

            UStruct* NextClass = Class->GetClassPrivate();
            if (NextClass != Class)
            {
                Class = NextClass;
            }
            else
            {
                co_return;
            }
        }
    }

    auto UStruct::ForEachFunctionInChain() -> Generator<UFunction*>
    {
        UClass* Class = Cast<UClass>(this);

        while (Class)
        {
            for (UFunction* Function : Class->ForEachFunction())
            {
                co_yield Function;
            }

            for (UStruct* SuperStruct : Class->ForEachSuperStruct())
            {
                if (!SuperStruct) continue;

                for (UFunction* Function : SuperStruct->ForEachFunction())
                {
                    co_yield Function;
                }
            }
            

            auto& Interfaces = Class->GetInterfaces();
            for (FImplementedInterface& Interface : Interfaces)
            {
                for (UFunction* Function : Interface.Class->ForEachFunctionInChain())
                {
                    co_yield Function;
                }
            }

            UClass* NextClass = Class->GetClassPrivate();
            if (NextClass != Class)
            {
                Class = NextClass;
            }
            else
            {
                co_return;
            }
        }
    }

    struct FPropertyCacheKey
    {
        void* ClassPtr;
        FName PropertyName;
        bool operator==(const FPropertyCacheKey& Other) const
        {
            return (ClassPtr == Other.ClassPtr && PropertyName == Other.PropertyName);
        }
    };
    struct FPropertyCacheKeyHash
    {
        size_t operator()(const FPropertyCacheKey& Item) const
        {
            return std::hash<uintptr_t>()((uintptr_t)Item.ClassPtr) ^ std::hash<FName>()(Item.PropertyName);
        }
    };
    FProperty* UStruct::FindProperty(FName PropertyName)
    {
        static std::unordered_map<FPropertyCacheKey, FProperty*, FPropertyCacheKeyHash> PropertyCache;
        FPropertyCacheKey CacheIndex{this, PropertyName};
        if (PropertyCache.contains(CacheIndex)) { return PropertyCache[CacheIndex]; }

        for (FProperty* Property : ForEachPropertyInChain())
        {
            if (Property->GetFName() == PropertyName)
            {
                PropertyCache[CacheIndex] = Property;
                return Property;
            }
        }
        return nullptr;
    }

    bool UStruct::HasChildren()
    {
        if (Version::IsBelow(4, 25))
        {
            return GetChildren();
        }
        else
        {
            return GetChildProperties() || GetChildren();
        }
    }

    FProperty* UStruct::GetFirstProperty()
    {
        if (Version::IsBelow(4, 25))
        {
            // In <4.25, this is safe if a UField is a property, which 'CastField' checks
            // In <4.25, all properties are of type UField
            return CastField<FProperty>(std::bit_cast<FField*>(GetChildren()));
        }
        else
        {
            return CastField<FProperty>(GetChildProperties());
        }
    }
}