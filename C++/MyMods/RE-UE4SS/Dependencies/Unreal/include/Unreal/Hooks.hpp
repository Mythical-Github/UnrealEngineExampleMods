#ifndef RC_UNREAL_HOOKS_HPP
#define RC_UNREAL_HOOKS_HPP

#include <vector>
#include <unordered_map>
#include <memory>

#include <Unreal/Common.hpp>
#include <Unreal/UFunctionStructs.hpp>
#include <Unreal/FFrame.hpp>

namespace PLH
{
    class x64Detour;
}

namespace RC::LuaMadeSimple
{
    class Lua;
}

namespace RC::Unreal
{
    class UClass;
    class UFunction;
    class AGameModeBase;
    class AActor;
    class ULocalPlayer;
    class UWorld;
    struct FStaticConstructObjectParameters;

    namespace Hook
    {
        enum class HookType
        {
            Pre,
            Post,
        };

        using ProcessEventCallback = std::function<void(UObject* Context, UFunction* Function, void* Parms)>;
        using StaticConstructObjectPreCallback = std::function<UObject*(const FStaticConstructObjectParameters& Params)>;
        using StaticConstructObjectPostCallback = std::function<UObject*(const FStaticConstructObjectParameters& Params, UObject* ConstructedObject)>;
        using ProcessConsoleExecGlobalCallback = std::function<std::pair<bool, bool>(UObject* Context, const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor)>;
        using ProcessConsoleExecCallback = std::function<bool(UObject* Context, const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor)>;
        using ProcessInternalCallback = std::function<void(UObject* Context, FFrame& Stack, void* RESULT_DECL)>;
        using ProcessLocalScriptFunctionCallback = std::function<void(UObject* Context, FFrame& Stack, void* RESULT_DECL)>;
        using InitGameStateCallback = std::function<void(AGameModeBase* Context)>;
        using BeginPlayCallback = std::function<void(AActor* Context)>;
        using AActorTickCallback = std::function<void(AActor* Context, float DeltaSeconds)>;
        using CallFunctionByNameWithArgumentsCallback = std::function<std::pair<bool, bool>(UObject* Context, const TCHAR* Str, FOutputDevice& Ar, UObject* Executor, bool bForceCallWithNonExec)>;
        struct ULocalPlayerExecCallbackReturnValue { bool UseOriginalReturnValue{true}; bool NewReturnValue{}; bool ExecuteOriginalFunction{true}; };
        using ULocalPlayerExecCallback = std::function<ULocalPlayerExecCallbackReturnValue(ULocalPlayer* Context, UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)>;

        struct RC_UE_API StaticStorage
        {
            struct RequiredObject
            {
                std::wstring ObjectName{};
                bool ObjectConstructed{false};
            };

            static std::vector<RequiredObject> RequiredObjectsForInit;
            static int32_t NumRequiredObjectsConstructed;
            static bool bAllRequiredObjectsConstructed;
            static uint8_t FExecVTableOffsetInLocalPlayer;

            static std::unique_ptr<::PLH::x64Detour> StaticConstructObjectDetour;
            static std::unique_ptr<::PLH::x64Detour> ProcessEventDetour;
            static std::unique_ptr<::PLH::x64Detour> ProcessConsoleExecDetour;
            static std::unique_ptr<::PLH::x64Detour> UStructLinkDetour;
            static std::unique_ptr<::PLH::x64Detour> ProcessInternalDetour;
            static std::unique_ptr<::PLH::x64Detour> ProcessLocalScriptFunctionDetour;
            static std::unique_ptr<::PLH::x64Detour> InitGameStateDetour;
            static std::unique_ptr<::PLH::x64Detour> BeginPlayDetour;
            static std::unique_ptr<::PLH::x64Detour> AActorTickDetour;
            static std::unique_ptr<::PLH::x64Detour> CallFunctionByNameWithArgumentsDetour;
            static std::unique_ptr<::PLH::x64Detour> ULocalPlayerExecDetour;

            static std::vector<StaticConstructObjectPreCallback> StaticConstructObjectPreCallbacks;
            static std::vector<StaticConstructObjectPostCallback> StaticConstructObjectPostCallbacks;
            static std::vector<ProcessEventCallback> ProcessEventPreCallbacks;
            static std::vector<ProcessEventCallback> ProcessEventPostCallbacks;
            static std::vector<ProcessConsoleExecCallback> ProcessConsoleExecCallbacks;
            static std::vector<ProcessConsoleExecGlobalCallback> ProcessConsoleExecGlobalPreCallbacks;
            static std::vector<ProcessConsoleExecGlobalCallback> ProcessConsoleExecGlobalPostCallbacks;
            static std::vector<ProcessInternalCallback> ProcessInternalPreCallbacks;
            static std::vector<ProcessInternalCallback> ProcessInternalPostCallbacks;
            static std::vector<ProcessLocalScriptFunctionCallback> ProcessLocalScriptFunctionPreCallbacks;
            static std::vector<ProcessLocalScriptFunctionCallback> ProcessLocalScriptFunctionPostCallbacks;
            static std::vector<InitGameStateCallback> InitGameStatePreCallbacks;
            static std::vector<InitGameStateCallback> InitGameStatePostCallbacks;
            static std::vector<BeginPlayCallback> BeginPlayPreCallbacks;
            static std::vector<BeginPlayCallback> BeginPlayPostCallbacks;
            static std::vector<AActorTickCallback> AActorTickPreCallbacks;
            static std::vector<AActorTickCallback> AActorTickPostCallbacks;
            static std::vector<CallFunctionByNameWithArgumentsCallback> CallFunctionByNameWithArgumentsPreCallbacks;
            static std::vector<CallFunctionByNameWithArgumentsCallback> CallFunctionByNameWithArgumentsPostCallbacks;
            static std::vector<ULocalPlayerExecCallback> ULocalPlayerExecPreCallbacks;
            static std::vector<ULocalPlayerExecCallback> ULocalPlayerExecPostCallbacks;
        };

        auto RC_UE_API AddRequiredObject(const std::wstring& ObjectFullTypelessName) -> void;
        auto RC_UE_API AllRequiredObjectsConstructed() -> bool;

        // Registers a callback to be called whenever 'StaticConstructObject' is called
        // Callbacks may alter the return value of 'StaticConstructObject', and the last one to alter it is the one that takes effect
        // Alterations to parameters in the 'pre' callback are applied prior to object construction
        // Alterations to parameters in the 'post' callback have no effect
        auto RC_UE_API RegisterStaticConstructObjectPreCallback(StaticConstructObjectPreCallback) -> void;
        auto RC_UE_API RegisterStaticConstructObjectPostCallback(StaticConstructObjectPostCallback) -> void;

        // Registers a callback to be called whenever 'ProcessEvent' is called
        // Callbacks may not alter the return value 'ProcessEvent', because there is no return value
        // Alterations to parameters in the 'pre' callback are applied prior to object construction
        // Alterations to parameters in the 'post' callback have no effect
        auto RC_UE_API RegisterProcessEventPreCallback(ProcessEventCallback) -> void;
        auto RC_UE_API RegisterProcessEventPostCallback(ProcessEventCallback) -> void;

        // Registers a callback to be called whenever 'UGameViewportClient::ProcessConsoleExec' is executed
        auto RC_UE_API RegisterProcessConsoleExecCallback(ProcessConsoleExecCallback) -> void;
        auto RC_UE_API RegisterProcessConsoleExecGlobalPreCallback(ProcessConsoleExecGlobalCallback) -> void;
        auto RC_UE_API RegisterProcessConsoleExecGlobalPostCallback(ProcessConsoleExecGlobalCallback) -> void;

        // Registers a callback to be called whenever 'ProcessInternal' is called
        auto RC_UE_API RegisterProcessInternalPreCallback(ProcessInternalCallback) -> void;
        auto RC_UE_API RegisterProcessInternalPostCallback(ProcessInternalCallback) -> void;

        // Registers a callback to be called whenever 'ProcessLocalScriptFunction' is called
        auto RC_UE_API RegisterProcessLocalScriptFunctionPreCallback(ProcessLocalScriptFunctionCallback) -> void;
        auto RC_UE_API RegisterProcessLocalScriptFunctionPostCallback(ProcessLocalScriptFunctionCallback) -> void;

        // Registers a callback to be called whenever 'InitGameState' is called
        auto RC_UE_API RegisterInitGameStatePreCallback(InitGameStateCallback) -> void;
        auto RC_UE_API RegisterInitGameStatePostCallback(InitGameStateCallback) -> void;

        // Registers a callback to be called whenever 'InitGameState' is called
        auto RC_UE_API RegisterBeginPlayPreCallback(BeginPlayCallback) -> void;
        auto RC_UE_API RegisterBeginPlayPostCallback(BeginPlayCallback) -> void;

        // Registers a callback to be called whenever 'AActor::Tick' is called
        // WARNING! Be careful when hooking any 'Tick' functions because they are extremely performance sensitive.
        auto RC_UE_API RegisterAActorTickPreCallback(AActorTickCallback) -> void;
        auto RC_UE_API RegisterAActorTickPostCallback(AActorTickCallback) -> void;

        // Registers a callback to be called whenever 'CallFunctionByNameWithArguments' is called
        auto RC_UE_API RegisterCallFunctionByNameWithArgumentsPreCallback(CallFunctionByNameWithArgumentsCallback) -> void;
        auto RC_UE_API RegisterCallFunctionByNameWithArgumentsPostCallback(CallFunctionByNameWithArgumentsCallback) -> void;

        // Registers a callback to be called whenever 'CallFunctionByNameWithArguments' is called
        auto RC_UE_API RegisterULocalPlayerExecPreCallback(ULocalPlayerExecCallback) -> void;
        auto RC_UE_API RegisterULocalPlayerExecPostCallback(ULocalPlayerExecCallback) -> void;
    }

    auto RC_UE_API HookStaticConstructObject() -> void;
    auto RC_UE_API HookProcessEvent() -> void;
    auto RC_UE_API HookProcessConsoleExec() -> void;
    auto RC_UE_API HookUStructLink() -> void;
    auto RC_UE_API HookProcessInternal() -> void;
    auto RC_UE_API HookProcessLocalScriptFunction() -> void;
    auto RC_UE_API HookInitGameState() -> void;
    auto RC_UE_API HookBeginPlay() -> void;
    auto RC_UE_API HookAActorTick() -> void;
    auto RC_UE_API HookCallFunctionByNameWithArguments() -> void;
    auto RC_UE_API HookULocalPlayerExec(uint8_t FExecVTableOffsetInLocalPlayer) -> void;


}

#endif //RC_UNREAL_HOOKS_HPP
