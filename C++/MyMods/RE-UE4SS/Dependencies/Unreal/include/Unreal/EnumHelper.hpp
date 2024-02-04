#ifndef RC_UNREAL_ENUMHELPER_H
#define RC_UNREAL_ENUMHELPER_H

// Defines all bitwise operators for enum classes so it can be (mostly) used as a regular flags enum
#define ENUM_CLASS_FLAGS(Enum) \
	inline           Enum& operator|=(Enum& Lhs, Enum Rhs) { return Lhs = (Enum)((__underlying_type(Enum))Lhs | (__underlying_type(Enum))Rhs); } \
	inline           Enum& operator&=(Enum& Lhs, Enum Rhs) { return Lhs = (Enum)((__underlying_type(Enum))Lhs & (__underlying_type(Enum))Rhs); } \
	inline           Enum& operator^=(Enum& Lhs, Enum Rhs) { return Lhs = (Enum)((__underlying_type(Enum))Lhs ^ (__underlying_type(Enum))Rhs); } \
	inline constexpr Enum  operator| (Enum  Lhs, Enum Rhs) { return (Enum)((__underlying_type(Enum))Lhs | (__underlying_type(Enum))Rhs); } \
	inline constexpr Enum  operator& (Enum  Lhs, Enum Rhs) { return (Enum)((__underlying_type(Enum))Lhs & (__underlying_type(Enum))Rhs); } \
	inline constexpr Enum  operator^ (Enum  Lhs, Enum Rhs) { return (Enum)((__underlying_type(Enum))Lhs ^ (__underlying_type(Enum))Rhs); } \
	inline constexpr bool  operator! (Enum  E)             { return !(__underlying_type(Enum))E; } \
	inline constexpr Enum  operator~ (Enum  E)             { return (Enum)~(__underlying_type(Enum))E; }

#define ENUM_MAKE_IMMUTABLE(Enum) \
	inline           Enum& operator|=(Enum& Lhs, Enum Rhs) { static_assert(false, "This enum cannot be modified directly"); return Lhs; } \
	inline           Enum& operator&=(Enum& Lhs, Enum Rhs) { static_assert(false, "This enum cannot be modified directly"); return Lhs; } \
	inline           Enum& operator^=(Enum& Lhs, Enum Rhs) { static_assert(false, "This enum cannot be modified directly"); return Lhs; } \
	inline constexpr Enum  operator| (Enum  Lhs, Enum Rhs) { static_assert(false, "This enum cannot be modified directly"); return Lhs; } \
	inline constexpr Enum  operator& (Enum  Lhs, Enum Rhs) { static_assert(false, "This enum cannot be modified directly"); return Lhs; } \
	inline constexpr Enum  operator^ (Enum  Lhs, Enum Rhs) { static_assert(false, "This enum cannot be modified directly"); return Lhs; } \
	inline constexpr bool  operator! (Enum  E)             { static_assert(false, "This enum cannot be modified directly"); return false; } \
	inline constexpr Enum  operator~ (Enum  E)             { static_assert(false, "This enum cannot be modified directly"); return E; }

#endif //RC_UNREAL_ENUMHELPER_H
