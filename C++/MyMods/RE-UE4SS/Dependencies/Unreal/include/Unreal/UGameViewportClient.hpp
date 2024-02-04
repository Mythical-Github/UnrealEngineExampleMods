#ifndef RC_UNREAL_UGAMEVIEWPORTCLIENT_HPP
#define RC_UNREAL_UGAMEVIEWPORTCLIENT_HPP

#include <Unreal/UObject.hpp>

namespace RC::Unreal
{
    // NOTE: The inheritance for this class is not correct.
    //       But for now it will work as we only need this in the context of a regular UObject
    //       This may need to change in the future if we want access to the "Exec" virtual function
    class RC_UE_API UGameViewportClient : public UObject
    {
    DECLARE_EXTERNAL_OBJECT_CLASS(UGameViewportClient, Engine);

    public:

    };
}

#endif // RC_UNREAL_UGAMEVIEWPORTCLIENT_HPP