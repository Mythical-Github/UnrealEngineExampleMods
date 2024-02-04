#ifndef RC_UNREAL_FBOOLPROPERTY_H
#define RC_UNREAL_FBOOLPROPERTY_H

#include <File/File.hpp>
#include <Unreal/FProperty.hpp>

namespace RC::Unreal
{
    class RC_UE_API FBoolProperty : public FProperty
    {
        DECLARE_FIELD_CLASS(FBoolProperty);
        DECLARE_VIRTUAL_TYPE(FBoolProperty);

    public:
#include <MemberVariableLayout_HeaderWrapper_FBoolProperty.hpp>

    public:
        //Emulate the CPP type API, see TPropertyTypeFundamentals
        //this is incomplete as some operations make no sense for bitfields, for example they don't have a usable address
        typedef bool TCppType;

        /** Returns the value of the boolean property */
        FORCEINLINE auto GetPropertyValue(const void* A) -> bool
        {
            uint8_t* ByteValue = (uint8_t*)A + GetByteOffset();
            return !!(*ByteValue & GetFieldMask());
        }

        /** Returns the value of the boolean property inside of it's container */
        FORCEINLINE auto GetPropertyValueInContainer(const void* A, int32_t ArrayIndex = 0) -> bool
        {
            return GetPropertyValue(ContainerPtrToValuePtr<void>(A, ArrayIndex));
        }

        /** Returns the default value of the boolean property */
        FORCEINLINE static auto GetDefaultPropertyValue() -> bool
        {
            return false;
        }

        /** Returns the property value from the given address, or default value if it represents the nullptr */
        FORCEINLINE auto GetOptionalPropertyValue(const void* B) -> bool
        {
            return B ? GetPropertyValue(B) : GetDefaultPropertyValue();
        }

        /** Returns the property value from the given container address, or default value if it represents the nullptr */
        FORCEINLINE auto GetOptionalPropertyValueInContainer(const void* B, int32_t ArrayIndex = 0) -> bool
        {
            return B ? GetPropertyValueInContainer(B, ArrayIndex) : GetDefaultPropertyValue();
        }

        /** Updates property value to the provided one */
        FORCEINLINE auto SetPropertyValue(void* A, bool Value) -> void
        {
            uint8_t* byte_value = (uint8_t*)A + GetByteOffset();
            *byte_value = ((*byte_value) & ~GetFieldMask()) | (Value ? GetByteMask() : 0);
        }

        /** Updates property value inside of the container */
        FORCEINLINE auto SetPropertyValueInContainer(void* A, bool Value, int32_t ArrayIndex = 0)
        {
            SetPropertyValue(ContainerPtrToValuePtr<void>(A, ArrayIndex), Value);
        }

        /** If the return value is true this FBoolProperty represents C++ bool type */
        FORCEINLINE auto IsNativeBool() -> bool
        {
            return GetFieldMask() == 0xff;
        }
    };
}

#endif //RC_UNREAL_FBOOLPROPERTY_H
