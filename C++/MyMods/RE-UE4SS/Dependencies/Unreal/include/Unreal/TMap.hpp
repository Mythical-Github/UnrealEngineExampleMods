#ifndef RC_UNREAL_TMAP_HPP
#define RC_UNREAL_TMAP_HPP

#include <Constructs/Loop.hpp>

#include <Unreal/Common.hpp>
#include <Unreal/TypeChecker.hpp>
#include <Unreal/VersionedContainer/Base.hpp>
#include <Unreal/Property/FMapProperty.hpp>

namespace RC::Unreal
{
    template<typename MapInnerKeyType, typename MapInnerValueType>
    class TMapElement
    {
    public:
        MapInnerKeyType Key;
        MapInnerValueType Value;
        int64_t Padding; // Figure out what this is later
    };

    template<typename MapInnerKeyType, typename MapInnerValueType>
    class TMap
    {
    public:
        static constexpr InternalType InternalType = InternalType::Map;
        using MapElement = TMapElement<MapInnerKeyType, MapInnerValueType>;

    protected:
        MapElement* Elements{};
        int32_t MapNum{};
        int32_t MapMax{};

    public:
        TMap(MapElement* ElementsPtr, int32_t CurrentSize, int32_t Capacity) : Elements(ElementsPtr), MapNum(CurrentSize), MapMax(Capacity) {}

    protected:
        template<typename Callable>
        auto ForEach(Callable Callable_) -> void
        {
            if (!Elements) { return; }

            for (int32_t i = 0; i < Num(); ++i)
            {
                if (Callable_(&Elements[i]) == LoopAction::Break)
                {
                    break;
                }
            }
        }

    public:
        auto Num() -> int32_t
        {
            return MapNum;
        }

        auto Max() -> int32_t
        {
            return MapMax;
        }

        auto GetElementsPtr() -> MapElement*
        {
            return Elements;
        }

        auto At(MapInnerKeyType Key) -> MapInnerValueType*
        {
            // Map is empty, figure out what to do here
            if (Num() == 0)
            {

            }

            MapInnerValueType* FoundValue{};

            ForEach([&](MapElement* Element) {
                if (Element->Key == Key)
                {
                    FoundValue = &Element->Value;
                    return LoopAction::Break;
                }
                else
                {
                    return LoopAction::Continue;
                }
            });

            return FoundValue;
        }

        auto operator[](MapInnerKeyType Key) -> MapInnerValueType*
        {
            return static_cast<MapInnerValueType*>(At(Key));
        }
    };
}


#endif //RC_UNREAL_TMAP_HPP
