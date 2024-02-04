#ifndef RC_UNREAL_FARRAYPROPERTY_HPP
#define RC_UNREAL_FARRAYPROPERTY_HPP

#include <Unreal/FProperty.hpp>
#include <Unreal/TProperty.hpp>
#include <Unreal/FScriptArray.hpp>

namespace RC::Unreal
{
    class RC_UE_API FArrayProperty : public FProperty
    {
        DECLARE_FIELD_CLASS(FArrayProperty);
        DECLARE_VIRTUAL_TYPE(FArrayProperty);

    public:
#include <MemberVariableLayout_HeaderWrapper_FArrayProperty.hpp>
    };
}


#endif //RC_UNREAL_FARRAYPROPERTY_HPP
