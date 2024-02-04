#include <Unreal/UClass.hpp>
#include <Unreal/TArray.hpp>
#include <Unreal/FProperty.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UClass)
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UBlueprintGeneratedClass)
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UWidgetBlueprintGeneratedClass)
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UAnimBlueprintGeneratedClass)

#include <MemberVariableLayout_SrcWrapper_UClass.hpp>

    int32_t UClass::Offset::class_config_name{};

    auto UClass::HasAnyClassFlags(EClassFlags FlagsToCheck) -> bool
    {
        return (GetClassFlags() & FlagsToCheck) != 0;
    }

    auto UClass::HasAllClassFlags(EClassFlags FlagsToCheck) -> bool
    {
        return (GetClassFlags() & FlagsToCheck) == FlagsToCheck;
    }

    bool UClass::HasAnyCastFlag(EClassCastFlags FlagToCheck) const
    {
        return (GetClassCastFlags() & FlagToCheck) != 0;
    }

    bool UClass::HasAllCastFlags(EClassCastFlags FlagsToCheck) const
    {
        return (GetClassCastFlags() & FlagsToCheck) == FlagsToCheck;
    }
}