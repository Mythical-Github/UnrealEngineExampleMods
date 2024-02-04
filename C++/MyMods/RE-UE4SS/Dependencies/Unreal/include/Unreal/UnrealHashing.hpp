#ifndef RC_UNREAL_UNREALHASHING_H
#define RC_UNREAL_UNREALHASHING_H

#include <Unreal/Common.hpp>
#include <cstdlib>
#include <type_traits>
#include <Unreal/UnrealHashing.hpp>

/**
 * Combines two hash values to get a third.
 * Note - this function is not commutative.
 */
inline uint32_t hash_combine(uint32_t A, uint32_t C)
{
    uint32_t B = 0x9e3779b9;
    A += B;

    A -= B; A -= C; A ^= (C>>13);
    B -= C; B -= A; B ^= (A<<8);
    C -= A; C -= B; C ^= (B>>13);
    A -= B; A -= C; A ^= (C>>12);
    B -= C; B -= A; B ^= (A<<16);
    C -= A; C -= B; C ^= (B>>5);
    A -= B; A -= C; A ^= (C>>3);
    B -= C; B -= A; B ^= (A<<10);
    C -= A; C -= B; C ^= (B>>15);

    return C;
}


inline uint32_t pointer_hash(const void* key, uint32_t C = 0)
{
    // Ignoring the lower 4 bits since they are likely zero anyway.
	// Higher bits are more significant in 64 bit builds.
	auto ptr_int = reinterpret_cast<uintptr_t>(key) >> 4;
    return hash_combine((uint32_t) ptr_int, C);
}

//
// Hash functions for common types.
//

inline uint32_t get_type_hash(const uint8_t A)
{
    return A;
}

inline uint32_t get_type_hash(const int8_t A)
{
    return A;
}

inline uint32_t get_type_hash(const uint16_t A)
{
    return A;
}

inline uint32_t get_type_hash(const int16_t A)
{
    return A;
}

inline uint32_t get_type_hash(const int32_t A)
{
    return A;
}

inline uint32_t get_type_hash(const uint32_t A)
{
    return A;
}

inline uint32_t get_type_hash(const uint64_t A)
{
    return (uint32_t)A+((uint32_t)(A>>32) * 23);
}

inline uint32_t get_type_hash(const int64_t A)
{
    return (uint32_t)A+((uint32_t)(A>>32) * 23);
}

inline uint32_t get_type_hash(float Value)
{
    return *(uint32_t*)&Value;
}

inline uint32_t get_type_hash(double Value)
{
    return get_type_hash(*(uint64_t*)&Value);
}

// Uncomment when we have an implementation of 'FCrc'
/*
inline uint32_t get_type_hash(const wchar_t* S)
{
    return FCrc::strihash_deprecated(S);
}
//*/

inline uint32_t get_type_hash(const void* A)
{
    return pointer_hash(A);
}

inline uint32_t get_type_hash(void* A)
{
    return pointer_hash(A);
}

template<typename EnumType>
FORCEINLINE std::enable_if_t<std::is_enum_v<EnumType>, uint32_t> get_type_hash(EnumType E)
{
    return get_type_hash((__underlying_type(EnumType))E);
}

#endif //RC_UNREAL_UNREALHASHING_H
