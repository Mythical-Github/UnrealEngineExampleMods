#include <Unreal/FWeakObjectPtr.hpp>
#include <Unreal/VersionedContainer/Container.hpp>
#include <Unreal/UObjectArray.hpp>
#include <Unreal/UObject.hpp>
#include <DynamicOutput/Output.hpp>

namespace RC::Unreal
{
    auto FWeakObjectPtr::SerialNumbersMatch(FUObjectItem* ObjectItem) const -> bool
    {
        return Container::UnrealVC->FUObjectItem_get_serial_number(ObjectItem) == ObjectSerialNumber;
    }

    auto FWeakObjectPtr::InternalGetObjectItem() const -> FUObjectItem*
    {
        if (ObjectSerialNumber == 0) { return nullptr; }
        if (ObjectIndex < 0) { return nullptr; }

        FUObjectItem* const ObjectItem = static_cast<FUObjectItem* const>(Container::UnrealVC->UObjectArray_index_to_object(ObjectIndex));

        if (!ObjectItem) { return nullptr; }
        if (!SerialNumbersMatch(ObjectItem)) { return nullptr; }

        return ObjectItem;
    }

    auto FWeakObjectPtr::Reset() -> void
    {
        ObjectIndex = INDEX_NONE;
        ObjectSerialNumber = 0;
    }

    auto FWeakObjectPtr::operator=(UObject* NewObject) -> void
    {
        if (!NewObject)
        {
            Reset();
        }
        else
        {
            ObjectIndex = NewObject->GetInternalIndex();
            ObjectSerialNumber = Container::UnrealVC->FUObjectItem_get_serial_number(ObjectIndex);
        }
    }

    auto FWeakObjectPtr::InternalGet(bool bEvenIfPendingKill) const -> UObject*
    {
        FUObjectItem* const ObjectItem = InternalGetObjectItem();
        return ((ObjectItem != nullptr) && UObjectArray::IsValid(ObjectItem, bEvenIfPendingKill)) ? ObjectItem->GetUObject() : nullptr;
    }

    auto FWeakObjectPtr::Get() const -> UObject*
    {
        return InternalGet(false);
    }
}
