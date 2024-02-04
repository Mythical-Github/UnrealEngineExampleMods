#include <Unreal/FArchive.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    std::unordered_map<File::StringType, uint32_t> FArchiveState::VTableLayoutMap;
    std::unordered_map<File::StringType, uint32_t> FArchive::VTableLayoutMap;

    #include <MemberVariableLayout_SrcWrapper_FArchiveState.hpp>
    #include <MemberVariableLayout_SrcWrapper_FArchive.hpp>
}
