#include <filesystem>

#include <Unreal/Signatures.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <Unreal/UObjectArray.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/FString.hpp>
#include <Unreal/FMemory.hpp>
#include <SigScanner/SinglePassSigScanner.hpp>
#include <File/File.hpp>
#include <Helpers/ASM.hpp>
#include <Helpers/Casting.hpp>
#include <ASMHelper/ASMHelper.hpp>

namespace RC::Unreal::Signatures
{
    auto ScanForGameFunctionsAndData(const UnrealInitializer::Config& config) -> ScanResult
    {
        // TODO: Add some code here to deal with nothing being found due to code being injected too early
        return ScanForGameFunctionsAndDataImpl(config);
    }
    auto ScanForGUObjectArray(const UnrealInitializer::Config& config) -> ScanResult
    {
        // TODO: Add some code here to deal with nothing being found due to code being injected too early
        return ScanForGUObjectArrayImpl(config);
    }

    auto ScanForGameFunctionsAndDataImpl(const UnrealInitializer::Config& config) -> ScanResult
    {
        ScanResult scan_result;

        SinglePassScanner::SignatureContainerMap signature_container_map;
        std::vector<SignatureContainer> signature_containers_coreuobject;
        std::vector<SignatureContainer> signature_containers_core;
        std::vector<SignatureContainer> signature_containers_engine;
        std::vector<SignatureContainer> signature_containers_umg;
        std::vector<SignatureContainer> signature_containers_mainexe;

        uint8_t* FNameToStringAddress{};
        uint8_t FNameToStringNumMatches{};

        
        VersionStatus version_status{};

        if (config.ScanOverrides.version_finder)
        {
            config.ScanOverrides.version_finder(signature_containers_core, scan_result);
        }
        else
        {
            SignatureContainer unreal_version_finder{
                    {
                            {
                                    // 4.x.x
                                    "0 4/0 0/? ?/0 0/? ?/0 0/0 0/0 0/? ?/? ?/? ?/? ?/0 0/0 0/0 0/0 0/? ?/? ?/? ?/? ?/? ?/? ?/0 0/0 0/? ?/0 0/0 0/0 0/? ?/0 0/0 0/0 0/0 4/0 0/? ?/0 0/? ?/0 0/0 0/0 0",
                            },
                            {
                                    // 5.x.x
                                    "0 5/0 0/? ?/0 0/? ?/0 0/0 0/0 0/? ?/? ?/? ?/? ?/0 0/0 0/0 0/0 0/? ?/? ?/? ?/? ?/? ?/? ?/0 0/0 0/? ?/0 0/0 0/0 0/? ?/0 0/0 0/0 0/0 5/0 0/? ?/0 0/? ?/0 0/0 0/0 0",
                            },
                    },
                    // On Match Found
                    [&]([[maybe_unused]]SignatureContainer& self) {
                        version_status = Unreal::Version::Initialize(self.get_match_address());

                        if (version_status.Status == VersionStatus::SUCCESS)
                        {
                            scan_result.SuccessMessage.emplace_back(std::format(STR("Engine Version: {}.{} <- Built-in\n"), Version::Major, Version::Minor));
                        }

                        return version_status.Status == VersionStatus::SUCCESS;
                    },
                    // On Scan Completed
                    [&]([[maybe_unused]]SignatureContainer& self) {
                        if (version_status.Status != VersionStatus::SUCCESS)
                        {
                            // We're not including the error message from VersionStatus here because it's inaccurate
                            scan_result.Errors.emplace_back(std::format("Was unable to find AOB for 'Unreal Engine Version'.\n{}\nYou need to override the engine version in 'UE4SS-settings.ini.", to_string(version_status.ErrorMessage)));
                        }
                    }
            };
            signature_containers_core.emplace_back(unreal_version_finder);
        }

        if (config.ScanOverrides.fname_to_string)
        {
            // If we have an override look in the 'Core' module because that's where FName::ToString is
            config.ScanOverrides.fname_to_string(signature_containers_core, scan_result);
        }
        else
        {
            enum FNameToStringSignatureType
            {
                GroupOneIndirect,
                GroupTwoIndirect,
            };
            // If we don't have an override, look in whatever module has a reference to FName::ToString
            SignatureContainer fname_to_string{
                    {
                            {
                                    // 4.12 - 5.0 EA
                                    "E 8/? ?/? ?/? ?/? ?/4 8/8 B/4 C/2 4/? ?/8 B/F D/4 8/8 5/C 9",
                                    FNameToStringSignatureType::GroupOneIndirect,
                            },
                            {
                                // 4.11 - 5.2 - LongerWarrior (FName::ToString alternative)
                                "4 8/8 B/4 8/? ?/4 8/8 9/4 C/2 4/? ?/4 8/8 D/4 C/2 4/? ?/E 8/? ?/? ?/? ?/? ?/8 3/7 C/2 4/? ?/0 0/4 8/8 D",
                                FNameToStringSignatureType::GroupTwoIndirect,
                            },
                            {
                                    // 4.12 - 5.0 EA, Modular games (i.e. Satisfactory)
                                    "F F/1 5/? ?/? ?/? ?/? ?/8 0/3 D/? ?/? ?/? ?/? ?/? ?/7 2/3 A/4 4/3 9/7 4/2 4/4 8",
                                    FNameToStringSignatureType::GroupOneIndirect,
                            },
                    },
                    // On Match Found
                    [&](SignatureContainer& self) {
                        const auto signature_identifier = static_cast<const FNameToStringSignatureType>(self.get_signatures()[self.get_index_into_signatures()].custom_data);

                        uint8_t* address = self.get_match_address();
                        uint8_t* call_instr{};
                        if (signature_identifier == FNameToStringSignatureType::GroupOneIndirect)
                        {
                            call_instr = address;
                        }
                        else
                        {
                            call_instr = static_cast<uint8_t*>(address) + 0xE;
                        }
                        
                        FNameToStringAddress = Helper::ASM::follow_call(call_instr);
                        ++FNameToStringNumMatches;
                        self.get_did_succeed() = true;
                        return true;
                    },
                    // On Scan Completed
                    [&]([[maybe_unused]]const SignatureContainer& self) {
                    }
            };
            signature_containers_engine.emplace_back(fname_to_string);

            SignatureContainer fname_to_string_backup{
                    {
                            {
                                    // 4.25+ Backup (sometimes the first one fails)
                                    "E 8/? ?/? ?/? ?/? ?/B D/0 1/0 0/0 0/0 0/4 1/3 9/6 E/? ?/0 F/8 E",
                            },
                            {
                                    // 4.25+ Backup, Modular games (i.e. Satisfactory) (sometimes the first one fails)
                                    "F F/1 5/? ?/? ?/? ?/? ?/4 1/B E/0 1/0 0/0 0/0 0/4 5/3 9/7 5/4 8",
                            },
                    },
                    // On Match Found
                    [&](SignatureContainer& self) {
                        FNameToStringAddress = Helper::ASM::follow_call(self.get_match_address());
                        self.get_did_succeed() = true;
                        ++FNameToStringNumMatches;
                        return true;
                    },
                    // On Scan Completed
                    [&]([[maybe_unused]]const SignatureContainer& self) {
                    }
            };
            signature_containers_coreuobject.emplace_back(fname_to_string_backup);
        }

        if (config.ScanOverrides.static_construct_object)
        {
            config.ScanOverrides.static_construct_object(signature_containers_umg, scan_result);
        }
        else
        {
            enum StaticConstructObjectSignatureType
            {
                GroupOneIndirect,
                GroupTwoIndirect,
            };
            SignatureContainer static_construct_object{
                    {
                            {
                                    "C 0/E 9/0 2/3 2/8 8/? ?/? ?/? ?/? ?/8 0/E 1/0 1/3 0/8 8/? ?/? ?/? ?/? ?/4 8",
                                    StaticConstructObjectSignatureType::GroupOneIndirect,
                            },
                            {
                                    // 4.12 (FirstPerson C++)
                                    "8 9/8 E/C 8/0 3/0 0/0 0/3 B/8 E/C C/0 3/0 0/0 0/7 E/0 F/4 1/8 B/D 6/4 8/8 D/8 E/C 0/0 3/0 0/0 0",
                                    StaticConstructObjectSignatureType::GroupOneIndirect,
                            },
                            {
                                    // 4.16, 4.19
                                    "E 8/? ?/? ?/? ?/? ?/0 F/B 6/8 F/? ?/0 1/0 0/0 0/4 8/8 9/8 7/? ?/0 1/0 0/0 0",
                                    StaticConstructObjectSignatureType::GroupTwoIndirect,
                            },
                            {
                                    // 5.00
                                    "E8 ?? ?? ?? ?? 48 8B D8 48 39 75 30 74 15",
                                    StaticConstructObjectSignatureType::GroupTwoIndirect,
                            },
                    },
                    // On Match Found
                    [&](SignatureContainer& self) {
                        const auto signature_identifier = static_cast<const StaticConstructObjectSignatureType>(self.get_signatures()[self.get_index_into_signatures()].custom_data);

                        uint8_t* address = self.get_match_address();
                        uint8_t* call_instr{};
                        if (signature_identifier == StaticConstructObjectSignatureType::GroupOneIndirect)
                        {
                            call_instr = static_cast<uint8_t*>(address) - 0x13;
                        }
                        else
                        {
                            call_instr = address;
                        }

                        auto callee = ASM::resolve_function_address_from_potential_jmp(ASM::resolve_call(call_instr));
                        
                        // If no callee, try go back one more byte, the call instruction might be prefixed with 0xFF
                        if (!callee)
                        {
                            --call_instr;
                            callee = ASM::resolve_function_address_from_potential_jmp(Helper::ASM::follow_call(call_instr));
                        }

                        if (!callee) { return false; }

                        scan_result.SuccessMessage.emplace_back(std::format(STR("StaticConstructObject_Internal address: {} <- Built-in\n"), callee));
                        
                        UObjectGlobals::SetupStaticConstructObjectInternalAddress(callee);
                        self.get_did_succeed() = true;
                        return true;
                    },
                    // On Scan Completed
                    [&](const SignatureContainer& self) {
                        if (!self.get_did_succeed())
                        {
                            scan_result.Errors.emplace_back("Was unable to find address for 'StaticConstructObject_Internal'\nYou can supply your own in 'UE4SS_Signatures/StaticConstructObject'");
                        }
                    }
            };
            signature_containers_umg.emplace_back(static_construct_object);
        }

        signature_container_map.emplace(ScanTarget::CoreUObject, signature_containers_coreuobject);
        signature_container_map.emplace(ScanTarget::Core, signature_containers_core);
        signature_container_map.emplace(ScanTarget::Engine, signature_containers_engine);
        signature_container_map.emplace(ScanTarget::UMG, signature_containers_umg);
        signature_container_map.emplace(ScanTarget::MainExe, signature_containers_mainexe);

        SinglePassScanner::start_scan(signature_container_map);

        // Special error handler for FName::ToString
        // Needed because it checks in more than one module and the scanner isn't setup for that
        if (FNameToStringNumMatches > 1)
        {
            scan_result.InfoMessages.emplace(STR("Found more than one FName::ToString, using the first match\n"));
        }

        if (!config.ScanOverrides.fname_to_string)
        {
            if (FNameToStringNumMatches >= 1 && FNameToStringAddress)
            {
                FName::ToStringInternal.assign_address(FNameToStringAddress);
                scan_result.SuccessMessage.emplace_back(std::format(STR("FName::ToString address: {} <- Built-in\n"), static_cast<void*>(FNameToStringAddress)));
            }
            else
            {
                scan_result.Errors.emplace_back("Was unable to find AOB for 'FName::ToString'\nYou can supply your own in 'UE4SS_Signatures/FName_ToString.lua'");
            }
        }

        if (scan_result.Errors.empty())
        {
            scan_result.Status = ScanStatus::Succeeded;
        }
        return scan_result;
    }
    auto ScanForGUObjectArrayImpl(const UnrealInitializer::Config& config) -> ScanResult
    {
        ScanResult scan_result;

        SinglePassScanner::SignatureContainerMap signature_container_map;
        std::vector<SignatureContainer> signature_containers_coreuobject;
        std::vector<SignatureContainer> signature_containers_core;

        // FName:FName has to be in the second pass because we need access to FName::ToString which is found in the first pass
        if (config.ScanOverrides.fname_constructor)
        {
            config.ScanOverrides.fname_constructor(signature_containers_core, scan_result);
        }
        else
        {
            auto resolve_fname_jmp = [&](uint8_t* ptr, int32_t offset, ScanResult& scan_result, bool call_instead_of_jmp = false) -> bool {
                uint8_t* instr = ptr + offset;

                uint8_t* destination;
                if (call_instead_of_jmp)
                {
                    destination = Helper::ASM::follow_call(instr);
                }
                else
                {
                    destination = Helper::ASM::follow_jmp(instr);
                }

                if (!destination) { return false; }

                FName name = FName(L"bCanBeDamaged", FNAME_Find, destination);

                if (name == L"bCanBeDamaged")
                {
                    scan_result.SuccessMessage.emplace_back(std::format(STR("FName::FName address: {} <- Built-in\n"), static_cast<void*>(destination)));
                    FName::ConstructorInternal.assign_address(destination);
                    return true;
                }
                else
                {
                    return false;
                }
            };

            enum FNameConstructorSignatureType
            {
                DefaultOld,
                DefaultNew,
                Modularized_425,
                Default_501,
            };

            SignatureContainer fname_constructor{
                    {
                            //{
                            //        // Old
                            //        "4 1/B 8/0 1/0 0/0 0/0 0/4 8/8 D/1 5/? ?/? ?/? ?/? ?/4 8/8 D/0 D/? ?/? ?/? ?/? ?/E 9",
                            //        FNameConstructorSignatureType::DefaultOld,
                            //},
                            {
                                    // New (from Sunbeam)
                                    "40 53 48 83 EC ?? 41 B8 01 00 00 00 48 8D 15 ?? ?? ?? ?? 48 8D 4C 24 ?? E8 ?? ?? ?? ?? B9",
                                    FNameConstructorSignatureType::DefaultNew,
                            },
                            {
                                    // 5.1 (same location as the one from Sunbeam but the bytes changed slightly)
                                    "57 48 83 EC 50 41 B8 01 00 00 00 0F 29 74 24 40 48 8D ?? ?? ?? ?? ?? 48 8D 4C 24 60 E8",
                                    FNameConstructorSignatureType::Default_501,
                            },
                            // Removed because it's not unique enough and can be found in some non-modularized games and it leads to the wrong place in those.
                            /*
                            {
                                    // 4.25 Modularized
                                    "E 8/? ?/? ?/? ?/? ?/4 8/8 B/4 4/2 4/3 0/4 8/8 9/? ?/? ?/? ?/? ?/? ?/C 7/0 5",
                                    FNameConstructorSignatureType::Modularized_425,
                            },
                            //*/
                    },
                    // On Match Found
                    []([[maybe_unused]]const SignatureContainer& self) {
                        return false;
                    },
                    // On Scan Completed
                    [&](SignatureContainer& self) {
                        bool success{};

                        for (const auto& result_container : self.get_result_store())
                        {
                            const int32_t custom_data = self.get_signatures()[result_container.index_into_signatures].custom_data;
                            const FNameConstructorSignatureType signature_identifier = static_cast<const FNameConstructorSignatureType>(custom_data);

                            if (signature_identifier == FNameConstructorSignatureType::DefaultOld)
                            {
                                success = resolve_fname_jmp(result_container.match_address, 0x14, scan_result);
                            }
                            else if (signature_identifier == FNameConstructorSignatureType::DefaultNew)
                            {
                                success = resolve_fname_jmp(result_container.match_address, 0x18, scan_result, true);
                            }
                            else if (signature_identifier == FNameConstructorSignatureType::Modularized_425)
                            {
                                success = resolve_fname_jmp(result_container.match_address, 0x0, scan_result, true);
                            }
                            else if (signature_identifier == FNameConstructorSignatureType::Default_501)
                            {
                                if (Version::IsBelow(5, 1)) { return; }
                                success = resolve_fname_jmp(result_container.match_address, 0x1C, scan_result, true);
                            }

                            if (success) { break; }
                        }

                        if (!success)
                        {
                            scan_result.Errors.emplace_back("Was unable to find AOB for 'FName::FName'\nYou can supply your own in 'UE4SS_Signatures/FName_Constructor.lua'");
                        }
                        else
                        {
                            self.get_did_succeed() = true;
                        }
                    }, true // true = store results
            };
            signature_containers_core.emplace_back(fname_constructor);
        }

        // FMemory stuff needs to be scanned in the second pass
        // This is because we need access to the engine version which we don't until after the first pass
        if (config.ScanOverrides.fmemory_free)
        {
            config.ScanOverrides.fmemory_free(signature_containers_core, scan_result);
        }
        else
        {
            enum FMemoryFreeSignatureType
            {
                First,
                Second,
            };

            SignatureContainer fmemory_free{
                    {
                            {
                                    // 4.12, 4.22, 4.25, 4.26
                                    "4 8/8 5/C 9/7 4/2 E/5 3/4 8/8 3/E C/2 0/4 8/8 B/D 9/4 8/8 B/? ?/? ?/? ?/? ?/? ?/4 8/8 5/C 9",
                                    FMemoryFreeSignatureType::First,
                            },
                            {
                                    // 4.21
                                    "4 8/8 5/C 9/7 4/1 D/4 C/8 B/? ?/? ?/? ?/? ?/? ?/4 D/8 5/C 0/0 F/8 4",
                                    FMemoryFreeSignatureType::Second,
                            },
                    },
                    // On Match Found
                    [&](SignatureContainer& self) {
                        scan_result.SuccessMessage.emplace_back(std::format(STR("GMalloc address: {} <- Built-in\n"), static_cast<void*>(self.get_match_address())));
                        self.get_did_succeed() = true;

                        const auto signature_identifier = static_cast<const FMemoryFreeSignatureType>(self.get_signatures()[self.get_index_into_signatures()].custom_data);

                        if (signature_identifier == FMemoryFreeSignatureType::First)
                        {
                            // Find the second MOV instruction and resolve it
                            // Ideally a disassembler is used to guarantee that we are at the second MOV instruction
                            // But seeing as FMemory::Free has never really changed, we can take a shortcut and just count the bytes to the second MOV instruction
                            // 13 bytes (0xD)
                            // This MOV instruction behaves like a LEA instruction
                            uint8_t* mov_instruction = self.get_match_address() + 0xD;
                            // Instruction size, including REX and ModR
                            constexpr uint8_t instr_size = 0x7;
                            uint8_t* next_instruction = mov_instruction + instr_size;
                            uint32_t* offset = std::bit_cast<uint32_t*>(mov_instruction + 0x3);
                            FMalloc::UnrealStaticGMalloc = std::bit_cast<FMalloc**>(next_instruction + *offset);
                            GMalloc = *FMalloc::UnrealStaticGMalloc;
                        }
                        else
                        {
                            // Find the first MOV instruction and resolve it
                            // Ideally a disassembler is used to guarantee that we are at the first MOV instruction
                            // But seeing as FMemory::Free has never really changed, we can take a shortcut and just count the bytes to the second MOV instruction
                            // 5 bytes
                            // This MOV instruction behaves like a LEA instruction
                            uint8_t* mov_instruction = self.get_match_address() + 0x5;
                            // Instruction size, including REX and ModR
                            constexpr uint8_t instr_size = 0x7;
                            uint8_t* next_instruction = mov_instruction + instr_size;
                            uint32_t* offset = std::bit_cast<uint32_t*>(mov_instruction + 0x3);
                            FMalloc::UnrealStaticGMalloc = std::bit_cast<FMalloc**>(next_instruction + *offset);
                            GMalloc = *FMalloc::UnrealStaticGMalloc;
                        }

                        return true;
                    },
                    // On Scan Completed
                    [&](const SignatureContainer& self) {
                        if (!self.get_did_succeed())
                        {
                            scan_result.Errors.emplace_back("Was unable to find AOB for 'GMalloc'\nYou can supply your own in 'UE4SS_Signatures/GMalloc.lua");
                        }
                    }
            };
            signature_containers_core.emplace_back(fmemory_free);
        }

        if (config.ScanOverrides.guobjectarray)
        {
            config.ScanOverrides.guobjectarray(signature_containers_coreuobject, scan_result);
        }
        else
        {
            SignatureContainer guobjectarray = [&]() -> SignatureContainer {
                // Custom AOBs for specific games
                if (UnrealInitializer::StaticStorage::GameExe.filename() == STR("FactoryGame-Win64-Shipping.exe") && Version::IsAtLeast(4, 26))
                {
                    // Satisfactory is special, maybe it's because it's modular ?
                    return {
                            {
                                    {
                                            "4 8/8 3/C 4/3 8/C 3/4 8/8 B/D 1/4 8/8 D",
                                    },
                            },
                            [&](SignatureContainer& self) {
                                void* guobjectarray = Helper::ASM::resolve_lea<uint8_t*>(self.get_match_address() + self.get_match_signature_size() - 1);

                                if (!guobjectarray)
                                {
                                    scan_result.Errors.emplace_back("Was unable to find GUObjectArray: LEA instruction resolved to nullptr\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                    return true;
                                }

                                scan_result.SuccessMessage.emplace_back(std::format(STR("GUObjectArray address: {} <- Built-in\n"), guobjectarray));
                                UObjectArray::SetupGUObjectArrayAddress(guobjectarray);

                                self.get_did_succeed() = true;
                                return true;
                            },
                            [&](const SignatureContainer& self) {
                                if (!self.get_did_succeed())
                                {
                                    scan_result.Errors.emplace_back("Was unable to find AOB for 'GUObjectArray'\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                }
                            }
                    };
                }
                // Default AOBs that work for most games
                else if (Version::IsAtMost(4, 12))
                {
                    return {
                            {
                                    {
                                            "4 8/0 3/? ?/? ?/? ?/? ?/? ?/4 8/8 B/1 0/4 8/8 5/D 2/7 4/0 7",
                                    },
                            },
                            [&](SignatureContainer& self) {
                                uint8_t* add_instr = static_cast<uint8_t*>(self.get_match_address());
                                uint8_t* next_instr = add_instr + 0x7;
                                uint32_t offset = Helper::Casting::ptr_cast_deref<uint32_t>(add_instr, 0x3);
                                void* guobjectarray = next_instr + offset - 0x10;

                                if (!guobjectarray)
                                {
                                    scan_result.Errors.emplace_back("Was unable to find GUObjectArray: ADD instruction resolved to nullptr\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                    return true;
                                }

                                scan_result.SuccessMessage.emplace_back(std::format(STR("GUObjectArray address: {} <- Built-in\n"), guobjectarray));
                                UObjectArray::SetupGUObjectArrayAddress(guobjectarray);

                                self.get_did_succeed() = true;
                                return true;
                            },
                            [&](const SignatureContainer& self) {
                                if (!self.get_did_succeed())
                                {
                                    scan_result.Errors.emplace_back("Was unable to find AOB for 'GUObjectArray'\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                }
                            }
                    };
                }
                else if (Version::IsAtMost(4, 13))
                {
                    return {
                            {
                                    {
                                            "4 8/8 3/7 9/1 0/0 0/7 4/F 6/4 8/8 B/D 1/4 8/8 D",
                                    },
                            },
                            [&](SignatureContainer& self) {
                                void* guobjectarray = Helper::ASM::resolve_lea<void*>(self.get_match_address() + self.get_match_signature_size() - 1);

                                if (!guobjectarray)
                                {
                                    scan_result.Errors.emplace_back("Was unable to find GUObjectArray: LEA instruction resolved to nullptr\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                    return true;
                                }

                                scan_result.SuccessMessage.emplace_back(std::format(STR("GUObjectArray address: {} <- Built-in\n"), guobjectarray));
                                UObjectArray::SetupGUObjectArrayAddress(guobjectarray);

                                self.get_did_succeed() = true;
                                return true;
                            },
                            [&](const SignatureContainer& self) {
                                if (!self.get_did_succeed())
                                {
                                    scan_result.Errors.emplace_back("Was unable to find AOB for 'GUObjectArray'\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                }
                            }
                    };
                }
                else if (Version::IsAtMost(4, 19))
                {
                    return {
                            {
                                    {
                                            "4 8/8 B/? ?/? ?/? ?/? ?/? ?/4 C/8 B/0 4/C 8/4 D/8 5/C 0/7 4/0 7",
                                    },
                            },
                            [&](SignatureContainer& self) {
                                void* guobjectarray = Helper::ASM::resolve_mov<uint8_t*>(self.get_match_address()) - 0x10;

                                if (!guobjectarray)
                                {
                                    scan_result.Errors.emplace_back("Was unable to find GUObjectArray: MOV instruction resolved to nullptr\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                    return true;
                                }

                                scan_result.SuccessMessage.emplace_back(std::format(STR("GUObjectArray address: {} <- Built-in\n"), guobjectarray));
                                UObjectArray::SetupGUObjectArrayAddress(guobjectarray);

                                self.get_did_succeed() = true;
                                return true;
                            },
                            [&](const SignatureContainer& self) {
                                if (!self.get_did_succeed())
                                {
                                    scan_result.Errors.emplace_back("Was unable to find AOB for 'GUObjectArray'\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                }
                            }
                    };
                }
                else if (Version::IsAtLeast(4, 20))
                {
                    return {
                            {
                                    {
                                            "4 8/8 B/? ?/? ?/? ?/? ?/? ?/4 8/8 B/0 C/C 8/? ?/8 B/0 4/? ?/4 8/8 5/C 0",
                                    },
                            },
                            [&](SignatureContainer& self) {
                                void* guobjectarray = Helper::ASM::resolve_mov<uint8_t*>(self.get_match_address()) - 0x10;

                                if (!guobjectarray)
                                {
                                    scan_result.Errors.emplace_back("Was unable to find GUObjectArray: MOV instruction resolved to nullptr\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                    return true;
                                }

                                scan_result.SuccessMessage.emplace_back(std::format(STR("GUObjectArray address: {} <- Built-in\n"), guobjectarray));
                                UObjectArray::SetupGUObjectArrayAddress(guobjectarray);

                                self.get_did_succeed() = true;
                                return true;
                            },
                            [&](const SignatureContainer& self) {
                                if (!self.get_did_succeed())
                                {
                                    scan_result.Errors.emplace_back("Was unable to find AOB for 'GUObjectArray'\nYou can supply your own in 'UE4SS_Signatures/GUObjectArray.lua'");
                                }
                            }
                    };
                }
                else
                {
                    throw std::runtime_error{std::format("GUObjectArray Finder: Unsupported engine version '{}.{}'", Version::Major, Version::Minor)};
                }
            }();

            signature_containers_coreuobject.emplace_back(guobjectarray);
        }

        signature_container_map.emplace(ScanTarget::Core, signature_containers_core);
        signature_container_map.emplace(ScanTarget::CoreUObject, signature_containers_coreuobject);
        SinglePassScanner::start_scan(signature_container_map);

        if (scan_result.Errors.empty())
        {
            scan_result.Status = Signatures::ScanStatus::Succeeded;
        }
        return scan_result;
    }
}
