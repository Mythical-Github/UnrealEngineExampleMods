#ifndef RC_UNREAL_UFUNCTION_HPP
#define RC_UNREAL_UFUNCTION_HPP

#include <Unreal/UStruct.hpp>
#include <Unreal/UFunctionStructs.hpp>
#include <Unreal/Hooks.hpp>

namespace RC::Unreal
{
    struct FFrame;

    class RC_UE_API UFunction : public UStruct
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UFunction, CoreUObject)

    public:
#include <MemberVariableLayout_HeaderWrapper_UFunction.hpp>

    public:
        /**
         * Retrieves the flag set on this function object
         * Function calls define their type, metadata, access and additional attributes
         */
        //auto GetFunctionFlags() -> EFunctionFlags;

        /**
         * Checks if function has any of the flags specified
         * Returns true if either of the provided flags are set on the function
         */
        inline auto HasAnyFunctionFlags(EFunctionFlags function_flags) -> bool
        {
            return (GetFunctionFlags() & function_flags) != 0;
        }

        /**
         * Checks if function has all of the specified flags
         * Returns true only if all of the provided flags are set on the function
         */
        inline auto HasAllFunctionFlags(EFunctionFlags function_flags) -> bool
        {
            return (GetFunctionFlags() & function_flags) == function_flags;
        }

        /**
         * Returns amount of parameters of the function, including
         * output parameters and the return value if it is defined for the function
         */
        //auto GetNumParms() -> uint8_t;

        //uint16 GetReturnValueOffset();

        /**
         * Returns the total size of the function params used by the function
         * Keep in mind that this value is different from properties size, as it includes
         * only function parameters and does not include other local variables
         */
        //auto GetParmsSize() -> int32_t;

        /**
         * Retrieves the return property of the function, or returns nullptr
         * if the function does not have a return value
         */
        auto GetReturnProperty() -> FProperty*;

        /**
         * Retrieves the pointer to the underlying native function
         * For script functions that would point to UObject::ProcessInternal, which handles
         * execution of the Blueprint VM bytecode, otherwise it would point to the actual native function
         */
        auto GetFuncPtr() -> UnrealScriptFunction;

        /**
         * Updates function pointer to the new value
         * The provided function will be executed when this UFunction object is called
         */
        auto SetFuncPtr(UnrealScriptFunction NewFuncPtr) -> void;

        auto RegisterPreHook(const UnrealScriptFunctionCallable& PreCallback, void* CustomData = nullptr) -> CallbackId;
        auto RegisterPostHook(const UnrealScriptFunctionCallable& PostCallback, void* CustomData = nullptr) -> CallbackId;

        // Same as 'RegisterPre/PostHook' except it only fires if the instance pointer matches the context pointer.
        // Only safe if you can guarantee the validity of the instance passed to these functions.
        auto RegisterPreHookForInstance(const UnrealScriptFunctionCallable& PreCallback, void* CustomData = nullptr, UObject* FireOnInstance = nullptr) -> CallbackId;
        auto RegisterPostHookForInstance(const UnrealScriptFunctionCallable& PostCallback, void* CustomData = nullptr, UObject* FireOnInstance = nullptr) -> CallbackId;

        auto UnregisterHook(CallbackId CallbackId) -> bool;
        auto UnregisterAllHooks() -> void;
        auto GetFunctionHookCallbackData(CallbackId) -> UnrealScriptCallbackData*;
    protected:
        auto GetFunctionHookData() -> UnrealScriptFunctionData&;
    };
}


#endif //RC_UNREAL_UFUNCTION_HPP
