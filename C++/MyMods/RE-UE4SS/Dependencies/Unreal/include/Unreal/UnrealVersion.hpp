#ifndef RC_UNREAL_UNREAL_VERSION_HPP
#define RC_UNREAL_UNREAL_VERSION_HPP

#include <cassert>
#include <utility>
#include <format>

#include <Helpers/ASM.hpp>
#include <Helpers/String.hpp>
#include <File/File.hpp>

#include <Unreal/UObjectGlobals.hpp>

#ifndef UNREAL_VERSION_RUN_TESTS
#define UNREAL_VERSION_RUN_TESTS 0
#endif

namespace RC::Unreal
{
    struct RC_UE_API VersionStatus
    {
        enum StatusCode
        {
            SUCCESS,
            FAILURE,
        };

        std::wstring ErrorMessage{};
        StatusCode Status{};

        VersionStatus() = default;
        VersionStatus(StatusCode StatusParam, std::wstring ErrorMessageParam);
    };

    class RC_UE_API Version
    {
    public:
        static int32_t Major;
        static int32_t Minor;

        auto static Initialize(void* Address) -> VersionStatus;

        [[nodiscard]]
        auto static IsEqual(int32_t major_p, int32_t minor_p) -> bool { return (Major == major_p && Minor == minor_p); }

        [[nodiscard]]
        auto static IsAtLeast(int32_t major_p, int32_t minor_p) -> bool { return ((Major > major_p) || (Major == major_p && Minor >= minor_p)); }

        [[nodiscard]]
        auto static IsAtMost(int32_t major_p, int32_t minor_p) -> bool { return ((Major < major_p) || (Major == major_p && Minor <= minor_p)); }

        [[nodiscard]]
        auto static IsBelow(int32_t major_p, int32_t minor_p) -> bool { return ((Major < major_p) || (Major == major_p && Minor < minor_p)); }

        [[nodiscard]]
        auto static IsAbove(int32_t major_p, int32_t minor_p) -> bool { return ((Major > major_p) || (Major == major_p && Minor > minor_p)); }

#if UNREAL_VERSION_RUN_TESTS == 1
        auto static RunTests() -> void;
#endif
    };
}


#endif //RC_UNREAL_UNREAL_VERSION_HPP
