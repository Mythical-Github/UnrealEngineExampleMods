#ifndef RC_UNREAL_NUMERICPROPERTYTYPES_HPP
#define RC_UNREAL_NUMERICPROPERTYTYPES_HPP

#include <Unreal/Property/FNumericProperty.hpp>
#include <Unreal/PrimitiveTypes.hpp>

namespace RC::Unreal
{
    class RC_UE_API FByteProperty : public TProperty_Numeric<uint8>
    {
        DECLARE_FIELD_CLASS(FByteProperty);
        DECLARE_VIRTUAL_TYPE(FByteProperty);

    public:
#include <MemberVariableLayout_HeaderWrapper_FByteProperty.hpp>
    };

    class RC_UE_API FInt8Property : public TProperty_Numeric<int8>
    {
        DECLARE_FIELD_CLASS(FInt8Property);
        DECLARE_VIRTUAL_TYPE(FInt8Property);
    };

    class RC_UE_API FInt16Property : public TProperty_Numeric<int16>
    {
        DECLARE_FIELD_CLASS(FInt16Property);
        DECLARE_VIRTUAL_TYPE(FInt16Property);
    };

    class RC_UE_API FIntProperty : public TProperty_Numeric<int32>
    {
        DECLARE_FIELD_CLASS(FIntProperty);
        DECLARE_VIRTUAL_TYPE(FIntProperty);
    };

    class RC_UE_API FInt64Property : public TProperty_Numeric<int64>
    {
        DECLARE_FIELD_CLASS(FInt64Property);
        DECLARE_VIRTUAL_TYPE(FInt64Property);
    };

    class RC_UE_API FUInt16Property : public TProperty_Numeric<uint16>
    {
        DECLARE_FIELD_CLASS(FUInt16Property);
        DECLARE_VIRTUAL_TYPE(FUInt16Property);
    };

    class RC_UE_API FUInt32Property : public TProperty_Numeric<uint32>
    {
        DECLARE_FIELD_CLASS(FUInt32Property);
        DECLARE_VIRTUAL_TYPE(FUInt32Property);
    };

    class RC_UE_API FUInt64Property : public TProperty_Numeric<uint64>
    {
        DECLARE_FIELD_CLASS(FUInt64Property);
        DECLARE_VIRTUAL_TYPE(FUInt64Property);
    };

    class RC_UE_API FFloatProperty : public TProperty_Numeric<float>
    {
        DECLARE_FIELD_CLASS(FFloatProperty);
        DECLARE_VIRTUAL_TYPE(FFloatProperty);
    };

    class RC_UE_API FDoubleProperty : public TProperty_Numeric<double>
    {
        DECLARE_FIELD_CLASS(FDoubleProperty);
        DECLARE_VIRTUAL_TYPE(FDoubleProperty);
    };
}

#endif //RC_UNREAL_NUMERICPROPERTYTYPES_HPP
