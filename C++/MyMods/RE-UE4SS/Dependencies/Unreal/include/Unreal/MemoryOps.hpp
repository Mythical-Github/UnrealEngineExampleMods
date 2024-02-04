#ifndef RC_UNREAL_MEMORY_OPS_HPP
#define RC_UNREAL_MEMORY_OPS_HPP

#include <Unreal/TypeTraits.hpp>

namespace RC::Unreal
{
    template <typename ElementType, typename SizeType>
    FORCEINLINE void DestructItems(ElementType* Element, SizeType Count)
    {
        if constexpr (!TIsTriviallyDestructible<ElementType>::Value)
        {
            while (Count)
            {
                // We need a typedef here because VC won't compile the destructor call below if ElementType itself has a member called ElementType
                typedef ElementType DestructItemsElementTypeTypedef;

                Element->DestructItemsElementTypeTypedef::~DestructItemsElementTypeTypedef();
                ++Element;
                --Count;
            }
        }
    }
}

#endif //RC_UNREAL_MEMORY_OPS_HPP
