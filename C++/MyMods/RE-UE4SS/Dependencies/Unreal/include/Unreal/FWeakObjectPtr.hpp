#ifndef RC_UNREAL_FWEAKOBJECTPTR_HPP
#define RC_UNREAL_FWEAKOBJECTPTR_HPP

#include <cstdint>

#include <Unreal/Common.hpp>

namespace RC::Unreal
{
    struct RC_UE_API FWeakObjectPtr
    {
    private:
        // Why does this case this error: "error C2059: syntax error: '-'"
        //constexpr static int32_t INDEX_NONE = -1;

        int32_t ObjectIndex{};
        int32_t ObjectSerialNumber{};

        auto InternalGetObjectItem() const -> struct FUObjectItem*;
        auto InternalGet(bool bEvenIfPendingKill) const -> class UObject*;
        auto Reset() -> void;

    public:
        auto operator=(class UObject*) -> void;

    public:
        auto SerialNumbersMatch(struct FUObjectItem*) const -> bool;
        auto Get() const -> class UObject*;
    };

    template<class T=UObject, class TWeakObjectPtrBase=FWeakObjectPtr>
    struct TWeakObjectPtr;

    template<class T, class TWeakObjectPtrBase>
    struct TWeakObjectPtr : private TWeakObjectPtrBase
    {

    };
}


#endif //RC_UNREAL_FWEAKOBJECTPTR_HPP
