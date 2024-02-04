#ifndef RC_UNREAL_SIGNATURES_HPP
#define RC_UNREAL_SIGNATURES_HPP

#include <string>
#include <unordered_set>

#include <Unreal/Common.hpp>
#include <Unreal/UnrealInitializer.hpp>

namespace RC::Unreal::Signatures
{
    enum ScanStatus
    {
        Failed,
        Succeeded,
    };

    struct RC_UE_API ScanError
    {
        std::string Message;
        bool bIsFatal{true};

        ScanError(std::string_view Error) : Message(Error) {}
    };

    struct RC_UE_API ScanResult
    {
        std::vector<std::wstring> SuccessMessage{};
        std::unordered_set<std::wstring> InfoMessages{};
        std::vector<ScanError> Errors;
        ScanStatus Status{ScanStatus::Failed};
    };

    auto RC_UE_API ScanForGameFunctionsAndData(const UnrealInitializer::Config&) -> ScanResult;
    auto RC_UE_API ScanForGUObjectArray(const UnrealInitializer::Config&) -> ScanResult;

    auto RC_UE_API ScanForGameFunctionsAndDataImpl(const UnrealInitializer::Config&) -> ScanResult;
    auto RC_UE_API ScanForGUObjectArrayImpl(const UnrealInitializer::Config&) -> ScanResult;
}


#endif //RC_UNREAL_SIGNATURES_HPP
