#include <Unreal/VersionedContainer/Derived412.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/UStruct.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/FField.hpp>
#include <Unreal/FProperty.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    auto Derived412::Field_get_type_fname(FField* p_this) -> FName
    {
        return p_this->GetClass().GetFName();
    }

    auto Derived412::Field_get_ffield_owner([[maybe_unused]]FField* p_this) -> void*
    {
        // FField does not exist before 4.25 so therefor FField::Owner also does not exist
        // It's up to the caller to make sure the returned value isn't nullptr
        return nullptr;
    }

    auto Derived412::FFieldClass_get_fname(FFieldClass* p_this) -> FName
    {
        return std::bit_cast<Unreal::UObject*>(p_this)->GetNamePrivate();
    }

    bool Derived412::FUObjectItem_HasAnyFlags(void* RawThis, EInternalObjectFlags InFlags)
    {
        FUObjectItem* TypedThis = static_cast<FUObjectItem*>(RawThis);
        return !!(TypedThis->cluster_and_flags & int32(InFlags));
    }

    void Derived412::UObjectArray_AddUObjectCreateListener(FUObjectCreateListener* Listener)
    {
        if (m_guobjectarray_internal->UObjectCreateListeners.Contains(Listener))
        {
            throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
        }
        m_guobjectarray_internal->UObjectCreateListeners.Add(Listener);
    }

    void Derived412::UObjectArray_RemoveUObjectCreateListener(FUObjectCreateListener* Listener)
    {
        m_guobjectarray_internal->UObjectCreateListeners.RemoveSingleSwap(Listener);
    }

    void Derived412::UObjectArray_AddUObjectDeleteListener(FUObjectDeleteListener* Listener)
    {
        if (m_guobjectarray_internal->UObjectDeleteListeners.Contains(Listener))
        {
            throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
        }
        m_guobjectarray_internal->UObjectDeleteListeners.Add(Listener);
    }

    void Derived412::UObjectArray_RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener)
    {
        m_guobjectarray_internal->UObjectDeleteListeners.RemoveSingleSwap(Listener);
    }
}
