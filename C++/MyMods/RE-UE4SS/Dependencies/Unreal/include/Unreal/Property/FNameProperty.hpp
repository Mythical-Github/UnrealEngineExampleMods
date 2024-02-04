#ifndef RC_UNREAL_FNAMEPROPERTY_HPP
#define RC_UNREAL_FNAMEPROPERTY_HPP

#include <Unreal/FProperty.hpp>
#include <Unreal/TProperty.hpp>

namespace RC::Unreal
{
    class RC_UE_API FNameProperty : public TProperty_WithEqualityAndSerializer<FName, FProperty>
    {
        DECLARE_FIELD_CLASS(FNameProperty);
        DECLARE_VIRTUAL_TYPE(FNameProperty);
    };
}


#endif //RC_UNREAL_FNAMEPROPERTY_HPP
