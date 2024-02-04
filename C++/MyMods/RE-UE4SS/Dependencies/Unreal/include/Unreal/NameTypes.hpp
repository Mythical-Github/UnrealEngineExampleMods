#ifndef RC_UNREAL_NAMETYPES_HPP
#define RC_UNREAL_NAMETYPES_HPP

#include <string>

#include <Function/Function.hpp>
#include <Unreal/Common.hpp>
#include <Unreal/PrimitiveTypes.hpp>

#define INVALID_LONGPACKAGE_CHARACTERS TEXT("\\:*?\"<>|' ,.&!~\n\r\t@#")

namespace RC::Unreal
{
    namespace UnrealInitializer
    {
        struct CacheInfo;
        RC_UE_API auto CreateCache(UnrealInitializer::CacheInfo& Target) -> void;
    }

    enum {NAME_SIZE	= 1024};

    enum EFindName
    {
        FNAME_Find,
        FNAME_Add,
        FNAME_Replace_Not_Safe_For_Threading
    };

    // TODO:   Figure out what's going on here
    //         It shouldn't be required to use 'alignas' here to make sure it's aligned properly in containers (like TArray)
    //         I've never seen an FName not be 8-byte aligned in memory,
    //         but it is 4-byte aligned in the source so hopefully this doesn't cause any problems
    // UPDATE: This matters in the UE VM, when ElementSize is 0xC in memory for case-preserving games, it must be aligned by 0x4 in that case
#pragma warning(disable: 4324) // Suppressing warning about struct alignment
#ifdef WITH_CASE_PRESERVING_NAME
    struct alignas(4) RC_UE_API FName
#else
    struct alignas(8) RC_UE_API FName
#endif
    {
    private:
        friend RC_UE_API auto UnrealInitializer::CreateCache(UnrealInitializer::CacheInfo& Target) -> void;

        uint32_t ComparisonIndex{};
#ifdef WITH_CASE_PRESERVING_NAME
        uint32_t DisplayIndex{};
#endif
        uint32_t Number{};

    public:
        static Function<void(const FName*, class FStringOut&)> ToStringInternal;
        static Function<FName(const wchar_t*, EFindName)> ConstructorInternal;

    private:
        auto construct_with_string(const wchar_t* StrName, EFindName FindType, void* FunctionAddressOverride) -> void
        {
            if (!ConstructorInternal.is_ready() && !FunctionAddressOverride) { return; }

            // Assign the temporary address if one exists
            if (FunctionAddressOverride) { ConstructorInternal.assign_temp_address(FunctionAddressOverride); }

            FName Name = ConstructorInternal(StrName, FindType);
            ComparisonIndex = Name.ComparisonIndex;
#ifdef WITH_CASE_PRESERVING_NAME
            DisplayIndex = Name.DisplayIndex;
#endif
            Number = Name.Number;

            // Reset the address to what it was before it was overridden by a temporary address
            if (FunctionAddressOverride) { ConstructorInternal.reset_address(); }
        }

        auto construct_with_string(const wchar_t* Name, uint32 InNumber, EFindName FindType, void* FunctionAddressOverride) -> void
        {
            construct_with_string(Name, FindType, FunctionAddressOverride);
            Number = InNumber;
        }

    public:
        FName() = default;

        // Construct from an existing FName without looking up
        // Safe to pass to Unreal Engine internals
        // Not safe to use for return values from Unreal Engine internals
        explicit constexpr FName(int64_t IndexAndNumber)
        {
            // Split the 64-bit integer into two 32-bit integers
            Number = (IndexAndNumber & 0xFFFFFFFF00000000LL) >> 32;
            ComparisonIndex = (IndexAndNumber & 0xFFFFFFFFLL);
#ifdef WITH_CASE_PRESERVING_NAME
            DisplayIndex = ComparisonIndex;
#endif
        }

        // Construct from an existing FName without looking up
        // Safe to pass to Unreal Engine internals
        // Not safe to use for return values from Unreal Engine internals
        explicit constexpr FName(uint32_t IndexParam, uint32_t NumberParam)
        {
            ComparisonIndex = IndexParam;
#ifdef WITH_CASE_PRESERVING_NAME
            DisplayIndex = IndexParam;
#endif
            Number = NumberParam;
        }

#ifdef WITH_CASE_PRESERVING_NAME
        // Construct from an existing FName without looking up
        // Safe to pass to Unreal Engine internals
        // Not safe to use for return values from Unreal Engine internals
        explicit FName(uint32_t IndexParam, uint32_t DisplayIndexParam, uint32_t NumberParam)
        {
            ComparisonIndex = IndexParam;
            DisplayIndex = DisplayIndexParam;
            Number = NumberParam;
        }
#endif

        // Lookup & create from an existing FName
        // Not safe to pass to Unreal Engine internals
        // Safe to use for return values from Unreal Engine internals
        explicit FName(const wchar_t* StrName, EFindName FindType = FNAME_Find, void* FunctionAddressOverride = nullptr)
        {
            construct_with_string(StrName, FindType, FunctionAddressOverride);
        }

        explicit FName(std::wstring_view str_name, EFindName FindType = FNAME_Find, void* FunctionAddressOverride = nullptr)
        {
            construct_with_string(str_name.data(), FindType, FunctionAddressOverride);
        }

        explicit FName(std::wstring_view Name, uint32 InNumber, EFindName FindType = FNAME_Find, void* FunctionAddressOverride = nullptr)
        {
            construct_with_string(Name.data(), InNumber, FindType, FunctionAddressOverride);
        }

        auto inline operator==(FName other) const -> bool
        {
            return (ComparisonIndex == other.ComparisonIndex) & (Number == other.Number);
        }

        auto inline operator==(const wchar_t* Other) -> bool
        {
            return ToString() == Other;
        }

        auto inline operator!=(FName Other) const -> bool
        {
            return !(*this == Other);
        }

        auto inline operator!() const -> bool
        {
            return ComparisonIndex == 0 && Number == 0;
        }

        // Returns whether the ComparisonIndex is equal
        // Use this when you don't care for an identical match
        // The operator overloads will make sure both ComparisonIndex and Number are equal
        [[nodiscard]] auto Equals(const FName& Other) const -> bool
        {
            return ComparisonIndex == Other.ComparisonIndex;
        }

        auto ToString() -> std::wstring;
        auto ToString() const -> const std::wstring;
        uint32 GetPlainNameString(TCHAR(&OutName)[NAME_SIZE]);

        [[nodiscard]] auto GetComparisonIndex() const -> uint32_t { return ComparisonIndex; }
        [[nodiscard]] auto GetDisplayIndex() const -> uint32_t
        {
#ifdef WITH_CASE_PRESERVING_NAME
            return DisplayIndex;
#else
            return ComparisonIndex;
#endif
        }
        [[nodiscard]] auto GetNumber() const -> uint32_t { return Number; }
    };
#pragma warning(default: 4324)

    static constexpr FName NAME_None = FName(0, 0);
}

namespace std
{
    template<>
    struct hash<RC::Unreal::FName>
    {
        auto operator()(const RC::Unreal::FName& name) const -> size_t
        {
            size_t ComparisonIndexHash = hash<uint32_t>()(name.GetComparisonIndex());
            size_t NumberHash = hash<uint32_t>()(name.GetNumber());
            return ComparisonIndexHash ^ NumberHash;
        }
    };
}

#endif //RC_UNREAL_NAMETYPES_HPP
