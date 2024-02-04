#ifndef RC_UNREAL_UOBJECTARRAY_HPP
#define RC_UNREAL_UOBJECTARRAY_HPP

// User API for UObjectArray related abstractions
// See Base.hpp / DerivedX.hpp files for implementations

#include <Unreal/Common.hpp>
#include <Unreal/PrimitiveTypes.hpp>

namespace RC::Unreal
{
    // This is implemented as a regular polymorphic object instead of using the vtable generator.
    // That's because the struct is very small and so is the vtable, and it hasn't changed from 4.12.
    // It's just easier to not use the vtable generator for this.
    class RC_UE_API FUObjectCreateListener
    {
    public:
        virtual ~FUObjectCreateListener() = default;
        virtual void NotifyUObjectCreated(const class UObjectBase* Object, int32 Index) = 0;
        virtual void OnUObjectArrayShutdown() = 0;
    };

    class RC_UE_API FUObjectDeleteListener
    {
    public:
        virtual ~FUObjectDeleteListener() = default;
        virtual void NotifyUObjectDeleted(const class UObjectBase* Object, int32 Index) = 0;
        virtual void OnUObjectArrayShutdown() = 0;
    };

    struct RC_UE_API FUObjectItem
    {
        auto IsUnreachable() const -> bool;
        auto SetRootSet() -> void;
        auto UnsetRootSet() -> void;
        auto SetGCKeep() -> void;
        auto UnsetGCKeep() -> void;
        auto GetUObject() const -> class UObject*;
    };

    class RC_UE_API UObjectArray
    {
    public:
        auto static SetupGUObjectArrayAddress(void* address) -> void;

    public:
        auto static IsValid(FUObjectItem* ObjectItem, bool bEvenIfPendingKill) -> bool;
        static void AddUObjectCreateListener(FUObjectCreateListener* Listener);
        static void RemoveUObjectCreateListener(FUObjectCreateListener* Listener);
        static void AddUObjectDeleteListener(FUObjectDeleteListener* Listener);
        static void RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener);
        static int32_t GetNumElements();
        static int32_t GetNumChunks();
    };
}


#endif //RC_UNREAL_UOBJECTARRAY_HPP
