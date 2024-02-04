#ifndef RC_UNREAL_CONTAINERS_FWD_HPP
#define RC_UNREAL_CONTAINERS_FWD_HPP

namespace RC::Unreal
{
    template<int IndexSize>
    class TSizedDefaultAllocator;
    using FDefaultAllocator = TSizedDefaultAllocator<32>;

    template<typename T, typename Allocator = FDefaultAllocator>
    class TArray;
}

#endif //RC_UNREAL_CONTAINERS_FWD_HPP
