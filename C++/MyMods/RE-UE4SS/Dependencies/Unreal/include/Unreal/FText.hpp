#ifndef RC_UNREAL_FTEXT_HPP
#define RC_UNREAL_FTEXT_HPP

#include <string>

#include <Unreal/Common.hpp>
#include <Unreal/PrimitiveTypes.hpp>

namespace RC::Unreal
{
    class FString;

    // Real type: TSharedPtr<FString, ESPMode::ThreadSafe>
    using FTextDisplayStringPtr = FString*;

    struct RC_UE_API FTextKey
    {
    private:
        const TCHAR* StrPtr;
        uint32 StrHash;
    };

    struct RC_UE_API FTextId
    {
    private:
        FTextKey Namespace;
        FTextKey Key;
    };

    class RC_UE_API FText
    {
    public:
        void* Data{nullptr};

    public:
        auto ToFString() -> FString*;
        auto ToString() -> std::wstring;
        auto SetString(FString*) -> void;
    };
}

#endif //RC_UNREAL_FTEXT_HPP
