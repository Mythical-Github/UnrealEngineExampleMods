#include <Unreal/NameTypes.hpp>
#include <Unreal/FString.hpp>

namespace RC::Unreal
{
    Function<void(const FName*, class FStringOut&)> FName::ToStringInternal;
    Function<FName(const wchar_t*, EFindName)> FName::ConstructorInternal;

    const std::wstring ToStringInternalWrapper(const FName* name)
    {
        if (!FName::ToStringInternal.is_ready())
        {
            throw std::runtime_error{"FName::ToString was not ready but was called anyway"};
        }

        FStringOut string{};
        FName::ToStringInternal(name, string);

        std::wstring name_string{string.GetCharArray() ? string.GetCharArray() : L"UE4SS_None"};
        return name_string;
    }

    auto FName::ToString() -> std::wstring
    {
        return ToStringInternalWrapper(this);
    }

    auto FName::ToString() const -> const std::wstring
    {
        return ToStringInternalWrapper(this);
    }

    uint32 FName::GetPlainNameString(TCHAR(&OutName)[NAME_SIZE])
    {
        const uint32 Entry = GetDisplayIndex();
        auto String = FName(Entry).ToString();
        std::memcpy(OutName, &String[0], String.size() * sizeof(File::StringType::size_type));
        return static_cast<uint32>(String.size());
    }
}
