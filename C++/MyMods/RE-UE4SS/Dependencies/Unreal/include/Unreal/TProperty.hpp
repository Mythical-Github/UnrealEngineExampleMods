#ifndef RC_UNREAL_TPROPERTY_H
#define RC_UNREAL_TPROPERTY_H

#include <Unreal/FProperty.hpp>

namespace RC::Unreal
{
    /** Implements common operations for the provided template type */
    template<typename InTCppType>
    class RC_UE_API TPropertyTypeFundamentals
    {
    public:
        typedef InTCppType TCppType;
        enum
        {
            CPPSize = sizeof(TCppType),
            CPPAlignment = alignof(TCppType)
        };

        /** Convert the address of a value of the property to the proper type */
        FORCEINLINE static auto GetPropertyValuePtr(const void* Value) -> const TCppType*
        {
            return std::bit_cast<const TCppType*>(Value);
        }

        /** Convert the address of a value of the property to the proper type */
        FORCEINLINE static auto GetPropertyValuePtr(void* Value) -> TCppType*
        {
            return std::bit_cast<TCppType*>(Value);
        }

        /** Get the value of the property from an address */
        FORCEINLINE static auto GetPropertyValue(const void* Value) -> const TCppType&
        {
            return *GetPropertyValuePtr(Value);
        }

        /** Get the default value of the cpp type, just the default constructor, which works even for things like int32 */
        FORCEINLINE static auto GetDefaultPropertyValue() -> TCppType
        {
            return TCppType();
        }

        /** Get the value of the property from an address, unless it is NULL, then return the default value */
        FORCEINLINE static auto GetOptionalPropertyValue(const void* Value) -> TCppType
        {
            return Value ? GetPropertyValue(Value) : GetDefaultPropertyValue();
        }

        /** Set the value of a property at an address */
        FORCEINLINE static auto SetPropertyValue(void* PropertyValue, const TCppType& Value) -> void
        {
            *GetPropertyValuePtr(PropertyValue) = Value;
        }

        /** Initialize the value of a property at an address, this assumes over uninitialized memory */
        FORCEINLINE static auto InitializePropertyValue(void* Value) -> TCppType*
        {
            return new (Value) TCppType();
        }

        /** Destroy the value of a property at an address */
        FORCEINLINE static auto DestroyPropertyValue(void* Value) -> void
        {
            GetPropertyValuePtr(Value)->~TCppType();
        }
    };

    /** Generic property implementation for standard C++ types */
    template<typename InTCppType, class TInPropertyBaseClass>
    class RC_UE_API TProperty : public TInPropertyBaseClass, public TPropertyTypeFundamentals<InTCppType>
    {
    public:
        typedef InTCppType TCppType;
        typedef TInPropertyBaseClass Super;
        typedef TPropertyTypeFundamentals<InTCppType> TTypeFundamentals;

        /** Convert the address of a container to the address of the property value, in the proper type */
        FORCEINLINE auto GetPropertyValuePtrInContainer(const void* A, int32_t ArrayIndex = 0) -> const TCppType*
        {
            AssetTypeEquality();
            return TTypeFundamentals::GetPropertyValuePtr(Super::template ContainerPtrToValuePtr<void>(A, ArrayIndex));
        }

        /** Convert the address of a container to the address of the property value, in the proper type */
        FORCEINLINE auto GetPropertyValuePtrInContainer(void* A, int32_t ArrayIndex = 0) -> TCppType*
        {
            AssetTypeEquality();
            return TTypeFundamentals::GetPropertyValuePtr(Super::template ContainerPtrToValuePtr<void>(A, ArrayIndex));
        }

        /** Get the value of the property from a container address */
        FORCEINLINE auto GetPropertyValueInContainer(void const* A, int32_t ArrayIndex = 0) -> TCppType const&
        {
            return *GetPropertyValuePtrInContainer(A, ArrayIndex);
        }

        /** Get the value of the property from a container address, unless it is NULL, then return the default value */
        FORCEINLINE auto GetOptionalPropertyValueInContainer(const void* A, int32_t ArrayIndex = 0) -> TCppType
        {
            AssetTypeEquality();
            return A ? GetPropertyValueInContainer(A, ArrayIndex) : TTypeFundamentals::GetDefaultPropertyValue();
        }

        /** Set the value of a property in a container */
        FORCEINLINE auto SetPropertyValueInContainer(void* A, const TCppType& Value, int32_t ArrayIndex = 0) -> void
        {
            *GetPropertyValuePtrInContainer(A, ArrayIndex) = Value;
        }
    protected:
        auto InitializeValueImpl(void* Dest) -> void
        {
            AssetTypeEquality();
            for (int32_t i = 0; i < this->GetArrayDim(); i++)
            {
                TTypeFundamentals::InitializePropertyValue((uint8_t*)Dest + i * this->GetElementSize());
            }
        }

        auto DestroyValueImpl(void* Dest) -> void
        {
            AssetTypeEquality();
            for (int32_t i = 0; i < this->GetArrayDim(); i++)
            {
                TTypeFundamentals::DestroyPropertyValue((uint8_t*) Dest + i * this->GetElementSize());
            }
        }

        auto ClearValueImpl(void* Data) -> void
        {
            AssetTypeEquality();
            TTypeFundamentals::SetPropertyValue(Data, TTypeFundamentals::GetDefaultPropertyValue());
        }

        auto CopyValuesInternalImpl(void* Dest, void const* Src, int32_t Count) -> void
        {
            AssetTypeEquality();
            for (int32_t i = 0; i < Count; i++)
            {
                TTypeFundamentals::GetPropertyValuePtr(Dest)[i] = TTypeFundamentals::GetPropertyValuePtr(Src)[i];
            }
        }

        FORCEINLINE auto AssetTypeEquality()
        {
            if (this->GetElementSize() != TTypeFundamentals::CPPSize)
            {
                throw std::runtime_error("Type equality assertion failed: GetElementSize() != TTypeFundamentals::CPPSize");
            }
        }
    };

    template<typename InTCppType, class TInPropertyBaseClass>
    class RC_UE_API TProperty_WithEqualityAndSerializer : public TProperty<InTCppType, TInPropertyBaseClass>
    {
    public:
        typedef TProperty<InTCppType, TInPropertyBaseClass> Super;
        typedef InTCppType TCppType;
        typedef typename Super::TTypeFundamentals TTypeFundamentals;
    protected:
        auto IdenticalImpl(const void* A, const void* B, uint32_t PortFlags) -> bool
        {
            // RHS is the same as TTypeFundamentals::GetOptionalPropertyValue(B) but avoids an unnecessary copy of B
            return TTypeFundamentals::GetPropertyValue(A) == (B ? TTypeFundamentals::GetPropertyValue(B) : TTypeFundamentals::GetDefaultPropertyValue());
        }

        //virtual void SerializeItem(FStructuredArchive::FSlot Slot, void *Value, void const *Defaults) const override {
        //    Slot << *TTypeFundamentals::GetPropertyValuePtr(Value);
        //}
    };

    // From: https://stackoverflow.com/a/22592618
    template<class SupposedTProperty>
    struct RC_UE_API IsTPropertyHelper
    {
    private:
#pragma warning(disable: 4068)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"
        template<class InTCppType, class TInPropertyBaseClass>
        static decltype(static_cast<const ::RC::Unreal::TProperty<InTCppType, TInPropertyBaseClass>&>(std::declval<SupposedTProperty>()), std::true_type{})
        test(const ::RC::Unreal::TProperty<InTCppType, TInPropertyBaseClass>&);

        static std::false_type test(...);
#pragma clang diagnostic pop
#pragma warning(default: 4068)
    public:
        static constexpr bool value = decltype(IsTPropertyHelper::test(std::declval<SupposedTProperty>()))::value;
    };
    template<class SupposedTProperty>
    inline constexpr bool IsTProperty = IsTPropertyHelper<SupposedTProperty>::value;
}

#endif //RC_UNREAL_TPROPERTY_H
