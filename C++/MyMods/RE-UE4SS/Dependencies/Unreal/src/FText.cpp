#include <stdexcept>

#include <Unreal/FText.hpp>
#include <Unreal/FString.hpp>
#include <Unreal/UnrealVersion.hpp>

namespace RC::Unreal
{
    struct FTextDataImplBefore5
    {
        void* vtable{};
        FTextDisplayStringPtr LocalizedString{};
    };

    struct FTextDataImplAfter5
    {
        void* vtable{};

        // FTextHistory
        uint16 GlobalRevision{};
        uint16 LocalRevision{};

        // FTextHistory_Base
        FTextId TextId{};
        FString SourceString{};
        FTextDisplayStringPtr LocalizedString{};
    };

    FString* FTextToLocalizedFString(auto* PtrToImpl)
    {
        if (!PtrToImpl || !PtrToImpl->LocalizedString)
        {
            return nullptr;
        }
        else
        {
            return PtrToImpl->LocalizedString;
        }
    }

    std::wstring FTextToLocalizedString(auto* PtrToImpl)
    {
        if (!PtrToImpl || !PtrToImpl->LocalizedString)
        {
            return STR("");
        }
        else
        {
            return PtrToImpl->LocalizedString->GetCharArray();
        }
    }

    void SetLocalizedFString(auto* PtrToImpl, FString* ReplacementString)
    {
        PtrToImpl->LocalizedString = ReplacementString;
    }

    auto FText::ToString() -> std::wstring
    {
        if (Version::IsBelow(5, 0))
        {
            auto* TypedData = static_cast<FTextDataImplBefore5*>(Data);
            return FTextToLocalizedString(TypedData);
        }
        else
        {
            auto* TypedData = static_cast<FTextDataImplAfter5*>(Data);
            return FTextToLocalizedString(TypedData);
        }
    }

    auto FText::ToFString() -> FString*
    {
        if (Version::IsBelow(5, 0))
        {
            auto* TypedData = static_cast<FTextDataImplBefore5*>(Data);
            return FTextToLocalizedFString(TypedData);
        }
        else
        {
            auto* TypedData = static_cast<FTextDataImplAfter5*>(Data);
            return FTextToLocalizedFString(TypedData);
        }
    }

    auto FText::SetString(FString* NewString) -> void
    {
        if (Version::IsBelow(5, 0))
        {
            auto* TypedData = static_cast<FTextDataImplBefore5*>(Data);
            SetLocalizedFString(TypedData, NewString);
        }
        else
        {
            auto* TypedData = static_cast<FTextDataImplAfter5*>(Data);
            SetLocalizedFString(TypedData, NewString);
        }
    }
}
