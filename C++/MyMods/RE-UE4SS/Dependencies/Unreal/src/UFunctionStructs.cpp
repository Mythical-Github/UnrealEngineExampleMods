#include <Unreal/UFunctionStructs.hpp>
#include <Unreal/UFunction.hpp>
#include <DynamicOutput/Output.hpp>
#include <Helpers/Format.hpp>
#include <Unreal/Hooks.hpp>

namespace RC::Unreal
{
    UnrealScriptFunctionData::UnrealScriptFunctionData(UnrealScriptFunction OriginalFuncPtr) {
        this->OriginalFunc = OriginalFuncPtr;
        this->HookIndexCounter = 1;
    }

    CallbackId UnrealScriptFunctionData::AddPreCallback(const UnrealScriptFunctionCallable& Callable, void* CustomData, UObject* FireOnInstance)
    {
        CallbackId NewCallbackId = this->HookIndexCounter++;
        this->PreCallbacks.emplace(std::piecewise_construct, std::forward_as_tuple(NewCallbackId), std::forward_as_tuple(Callable, CustomData, FireOnInstance));
        return NewCallbackId;
    }

    CallbackId UnrealScriptFunctionData::AddPostCallback(const UnrealScriptFunctionCallable& Callable, void* CustomData, UObject* FireOnInstance)
    {
        CallbackId NewCallbackId = this->HookIndexCounter++;
        this->PostCallbacks.emplace(std::piecewise_construct, std::forward_as_tuple(NewCallbackId), std::forward_as_tuple(Callable, CustomData, FireOnInstance));
        return NewCallbackId;
    }

    bool UnrealScriptFunctionData::RemoveCallback(CallbackId CallbackId)
    {
        auto CallbackData = GetCallbackData(CallbackId);
        if (CallbackData)
        {
            if (bIsMidExecution)
            {
                // Hook will be unregistered after the callback is done executing.
                CallbackData->UnregistrationRequested = true;
                return true;
            }
            else
            {
                return PreCallbacks.erase(CallbackId) || PostCallbacks.erase(CallbackId);
            }
        }
        else
        {
            return false;
        }
    }

    void UnrealScriptFunctionData::RemoveAllCallbacks()
    {
        for (auto PreCallbackIterator = PreCallbacks.begin(); PreCallbackIterator != PreCallbacks.end();)
        {
            if (bIsMidExecution)
            {
                // Hook will be unregistered after the callback is done executing.
                PreCallbackIterator->second.UnregistrationRequested = true;
            }
            else
            {
                PreCallbackIterator = PreCallbacks.erase(PreCallbackIterator);
            }
        }

        for (auto PostCallbackIterator = PostCallbacks.begin(); PostCallbackIterator != PostCallbacks.end();)
        {
            if (bIsMidExecution)
            {
                // Hook will be unregistered after the callback is done executing.
                PostCallbackIterator->second.UnregistrationRequested = true;
            }
            else
            {
                PostCallbackIterator = PostCallbacks.erase(PostCallbackIterator);
            }
        }
    }

    void UnrealScriptFunctionData::FirePreCallbacks(UnrealScriptFunctionCallableContext& Context)
    {
        for (auto PreCallbackIterator = PreCallbacks.begin(); PreCallbackIterator != PreCallbacks.end();)
        {
            if (PreCallbackIterator->second.FireOnInstance && PreCallbackIterator->second.FireOnInstance != Context.Context) { continue; }
            PreCallbackIterator->second.Callable(Context, PreCallbackIterator->second.CustomData);
            if (PreCallbackIterator->second.UnregistrationRequested)
            {
                PreCallbackIterator = PreCallbacks.erase(PreCallbackIterator);
            }
            else
            {
                ++PreCallbackIterator;
            }
        }
    }

    void UnrealScriptFunctionData::FirePostCallbacks(UnrealScriptFunctionCallableContext& Context)
    {
        for (auto PostCallbackIterator = PostCallbacks.begin(); PostCallbackIterator != PostCallbacks.end();)
        {
            PostCallbackIterator->second.Callable(Context, PostCallbackIterator->second.CustomData);
            if (PostCallbackIterator->second.UnregistrationRequested)
            {
                PostCallbackIterator = PostCallbacks.erase(PostCallbackIterator);
            }
            else
            {
                ++PostCallbackIterator;
            }
        }
    }

    UnrealScriptCallbackData* UnrealScriptFunctionData::GetCallbackData(CallbackId CallbackId)
    {
        auto PreIterator = PreCallbacks.find(CallbackId);
        if (PreIterator != PreCallbacks.end()) { return &PreIterator->second; }

        auto PostIterator = PostCallbacks.find(CallbackId);
        if (PostIterator != PostCallbacks.end()) { return &PostIterator->second; }

        return nullptr;
    }

    UnrealScriptFunctionCallableContext::UnrealScriptFunctionCallableContext(UObject* Context, FFrame& TheStack, void* RESULT_DECL)
            : Context(Context),
              TheStack(TheStack),
              RESULT_DECL(RESULT_DECL) {}

    static Internal::HookedUFunctionMap GHookedScriptFunctions{};

    auto Internal::GetHookedFunctionsMap() -> HookedUFunctionMap&
    {
        return GHookedScriptFunctions;
    }

    auto Internal::UnrealScriptFunctionHook(UObject* Context, FFrame& TheStack, void* RESULT_DECL) -> void
    {
        try
        {
            HookedUFunctionMap& FunctionMap = GetHookedFunctionsMap();
            const auto Iterator = FunctionMap.find(TheStack.CurrentNativeFunction());

            if (Iterator == FunctionMap.end())
            {
                // For some reason, CurrentNativeFunction isn't hooked.
                // This could be due to a bug.
                // Either way, if CurrentNativeFunction is nullptr, it might be safe to call ProcessInternal.
                // If CurrentNativeFunction is non-nullptr, then we call whatever is stored in CurrentNativeFunction.Func.
                if (TheStack.CurrentNativeFunction())
                {
                    Output::send<LogLevel::Warning>(STR("Tried to execute UFunction::FuncPtr hook but there was no function map entry for UFunction:\n\t{:016X} {}.\n\tExecuting original function instead.\n"),
                                                    std::bit_cast<uintptr_t>(TheStack.CurrentNativeFunction()),
                                                    TheStack.CurrentNativeFunction() ? TheStack.CurrentNativeFunction()->GetFullName() : STR("None"));
                    TheStack.CurrentNativeFunction()->GetFuncPtr()(Context, TheStack, RESULT_DECL);
                }
                else
                {
                    Output::send<LogLevel::Warning>(STR("Tried to execute UFunction::FuncPtr hook but there was no function map entry for UFunction:\n\t{:016X} {}.\n\tNo original function to execute.\n\tExecuting ProcessInternal instead.\n"),
                                                    std::bit_cast<uintptr_t>(TheStack.CurrentNativeFunction()),
                                                    TheStack.CurrentNativeFunction() ? TheStack.CurrentNativeFunction()->GetFullName() : STR("None"));
                    static auto Object_ExecuteUbergraph = UObjectGlobals::StaticFindObject<UFunction*>(nullptr, nullptr, STR("/Script/CoreUObject.Object:ExecuteUbergraph"));
                    static auto ProcessInternal = Object_ExecuteUbergraph->GetFuncPtr();
                    Output::send(STR("Object_ExecuteUbergraph: {}\n"), (void*)Object_ExecuteUbergraph);
                    Output::send(STR("ProcessInternal: {}\n"), (void*)ProcessInternal);
                    ProcessInternal(Context, TheStack, RESULT_DECL);
                }
            }
            else
            {
                UnrealScriptFunctionCallableContext FuncContext(Context, TheStack, RESULT_DECL);

                Iterator->second.bIsMidExecution = true;

                try
                {
                    Iterator->second.FirePreCallbacks(FuncContext);
                }
                catch (std::exception& e)
                {
                    Output::send(STR("Error executing hook pre-callback {}: {}\n"), TheStack.CurrentNativeFunction()->GetPathName(), to_wstring(e.what()));
                }

                Iterator->second.GetOriginalFuncPtr()(Context, TheStack, RESULT_DECL);

                try
                {
                    Iterator->second.FirePostCallbacks(FuncContext);
                }
                catch (std::exception& e)
                {
                    Output::send(STR("Error executing hook post-callback {}: {}\n"), TheStack.CurrentNativeFunction()->GetPathName(), to_wstring(e.what()));
                }

                Iterator->second.bIsMidExecution = false;
            }
        }
        catch (std::exception& e)
        {
            Output::send(STR("Error executing hooked function {}: {}\n"), TheStack.CurrentNativeFunction()->GetPathName(), to_wstring(e.what()));
        }
    }
}
