#ifndef RC_UNREAL_FSTRPROPERTY_HPP
#define RC_UNREAL_FSTRPROPERTY_HPP

#include <Helpers/Format.hpp>

#include <Unreal/FProperty.hpp>
#include <Unreal/TProperty.hpp>
#include <Unreal/FString.hpp>

namespace RC::Unreal
{
    class RC_UE_API FStrProperty : public TProperty_WithEqualityAndSerializer<FString, FProperty>
    {
        DECLARE_FIELD_CLASS(FStrProperty);
        DECLARE_VIRTUAL_TYPE(FStrProperty);
    };
}


#endif //RC_UNREAL_FSTRPROPERTY_HPP
