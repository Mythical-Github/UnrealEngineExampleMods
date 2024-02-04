#ifndef RC_UNREAL_TPAIR_HPP
#define RC_UNREAL_TPAIR_HPP

namespace RC::Unreal
{
    template<typename KeyType, typename ValueType>
    struct TTuple
    {
        KeyType Key;
        ValueType Value;
    };

    template<typename KeyType, typename ValueType>
    using TPair = TTuple<KeyType, ValueType>;
}

#endif //RC_UNREAL_TPAIR_HPP
