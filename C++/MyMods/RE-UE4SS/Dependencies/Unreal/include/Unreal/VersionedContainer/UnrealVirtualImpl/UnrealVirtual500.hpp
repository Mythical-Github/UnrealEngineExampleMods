#ifndef RC_UNREAL_UNREAL_VIRTUAL500_HPP
#define RC_UNREAL_UNREAL_VIRTUAL500_HPP

#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtualBaseVC.hpp>

namespace RC::Unreal
{
    class UnrealVirtual500 : public UnrealVirtualBaseVC
    {
        auto set_virtual_offsets() -> void override;
    };
}


#endif //RC_UNREAL_UNREAL_VIRTUAL500_HPP
