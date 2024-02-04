#include <Unreal/FFrame.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <stdexcept>

namespace RC::Unreal
{
    UFunction* FFrame::Node()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->Node;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->Node;
        }
    }

    UObject* FFrame::Object()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->Object;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->Object;
        }
    }

    uint8_t* FFrame::Code()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->Code;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->Code;
        }
    }

    uint8_t* FFrame::Locals()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->Locals;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->Locals;
        }
    }

    UProperty* FFrame::MostRecentProperty()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->MostRecentProperty;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->MostRecentProperty;
        }
    }

    uint8_t* FFrame::MostRecentPropertyAddress()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->MostRecentPropertyAddress;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->MostRecentPropertyAddress;
        }
    }

    uint8* FFrame::MostRecentPropertyContainer()
    {
        if (Version::IsBelow(5, 1))
        {
            throw std::runtime_error{"FFrame::MostRecentPropertyContainer doesn't exist in <=5.0."};
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->MostRecentPropertyContainer;
        }
    }

    FlowStackTypePtr FFrame::FlowStack()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->FlowStack;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->FlowStack;
        }
    }

    FFrame* FFrame::PreviousFrame()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame*>(std::bit_cast<FFrame_50_AndBelow*>(this)->PreviousFrame);
        }
        else
        {
            return std::bit_cast<FFrame*>(std::bit_cast<FFrame_51_AndAbove*>(this)->PreviousFrame);
        }
    }

    FOutParmRec* FFrame::OutParms()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->OutParms;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->OutParms;
        }
    }

    UField* FFrame::PropertyChainForCompiledIn()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->PropertyChainForCompiledIn;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->PropertyChainForCompiledIn;
        }
    }

    UFunction* FFrame::CurrentNativeFunction()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->CurrentNativeFunction;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->CurrentNativeFunction;
        }
    }

    bool FFrame::bArrayContextFailed()
    {
        if (Version::IsBelow(5, 1))
        {
            return std::bit_cast<FFrame_50_AndBelow*>(this)->bArrayContextFailed;
        }
        else
        {
            return std::bit_cast<FFrame_51_AndAbove*>(this)->bArrayContextFailed;
        }
    }

}
