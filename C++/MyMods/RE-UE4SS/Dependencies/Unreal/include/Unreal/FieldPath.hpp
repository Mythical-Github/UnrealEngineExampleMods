#ifndef RC_UNREAL_FIELD_PATH_HPP
#define RC_UNREAL_FIELD_PATH_HPP

#include <Unreal/FWeakObjectPtr.hpp>

namespace RC::Unreal
{
    struct RC_UE_API FFieldPath
    {
        mutable FField* ResolvedField = nullptr;
        mutable /*TWeakObjectPtr<UStruct>*/FWeakObjectPtr ResolvedOwner;
        TArray<FName> Path;
    };

    template<typename T>
    struct TFieldPath : public FFieldPath
    {

    };
}

#endif // RC_UNREAL_FIELD_PATH_HPP