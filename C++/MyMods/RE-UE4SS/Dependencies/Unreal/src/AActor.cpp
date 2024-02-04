#include <Unreal/AActor.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/UObjectArray.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/World.hpp>

namespace RC::Unreal
{
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(AActor)

    Function<AActor::BeginPlaySignature> AActor::BeginPlayInternal;
    Function<AActor::TickSignature> AActor::TickInternal;
    std::unordered_map<File::StringType, uint32_t> AActor::VTableLayoutMap;

    auto AActor::GetLevel() -> UObject*
    {
        UObject* Outer = GetOuterPrivate();
        if (!Outer) { return nullptr; }

        if (!HasAnyFlags(Unreal::RF_ClassDefaultObject) && !Outer->HasAnyFlags(Unreal::RF_BeginDestroyed) && !Outer->GetObjectItem()->IsUnreachable())
        {
            while (Outer)
            {
                if (Outer->GetClassPrivate()->GetNamePrivate() == TypeChecker::get_level_name())
                {
                    return Outer;
                }

                Outer = Outer->GetOuterPrivate();
            }
        }

        return nullptr;
    }

    auto AActor::GetWorld() -> UWorld*
    {
        UObject* Outer = GetOuterPrivate();
        if (!Outer) { return nullptr; }

        if (!HasAnyFlags(Unreal::RF_ClassDefaultObject) && !Outer->HasAnyFlags(Unreal::RF_BeginDestroyed) && !Outer->GetObjectItem()->IsUnreachable())
        {
            while (Outer)
            {
                if (Outer->GetClassPrivate()->GetNamePrivate() == TypeChecker::get_world_name())
                {
                    return static_cast<UWorld*>(Outer);
                }

                Outer = Outer->GetOuterPrivate();
            }
        }

        return nullptr;
    }

    auto AActor::K2_TeleportTo(FVector DestLocation, FRotator DestRotation) -> bool
    {
        static UFunction* Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, L"/Script/Engine.Actor:K2_TeleportTo");
        if (!Function)
        {
            throw std::runtime_error{"UFunction not found: 'K2_TeleportTo'"};
        }

        struct K2_TeleportTo_Params
        {
            FVector DestLocation;
            FRotator DestRotation;
            bool ReturnValue;
        };
        K2_TeleportTo_Params Params{
            .DestLocation = DestLocation,
            .DestRotation = DestRotation,
        };

        ProcessEvent(Function, &Params);
        return Params.ReturnValue;
    }

    auto AActor::K2_GetActorLocation() -> FVector
    {
        static UFunction* Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, L"/Script/Engine.Actor:K2_GetActorLocation");
        if (!Function)
        {
            throw std::runtime_error{"UFunction not found: 'K2_GetActorLocation'"};
        }

        struct K2_GetActorLocation_Params
        {
            FVector ReturnValue;
        };
        K2_GetActorLocation_Params Params{};

        ProcessEvent(Function, &Params);
        return Params.ReturnValue;
    }

    auto AActor::K2_GetComponentsByClass(UClass* ComponentClass) -> TArray<UObject*>
    {
        static UFunction* Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, L"/Script/Engine.Actor:K2_GetComponentsByClass");
        if (!Function)
        {
            Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, L"/Script/Engine.Actor:GetComponentsByClass");
        }
        if (!Function)
        {
            throw std::runtime_error{"UFunction not found: 'K2_GetComponentsByClass'"};
        }

        struct K2_GetComponentsByClass_Params
        {
            UClass* ComponentClass;
            TArray<UObject*> ReturnValue;
        };
        K2_GetComponentsByClass_Params Params{ComponentClass};

        ProcessEvent(Function, &Params);
        return Params.ReturnValue;
    }

    auto AActor::GetActorForwardVector() -> FVector
    {
        static UFunction* Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, L"/Script/Engine.Actor:GetActorForwardVector");
        if (!Function)
        {
            throw std::runtime_error{"UFunction not found: 'GetActorForwardVector'"};
        }

        struct GetActorForwardVector_Params
        {
            FVector ReturnValue;
        };
        GetActorForwardVector_Params Params{};

        ProcessEvent(Function, &Params);
        return Params.ReturnValue;
    }

    FTransform AActor::GetTransform()
    {
        static UFunction* Function = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, STR("/Script/Engine.Actor:GetTransform"));
        if (!Function)
        {
            throw std::runtime_error{"UFunction not found: 'GetTransform'"};
        }

        struct GetTransform_Params
        {
            FTransform ReturnValue; // 0x0
        };
        GetTransform_Params Params{};

        ProcessEvent(Function, &Params);
        return Params.ReturnValue;
    }
}
