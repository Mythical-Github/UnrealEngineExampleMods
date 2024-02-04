#ifndef RC_UNREAL_FSTRUCTROPERTY_HPP
#define RC_UNREAL_FSTRUCTROPERTY_HPP

#include <Unreal/FProperty.hpp>

namespace RC::Unreal
{
    class UScriptStruct;
    class XStructData;

    class RC_UE_API FStructProperty : public FProperty
    {
        DECLARE_FIELD_CLASS(FStructProperty);
        DECLARE_VIRTUAL_TYPE(FStructProperty);

    public:
#include <MemberVariableLayout_HeaderWrapper_FStructProperty.hpp>
    };
}


#endif //RC_UNREAL_FSTRUCTROPERTY_HPP
