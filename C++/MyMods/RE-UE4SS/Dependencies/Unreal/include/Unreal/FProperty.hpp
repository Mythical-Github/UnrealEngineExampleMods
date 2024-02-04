#ifndef RC_UNREAL_XPROPERTY_HPP
#define RC_UNREAL_XPROPERTY_HPP

#include <Unreal/FField.hpp>
#include <Unreal/PrimitiveTypes.hpp>

namespace RC::Unreal
{
    class FString;

    enum class EPropertyObjectReferenceType
    {
        None = 0,
        Strong = 1 << 0,
        Weak = 1 << 1,
    };

    class RC_UE_API FProperty : public FField
    {
        DECLARE_FIELD_CLASS(FProperty);
        DECLARE_VIRTUAL_TYPE(FProperty);

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
#include <MemberVariableLayout_HeaderWrapper_FProperty.hpp>

    public:
        /**
         * Retrieves the offset of this property inside of it's parent struct
         * That would mean the offset of the property inside of the UObject or UStruct
         */
        [[deprecated("Use 'GetOffset_Internal' instead")]]
        auto GetOffset_ForInternal() -> int32_t;

        /**
         * Returns the total size of the property, correctly handling the statically sized array properties
         * Equivalent to element size for other properties
         */
        inline auto GetSize() -> int32_t
        {
            return GetElementSize() * GetArrayDim();
        }

        inline auto HasAnyPropertyFlags(EPropertyFlags FlagsToCheck) -> bool
        {
            return (GetPropertyFlags() & FlagsToCheck) != 0 || FlagsToCheck == CPF_AllFlags;
        }

        inline auto HasAllPropertyFlags(EPropertyFlags flags_to_check) -> bool
        {
            return ((GetPropertyFlags() & flags_to_check) == flags_to_check);
        }

        /** See if the offset of this property is below the supplied container size */
        bool IsInContainer(UStruct* ContainerClass);

        template<typename T>
        auto ContainerPtrToValuePtr(void* Container, int32_t ArrayIndex = 0) -> T*
        {
            return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(Container) + GetOffset_Internal() + GetElementSize() * ArrayIndex);
        }

        template<typename T>
        auto ContainerPtrToValuePtr(const void* Container, int32_t ArrayIndex = 0) -> const T*
        {
            return reinterpret_cast<const T*>(reinterpret_cast<uintptr_t>(Container) + GetOffset_Internal() + GetElementSize() * ArrayIndex);
        }

        auto GetCPPMacroType(FString& ExtendedTypeText) const -> FString;

        auto PassCPPArgsByRef() const -> bool;

        auto GetCPPType(FString* ExtendedTypeText = nullptr, uint32 CPPExportFlags = 0) const -> FString;

        auto GetCPPTypeForwardDeclaration() const -> FString;

        auto LinkInternal(FArchive& Ar) -> void;

        using EConvertFromTypeResult = int32; // Remove if/when we have an EConvertFromTypeResult implementation, safe to use if you know the underlying enum numbers
        using FPropertyTag = void*; // Remove if/when we have a FPropertyTag implementation, for now, probably a bad idea to call
        struct FStructuredArchive { enum class FSlot {}; }; // Remove if/when we have a FStructuredArchive implementation, for now, probably a bad idea to call
        auto ConvertFromType(const FPropertyTag& Tag, FStructuredArchive::FSlot Slot, uint8* Data, UStruct* DefaultsStruct) -> EConvertFromTypeResult;

        /**
         * Determines whether the property values are identical.
         *
         * @param A	property data to be compared, already offset
         * @param B	property data to be compared, already offset
         * @param port_flags allows caller more control over how the property values are compared
         * @return true if the property values are identical
         */
        auto Identical(const void* A, const void* B, uint32_t PortFlags = 0) -> bool;

        /**
         * Determines whether the property values are identical.
         *
         * @param A property container of data to be compared, NOT offset
         * @param B property container of data to be compared, NOT offset
         * @param port_flags allows caller more control over how the property values are compared
         * @return true if the property values are identical
         */
        auto Identical_InContainer(const void* A, const void* B, int32_t ArrayIndex = 0, uint32_t PortFlags = 0) -> bool;

        auto SerializeItem(FStructuredArchive::FSlot Slot, void* Value, void const* Defaults = nullptr) const -> void;

        using UPackageMap = void*; // Remove if/when we have a UPackageMap implementation, for now, probably a bad idea to call
        auto NetSerializeItem(FArchive& Ar, UPackageMap* Map, void* Data, TArray<uint8>* MetaData = nullptr) const -> bool;

        auto SupportsNetSharedSerialization() const -> bool;

        /**
         * Exports the property value into the text string provided
         *
         * @param value_str string to serialize the property value into
         * @param property_value property value to serialize
         * @param default_value the default value of the property, or nullptr to serialize everything
         * @param parent parent object on which the property is set
         * @param port_flags the additional flags for property serialization
         * @param export_root_scope the scope to create relative paths from, if the PPF_ExportsNotFullyQualified flag is passed in. If nullptr, the package containing the object will be used instead.
         */
        auto ExportTextItem(FString& ValueStr, const void* PropertyValue, const void* DefaultValue, UObject* Parent, int32_t PortFlags, UObject* ExportRootScope = nullptr) -> void;

        /**
         * Imports the property value from the provided text string
         *
         * @param buffer the text to read the value from
         * @param data the property value to serialize the data into
         * @param port_flags the extra flags for parsing the value
         * @param owner_object the object owning this property's value
         * @return the remaining string after the value has been read, or nullptr if the value has not been read
         */
        auto ImportText(const TCHAR* Buffer, void* Data, int32_t PortFlags, UObject* OwnerObject, class FOutputDevice* ErrorText) -> const TCHAR*;
        auto ImportText_Internal(const TCHAR* Buffer, void* Data, int32 PortFlags, UObject* OwnerObject, class FOutputDevice* ErrorText) -> const TCHAR*;

        /**
         * Exports the property value to the string if it differs from the delta value specified
         *
         * @param value_str string to append the property value to
         * @param data property value to serialize
         * @param delta default property value, serialization is skipped if it is identical to the data
         * @param parent parent object on which property is being serialized
         * @param port_flags the additional flags for property serialization
         * @param export_root_scope the scope to create relative paths from, if the PPF_ExportsNotFullyQualified flag is passed in
         * @return true if the value was different from delta and was actually serialized to string
         */
        auto ExportText_Direct(FString& ValueStr, const void* Data, const void* Delta, UObject* Parent, int32_t PortFlags, UObject* ExportRootScope = nullptr) -> bool;

        /**
         * Exports the property value to the string if it is different from the default value specified, in the container
         *
         * @param index index of the value if the property represents the statically sized array
         * @param value_str string to serialize the value into
         * @param data the pointer to the container with the property value
         * @param delta the pointer to the container with the default property value
         * @param parent the pointer to the UObject which property is being exported
         * @param port_flags the additional flags for property serialization
         * @param export_root_scope the scope to create relative paths from, if the PPF_ExportsNotFullyQualified flag is passed in
         * @return true if the value was different from delta and was actually serialized to string
         */
        auto ExportText_InContainer(int32_t Index, FString& ValueStr, const void* Data, const void* Delta, UObject* Parent, int32_t PortFlags, UObject* ExportRootScope = NULL) -> bool;

    public:
        /**
         * Copy the value for a single element of this property.
         * Behaves exactly the same as copy_complete_value for non-static sized array properties
         *
         * @param dest the address where the value should be copied to
         * @param src the address of the value to copy from
         */
        auto CopySingleValue(void* Dest, void const* Src) -> void;

        /**
         * Returns the hash value for an element of this property.
         * Will throw the exception if the property value is not hashable.
         */
        uint32_t GetValueTypeHash(const void* Src);

        /**
         * Copies specified number of property values from src address to dest
         * Internal function, do not call directly!
         */
        auto CopyValuesInternal(void* Dest, const void* Src, int32_t Count) -> void;

        auto GetValueTypeHashInternal(const void* Src) const -> uint32;

        /**
         * Copy the value for all elements of this property.
         *
         * @param dest the address where the value should be copied to
         * @param src the address of the value to copy from
         */
        auto CopyCompleteValue(void* Dest, const void* Src) -> void;

        auto CopyCompleteValue_InContainer(void* Dest, const void* Src) -> void;


        /**
         * Copy the value for a single element of this property. To the script VM.
         *
         * @param dest the address where the value should be copied to
         * @param src the address of the value to copy from. should be evaluated the same way as Dest
         */
        auto CopySingleValueToScriptVM(void* Dest, void const* Src) const -> void;

        /**
         * Copy the value for all elements of this property. To the script VM.
         *
         * @param dest the address where the value should be copied to
         * @param src the address of the value to copy from. should be evaluated the same way as Dest
         */
        auto CopyCompleteValueToScriptVM(void* Dest, void const* Src) const -> void;

        /**
         * Copy the value for a single element of this property. From the script VM.
         *
         * @param dest the address where the value should be copied to
         * @param src the address of the value to copy from. should be evaluated the same way as Dest
         */
        auto CopySingleValueFromScriptVM(void* Dest, void const* Src) const -> void;

        /**
         * Copy the value for all elements of this property. From the script VM.
         *
         * @param dest the address where the value should be copied to
         * @param src the address of the value to copy from. should be evaluated the same way as Dest
         */
        auto CopyCompleteValueFromScriptVM(void* Dest, void const* Src) const -> void;

        /**
         * Zeros the value for this property. The existing data is assumed valid (so for example this calls FString::Empty)
         * This only does one item and not the entire fixed size array.
         *
         * @param data the address of the value for this property that should be cleared.
         */
        auto ClearValue(void* Data) -> void;

        /**
         * Zeros the value for this property. The existing data is assumed valid (so for example this calls FString::Empty)
         * This only does one item and not the entire fixed size array.
         *
         * @param Data the address of the container of the value for this property that should be cleared.
         */
        auto ClearValue_InContainer(void* Data, int32_t ArrayIndex = 0) -> void;
        auto ClearValueInternal(void* Data) const -> void;

        /**
         * Destroys the value for this property. The existing data is assumed valid (so for example this calls FString::Empty)
         * This does the entire fixed size array.
         *
         * @param dest the address of the value for this property that should be destroyed.
         */
        auto DestroyValue(void* Dest) -> void;

        /**
         * Destroys the value for this property. The existing data is assumed valid (so for example this calls FString::Empty)
         * This does the entire fixed size array.
         *
         * @param dest the address of the container containing the value that should be destroyed.
         */
        auto DestroyValue_InContainer(void* Dest) -> void;
        auto DestroyValueInternal(void* Dest) const -> void;

        /**
         * Zeros, copies from the default, or calls the constructor for on the value for this property.
         * The existing data is assumed invalid (so for example this might indirectly call FString::FString,
         * This will do the entire fixed size array.
         *
         * @param dest the address of the value for this property that should be cleared.
         */
        auto InitializeValue(void* Dest) -> void;

        /**
         * Zeros, copies from the default, or calls the constructor for on the value for this property.
         * The existing data is assumed invalid (so for example this might indirectly call FString::FString,
         * This will do the entire fixed size array.
         *
         * @param dest the address of the container of value for this property that should be cleared.
         */
        auto InitializeValue_InContainer(void* Dest) -> void;
        auto InitializeValueInternal(void* Dest) const -> void;

        auto GetID() const -> FName;

        auto InstanceSubobjects(void* Data, void const* DefaultData, UObject* Owner, struct FObjectInstancingGraph* InstanceGraph) -> void;

        auto GetMinAlignment() const -> int32;

        auto ContainsObjectReference(TArray<const class FStructProperty*>& EncounteredStructProps, EPropertyObjectReferenceType InReferenceType) const -> bool;
        auto ContainsObjectReference(TArray<const class FStructProperty*>& EncounteredStructProps) const -> bool;

        auto EmitReferenceInfo(UClass& OwnerClass, int32 BaseOffset, TArray<const FStructProperty*>& EncounteredStructProps) -> void;

        auto SameType(const FProperty* Other) const -> bool;

        /**
         * Copies specified number of property values into the kismet VM
         * Internal function, do not call directly!
         */
        auto CopyValuesToScriptVMInternal(void* Dest, const void* Src, int32_t Count) -> void;

        /**
         * Copies specified number of property values from the kismet VM
         * Internal function, do not call directly!
         */
        auto CopyValuesFromScriptVMInternal(void* Dest, const void* Src, int32_t Count) -> void;
    protected:
        auto CopyValuesFromScriptVMInternal_Impl(void* Dest, const void* Src, int32_t Count) -> void;
        auto CopyValuesToScriptVMInternal_Impl(void* Dest, const void* Src, int32_t Count) -> void;
        

        //auto copy_values_internal_impl(void* dest, void const* src, int32_t count);
    };

    // This is commented out because the implementation is not complete, and I want the project compile
    /*
    class RC_UE_API FPropertyHelpers
    {
    public:
        static const wchar_t* ReadToken(const TCHAR* Buffer, FString& Out, bool DottedNames = false);
    };
    //*/
}


#endif //RC_UNREAL_XPROPERTY_HPP
