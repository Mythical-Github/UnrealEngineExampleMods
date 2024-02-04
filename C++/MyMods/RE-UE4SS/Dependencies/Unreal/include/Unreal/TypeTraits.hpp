#ifndef RC_UNREAL_TYPETRAITS_HPP
#define RC_UNREAL_TYPETRAITS_HPP

#include <type_traits>

namespace RC::Unreal
{
    template<typename A, typename B>
    struct TAreTypesEqual
    {
        static constexpr bool Value = std::is_same_v<A, B>;
    };

    template<typename T>
    struct TIsTriviallyDestructible
    {
        static constexpr bool Value = std::is_trivially_constructible_v<T>;
    };
}

#endif //RC_UNREAL_TYPETRAITS_HPP
