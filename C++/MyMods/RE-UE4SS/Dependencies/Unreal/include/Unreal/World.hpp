#ifndef RC_UNREAL_WORLD_HPP
#define RC_UNREAL_WORLD_HPP

#include <Unreal/UObject.hpp>
#include <Unreal/UnrealCoreStructs.hpp>

namespace RC::Unreal
{
    class RC_UE_API UWorld : public UObject
    {
    DECLARE_EXTERNAL_OBJECT_CLASS(UWorld, Engine)

    public:
#include <MemberVariableLayout_HeaderWrapper_UWorld.hpp>

    public:
        class AActor* SpawnActor(UClass* InClass, struct FVector const* Location = nullptr, struct FRotator const* Rotation = nullptr);
        class AActor* SpawnActor(UClass* Class, struct FTransform const* Transform);
    };
}

#endif // RC_UNREAL_WORLD_HPP