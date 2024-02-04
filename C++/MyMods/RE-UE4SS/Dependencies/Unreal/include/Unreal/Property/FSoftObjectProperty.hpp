#ifndef RC_UNREAL_FSOFTOBJECTPROPERTY_HPP
#define RC_UNREAL_FSOFTOBJECTPROPERTY_HPP

#include <Unreal/Property/FObjectProperty.hpp>
#include <Unreal/PersistentObjectPtr.hpp>
#include <Unreal/FString.hpp>

namespace RC::Unreal
{
    struct FSoftObjectPath
    {
        FName AssetPathName;
        FString SubPathString;
    };

    struct FSoftObjectPtr : public TPersistentObjectPtr<FSoftObjectPath>
    {
    };

    class RC_UE_API FSoftObjectProperty : public TFObjectPropertyBase<FSoftObjectPtr>
    {
        DECLARE_FIELD_CLASS(FSoftObjectProperty);
        DECLARE_VIRTUAL_TYPE(FSoftObjectProperty);
    };
}


#endif //RC_UNREAL_FSOFTOBJECTPROPERTY_HPP
