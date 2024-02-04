#ifndef RC_UNREAL_AGAMEMODEBASE_HPP
#define RC_UNREAL_AGAMEMODEBASE_HPP

#include <Unreal/AActor.hpp>
#include <Unreal/TObjectPtr.hpp>
#include <Unreal/FString.hpp>
#include <Unreal/FText.hpp>

namespace RC::Unreal
{
    class AGameSession;
    class AHUD;
    class APlayerState;
    class AServerStatReplicator;
    class ASpectatorPawn;

    class RC_UE_API AGameModeBase : public AActor
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(AGameModeBase, Engine);

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
        using InitGameStateSignature = void(AGameModeBase* Context);
        static Function<InitGameStateSignature> InitGameStateInternal;

    public:
#include <MemberVariableLayout_HeaderWrapper_AGameModeBase.hpp>
    };
}


#endif //RC_UNREAL_AGAMEMODEBASE_HPP
