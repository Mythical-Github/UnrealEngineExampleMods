#ifndef RC_UNREAL_XMULTICASTINLINEDELEGATEPROPERTY_HPP
#define RC_UNREAL_XMULTICASTINLINEDELEGATEPROPERTY_HPP

#include <Helpers/Format.hpp>

#include <Unreal/FProperty.hpp>
#include <Unreal/TProperty.hpp>
#include <Unreal/FWeakObjectPtr.hpp>
#include <Unreal/Property/FDelegateProperty.hpp>
#include <Unreal/Property/FMulticastDelegateProperty.hpp>
#include <Unreal/TArray.hpp>

namespace RC::Unreal
{
    class RC_UE_API FMulticastInlineDelegateProperty : public TProperty<FMulticastScriptDelegate, FMulticastDelegateProperty>
    {
        DECLARE_FIELD_CLASS(FMulticastInlineDelegateProperty);
        DECLARE_VIRTUAL_TYPE(FMulticastInlineDelegateProperty);
    };
}


#endif //RC_UNREAL_XMULTICASTINLINEDELEGATEPROPERTY_HPP
