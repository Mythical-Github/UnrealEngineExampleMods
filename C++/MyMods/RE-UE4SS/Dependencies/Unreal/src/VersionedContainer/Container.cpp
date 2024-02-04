#include <Unreal/VersionedContainer/Container.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <Unreal/VersionedContainer/Derived412.hpp>
#include <Unreal/VersionedContainer/Derived413.hpp>
#include <Unreal/VersionedContainer/Derived415.hpp>
#include <Unreal/VersionedContainer/Derived417.hpp>
#include <Unreal/VersionedContainer/Derived420.hpp>
#include <Unreal/VersionedContainer/Derived422.hpp>
#include <Unreal/VersionedContainer/Derived425.hpp>
#include <Unreal/VersionedContainer/Derived427.hpp>
#include <Unreal/VersionedContainer/UObject412.hpp>
#include <Unreal/VersionedContainer/UObject415.hpp>
#include <Unreal/VersionedContainer/UObject422.hpp>
#include <Unreal/VersionedContainer/UObject425.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual411.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual412.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual413.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual414.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual415.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual416.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual417.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual418.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual419.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual420.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual421.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual422.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual423.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual424.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual425.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual426.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual427.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual500.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual501.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtual502.hpp>

namespace RC::Unreal
{
    std::unique_ptr<Base> Container::UnrealVC;
    std::unique_ptr<UObjectBaseVC> Container::UnrealObjectVC;
    std::unique_ptr<UnrealVirtualBaseVC> Container::UnrealVirtualVC;

    auto Container::SetDerivedBaseObjects() -> void
    {
        if (Version::IsEqual(4, 11))
        {
            UnrealVC = std::make_unique<Derived412>();
            UnrealObjectVC = std::make_unique<UObject412>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual411>();
        }
        else if (Version::IsEqual(4, 12))
        {
            UnrealVC = std::make_unique<Derived412>();
            UnrealObjectVC = std::make_unique<UObject412>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual412>();
        }
        else if (Version::IsEqual(4, 13))
        {
            // FUObjectItem changed in this version
            UnrealVC = std::make_unique<Derived413>();
            UnrealObjectVC = std::make_unique<UObject415>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual413>();
        }
        else if (Version::IsEqual(4, 14))
        {
            UnrealVC = std::make_unique<Derived413>();
            UnrealObjectVC = std::make_unique<UObject415>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual414>();
        }
        else if (Version::IsEqual(4, 15))
        {
            UnrealVC = std::make_unique<Derived413>();
            UnrealObjectVC = std::make_unique<UObject412>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual415>();
        }
        else if (Version::IsEqual(4, 16))
        {
            UnrealVC = std::make_unique<Derived417>();
            UnrealObjectVC = std::make_unique<UObject412>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual416>();
        }
        else if (Version::IsEqual(4, 17))
        {
            // TLockFreePointerListUnordered was changed and is now a pointer surrounded by padding
            UnrealVC = std::make_unique<Derived417>();
            UnrealObjectVC = std::make_unique<UObject412>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual417>();
        }
        else if (Version::IsEqual(4, 18))
        {
            // Using 4.12 since it seems to have the correct GUObjectArray definition
            UnrealVC = std::make_unique<Derived417>();
            UnrealObjectVC = std::make_unique<UObject412>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual418>();
        }
        else if (Version::IsEqual(4, 19))
        {
            UnrealVC = std::make_unique<Derived417>();
            UnrealObjectVC = std::make_unique<UObject422>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual419>();
        }
        else if (Version::IsEqual(4, 20))
        {
            // FFixedUObjectArray was replaced with FChunkedFixedUObjectArray
            UnrealVC = std::make_unique<Derived420>();
            UnrealObjectVC = std::make_unique<UObject422>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual420>();
        }
        else if (Version::IsEqual(4, 21))
        {
            UnrealVC = std::make_unique<Derived420>();
            UnrealObjectVC = std::make_unique<UObject422>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual421>();
        }
        else if (Version::IsEqual(4, 22))
        {
            // PLATFORM_CACHE_LINE_SIZE changed from 128 to 64
            UnrealVC = std::make_unique<Derived422>();
            UnrealObjectVC = std::make_unique<UObject422>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual422>();
        }
        else if (Version::IsEqual(4, 23))
        {
            UnrealVC = std::make_unique<Derived422>();
            UnrealObjectVC = std::make_unique<UObject422>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual423>();
        }
        else if (Version::IsEqual(4, 24))
        {
            UnrealVC = std::make_unique<Derived422>();
            UnrealObjectVC = std::make_unique<UObject422>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual424>();
        }
        else if (Version::IsEqual(4, 25))
        {
            UnrealVC = std::make_unique<Derived425>();
            UnrealObjectVC = std::make_unique<UObject425>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual425>();
        }
        else if (Version::IsEqual(4, 26))
        {
            UnrealVC = std::make_unique<Derived425>();
            UnrealObjectVC = std::make_unique<UObject425>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual426>();
        }
        else if (Version::IsEqual(4, 27))
        {
            // Type of FUObjectArray.ObjAvailableList was changed to TArray<int32>
            UnrealVC = std::make_unique<Derived427>();
            UnrealObjectVC = std::make_unique<UObject425>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual427>();
        }
        else if (Version::IsEqual(5, 0))
        {
            UnrealVC = std::make_unique<Derived427>();
            UnrealObjectVC = std::make_unique<UObject425>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual500>();
        }
        else if (Version::IsEqual(5, 1))
        {
            UnrealVC = std::make_unique<Derived427>();
            UnrealObjectVC = std::make_unique<UObject425>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual501>();
        }
        else if (Version::IsEqual(5, 2))
        {
            UnrealVC = std::make_unique<Derived427>();
            UnrealObjectVC = std::make_unique<UObject425>();
            UnrealVirtualVC = std::make_unique<UnrealVirtual502>();
        }
        else
        {
            // If this code is ever reached then the version isn't explicitly supported
            // Using 4.25 as a long-shot, sometimes this will work but in the future it's likely that this will break
            // Update: It will break in 4.27+ because GUObjectArray is different
            throw std::runtime_error{"Engine version is not supported."};
        }
    }
}