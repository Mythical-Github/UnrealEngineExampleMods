#ifndef RC_UNREAL_UKISMETSYSTEMLIBRARY_HPP
#define RC_UNREAL_UKISMETSYSTEMLIBRARY_HPP

#include <Unreal/Common.hpp>
#include <Unreal/ReflectedFunction.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/FString.hpp>

namespace RC::Unreal
{
    class RC_UE_API UKismetSystemLibrary : public UObject
    {
    public:
        using StaticReflectedFunction = StaticReflectedFunctionBase<UKismetSystemLibrary>;

        static inline UKismetSystemLibrary* Self{nullptr};
        struct StaticFunctions
        {
            static inline StaticReflectedFunction GetGameName{STR("/Script/Engine.KismetSystemLibrary:GetGameName")};
        };

    public:
        struct GetGameName_Params
        {
        public:
            FString ReturnValue; // 0x0
        };

    private:
        auto static VerifySelf() -> bool;

    public:
        auto static GetGameName() -> FString;
    };
}

#endif //RC_UNREAL_UKISMETSYSTEMLIBRARY_HPP
