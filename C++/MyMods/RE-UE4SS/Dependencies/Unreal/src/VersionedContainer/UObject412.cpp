#include <Unreal/VersionedContainer/UObject412.hpp>
#include <Unreal/VersionedContainer/Flags412.hpp>
#include <Unreal/VersionedContainer/Flags.hpp>
#include <Unreal/VersionedContainer/Container.hpp>

namespace RC::Unreal
{
    auto UObject412::UObject_clear_flags(void* p_this, const EObjectFlags flags_to_clear) -> void
    {
        Flags::clear_flags(p_this, Flags412::to_impl_flags(flags_to_clear));
    }

    auto UObject412::UObject_set_flags_to(void* p_this, EObjectFlags new_flags) -> void
    {
        Flags::set_flags_to(p_this, Flags412::to_impl_flags(new_flags));
    }

    auto UObject412::UObject_set_flags(void* p_this, const EObjectFlags new_flags) -> void
    {
        Flags::set_flags(p_this, Flags412::to_impl_flags(new_flags));
    }

    auto UObject412::UObject_has_any_flag(void* p_this, const EObjectFlags flags_to_check) -> bool
    {
        return Flags::has_any_flag(p_this, Flags412::to_impl_flags(flags_to_check));
    }

    auto UObject412::UObject_has_all_flags(void* p_this, const EObjectFlags flags_to_check) -> bool
    {
        return Flags::has_all_flags(p_this, Flags412::to_impl_flags(flags_to_check));
    }

    bool UObject412::UObject_HasAnyInternalFlags(void* p_this, const EInternalObjectFlags FlagsToCheck)
    {
        return Container::UnrealVC->FUObjectItem_HasAnyFlags(Container::UnrealVC->UObjectArray_index_to_object(UObject_get_internal_index(p_this)), FlagsToCheck);
    }
}
