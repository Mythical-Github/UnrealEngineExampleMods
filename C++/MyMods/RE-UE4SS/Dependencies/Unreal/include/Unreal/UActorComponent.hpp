#ifndef RC_UNREAL_UACTORCOMPONENT_HPP
#define RC_UNREAL_UACTORCOMPONENT_HPP

#include <Unreal/Common.hpp>
#include <Unreal/UObject.hpp>

namespace RC::Unreal
{
    class RC_UE_API UActorComponent : public UObject
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UActorComponent, Engine);
    };

    class RC_UE_API USceneComponent : public UActorComponent
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(USceneComponent, Engine);
    };
}

#endif //RC_UNREAL_UACTORCOMPONENT_HPP
