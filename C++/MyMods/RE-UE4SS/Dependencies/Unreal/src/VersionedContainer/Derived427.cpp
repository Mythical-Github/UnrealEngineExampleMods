#include <Unreal/VersionedContainer/Derived427.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/FProperty.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    void Derived427::UObjectArray_AddUObjectCreateListener(FUObjectCreateListener* Listener)
    {
        if (m_guobjectarray_internal->UObjectCreateListeners.Contains(Listener))
        {
            throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
        }
        m_guobjectarray_internal->UObjectCreateListeners.Add(Listener);
    }

    void Derived427::UObjectArray_RemoveUObjectCreateListener(FUObjectCreateListener* Listener)
    {
        m_guobjectarray_internal->UObjectCreateListeners.RemoveSingleSwap(Listener);
    }

    void Unreal::Derived427::UObjectArray_AddUObjectDeleteListener(FUObjectDeleteListener* Listener)
    {
        if (m_guobjectarray_internal->UObjectDeleteListeners.Contains(Listener))
        {
            throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
        }
        m_guobjectarray_internal->UObjectDeleteListeners.Add(Listener);
    }

    void Unreal::Derived427::UObjectArray_RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener)
    {
        m_guobjectarray_internal->UObjectDeleteListeners.RemoveSingleSwap(Listener);
    }

    auto Derived427::Field_get_type_fname(FField* p_this) -> FName
    {
        return p_this->GetClass().GetFName();
    }

    auto Derived427::Field_get_ffield_owner(FField* p_this) -> void*
    {
        return p_this->GetOwnerVariant().ToField();
    }

    auto Derived427::FFieldClass_get_fname(FFieldClass* p_this) -> FName
    {
        return Helper::Casting::offset_deref<FName>(p_this, 0);
    }
}
