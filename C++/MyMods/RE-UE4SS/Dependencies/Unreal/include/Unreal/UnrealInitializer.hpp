#ifndef RC_UNREAL_UNREAL_INITIALIZER_HPP
#define RC_UNREAL_UNREAL_INITIALIZER_HPP

#include <cstdint>
#include <functional>
#include <filesystem>

#include <File/File.hpp>
#include <SigScanner/SinglePassSigScanner.hpp>

#include <Unreal/Common.hpp>
#include <Unreal/UObjectGlobals.hpp>

namespace RC
{
    class SignatureContainer;

    namespace Unreal::Signatures
    {
        struct ScanResult;
    }
}

namespace RC::Unreal::UnrealInitializer
{
    struct ScanOverrides
    {
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> guobjectarray;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> static_find_object;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> version_finder;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> fname_to_string;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> fname_constructor;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> fmemory_free;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> process_event;
        std::function<void(std::vector<SignatureContainer>&, Signatures::ScanResult&)> static_construct_object;
    };

    // Struct to be passed to the 'initialize' function
    // Should always have valid default values
    struct Config
    {
    public:
        uint32_t NumScanThreads{8};
        uint32_t MultithreadingModuleSizeThreshold{0x1000000};

        // Functions to be called if you want to override one or more scans
        ScanOverrides ScanOverrides{};

        int64_t SecondsToScanBeforeGivingUp{30};

        // Cache settings
        // Path to cache files, used to bypass aob scanning when the module hasn't changed from the last time it was scanned
        // If empty, this default will be used: <GameExeDirectory>/cache
        std::filesystem::path CachePath{};
        bool bEnableCache{false};
        bool bInvalidateCacheIfSelfChanged{true};
        SinglePassScanner::ScanMethod ScanMethod{SinglePassScanner::ScanMethod::StdFind};

        // If false, will not use UObject create/delete listeners in GUObjectArray.
        bool bUseUObjectArrayCache{true};

        // Which functions to hook.
        bool bHookProcessInternal{false};
        bool bHookProcessLocalScriptFunction{false};
        bool bHookInitGameState{false};
        bool bHookCallFunctionByNameWithArguments{false};
        bool bHookBeginPlay{false};
        bool bHookLocalPlayerExec{false};
        bool bHookAActorTick{false};

        uint8_t FExecVTableOffsetInLocalPlayer{0x28};
    };

    struct CacheInfo
    {
        File::Handle GameExeFile;
        bool bShouldUseCache;
        bool bShouldSerializeCache;
    };

    struct StaticStorage
    {
        static std::filesystem::path GameExe;
        RC_UE_API static bool bIsInitialized;
        RC_UE_API static bool bVersionedContainerIsInitialized;
    };

    auto RC_UE_API SetupUnrealModules() -> void;
    auto RC_UE_API VerifyModuleCache(const Config&) -> CacheInfo;
    auto RC_UE_API CreateCache(CacheInfo&) -> void;
    auto RC_UE_API LoadCache(CacheInfo&) -> void;
    auto RC_UE_API InitializeVersionedContainer() -> void;
    auto RC_UE_API Initialize(const Config&) -> void;
}


#endif //RC_UNREAL_UNREAL_INITIALIZER_HPP
