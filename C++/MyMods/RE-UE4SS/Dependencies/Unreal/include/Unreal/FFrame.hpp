#ifndef RC_UNREAL_FFRAME_HPP
#define RC_UNREAL_FFRAME_HPP

#include <Unreal/Common.hpp>
#include <Unreal/FOutputDevice.hpp>

namespace RC::Unreal
{
    class UObject;
    class UProperty;
    class UField;
    struct FOutParmRec;
    class UFunction;

    using FlowStackType = uint8_t[0x30];
    using FlowStackTypePtr = uint8_t*;

    struct RC_UE_API FFrame_50_AndBelow : public FOutputDevice
    {
        using FFrame = FFrame_50_AndBelow;

        // Variables.
        UFunction* Node;
        UObject* Object;
        uint8_t* Code;
        uint8_t* Locals;

        UProperty* MostRecentProperty;
        uint8_t* MostRecentPropertyAddress;

        /** The execution flow stack for compiled Kismet code */
        FlowStackType FlowStack;

        /** Previous frame on the stack */
        FFrame* PreviousFrame;

        /** contains information on any out parameters */
        FOutParmRec* OutParms;

        /** If a class is compiled in then this is set to the property chain for compiled-in functions. In that case, we follow the links to setup the args instead of executing by code. */
        UField* PropertyChainForCompiledIn;

        /** Currently executed native function */
        UFunction* CurrentNativeFunction;

        bool bArrayContextFailed;
    };

    struct RC_UE_API FFrame_51_AndAbove : public FOutputDevice
    {
        using FFrame = FFrame_51_AndAbove;

        // Variables.
        UFunction* Node;
        UObject* Object;
        uint8_t* Code;
        uint8_t* Locals;

        UProperty* MostRecentProperty;
        uint8_t* MostRecentPropertyAddress;
        uint8* MostRecentPropertyContainer; // New in 5.1.

        /** The execution flow stack for compiled Kismet code */
        FlowStackType FlowStack;

        /** Previous frame on the stack */
        FFrame* PreviousFrame;

        /** contains information on any out parameters */
        FOutParmRec* OutParms;

        /** If a class is compiled in then this is set to the property chain for compiled-in functions. In that case, we follow the links to setup the args instead of executing by code. */
        UField* PropertyChainForCompiledIn;

        /** Currently executed native function */
        UFunction* CurrentNativeFunction;

        bool bArrayContextFailed;
    };

    struct RC_UE_API FFrame
    {
        UFunction* Node();
        UObject* Object();
        uint8_t* Code();
        uint8_t* Locals();
        UProperty* MostRecentProperty();
        uint8_t* MostRecentPropertyAddress();
        uint8* MostRecentPropertyContainer();
        FlowStackTypePtr FlowStack();
        FFrame* PreviousFrame();
        FOutParmRec* OutParms();
        UField* PropertyChainForCompiledIn();
        UFunction* CurrentNativeFunction();
        bool bArrayContextFailed();
    };
}

#endif //RC_UNREAL_FFRAME_HPP
