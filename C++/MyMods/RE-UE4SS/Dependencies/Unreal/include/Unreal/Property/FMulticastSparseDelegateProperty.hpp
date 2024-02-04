#ifndef RC_UNREAL_XMULTICASTSPARSEDELEGATEPROPERTY_HPP
#define RC_UNREAL_XMULTICASTSPARSEDELEGATEPROPERTY_HPP

#include <Helpers/Format.hpp>

#include <Unreal/FProperty.hpp>
#include <Unreal/FWeakObjectPtr.hpp>
#include <Unreal/Property/FMulticastDelegateProperty.hpp>

namespace RC::Unreal
{
    struct RC_UE_API FSparseDelegate
    {
        bool b_is_bound;
    };

    class RC_UE_API FMulticastSparseDelegateProperty : public TProperty<FSparseDelegate, FMulticastDelegateProperty>
    {
        DECLARE_FIELD_CLASS(FMulticastSparseDelegateProperty);
        DECLARE_VIRTUAL_TYPE(FMulticastSparseDelegateProperty);
    };
}


#endif //RC_UNREAL_XMULTICASTSPARSEDELEGATEPROPERTY_HPP
