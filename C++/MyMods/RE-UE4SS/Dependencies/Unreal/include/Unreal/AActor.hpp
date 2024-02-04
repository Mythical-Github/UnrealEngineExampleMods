#ifndef RC_UNREAL_AACTOR_HPP
#define RC_UNREAL_AACTOR_HPP

#include <Unreal/UObject.hpp>
#include <Unreal/Transform.hpp>
#include <Unreal/Rotator.hpp>

namespace RC::Unreal
{
    class RC_UE_API AActor : public UObject
    {
    DECLARE_EXTERNAL_OBJECT_CLASS(AActor, Engine)

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
        using BeginPlaySignature = void(AActor* Context);
        static Function<BeginPlaySignature> BeginPlayInternal;
        using TickSignature = void(AActor* Context, float DeltaSeconds);
        static Function<TickSignature> TickInternal;

    public:
        auto GetLevel() -> UObject*;
        auto GetWorld() -> UWorld*;

    public:
        // UFunction interfaces -> START
        auto K2_TeleportTo(FVector DestLocation, FRotator DestRotation) -> bool;
        auto K2_GetActorLocation() -> FVector;
        auto K2_GetComponentsByClass(UClass* ComponentClass) -> TArray<UObject*>; // Should be TArray<UActorComponent*> but we don't have UActorComponent yet.
        auto GetActorForwardVector() -> FVector;
        FTransform GetTransform();
        // UFunction interfaces -> END
    };
}


#endif //RC_UNREAL_AACTOR_HPP
