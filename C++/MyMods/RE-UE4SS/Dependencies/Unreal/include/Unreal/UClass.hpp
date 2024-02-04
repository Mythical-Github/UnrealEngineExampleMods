#ifndef RC_UNREAL_UCLASS_HPP
#define RC_UNREAL_UCLASS_HPP

#include <format>

#include <Unreal/Common.hpp>
#include <Unreal/UStruct.hpp>
#include <Unreal/Property/FStructProperty.hpp>
#include <Unreal/TypeChecker.hpp>

namespace RC::Unreal
{

    struct RC_UE_API FImplementedInterface
    {
        UClass* Class;
        int32_t PointerOffset;
        bool bImplementedByK2;
    };

    class RC_UE_API UClass : public UStruct
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UClass, CoreUObject);

    public:
#include <MemberVariableLayout_HeaderWrapper_UClass.hpp>

    public:
        struct Offset
        {
            /* Temporary implementation, based on:
                ClassConstructorType ClassConstructor;
                ClassVTableHelperCtorCallerType ClassVTableHelperCtorCaller;
                ClassAddReferencedObjectsType ClassAddReferencedObjects;
                mutable uint32 ClassUnique:31;                                   // 0x??
                uint32 bCooked:1;                                                // 0x??
                EClassFlags ClassFlags;                                          // 0xCC
                EClassCastFlags ClassCastFlags;                                  // 0xD0
                UClass* ClassWithin;                                             // 0xD8
                UObject* ClassGeneratedBy;                                       // 0xE0
                FName ClassConfigName;                                           // 0xE8
                TArray<FRepRecord> ClassReps;                                    // 0xF0
                TArray<UField*> NetFields;                                       // 0x100 -
                int32 FirstOwnedClassRep = 0;                                    // 0x114 -0x4
                UObject* ClassDefaultObject;                                     // 0x118
                void* SparseClassData;                                           // 0x120
                UScriptStruct* SparseClassDataStruct;                            // 0x128
                TMap<FName, UFunction*> FuncMap;                                 // 0x130
                mutable TMap<FName, UFunction*> SuperFuncMap;                    // 0x180
                mutable FRWLock SuperFuncMapLock;                                // 0x??? ; size 0x8
                TArray<FImplementedInterface> Interfaces;                        // 0x1D8 ?
            //*/
            static int32_t class_config_name;
        };
    public:
        auto HasAnyClassFlags(EClassFlags FlagsToCheck) -> bool;
        auto HasAllClassFlags(EClassFlags FlagsToCheck) -> bool;
        //auto GetClassFlags() -> EClassFlags;
        //auto GetClassWithin() -> UClass*;
        //auto GetClassConfigName() -> FName;
        //auto GetClassDefaultObject() -> UObject*;
        //auto GetInterfaces() -> TArray<FImplementedInterface>&;

        bool HasAnyCastFlag(EClassCastFlags FlagToCheck) const;
        bool HasAllCastFlags(EClassCastFlags FlagsToCheck) const;
        
        auto GetSuperClass() -> UClass* { return static_cast<UClass*>(GetSuperStruct()); }
        auto GetSuperClass() const -> const UClass* { return static_cast<const UClass*>(GetSuperStruct()); }
    };

    // TODO: Move these elsewhere
    class RC_UE_API UBlueprintGeneratedClass : public UClass
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UBlueprintGeneratedClass, Engine);
    };

    class RC_UE_API UWidgetBlueprintGeneratedClass : public UClass
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UWidgetBlueprintGeneratedClass, Engine);
    };

    class RC_UE_API UAnimBlueprintGeneratedClass : public UClass
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UAnimBlueprintGeneratedClass, Engine);
    };
}


#endif //RC_UNREAL_UCLASS_HPP
