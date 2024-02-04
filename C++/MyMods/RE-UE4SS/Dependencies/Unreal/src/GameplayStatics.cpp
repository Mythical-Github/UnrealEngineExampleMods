#include <Unreal/GameplayStatics.hpp>
#include <Unreal/AActor.hpp>
#include <Unreal/UClass.hpp>
#include <DynamicOutput/DynamicOutput.hpp>

namespace RC::Unreal
{
    auto UGameplayStatics::VerifySelf() -> bool
    {
        if (!Self)
        {
            Self = UObjectGlobals::StaticFindObject<UGameplayStatics*>(nullptr, nullptr, STR("/Script/Engine.Default__GameplayStatics"));
            if (!Self)
            {
                Output::send(STR("Was unable to locate GameplayStatics\n"));
                return false;
            }
        }

        return true;
    }

    AActor* UGameplayStatics::BeginDeferredActorSpawnFromClass(const UObject* WorldContextObject,
                                                               class UClass* ActorClass,
                                                               const FTransform& SpawnTransform,
                                                               ESpawnActorCollisionHandlingMethod CollisionHandlingOverride,
                                                               AActor* Owner)
    {
        if (!VerifySelf()) { return nullptr; }
        if (!StaticFunctions::BeginDeferredActorSpawnFromClass.IsValid()) { return nullptr; }

        if (Version::IsBelow(5, 0))
        {
            BeginDeferredActorSpawnFromClass_Params_AsPre500 Params{
                    .WorldContextObject = WorldContextObject,
                    .ActorClass = ActorClass,
                    .SpawnTransform = {},
                    .CollisionHandlingOverride = CollisionHandlingOverride,
                    .Owner = Owner,
            };
            Params.SpawnTransform = SpawnTransform;

            StaticFunctions::BeginDeferredActorSpawnFromClass(Params);
            return Params.ReturnValue;
        }
        else
        {
            BeginDeferredActorSpawnFromClass_Params_As500Plus Params{
                    .WorldContextObject = WorldContextObject,
                    .ActorClass = ActorClass,
                    .SpawnTransform = {},
                    .CollisionHandlingOverride = CollisionHandlingOverride,
                    .Owner = Owner,
            };
            Params.SpawnTransform = SpawnTransform;

            StaticFunctions::BeginDeferredActorSpawnFromClass(Params);
            return Params.ReturnValue;
        }
    }

    AActor* UGameplayStatics::FinishSpawningActor(AActor* Actor, const FTransform& SpawnTransform)
    {
        if (!VerifySelf()) { return nullptr; }
        if (!StaticFunctions::FinishSpawningActor.IsValid()) { return nullptr; }

        FinishSpawningActor_Params Params{
                .Actor = Actor,
                .SpawnTransform = SpawnTransform,
        };
        StaticFunctions::FinishSpawningActor(Params);
        return Params.ReturnValue;
    }
}
