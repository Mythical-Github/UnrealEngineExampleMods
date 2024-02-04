#include <Unreal/FProperty.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/FMemory.hpp>
#include <Unreal/FString.hpp>
#include <Unreal/VersionedContainer/Container.hpp>
//#include <Unreal/UnrealStringConversions.h>
//#include <Unreal/UnrealParsing.h>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    IMPLEMENT_FIELD_CLASS(FProperty);
    IMPLEMENT_VIRTUAL_FUNCTION(FProperty, CopyValuesToScriptVMInternal);
    IMPLEMENT_VIRTUAL_FUNCTION(FProperty, CopyValuesFromScriptVMInternal);

    std::unordered_map<File::StringType, uint32_t> FProperty::VTableLayoutMap;

#include <MemberVariableLayout_SrcWrapper_FProperty.hpp>

    auto FProperty::GetOffset_ForInternal() -> int32_t
    {
        return GetOffset_Internal();
    }

    auto FProperty::IsInContainer(UStruct* ContainerClass) -> bool
    {
        return GetOffset_Internal() + GetSize() <= (ContainerClass ? ContainerClass->GetPropertiesSize() : INT32_MAX);
    }

    auto FProperty::GetCPPMacroType(FString& ExtendedTypeText) const -> FString
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, GetCPPMacroType, FString, PARAMS(FString&), ARGS(ExtendedTypeText))
    }

    auto FProperty::PassCPPArgsByRef() const -> bool
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FProperty, PassCPPArgsByRef, bool)
    }

    auto FProperty::GetCPPType(FString* ExtendedTypeText, uint32 CPPExportFlags) const -> FString
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, GetCPPType, FString, PARAMS(FString*, uint32), ARGS(ExtendedTypeText, CPPExportFlags))
    }

    auto FProperty::GetCPPTypeForwardDeclaration() const -> FString
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FProperty, GetCPPTypeForwardDeclaration, FString)
    }

    auto FProperty::LinkInternal(FArchive& Ar) -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, LinkInternal, void, PARAMS(FArchive&), ARGS(Ar))
    }

    auto FProperty::ConvertFromType(const FPropertyTag& Tag, FStructuredArchive::FSlot Slot, uint8* Data, UStruct* DefaultsStruct) -> EConvertFromTypeResult
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         ConvertFromType,
                                         EConvertFromTypeResult,
                                         PARAMS(const FPropertyTag&, FStructuredArchive::FSlot, uint8*, UStruct*),
                                         ARGS(Tag, Slot, Data, DefaultsStruct))
    }

    auto FProperty::Identical(const void* A, const void* B, uint32_t PortFlags) -> bool
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, Identical, bool, PARAMS(const void*, const void*, uint32_t), ARGS(A, B, PortFlags))
    }

    auto FProperty::Identical_InContainer(const void* A, const void* B, int32_t ArrayIndex, uint32_t PortFlags) -> bool
    {
        return Identical(ContainerPtrToValuePtr<void>(A, ArrayIndex), B ? ContainerPtrToValuePtr<void>(B, ArrayIndex) : nullptr, PortFlags);
    }

    auto FProperty::SerializeItem(FStructuredArchive::FSlot Slot, void* Value, void const* Defaults) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         SerializeItem,
                                         void,
                                         PARAMS(FStructuredArchive::FSlot, void*, void const*),
                                         ARGS(Slot, Value, Defaults))
    }

    auto FProperty::NetSerializeItem(FArchive& Ar, UPackageMap* Map, void* Data, TArray<uint8>* MetaData) const -> bool
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         NetSerializeItem,
                                         bool,
                                         PARAMS(FArchive&, UPackageMap*, void*, TArray<uint8>*),
                                         ARGS(Ar, Map, Data, MetaData))
    }

    auto FProperty::SupportsNetSharedSerialization() const -> bool
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FProperty, SupportsNetSharedSerialization, bool)
    }
    auto FProperty::ExportTextItem(FString& value_str, const void* property_value, const void* default_value, UObject* parent, int32_t port_flags, UObject* export_root_scope) -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         ExportTextItem,
                                         void,
                                         PARAMS(FString&, const void*, const void*, UObject*, int32_t, UObject*),
                                         ARGS(value_str, property_value, default_value, parent, port_flags, export_root_scope))
    }

    auto FProperty::ImportText(const TCHAR* Buffer, void* Data, int32_t PortFlags, UObject* OwnerObject, FOutputDevice* ErrorText) -> const TCHAR* {
        //Do not allow property import on Config properties when it's restricted
        if ((PortFlags & EPropertyPortFlags::PPF_RestrictImportTypes) && (GetPropertyFlags() & CPF_Config))
        {
            return nullptr;
        }
        if (Buffer == nullptr)
        {
            return nullptr;
        }

        //Imports should always process deprecated properties
        PortFlags |= EPropertyPortFlags::PPF_UseDeprecatedProperties;

        return ImportText_Internal(Buffer, Data, PortFlags, OwnerObject, ErrorText);
    }

    auto FProperty::ImportText_Internal(const TCHAR* Buffer, void* Data, int32 PortFlags, UObject* OwnerObject, FOutputDevice* ErrorText) -> const TCHAR*
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         ImportText_Internal,
                                         const TCHAR*,
                                         PARAMS(const TCHAR*, void*, int32, UObject*, FOutputDevice*),
                                         ARGS(Buffer, Data, PortFlags, OwnerObject, ErrorText))
    }

    auto FProperty::ExportText_Direct(FString& ValueStr, const void* Data, const void* Delta, UObject* Parent, int32_t PortFlags, UObject* ExportRootScope) -> bool
    {
        if (Data == Delta || !Identical(Data, Delta, PortFlags))
        {
            ExportTextItem(ValueStr, Data, Delta, Parent, PortFlags, ExportRootScope);
            return true;
        }
        return false;
    }

    auto FProperty::ExportText_InContainer(int32_t Index, FString& ValueStr, const void* Data, const void* Delta, UObject* Parent, int32_t PortFlags, UObject* ExportRootScope) -> bool
    {
        return ExportText_Direct(ValueStr, ContainerPtrToValuePtr<void>(Data, Index),
                                 ContainerPtrToValuePtr<void>(Delta, Index),
                                 Parent, PortFlags, ExportRootScope);
    }

    auto FProperty::CopySingleValue(void* Dest, void const* Src) -> void
    {
        CopyValuesInternal(Dest, Src, 1);
    }

    auto FProperty::GetValueTypeHash(const void* Src) -> uint32_t
    {
        if ((GetPropertyFlags() & CPF_HasGetValueTypeHash) == 0)
        {
            throw std::runtime_error("This property does not have the GetValueTypeHash implementation");
        }
        return GetValueTypeHashInternal(Src);
    }

    auto FProperty::CopyValuesInternal(void* Dest, const void* Src, int32_t Count) -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, CopyValuesInternal, void, PARAMS(void*, const void*, int32_t), ARGS(Dest, Src, Count))
    }

    auto FProperty::GetValueTypeHashInternal(const void* Src) const -> uint32
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, GetValueTypeHashInternal, uint32, PARAMS(const void*), ARGS(Src))
    }

    auto FProperty::CopyCompleteValue(void* Dest, const void* Src) -> void
    {
        CopyValuesInternal(Dest, Src, GetArrayDim());
    }

    auto FProperty::CopyCompleteValue_InContainer(void* Dest, const void* Src) -> void
    {
        return CopyCompleteValue(ContainerPtrToValuePtr<void>(Dest), ContainerPtrToValuePtr<void>(Src));
    }

    auto FProperty::CopySingleValueToScriptVM(void* Dest, void const* Src) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, CopySingleValueToScriptVM, void, PARAMS(void*, void const*), ARGS(Dest, Src))
    }

    auto FProperty::CopyCompleteValueToScriptVM(void* Dest, void const* Src) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, CopyCompleteValueToScriptVM, void, PARAMS(void*, void const*), ARGS(Dest, Src))
    }

    auto FProperty::CopySingleValueFromScriptVM(void* Dest, void const* Src) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, CopySingleValueFromScriptVM, void, PARAMS(void*, void const*), ARGS(Dest, Src))
    }

    auto FProperty::CopyCompleteValueFromScriptVM(void* Dest, void const* Src) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, CopyCompleteValueFromScriptVM, void, PARAMS(void*, void const*), ARGS(Dest, Src))
    }

    auto FProperty::ClearValue(void* Data) -> void
    {
        if (HasAllPropertyFlags(CPF_NoDestructor | CPF_ZeroConstructor))
        {
            FMemory::Memzero(Data, GetElementSize());
        }
        else
        {
            ClearValueInternal(Data);
        }
    }

    auto FProperty::ClearValue_InContainer(void* Data, int32_t ArrayIndex) -> void
    {
        ClearValue(ContainerPtrToValuePtr<void>(Data, ArrayIndex));
    }

    auto FProperty::ClearValueInternal(void* Data) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, ClearValueInternal, void, PARAMS(void*), ARGS(Data))
    }

    auto FProperty::DestroyValue(void* Dest) -> void
    {
        if (!(GetPropertyFlags() & CPF_NoDestructor))
        {
            DestroyValueInternal(Dest);
        }
    }

    auto FProperty::DestroyValue_InContainer(void* Dest) -> void
    {
        DestroyValue(ContainerPtrToValuePtr<void>(Dest));
    }

    auto FProperty::DestroyValueInternal(void* Dest) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, DestroyValueInternal, void, PARAMS(void*), ARGS(Dest))
    }

    auto FProperty::InitializeValue(void* Dest) -> void
    {
        if (GetPropertyFlags() & CPF_ZeroConstructor)
        {
            FMemory::Memzero(Dest, GetElementSize() * GetArrayDim());
        }
        else
        {
            InitializeValueInternal(Dest);
        }
    }

    auto FProperty::InitializeValue_InContainer(void* Dest) -> void
    {
        InitializeValue(ContainerPtrToValuePtr<void>(Dest));
    }

    auto FProperty::InitializeValueInternal(void* Dest) const -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, InitializeValueInternal, void, PARAMS(void*), ARGS(Dest))
    }

    auto FProperty::GetID() const -> FName
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FProperty, GetID, FName)
    }

    auto FProperty::InstanceSubobjects(void* Data, void const* DefaultData, UObject* Owner, FObjectInstancingGraph* InstanceGraph) -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         InstanceSubobjects,
                                         void,
                                         PARAMS(void*, void const*, UObject*, FObjectInstancingGraph*),
                                         ARGS(Data, DefaultData, Owner, InstanceGraph))
    }

    auto FProperty::GetMinAlignment() const -> int32
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FProperty, GetMinAlignment, int32)
    }

    auto FProperty::ContainsObjectReference(TArray<const FStructProperty*>& EncounteredStructProps, EPropertyObjectReferenceType InReferenceType) const -> bool
    {
        if (Version::IsAtLeast(4, 26))
        {
            // In 4.26, the second param was added
            // This branch uses the 4.26 function signature that includes this param
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                             ContainsObjectReference,
                                             bool,
                                             PARAMS(TArray<const class FStructProperty*> & , EPropertyObjectReferenceType),
                                             ARGS(EncounteredStructProps, InReferenceType))
        }
        else
        {
            // Before 4.26, the second param didn't exist
            // This branch uses the <4.26 function signature that only has one param
            // All params that don't exist get ignored
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, ContainsObjectReference, bool, PARAMS(TArray<const FStructProperty*>&), ARGS(EncounteredStructProps))
        }
    }

    auto FProperty::ContainsObjectReference(TArray<const FStructProperty*>& EncounteredStructProps) const -> bool
    {
        if (Version::IsAtLeast(4, 26))
        {
            // In 4.26, the second param was added
            // This branch uses the 4.26 function signature that includes this param
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                             ContainsObjectReference,
                                             bool, PARAMS(TArray<const FStructProperty*>&, EPropertyObjectReferenceType),
                                             ARGS(EncounteredStructProps, EPropertyObjectReferenceType::Strong))
        }
        else
        {
            // Before 4.26, the second param didn't exist
            // This branch uses the <4.26 function signature that only has one param
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, ContainsObjectReference, bool, PARAMS(TArray<const FStructProperty*>&), ARGS(EncounteredStructProps))
        }
    }

    auto FProperty::EmitReferenceInfo(UClass& OwnerClass, int32 BaseOffset, TArray<const FStructProperty*>& EncounteredStructProps) -> void
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty,
                                         EmitReferenceInfo,
                                         void,
                                         PARAMS(UClass&, int32, TArray<const FStructProperty*>&),
                                         ARGS(OwnerClass, BaseOffset, EncounteredStructProps))
    }

    auto FProperty::SameType(const FProperty* Other) const -> bool
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FProperty, SameType, bool, PARAMS(const FProperty*), ARGS(Other))
    }

    auto FProperty::CopyValuesToScriptVMInternal(void* Dest, const void* Src, int32_t Count) -> void
    {
        return CALL_VIRTUAL_FUNCTION(this, CopyValuesToScriptVMInternal, Dest, Src, Count);
    }

    auto FProperty::CopyValuesFromScriptVMInternal(void* Dest, const void* Src, int32_t Count) -> void
    {
        return CALL_VIRTUAL_FUNCTION(this, CopyValuesFromScriptVMInternal, Dest, Src, Count);
    }

    auto FProperty::CopyValuesFromScriptVMInternal_Impl(void* Dest, const void* Src, int32_t Count) -> void
    {
        CopyValuesInternal(Dest, Src, Count);
    }

    auto FProperty::CopyValuesToScriptVMInternal_Impl(void* Dest, const void* Src, int32_t Count) -> void
    {
        CopyValuesInternal(Dest, Src, Count);
    }

    /*-----------------------------------------------------------------------------
	Helpers.
-----------------------------------------------------------------------------*/

    /*
    static std::wstring AlphaNumericChars = STR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    FORCEINLINE bool IsValidTokenStart(wchar_t FirstChar, bool DottedNames)
    {
        return AlphaNumericChars.find(FirstChar) != std::wstring::npos || (DottedNames && FirstChar == '/') || FirstChar > 255;
    }

    FORCEINLINE std::wstring ParsePropertyToken(const wchar_t* Str, bool DottedNames)
    {
        std::wstring ResultString;
        while (*Str)
        {
            const wchar_t Character = *Str++;
            if (AlphaNumericChars.find(Character) != std::wstring::npos ||
                    (Character == '_' || Character == '-' || Character == '+') ||
                    DottedNames && (Character == '.' || Character == '/' || Character == SUBOBJECT_DELIMITER_CHAR)) {
                ResultString.push_back(Character);
                continue;
            }
            break;
        }
        return ResultString;
    }

    const TCHAR* FPropertyHelpers::ReadToken(const TCHAR* Buffer, FString& String, bool DottedNames)
    {
        if(*Buffer == wchar_t('"'))
        {
            int32_t NumCharsRead = 0;
            if (!FParse::quoted_string(Buffer, String, &NumCharsRead))
            {
                return nullptr;
            }
            Buffer += NumCharsRead;
        }
        else if (IsValidTokenStart(*Buffer, DottedNames))
        {
            std::wstring Token = ParsePropertyToken(Buffer, DottedNames);
            String += Token;
            Buffer += Token.size();
        }
        else
        {
            // Get just one.
            String += *Buffer;
        }
        return Buffer;
    }
    //*/
}
