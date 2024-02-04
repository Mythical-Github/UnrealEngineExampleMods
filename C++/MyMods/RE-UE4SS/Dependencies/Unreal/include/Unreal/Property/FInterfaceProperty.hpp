#ifndef RC_UNREAL_FINTERFACEPROPERTY_HPP
#define RC_UNREAL_FINTERFACEPROPERTY_HPP

#include <Unreal/FProperty.hpp>
#include <Unreal/TProperty.hpp>

namespace RC::Unreal
{
    class FScriptInterface
    {
    public:
        UObject* ObjectPointer{};
        void* InterfacePointer{};
    };

    class RC_UE_API FInterfaceProperty : public TProperty<FScriptInterface, FProperty>
    {
        DECLARE_FIELD_CLASS(FInterfaceProperty);
        DECLARE_VIRTUAL_TYPE(FInterfaceProperty);

    public:
#include <MemberVariableLayout_HeaderWrapper_FInterfaceProperty.hpp>

    public:
        void SetInterfaceClass(UClass* NewInterfaceClass);
    };
}


#endif //RC_UNREAL_FINTERFACEPROPERTY_HPP
