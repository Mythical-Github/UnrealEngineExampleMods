#include <Unreal/ClassListener.hpp>
#include <Unreal/UnrealInitializer.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/Searcher/ObjectSearcher.hpp>

namespace RC::Unreal
{
    FClassCreateListener FClassCreateListener::ClassCreateListener{};
    FClassDeleteListener FClassDeleteListener::ClassDeleteListener{};

    void FClassCreateListener::NotifyUObjectCreated(const UObjectBase* Object, int32 Index)
    {
    }

    void FClassCreateListener::OnUObjectArrayShutdown()
    {
        UnrealInitializer::StaticStorage::bIsInitialized = false;
        UObjectArray::RemoveUObjectCreateListener(this);
    }

    void FClassDeleteListener::NotifyUObjectDeleted(const UObjectBase* Object, int32 Index)
    {
        auto* ObjectItem = Object->GetObjectItem();

        // All classes.
        ObjectSearcherPool<UClass, AnySuperStruct>::Pool.erase(std::remove_if(ObjectSearcherPool<UClass, AnySuperStruct>::Pool.begin(), ObjectSearcherPool<UClass, AnySuperStruct>::Pool.end(), [&](const auto& Item) {
            return Item == ObjectItem;
        }), ObjectSearcherPool<UClass, AnySuperStruct>::Pool.end());

        // All actor classes.
        ObjectSearcherPool<UClass, AActor>::Pool.erase(std::remove_if(ObjectSearcherPool<UClass, AActor>::Pool.begin(), ObjectSearcherPool<UClass, AActor>::Pool.end(), [&](const auto& Item) {
            return Item == ObjectItem;
        }), ObjectSearcherPool<UClass, AActor>::Pool.end());

        // All actor instances.
        ObjectSearcherPool<AActor, AnySuperStruct>::Pool.erase(std::remove_if(ObjectSearcherPool<AActor, AnySuperStruct>::Pool.begin(), ObjectSearcherPool<AActor, AnySuperStruct>::Pool.end(), [&](const auto& Item) {
            return Item == ObjectItem;
        }), ObjectSearcherPool<AActor, AnySuperStruct>::Pool.end());
    }

    void FClassDeleteListener::OnUObjectArrayShutdown()
    {
        UnrealInitializer::StaticStorage::bIsInitialized = false;
        UObjectArray::RemoveUObjectDeleteListener(this);
    }

}
