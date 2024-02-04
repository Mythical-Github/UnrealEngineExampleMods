#include <stdexcept>
#include <format>

#include <Helpers/Casting.hpp>
#include <Helpers/Integer.hpp>
#include <SigScanner/SinglePassSigScanner.hpp>
#include <DynamicOutput/DynamicOutput.hpp>
#include <Unreal/UnrealInitializer.hpp>
#include <Unreal/VersionedContainer/Container.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtualBaseVC.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <Unreal/Signatures.hpp>
#include <Unreal/Hooks.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/FString.hpp>
#include <Unreal/FMemory.hpp>
#include <Unreal/FAssetData.hpp>
#include <Unreal/AActor.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/AGameModeBase.hpp>
#include <Unreal/ULocalPlayer.hpp>
#include <Unreal/Searcher/ObjectSearcher.hpp>
#include <Unreal/ClassListener.hpp>
#include <Zydis/Zydis.h>

#define NOMINMAX
#include <Windows.h>
#include <Psapi.h>

namespace RC::Unreal::UnrealInitializer
{
    std::filesystem::path StaticStorage::GameExe;
    bool StaticStorage::bIsInitialized{false};
    bool StaticStorage::bVersionedContainerIsInitialized{false};

    auto SetupUnrealModules() -> void
    {
        // Setup all modules for the aob scanner
        MODULEINFO ModuleInfo;
        K32GetModuleInformation(GetCurrentProcess(), GetModuleHandle(nullptr), &ModuleInfo, sizeof(MODULEINFO));
        SigScannerStaticData::m_modules_info[ScanTarget::MainExe] = ModuleInfo;

        HMODULE Modules[1024];
        DWORD BytesRequired;

        if (K32EnumProcessModules(GetCurrentProcess(), Modules, sizeof(Modules), &BytesRequired) == 0)
        {
            throw std::runtime_error{std::format("Was unable to enumerate game modules. Error Code: {}", GetLastError())};
        }

        // Default all modules to be the same as MainExe
        // This is because most UE4 games only have the MainExe module
        for (size_t i = 0; i < static_cast<size_t>(ScanTarget::Max); ++i)
        {
            SigScannerStaticData::m_modules_info.array[i] = ModuleInfo;
        }

        // Check for modules and save the module info if they exist
        for (auto i = 0; i < BytesRequired / sizeof(HMODULE); ++i)
        {
            char ModuleRawName[MAX_PATH];
            // TODO: Fix an occasional error: "Call to K32GetModuleBaseNameA failed. Error Code: 6 (ERROR_INVALID_HANDLE)"
            if (K32GetModuleBaseNameA(GetCurrentProcess(), Modules[i], ModuleRawName, sizeof(ModuleRawName) / sizeof(char)) == 0)
            {
                continue;
            }

            std::string ModuleName{ModuleRawName};

            for (size_t i2 = 0; i2 < static_cast<size_t>(ScanTarget::Max); ++i2)
            {
                std::string ModuleToFind{"-"};
                ModuleToFind.append(ScanTargetToString(i2));
                ModuleToFind.append("-Win64-Shipping.dll");

                size_t Occurrence = ModuleName.find(ModuleToFind);
                if (Occurrence != ModuleName.npos)
                {
                    if (!SigScannerStaticData::m_is_modular) { SigScannerStaticData::m_is_modular = true; }

                    K32GetModuleInformation(GetCurrentProcess(), Modules[i], &SigScannerStaticData::m_modules_info[static_cast<ScanTarget>(i2)], sizeof(MODULEINFO));
                }
            }
        }
    }

    auto VerifyModuleCache(const Config& UnrealConfig) -> CacheInfo
    {
        if (!UnrealConfig.bEnableCache) { return {.GameExeFile = {}, .bShouldUseCache = false, .bShouldSerializeCache = false}; }

        bool bUseCache{};
        bool bShouldSerializeCache{true};
        bool bShouldSerializeCacheOverride{};
        File::Handle GameExeFile;
        File::Handle SelfFile;

        wchar_t ExePathBuffer[1024];
        GetModuleFileNameW(GetModuleHandle(nullptr), ExePathBuffer, 1023);
        StaticStorage::GameExe = ExePathBuffer;

        HMODULE SelfModule;
        wchar_t SelfPathBuffer[1024];
        GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, reinterpret_cast<LPCWSTR>(&VerifyModuleCache), &SelfModule);
        GetModuleFileNameW(SelfModule, SelfPathBuffer, sizeof(SelfPathBuffer));
        std::filesystem::path SelfPath = SelfPathBuffer;

        std::filesystem::path CachePath = UnrealConfig.CachePath;
        if (CachePath.empty())
        {
            Output::send(STR("Cache path is empty, using default\n"));
            CachePath = StaticStorage::GameExe.parent_path();
            CachePath.append("cache");
        }

        // Check if the self file (the injected dll that this code is contained within) has changed
        // and whether that means that we should invalidate the cache
        try
        {
            SelfFile = File::open(SelfPath);

            std::filesystem::path SelfCachePathAndFile = CachePath;
            SelfCachePathAndFile /= SelfPath.filename();
            SelfCachePathAndFile.replace_extension(".cache");

            SelfFile.set_serialization_output_file(SelfCachePathAndFile);

            if (!SelfFile.is_deserialized_and_live_equal())
            {
                // The self file has changed, invalidate the cache
                // This could also mean that the cache file didn't exist

                bool bShouldInvalidate = !std::filesystem::exists(SelfCachePathAndFile) || UnrealConfig.bInvalidateCacheIfSelfChanged;

                if (bShouldInvalidate)
                {
                    // Invalidate all caches
                    for (const auto& Item : std::filesystem::directory_iterator(CachePath))
                    {
                        std::error_code ec;
                        if (Item.is_directory()) { continue; }
                        if (ec.value() != 0) { throw std::runtime_error{""}; }

                        if (Item.path().extension() == ".cache")
                        {
                            File::Handle GameCacheFile = File::open(Item.path());
                            GameCacheFile.delete_file();
                        }
                    }

                    // If the self cache file didn't exist, then we must create it
                    // If it does exist then this means that the self file has changed
                    // We invalidate depending on a setting in the config
                    SelfFile.serialize_identifying_properties();
                    bShouldSerializeCacheOverride = true;
                }
            }

            SelfFile.close();
        }
        catch (std::runtime_error&)
        {
            // Make sure we don't load the cache if there was an error while checking the self file
            bShouldSerializeCacheOverride = true;
            SelfFile.close();
        }

        // Check whether the game has a usable cache or whether we need to create one
        if (!CachePath.empty() && !StaticStorage::GameExe.empty())
        {
            std::filesystem::path CachePathAndFile = CachePath;
            CachePathAndFile /= StaticStorage::GameExe.filename();
            CachePathAndFile.replace_extension(".cache");

            GameExeFile = File::open(StaticStorage::GameExe);
            GameExeFile.set_serialization_output_file(CachePathAndFile);

            if (GameExeFile.is_deserialized_and_live_equal() && !bShouldSerializeCacheOverride)
            {
                bUseCache = true;
                bShouldSerializeCache = false;
            }
            else
            {
                // Invalidate the serialization file if it already exists
                // The deserialization not matching may be due to the serialization file not existing
                GameExeFile.invalidate_serialization();

                bUseCache = false;
                bShouldSerializeCache = true;
            }
        }

        return {std::move(GameExeFile), bUseCache, bShouldSerializeCache};
    }

    auto CreateCache(CacheInfo& CacheInfo) -> void
    {
        auto GetModuleOffset = [&](ScanTarget Target, void* Address) -> unsigned long {
            MODULEINFO Module = SigScannerStaticData::m_modules_info[Target];
            return Helper::Integer::to<unsigned long>(reinterpret_cast<uintptr_t>(Address) - reinterpret_cast<uintptr_t>(Module.lpBaseOfDll));
        };

        auto Serialize = [&](ScanTarget Target, void* Address) -> void {
            // Serialize user data
            // This automatically creates the serialization file if it doesn't yet exist
            // This will also automatically serialize identifying properties if they aren't already serialized
            CacheInfo.GameExeFile.serialize_item(static_cast<unsigned long>(Target));
            CacheInfo.GameExeFile.serialize_item(GetModuleOffset(Target, Address));
        };

        // IMPORTANT: The ScanTarget does NOT have to be the same as they are in 'Signatures.cpp'
        // This is because, in 'Signatures.cpp', the ScanTarget is for the module to scan in
        // But when serializing, we're serializing the module offset into the module that contains the actual final data
        // So for example, ~FString(), exists the 'Core' module but the scanner scans in the MainExe module

        Serialize(ScanTarget::CoreUObject, Container::UnrealVC->UObjectArray_get_internal_storage_ptr());

#if 0
        // This is test code that shouldn't be compiled for release
        serialize(ScanTarget::PakFile, PakFileTesting::Storage::is_non_pak_filename_allowed_address);
        serialize(ScanTarget::PakFile, PakFileTesting::Storage::find_file_in_pak_files_address);
        serialize(ScanTarget::PakFile, PakFileTesting::Storage::open_read_address);
        serialize(ScanTarget::CoreUObject, PakFileTesting::Storage::static_load_object_address);
#endif

        // Version is special, it's major/minor instead of ScanTarget/ModuleOffset
        CacheInfo.GameExeFile.serialize_item(Version::Major);
        CacheInfo.GameExeFile.serialize_item(Version::Minor);

        Serialize(ScanTarget::Core, FName::ToStringInternal.get_function_address());
        Serialize(ScanTarget::Core, FName::ConstructorInternal.get_function_address());
        Serialize(ScanTarget::CoreUObject, UObjectGlobals::GlobalState::StaticConstructObjectInternal.get_function_address());
        Serialize(ScanTarget::Core, FMalloc::UnrealStaticGMalloc);
    }

    auto LoadCache(CacheInfo& CacheInfo) -> void
    {
        auto ModuleOffsetToAddress = [](ScanTarget Target, unsigned long ModuleOffset) -> void* {
            MODULEINFO module = SigScannerStaticData::m_modules_info[Target];
            return static_cast<void*>(static_cast<unsigned char*>(module.lpBaseOfDll) + ModuleOffset);
        };

        auto Deserialize = [&]() -> void* {
            ScanTarget Target = static_cast<ScanTarget>(CacheInfo.GameExeFile.get_serialized_item<unsigned long>());
            auto ModuleOffset = CacheInfo.GameExeFile.get_serialized_item<unsigned long>();

            return ModuleOffsetToAddress(Target, ModuleOffset);
        };


        void* GUObjectArray = Deserialize();

#if 0
        // This is test code that shouldn't be compiled for release
        PakFileTesting::Storage::is_non_pak_filename_allowed_func = std::bit_cast<PakFileTesting::IsNonPakFilenameAllowedFunc>(PakFileTesting::Storage::is_non_pak_filename_allowed_address);
        PakFileTesting::Storage::is_non_pak_filename_allowed_address = deserialize();
        PakFileTesting::Storage::find_file_in_pak_files_address = deserialize();
        PakFileTesting::Storage::find_file_in_pak_files_func = std::bit_cast<PakFileTesting::FindFileInPakFilesFunc>(PakFileTesting::Storage::find_file_in_pak_files_address);
        PakFileTesting::Storage::open_read_address = deserialize();
        PakFileTesting::Storage::open_read_func = std::bit_cast<PakFileTesting::OpenReadFunc>(PakFileTesting::Storage::open_read_address);
        PakFileTesting::Storage::static_load_object_address = deserialize();
        PakFileTesting::Storage::static_load_object_func = std::bit_cast<PakFileTesting::StaticLoadObjectFunc>(PakFileTesting::Storage::static_load_object_address);
#endif

        // Version is special, it's major/minor instead of ScanTarget/ModuleOffset
       auto Major = CacheInfo.GameExeFile.get_serialized_item<unsigned int>();
       auto Minor = CacheInfo.GameExeFile.get_serialized_item<unsigned int>();
        if (Version::Major == -1)
        {
            // Only set the version if it's not already been set elsewhere
            Version::Major = Major;
            Version::Minor = Minor;
        }

        InitializeVersionedContainer();
        Container::UnrealVC->UObjectArray_set_internal_storage_ptr(GUObjectArray);

        FName::ToStringInternal.assign_address(Deserialize());
        FName::ConstructorInternal.assign_address(Deserialize());
        void* StaticConstructObjectAddress = Deserialize();
        UObjectGlobals::GlobalState::StaticConstructObjectInternal.assign_address(StaticConstructObjectAddress);
        UObjectGlobals::GlobalState::StaticConstructObjectInternalDeprecated.assign_address(StaticConstructObjectAddress);
        FMalloc::UnrealStaticGMalloc = static_cast<FMalloc**>(Deserialize());
        GMalloc = *FMalloc::UnrealStaticGMalloc;

        Output::send(STR("Deserialized FName::ToString address: {}\n"), FName::ToStringInternal.get_function_address());
        Output::send(STR("Deserialized StaticConstructObject_Internal address: {}\n"), StaticConstructObjectAddress);
        Output::send(STR("Deserialized FName::FName address: {}\n"), FName::ConstructorInternal.get_function_address());
        Output::send(STR("Deserialized GUObjectArray address: {}\n"), GUObjectArray);
        Output::send(STR("Deserialized GMalloc address: {}\n"), static_cast<void*>(GMalloc));
    }

    auto InitializeVersionedContainer() -> void
    {
        Container::SetDerivedBaseObjects();
        Container::UnrealVirtualVC->set_virtual_offsets();
        StaticStorage::bVersionedContainerIsInitialized = true;
    }

    auto static PostInitialize(const Config& UnrealConfig) -> void
    {
        if (!GMalloc && FMalloc::UnrealStaticGMalloc)
        {
            GMalloc = *FMalloc::UnrealStaticGMalloc;
            Output::send(STR("Post-initialization: GMalloc: {} -> {}\n"), (void*)FMalloc::UnrealStaticGMalloc, (void*)GMalloc);
        }

        if (!GMalloc || !FMalloc::UnrealStaticGMalloc)
        {
            throw std::runtime_error{"UnrealInitializer::PostInitialize: GMalloc or FMalloc::UnrealStaticGMalloc is uninitialized."};
        }

        // FAssetData was not reflected before 4.17
        // We'll need to manually add FAssetData for every engine version eventually
        if (Version::IsAtLeast(4, 17))
        {
            if (FAssetData::FAssetDataAssumedStaticSize < FAssetData::StaticSize())
            {
                throw std::runtime_error{"Tell a developer: FAssetData::StaticSize is too small to hold the entire struct"};
            }
        }

        if (UnrealConfig.bUseUObjectArrayCache)
        {
            // Construct searcher pools
            AllSearcherPools.emplace(HashSearcherKey<UClass, AnySuperStruct>(), std::make_unique<ObjectSearcherPool<UClass, AnySuperStruct>>());
            AllSearcherPools.emplace(HashSearcherKey<UClass, AActor>(), std::make_unique<ObjectSearcherPool<UClass, AActor>>());
            AllSearcherPools.emplace(HashSearcherKey<AActor, AnySuperStruct>(), std::make_unique<ObjectSearcherPool<AActor, AnySuperStruct>>());

            // Populate searcher pools
            UObjectGlobals::ForEachUObject([](UObject* Object, ...) {
                auto* ObjectItem = Object->GetObjectItem();

                if (Object->IsA<UClass>())
                {
                    ObjectSearcherPool<UClass, AnySuperStruct>::Pool.emplace_back(ObjectItem);

                    if (static_cast<UClass*>(Object)->IsChildOf<AActor>())
                    {
                        ObjectSearcherPool<UClass, AActor>::Pool.emplace_back(ObjectItem);
                    }
                }

                if (Object->IsA<AActor>())
                {
                    ObjectSearcherPool<AActor, AnySuperStruct>::Pool.emplace_back(ObjectItem);
                }

                return LoopAction::Continue;
            });

            Output::send(STR("Adding GUObjectArray listeners\n"));
            UObjectArray::AddUObjectCreateListener(&FClassCreateListener::ClassCreateListener);
            UObjectArray::AddUObjectDeleteListener(&FClassDeleteListener::ClassDeleteListener);
        }

        StaticStorage::bIsInitialized = true;
    }

    auto Initialize(const Config& UnrealConfig) -> void
    {
        // Setup scanner
        SinglePassScanner::m_num_threads = UnrealConfig.NumScanThreads;
        SinglePassScanner::m_multithreading_module_size_threshold = UnrealConfig.MultithreadingModuleSizeThreshold;

        // Setup all modules for the aob scanner
        // This is currently done outside the Unreal API in order to over come a problem
        // TODO: Put an option here to check if the modules are initialized and initialize if they aren't
        SetupUnrealModules();

        // Check if we have a valid cache or if a cache should be created after scanning
        CacheInfo CacheInfo = VerifyModuleCache(UnrealConfig);

        if (UnrealConfig.bEnableCache && CacheInfo.bShouldUseCache)
        {
            LoadCache(CacheInfo);
        }
        else
        {
            enum class SuppressScanAttemptMessage { Yes, No };
            enum class OutputErrorsByThrowing { Yes, No };
            enum class ErrorsOnly { Yes, No };

            auto OutputResult = [](Signatures::ScanResult& ScanResult, OutputErrorsByThrowing OutputErrorsByThrowing = OutputErrorsByThrowing::No, ErrorsOnly ErrorsOnly = ErrorsOnly::No) {
                if (ScanResult.Status == Signatures::ScanStatus::Failed)
                {
                    std::string AllErrors{"AOB scans could not be completed because of the following reasons:\n"};
                    std::string FatalErrors{};
                    std::string NonFatalErrors{};
                    for (const auto& Error : ScanResult.Errors)
                    {
                        if (Error.bIsFatal)
                        {
                            FatalErrors.append(Error.Message + "\n\n");
                        }
                        else
                        {
                            NonFatalErrors.append(Error.Message + "\n\n");
                        }
                    }

                    AllErrors.append(FatalErrors);
                    AllErrors.append(NonFatalErrors);

                    if (!FatalErrors.empty() && OutputErrorsByThrowing == OutputErrorsByThrowing::Yes)
                    {
                        throw std::runtime_error{AllErrors};
                    }
                    else
                    {
                        Output::send(to_wstring(AllErrors));
                    }
                }

                if (ErrorsOnly == ErrorsOnly::No)
                {
                    for (const auto& SuccessMessage : ScanResult.SuccessMessage)
                    {
                        Output::send(SuccessMessage);
                    }

                    for (const auto& InfoMessage : ScanResult.InfoMessages)
                    {
                        Output::send(STR("Info: {}"), InfoMessage);
                    }
                }
            };

            SinglePassScanner::m_scan_method = UnrealConfig.ScanMethod;
            auto DoScan = [&](auto ScannerFunction, SuppressScanAttemptMessage SuppressScanAttemptMessage = SuppressScanAttemptMessage::No) {
                Signatures::ScanResult ScanResult{};
                size_t scan_count{};
                auto start = std::chrono::steady_clock::now();
                while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count() < UnrealConfig.SecondsToScanBeforeGivingUp)
                {
                    if (SuppressScanAttemptMessage == SuppressScanAttemptMessage::No)
                    {
                        Output::send<LogLevel::Verbose>(STR("Scan attempt {}\n"), scan_count + 1);
                    }

                    ScanResult = ScannerFunction(UnrealConfig);
                    OutputResult(ScanResult);

                    bool bHasFatalError{};
                    for (const auto& Error : ScanResult.Errors)
                    {
                        if (Error.bIsFatal)
                        {
                            bHasFatalError = true;
                            break;
                        }
                    }
                    if (!bHasFatalError) { break; }
                    ++scan_count;
                }

                OutputResult(ScanResult, OutputErrorsByThrowing::Yes, ErrorsOnly::Yes);
            };

            DoScan(&Signatures::ScanForGameFunctionsAndData);
            InitializeVersionedContainer();
            DoScan(&Signatures::ScanForGUObjectArray, SuppressScanAttemptMessage::Yes);
        }

        if (UnrealConfig.bEnableCache)
        {
            if (CacheInfo.bShouldSerializeCache)
            {
                CreateCache(CacheInfo);
            }

            CacheInfo.GameExeFile.close();
        }

        // Objects that are required to exist before we can continue
        Hook::AddRequiredObject(STR("/Script/CoreUObject.Class"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject.Struct"));
        Hook::AddRequiredObject(STR("/Script/Engine.Pawn"));
        Hook::AddRequiredObject(STR("/Script/Engine.Character"));
        Hook::AddRequiredObject(STR("/Script/Engine.Actor"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject.Vector"));
        Hook::AddRequiredObject(STR("/Script/Engine.Default__DefaultPawn"));
        Hook::AddRequiredObject(STR("/Script/Engine.HitResult"));
        Hook::AddRequiredObject(STR("/Script/Engine.Default__MaterialExpression"));
        Hook::AddRequiredObject(STR("/Script/Engine.ActorComponent"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject.OrientedBox"));
        Hook::AddRequiredObject(STR("/Script/Engine.MovementComponent"));
        Hook::AddRequiredObject(STR("/Script/Engine.HUD"));
        Hook::AddRequiredObject(STR("/Script/Engine.PlayerController"));
        Hook::AddRequiredObject(STR("/Script/Engine.PlayerCameraManager"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject.EInterpCurveMode"));
        Hook::AddRequiredObject(STR("/Script/Engine.ENetRole"));
        Hook::AddRequiredObject(STR("/Script/MovieScene.MovieSceneEditorData"));
        Hook::AddRequiredObject(STR("/Script/UMG.Widget"));
        Hook::AddRequiredObject(STR("/Script/UMG.ComboBoxString"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject.Interface"));
        Hook::AddRequiredObject(STR("/Script/CoreUObject.DynamicClass"));

        if (!Hook::AllRequiredObjectsConstructed())
        {
            for (int32_t i = 0; i < 2000 && !Hook::StaticStorage::bAllRequiredObjectsConstructed; ++i)
            {
                // The control variable for this loop is controlled from the game thread in a
                // hook created in the function call right above this loop

                if (Hook::StaticStorage::RequiredObjectsForInit.empty()) { break; }
                for (auto& RequiredObject : Hook::StaticStorage::RequiredObjectsForInit)
                {
                    if (Hook::StaticStorage::NumRequiredObjectsConstructed >= Hook::StaticStorage::RequiredObjectsForInit.size())
                    {
                        Hook::StaticStorage::bAllRequiredObjectsConstructed = true;
                        break;
                    }

                    if (RequiredObject.ObjectConstructed) { continue; }

                    UObject* required_object_ptr = UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, RequiredObject.ObjectName.c_str());
                    if (required_object_ptr)
                    {
                        RequiredObject.ObjectConstructed = true;
                        ++Hook::StaticStorage::NumRequiredObjectsConstructed;
                        Output::send(STR("Constructed [{} / {}]: {}\n"), Hook::StaticStorage::NumRequiredObjectsConstructed, Hook::StaticStorage::RequiredObjectsForInit.size(), RequiredObject.ObjectName);
                    }
                }

                // Sleeping here will prevent this loop from getting optimized away
                // It will also prevent unnecessarily high CPU usage
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
        }

        auto* Object = UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, STR("/Script/CoreUObject.Default__Object"));
        if (!Object)
        {
            throw std::runtime_error{"Post-initialization: Was unable to find 'CoreUObject.Default__Object' to use to retrieve the address of ProcessEvent"};
        }

        auto* Struct = UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, STR("/Script/CoreUObject.Default__Struct"));
        if (!Struct)
        {
            throw std::runtime_error{"Post-initialization: Was unable to find 'CoreUObject.Default__Struct' to use to retrieve the address of SetSuperStruct"};
        }

        auto* GameMode = UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, STR("/Script/Engine.Default__GameMode"));
        if (!GameMode)
        {
            throw std::runtime_error{"Post-initialization: Was unable to find 'Engine.Default__GameMode' to use to retrieve the address of InitGameState"};
        }

        auto* Actor = UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, STR("/Script/Engine.Default__Actor"));
        if (!Actor)
        {
            throw std::runtime_error{"Post-initialization: Was unable to find 'Engine.Default__Actor' to use to retrieve the address of BeginPlay"};
        }

        if (auto func_address = OPTIONAL_GET_ADDRESS_OF_UNREAL_VIRTUAL(AGameModeBase, InitGameState, GameMode); func_address)
        {
            AGameModeBase::InitGameStateInternal.assign_address(func_address);
        }
        if (auto func_address = OPTIONAL_GET_ADDRESS_OF_UNREAL_VIRTUAL(AActor, BeginPlay, Actor); func_address)
        {
            AActor::BeginPlayInternal.assign_address(func_address);
        }
        if (auto func_address = OPTIONAL_GET_ADDRESS_OF_UNREAL_VIRTUAL(AActor, Tick, Actor); func_address)
        {
            AActor::TickInternal.assign_address(func_address);
        }
        if (auto func_address = OPTIONAL_GET_ADDRESS_OF_UNREAL_VIRTUAL(UObject, ProcessEvent, Object); func_address)
        {
            UObject::ProcessEventInternal.assign_address(func_address);
        }
        UObject::ProcessConsoleExecInternal.assign_address(GET_ADDRESS_OF_UNREAL_VIRTUAL(UObject, ProcessConsoleExec, Object));
        UStruct::LinkInternal.assign_address(GET_ADDRESS_OF_UNREAL_VIRTUAL(UStruct, Link, Struct));
        if (UnrealConfig.bHookInitGameState) { HookInitGameState(); }
        if (UnrealConfig.bHookBeginPlay) { HookBeginPlay(); }
        if (UnrealConfig.bHookAActorTick) { HookAActorTick(); }
        HookProcessEvent();
        HookProcessConsoleExec();
        HookUStructLink();
        HookStaticConstructObject();

        TypeChecker::store_all_object_names();

        Output::send(STR("Constructed {} of {} objects\n"), Hook::StaticStorage::NumRequiredObjectsConstructed, Hook::StaticStorage::RequiredObjectsForInit.size());
        if (!Hook::StaticStorage::bAllRequiredObjectsConstructed)
        {
            Output::send(STR("Fatal error! The following objects were never constructed:\n"));
            for (const auto& RequiredObject : Hook::StaticStorage::RequiredObjectsForInit)
            {
                if (RequiredObject.ObjectConstructed) { continue; }
                Output::send(STR("{}\n"), RequiredObject.ObjectName);
            }
            throw std::runtime_error{""};
        }

        if (!TypeChecker::store_all_object_types())
        {
            throw std::runtime_error{"TypeChecker: Was unable to find some or all of the required core objects"};
        }

        auto ProcessInternal = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, STR("/Script/CoreUObject.Object:ExecuteUbergraph"))->GetFuncPtr();
        ProcessInternal = std::bit_cast<decltype(ProcessInternal)>(ASM::resolve_function_address_from_potential_jmp(std::bit_cast<void*>(ProcessInternal)));
        Output::send(STR("ProcessInternal address: {} <- Built-in\n"), std::bit_cast<void*>(ProcessInternal));
        if (Version::IsAtLeast(4, 22))
        {
            int CallCount{};
            auto Data = std::bit_cast<ZyanU8*>(ProcessInternal);
            ZydisDecoder Decoder;
            ZydisDecoderInit(&Decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_ADDRESS_WIDTH_64);
            ZyanU64 RuntimeAddress = std::bit_cast<ZyanU64>(ProcessInternal);
            ZyanUSize Offset = 0;
            const ZyanUSize NumBytesToDecode = 164;
            ZydisDecodedInstruction Instruction;
            while (ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&Decoder, Data + Offset, NumBytesToDecode - Offset, &Instruction)))
            {
                if (Instruction.mnemonic == ZYDIS_MNEMONIC_CALL)
                {
                    ++CallCount;
                }
                
                if (CallCount == 3)
                {
                    auto FunctionPtr = ASM::resolve_function_address_from_potential_jmp(std::bit_cast<void*>(RuntimeAddress));
                    UObject::ProcessLocalScriptFunctionInternal.assign_address(FunctionPtr);
                    break;
                }

                Offset += Instruction.length;
                RuntimeAddress += Instruction.length;
            }
        }
        UObject::ProcessInternalInternal.assign_address(ProcessInternal);
        Output::send(STR("ProcessLocalScriptFunction address: {} <- Built-in\n"), UObject::ProcessLocalScriptFunctionInternal.get_function_address());

        if (UnrealConfig.bHookProcessInternal && UObject::ProcessInternalInternal.is_ready())
        {
            HookProcessInternal();
        }

        if (UnrealConfig.bHookProcessLocalScriptFunction && UObject::ProcessLocalScriptFunctionInternal.is_ready())
        {
            HookProcessLocalScriptFunction();
        }

        if (UnrealConfig.bHookCallFunctionByNameWithArguments) { HookCallFunctionByNameWithArguments(); }
        if (UnrealConfig.bHookLocalPlayerExec) { HookULocalPlayerExec(UnrealConfig.FExecVTableOffsetInLocalPlayer); }
        Output::send<LogLevel::Verbose>(STR("UnrealConfig.FExecVTableOffsetInLocalPlayer: {:X}\n"), UnrealConfig.FExecVTableOffsetInLocalPlayer);

        PostInitialize(UnrealConfig);
    }
}
