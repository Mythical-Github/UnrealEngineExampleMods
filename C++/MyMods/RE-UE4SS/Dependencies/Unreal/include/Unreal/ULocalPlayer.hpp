#ifndef RC_UNREAL_ULOCALPLAYER_HPP
#define RC_UNREAL_ULOCALPLAYER_HPP

#include <Unreal/UPlayer.hpp>
#include <Unreal/TObjectPtr.hpp>
#include <Unreal/UGameViewportClient.hpp>
#include <Unreal/UnrealCoreStructs.hpp>

namespace RC::Unreal
{
    // TODO: Move to its own file.
    template<typename TEnum>
    class TEnumAsByte
    {
        uint8_t Value;
    };

    class RC_UE_API ULocalPlayer : public UPlayer
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(ULocalPlayer, Engine);

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
        using ExecSignature = bool(ULocalPlayer* Context, UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar);
        static Function<ExecSignature> ExecInternal;

    public:
#include <MemberVariableLayout_HeaderWrapper_ULocalPlayer.hpp>
    };
}


#endif //RC_UNREAL_ULOCALPLAYER_HPP
