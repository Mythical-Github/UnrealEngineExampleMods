#ifndef RC_UNREAL_COMMON_HPP
#define RC_UNREAL_COMMON_HPP

namespace RC::Unreal
{
    enum
    {
        // Default allocator alignment. If the default is specified, the allocator applies to engine rules.
        // Blocks >= 16 bytes will be 16-byte-aligned, Blocks < 16 will be 8-byte aligned. If the allocator does
        // not support allocation alignment, the alignment will be ignored.
        DEFAULT_ALIGNMENT = 0,

        // Minimum allocator alignment
        MIN_ALIGNMENT = 8,
    };
}

#define FORCENOINLINE __declspec(noinline)
#define FORCEINLINE __forceinline
#define RESTRICT __restrict

#define NS_RC_UE_START namespace RC::Unreal {
#define NS_RC_UE_END };

#ifndef RC_UNREAL_EXPORTS
#ifndef RC_UNREAL_BUILD_STATIC
#ifndef RC_UE_API
#define RC_UE_API __declspec(dllimport)
#endif
#else
#ifndef RC_UE_API
#define RC_UE_API
#endif
#endif
#else
#ifndef RC_UE_API
#define RC_UE_API __declspec(dllexport)
#endif
#endif

#endif //RC_UNREAL_COMMON_HPP
