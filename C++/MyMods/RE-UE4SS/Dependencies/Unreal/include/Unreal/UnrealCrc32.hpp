#ifndef RC_UNREAL_UNREALCRC32_H
#define RC_UNREAL_UNREALCRC32_H

#include <Unreal/Common.hpp>
#include <cstdint>
#include <cctype>
#include <type_traits>

NS_RC_UE_START;

/**
 * CRC hash generation for different types of input data
 **/
struct RC_UE_API FCrc {
    /** lookup table with precalculated CRC values - slicing by 8 implementation */
    static uint32_t CRCTablesSB8[8][256];

    /** generates CRC hash of the memory area */
    static uint32_t memcrc32(const void* data, int32_t length, uint32_t CRC = 0);

    /** generates CRC hash of the element */
    template<typename T>
    static uint32_t type_crc32(const T& data, uint32_t CRC = 0) {
        return memcrc32(&data, sizeof(T), CRC);
    }

    /** String CRC. */
    template<typename CharType>
    static typename std::enable_if_t<sizeof(CharType) != 1, uint32_t> strcrc32(const CharType* data, uint32_t CRC = 0) {
        // We ensure that we never try to do a strcrc32 with a CharType of more than 4 bytes.  This is because
        // we always want to treat every CRC as if it was based on 4 byte chars, even if it's less, because we
        // want consistency between equivalent strings with different character types.
        static_assert(sizeof(CharType) <= 4, "strcrc32 only works with CharType up to 32 bits.");

        CRC = ~CRC;
        while (CharType Ch = *data++) {
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC ^ Ch) & 0xFF];
            Ch >>= 8;
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC ^ Ch) & 0xFF];
            Ch >>= 8;
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC ^ Ch) & 0xFF];
            Ch >>= 8;
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC ^ Ch) & 0xFF];
        }
        return ~CRC;
    }

    template<typename CharType>
    static typename std::enable_if_t<sizeof(CharType) == 1, uint32_t> strcrc32(const CharType* data, uint32_t CRC = 0) {
        /* Overload for when CharType is a byte, which causes warnings when right-shifting by 8 */
        CRC = ~CRC;
        while (CharType Ch = *data++) {
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC ^ Ch) & 0xFF];
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC) & 0xFF];
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC) & 0xFF];
            CRC = (CRC >> 8) ^ CRCTablesSB8[0][(CRC) & 0xFF];
        }
        return ~CRC;
    }

    /**
     * DEPRECATED
     * These tables and functions are deprecated because they're using tables and implementations
     * which give values different from what a user of a typical CRC32 algorithm might expect.
     */

    /** lookup table with precalculated CRC values */
    static uint32_t CRCTable_DEPRECATED[256];
    /** lookup table with precalculated CRC values - slicing by 8 implementation */
    static uint32_t CRCTablesSB8_DEPRECATED[8][256];

    /** String CRC. */
    template<typename CharType>
    static inline uint32_t strcrc_deprecated(const CharType* data) {
        uint32_t CRC = 0xFFFFFFFF;
        while (*data) {
            CharType C = *data++;
            int32_t CL = (C & 255);
            CRC = (CRC << 8) ^ CRCTable_DEPRECATED[(CRC >> 24) ^ CL];
            int32_t CH = (C >> 8) & 255;
            CRC = (CRC << 8) ^ CRCTable_DEPRECATED[(CRC >> 24) ^ CH];
        }
        return ~CRC;
    }

    /** String CRC. */
    template<typename CharType>
    static inline uint32_t strcrc_deprecated(const int32_t data_len, const CharType* data) {
        uint32_t CRC = 0xFFFFFFFF;

        for (int32_t i = 0; i < data_len; i++) {
            CharType C = *data++;
            int32_t CL = (C & 255);
            CRC = (CRC << 8) ^ CRCTable_DEPRECATED[(CRC >> 24) ^ CL];
            int32_t CH = (C >> 8) & 255;
            CRC = (CRC << 8) ^ CRCTable_DEPRECATED[(CRC >> 24) ^ CH];
        }
        return ~CRC;
    }

    /** Case insensitive string hash function. */
    template<typename CharType>
    static inline uint32_t strihash_deprecated(const CharType* data);

    template<typename CharType>
    static inline uint32_t strihash_deprecated(const int32_t data_len, const CharType* data);

    /** generates CRC hash of the memory area */
    static uint32_t memcrc_deprecated(const void* data, int32_t data_length, uint32_t CRC = 0);
};

template <>
inline uint32_t FCrc::strihash_deprecated(const char* data)
{
    uint32_t hash = 0;
    while(*data)
    {
        char Ch = toupper(*data++);
        uint8_t B = Ch;
        hash = ((hash >> 8) & 0x00FFFFFF) ^ CRCTable_DEPRECATED[(hash ^ B) & 0x000000FF];
    }
    return hash;
}

template <>
inline uint32_t FCrc::strihash_deprecated(const int32_t data_len, const char* data)
{
    uint32_t hash = 0;
    for (int32_t i = 0; i < data_len; i++)
    {
        char Ch = toupper(*data++);
        uint8_t B = Ch;
        hash = ((hash >> 8) & 0x00FFFFFF) ^ CRCTable_DEPRECATED[(hash ^ B) & 0x000000FF];
    }
    return hash;
}

template <>
inline uint32_t FCrc::strihash_deprecated(const wchar_t* data)
{
    uint32_t hash = 0;
    while(*data)
    {
        wchar_t Ch = towupper(*data++);
        uint16_t B = Ch;
        hash = ((hash >> 8) & 0x00FFFFFF) ^ CRCTable_DEPRECATED[(hash ^ B) & 0x000000FF];
        B = Ch>>8;
        hash = ((hash >> 8) & 0x00FFFFFF) ^ CRCTable_DEPRECATED[(hash ^ B) & 0x000000FF];
    }
    return hash;
}

template <>
inline uint32_t FCrc::strihash_deprecated(const int32_t data_len, const wchar_t* data)
{
    uint32_t hash = 0;
    for (int32_t i = 0; i < data_len; i++)
    {
        wchar_t Ch = towupper(*data++);
        uint16_t B = Ch;
        hash = ((hash >> 8) & 0x00FFFFFF) ^ CRCTable_DEPRECATED[(hash ^ B) & 0x000000FF];
        B = Ch>>8;
        hash = ((hash >> 8) & 0x00FFFFFF) ^ CRCTable_DEPRECATED[(hash ^ B) & 0x000000FF];
    }
    return hash;
}

NS_RC_UE_END;

#endif //RC_UNREAL_UNREALCRC32_H
