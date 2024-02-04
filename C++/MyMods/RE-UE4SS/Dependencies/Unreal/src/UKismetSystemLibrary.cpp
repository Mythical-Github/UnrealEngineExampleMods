#include <DynamicOutput/DynamicOutput.hpp>
#include <Unreal/UKismetSystemLibrary.hpp>

namespace RC::Unreal
{
    auto UKismetSystemLibrary::VerifySelf() -> bool
    {
        if (!Self)
        {
            Self = UObjectGlobals::StaticFindObject<UKismetSystemLibrary*>(nullptr, nullptr, STR("/Script/Engine.Default__KismetSystemLibrary"));
            if (!Self)
            {
                Output::send(STR("Was unable to locate KismetSystemLibrary\n"));
                return false;
            }
        }

        return true;
    }

    auto UKismetSystemLibrary::GetGameName() -> FString
    {
        if (!VerifySelf()) { return {}; }
        if (!StaticFunctions::GetGameName.IsValid()) { return {}; }

        GetGameName_Params Params{};
        StaticFunctions::GetGameName(Params);
        return Params.ReturnValue;
    }
}
