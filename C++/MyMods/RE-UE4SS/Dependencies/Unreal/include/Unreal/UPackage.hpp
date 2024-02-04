#ifndef RC_UNREAL_UPACKAGE_HPP
#define RC_UNREAL_UPACKAGE_HPP

#include <Unreal/UObject.hpp>

namespace RC::Unreal
{
    class RC_UE_API UPackage : public UObject
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UPackage, CoreUObject)
    public:
        // Placeholder for now, but is there even anything inside that would be useful ?
        // It's needed regardless because it's used in a few places but not in any way that's different to a UObject
    };
}


#endif //RC_UNREAL_UPACKAGE_HPP
