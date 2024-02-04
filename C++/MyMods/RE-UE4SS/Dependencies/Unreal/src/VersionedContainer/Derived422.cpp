#include <Unreal/VersionedContainer/Derived422.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/FProperty.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    auto Derived422::Field_get_type_fname(FField* p_this) -> FName
    {
        return p_this->GetClass().GetFName();
    }

    auto Derived422::Field_get_ffield_owner([[maybe_unused]]FField* p_this) -> void*
    {
        // FField does not exist before 4.25 so therefor FField::Owner also does not exist
        // It's up to the caller to make sure the returned value isn't nullptr
        return nullptr;
    }

    auto Derived422::FFieldClass_get_fname(FFieldClass* p_this) -> FName
    {
        return std::bit_cast<Unreal::UObject*>(p_this)->GetNamePrivate();
    }
}
