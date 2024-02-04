#ifndef RC_UNREAL_XENUMPROPERTY_HPP
#define RC_UNREAL_XENUMPROPERTY_HPP

#include <Unreal/FProperty.hpp>
#include <Unreal/UnrealVersion.hpp>

namespace RC::Unreal
{
    class FNumericProperty;
    class UEnum;

    class RC_UE_API FEnumProperty : public FProperty
    {
        DECLARE_FIELD_CLASS(FEnumProperty);
        DECLARE_VIRTUAL_TYPE(FEnumProperty);

    public:
#include <MemberVariableLayout_HeaderWrapper_FEnumProperty.hpp>

    public:
        auto GetUnderlyingProperty() -> FNumericProperty*;
    };
}


#endif //RC_UNREAL_XENUMPROPERTY_HPP
