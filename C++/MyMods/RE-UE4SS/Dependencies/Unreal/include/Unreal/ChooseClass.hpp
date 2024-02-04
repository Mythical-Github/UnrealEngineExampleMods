#ifndef RC_UNREAL_CHOOSE_CLASS_HPP
#define RC_UNREAL_CHOOSE_CLASS_HPP

namespace RC::Unreal
{
/** Chooses between two different classes based on a boolean. */
    template<bool Predicate, typename TrueClass, typename FalseClass>
    class TChooseClass;

    template<typename TrueClass, typename FalseClass>
    class TChooseClass<true, TrueClass, FalseClass>
    {
    public:
        typedef TrueClass Result;
    };

    template<typename TrueClass, typename FalseClass>
    class TChooseClass<false, TrueClass, FalseClass>
    {
    public:
        typedef FalseClass Result;
    };
}

#endif //RC_UNREAL_CHOOSE_CLASS_HPP
