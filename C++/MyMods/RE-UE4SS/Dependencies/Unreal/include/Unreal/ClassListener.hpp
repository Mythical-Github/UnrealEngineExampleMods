#ifndef RC_UNREAL_CLASS_DELETE_LISTENER_HPP
#define RC_UNREAL_CLASS_DELETE_LISTENER_HPP

#include <Unreal/UObjectArray.hpp>

namespace RC::Unreal
{
    struct RC_UE_API FClassCreateListener : public FUObjectCreateListener
    {
        static FClassCreateListener ClassCreateListener;

        void NotifyUObjectCreated(const class UObjectBase* Object, int32 Index) override;
        void OnUObjectArrayShutdown() override;
    };

    struct RC_UE_API FClassDeleteListener : public FUObjectDeleteListener
    {
        static FClassDeleteListener ClassDeleteListener;

        void NotifyUObjectDeleted(const class UObjectBase* Object, int32 Index) override;
        void OnUObjectArrayShutdown() override;
    };
}

#endif // RC_UNREAL_CLASS_DELETE_LISTENER_HPP