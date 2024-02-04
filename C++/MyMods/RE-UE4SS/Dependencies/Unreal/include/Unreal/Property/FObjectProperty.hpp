#ifndef RC_UNREAL_FOBJECTPROPERTY_HPP
#define RC_UNREAL_FOBJECTPROPERTY_HPP

#include <Unreal/FProperty.hpp>
#include <Unreal/TProperty.hpp>

namespace RC::Unreal
{
    class RC_UE_API FObjectPropertyBase : public FProperty
    {
        DECLARE_FIELD_CLASS(FObjectPropertyBase);
        DECLARE_VIRTUAL_TYPE(FObjectPropertyBase);

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
#include <MemberVariableLayout_HeaderWrapper_FObjectPropertyBase.hpp>

    public:
        void SetPropertyClass(UClass* NewPropertyClass);

        // Virtual Functions
    public:
        FString GetCPPTypeCustom(FString* ExtendedTypeText, uint32 CPPExportFlags, const FString& InnerNativeTypeName) const;
        UObject* LoadObjectPropertyValue(const void* PropertyValueAddress) const;
        UObject* GetObjectPropertyValue(const void* PropertyValueAddress) const;
        void SetObjectPropertyValue(void* PropertyValueAddress, UObject* Value) const;
        bool AllowCrossLevel() const;
        void CheckValidObject(void* Value) const;
    };

    template<typename InTCppType>
    class TFObjectPropertyBase : public TProperty<InTCppType, FObjectPropertyBase>
    {
    };

    class RC_UE_API FObjectProperty : public TFObjectPropertyBase<UObject*>
    {
        DECLARE_FIELD_CLASS(FObjectProperty);
        DECLARE_VIRTUAL_TYPE(FObjectProperty);
    };

    class RC_UE_API FObjectPtrProperty : public FObjectProperty
    {
        DECLARE_FIELD_CLASS(FObjectPtrProperty)
    };

    class RC_UE_API FAssetObjectProperty : public FObjectProperty
    {
        DECLARE_FIELD_CLASS(FAssetObjectProperty)
    };

    class RC_UE_API FAssetClassProperty : public FAssetObjectProperty
    {
        DECLARE_FIELD_CLASS(FAssetClassProperty)
    };
}


#endif //RC_UNREAL_FOBJECTPROPERTY_HPP
