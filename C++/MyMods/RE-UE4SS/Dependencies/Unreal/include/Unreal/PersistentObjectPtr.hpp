#ifndef RC_UNREAL_PERSISTENTOBJECTPTR_HPP
#define RC_UNREAL_PERSISTENTOBJECTPTR_HPP

#include <Unreal/UnrealCoreStructs.hpp>
#include <Unreal/FWeakObjectPtr.hpp>

namespace RC::Unreal
{
    template<class TObjectID>
    struct TPersistentObjectPtr
    {
        mutable FWeakObjectPtr WeakPtr;
        mutable int32 TagAtLastTest;
        TObjectID ObjectID;
    };

    struct FUniqueObjectGuid
    {
        FGuid Guid;
    };
}

#endif //RC_UNREAL_PERSISTENTOBJECTPTR_HPP
