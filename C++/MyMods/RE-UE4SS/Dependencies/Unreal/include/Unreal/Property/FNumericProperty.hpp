#ifndef RC_UNREAL_FNUMERICPROPERTY_H
#define RC_UNREAL_FNUMERICPROPERTY_H

#include <Unreal/TProperty.hpp>
#include <File/File.hpp>
//#include <Unreal/UnrealStringConversions.h>

namespace RC::Unreal
{
    class UEnum;

    class RC_UE_API FNumericProperty : public FProperty
    {
        DECLARE_FIELD_CLASS(FNumericProperty);
        DECLARE_VIRTUAL_TYPE(FNumericProperty);

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
        /** Return true if this property is for a floating point number **/
        auto IsFloatingPoint() const -> bool;

        /** Return true if this property is for a integral or enum type **/
        auto IsInteger() const -> bool;

        /** Return the UEnum if this property is a FByteProperty with a non-null Enum **/
        auto GetIntPropertyEnum() const -> UEnum*;

        // TODO: The vtable offset generator isn't currently capable of handling multiple functions with the same name
        //       As a result, these two functions map to the same offset
        auto SetIntPropertyValue(void* Data, uint64 Value) const -> void;
        auto SetIntPropertyValue(void* Data, int64 Value) const -> void;

        /**
         * Set the value of a floating point property type
         * @param data - pointer to property data to set
         * @param value - Value to set data to
        **/
        auto SetFloatingPointPropertyValue(void* Data, double Value) -> void;

        /**
         * Set the value of any numeric type from a string point
         * @param data - pointer to property data to set
         * @param value - Value (as a string) to set
         * CAUTION: This routine does not do enum name conversion
        **/
        auto SetNumericPropertyValueFromString(void* Data, TCHAR const* Value) -> void;

        /**
         * Gets the value of a signed integral property type
         * @param data - pointer to property data to get
         * @return Data as a signed int
        **/
        auto GetSignedIntPropertyValue(void* Data) -> int64;

        /**
         * Gets the value of an unsigned integral property type
         * @param data - pointer to property data to get
         * @return Data as an unsigned int
        **/
        auto GetUnsignedIntPropertyValue(void const* Data) -> uint64;

        /**
         * Gets the value of an floating point property type
         * @param data - pointer to property data to get
         * @return Data as a double
        **/
        auto GetFloatingPointPropertyValue(void const* Data) -> double;

        /**
         * Get the value of any numeric type and return it as a string
         * @param data - pointer to property data to get
         * @return Data as a string
         * CAUTION: This routine does not do enum name conversion
        **/
        auto GetNumericPropertyValueToString(void const* Data) -> FString;

        auto CanHoldDoubleValueInternal(double Value) const -> bool;

        auto CanHoldSignedValueInternal(int64 Value) const -> bool;

        auto CanHoldUnsignedValueInternal(uint64 Value) const -> bool;

        /** Return true if this property is a FByteProperty with a non-null Enum **/
        auto IsEnum() -> bool
        {
            return !!GetIntPropertyEnum();
        }
    };

    template<typename InTCppType>
    class RC_UE_API TProperty_Numeric : public TProperty_WithEqualityAndSerializer<InTCppType, FNumericProperty>
    {
    public:
        typedef TProperty_WithEqualityAndSerializer<InTCppType, FNumericProperty> Super;
        typedef InTCppType TCppType;
        typedef typename Super::TTypeFundamentals TTypeFundamentals;

    public:
        auto IsUnsignedInteger() -> bool
        {
            return std::is_unsigned_v<TCppType>;
        }

        auto SetUnsignedIntPropertyValue(void* data, uint64_t value) -> void
        {
            if (!std::is_integral_v<TCppType>)
            {
                throw std::runtime_error("Cannot set floating point property value to integral value");
            }
            TTypeFundamentals::SetPropertyValue(data, (TCppType) value);
        }

        /**
         * Set the value of a signed integral property type
         * @param data - pointer to property data to set
         * @param value - Value to set data to
        **/
        auto SetSignedIntPropertyValue(void* data, int64_t value) -> void
        {
            if (!std::is_integral_v<TCppType>)
            {
                throw std::runtime_error("Cannot set floating point property value to integral value");
            }
            TTypeFundamentals::SetPropertyValue(data, (TCppType) value);
        }
    };
}

#endif //RC_UNREAL_FNUMERICPROPERTY_H
