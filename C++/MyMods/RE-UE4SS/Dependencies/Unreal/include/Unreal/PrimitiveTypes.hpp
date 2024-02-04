#ifndef RC_UNREAL_PRIMITIVE_TYPES_HPP
#define RC_UNREAL_PRIMITIVE_TYPES_HPP

#include <File/File.hpp>

#ifdef TEXT
#undef TEXT
#endif
#define TEXT STR

namespace RC::Unreal
{
    using uint8 = uint8_t;
    using uint16 = uint16_t;
    using uint32 = uint32_t;
    using uint64 = uint64_t;
    using int8 = int8_t;
    using int16 = int16_t;
    using int32 = int32_t;
    using int64 = int64_t;

    using TCHAR = File::CharType;
    using SIZE_T = size_t;

    // Custom primitives that don't exist in the UE source
    using bool32 = uint32;
    using bool64 = uint64;
}

#endif //RC_UNREAL_PRIMITIVE_TYPES_HPP
