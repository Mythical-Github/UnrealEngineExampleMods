#include <Unreal/VersionedContainer/Derived425.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/FField.hpp>
#include <Unreal/FProperty.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    auto Derived425::Field_get_type_fname(FField* p_this) -> FName
    {
        return p_this->GetClass().GetFName();
    }

    auto Derived425::Field_get_ffield_owner(FField* p_this) -> void*
    {
        return p_this->GetOwnerVariant().ToField();
    }

    auto Derived425::FFieldClass_get_fname(FFieldClass* p_this) -> FName
    {
        return Helper::Casting::offset_deref<FName>(p_this, 0);
    }
}
