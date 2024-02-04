#ifndef RC_UNREAL_FMEMORY_HPP
#define RC_UNREAL_FMEMORY_HPP

#include <unordered_map>

#include <Function/Function.hpp>
#include <Unreal/Common.hpp>
#include <Unreal/PrimitiveTypes.hpp>

/*
 * How GMalloc gets created:
 * 1. UnrealMemory.cpp -> FMemory_GCreateMalloc_ThreadUnsafe()
 * 2.     It sets GMalloc to:
 * 3. WindowsPlatformMemory.cpp -> FWindowsPlatformMemory::BaseAllocator()
 * 4. It selects Binned2
 * 5. It uses 'new' to create an instance of 'FMallocBinned2' and returns it
 */

namespace RC::Unreal
{
    struct FGenericMemoryStats;

    namespace UnrealInitializer
    {
        struct Config;
        struct CacheInfo;
        RC_UE_API auto CreateCache(UnrealInitializer::CacheInfo& Target) -> void;
        RC_UE_API auto LoadCache(UnrealInitializer::CacheInfo& Target) -> void;
    }

    namespace Signatures
    {
        struct ScanResult;
        RC_UE_API auto ScanForGUObjectArrayImpl(const UnrealInitializer::Config&) -> ScanResult;
    }

    class RC_UE_API FMalloc
    {
    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    private:
        friend Signatures::ScanResult Signatures::ScanForGUObjectArrayImpl(const UnrealInitializer::Config&);
        friend RC_UE_API void UnrealInitializer::CreateCache(UnrealInitializer::CacheInfo&);
        friend RC_UE_API void UnrealInitializer::LoadCache(UnrealInitializer::CacheInfo&);

    public:
        static FMalloc** UnrealStaticGMalloc;

    public:
        void* Malloc(SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
        void* TryMalloc(SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
        void* Realloc(void* Original, SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
        void* TryRealloc(void* Original, SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
        void Free(void* Original);
        SIZE_T QuantizeSize(SIZE_T Count, uint32 Alignment);
        bool GetAllocationSize(void* Original, SIZE_T& SizeOut);
        void Trim(bool bTrimThreadCaches);
        void SetupTLSCachesOnCurrentThread();
        void ClearAndDisableTLSCachesOnCurrentThread();
        void InitializeStatsMetadata();
        void UpdateStats();
        void GetAllocatorStats(FGenericMemoryStats& out_Stats);
        void DumpAllocatorStats(class FOutputDevice& Ar);
        bool IsInternallyThreadSafe() const;
        bool ValidateHeap();
        const TCHAR* GetDescriptiveName();
    };

    RC_UE_API extern FMalloc* GMalloc;

    class RC_UE_API FMemory
    {
    public:
        //static void* Memmove(void* Dest, const void* Src, SIZE_T Count);
        static void* Memzero(void* Dest, SIZE_T Count);
        static void* Malloc(SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
        static void* Realloc(void* Original, SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
        static void Free(void* Original);
        static void* Memcpy(void* Dest, const void* Src, SIZE_T Count);
        //static void Memswap(void* Ptr1, void* Ptr2, SIZE_T Size);
        static SIZE_T QuantizeSize(SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);

        // TODO: Implement if we need them
        //void static memmove(void* dest, void* src, size_t size);
        //void static memset(void* src, char value, size_t size);
        //void static memcpy(void* dest, const void* src, size_t size);
        //int static memcmp(const void* first, const void* second, size_t size);
    };
}

#endif //RC_UNREAL_FMEMORY_HPP
