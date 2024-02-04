#include <Unreal/FMemory.hpp>
#include <Unreal/VersionedContainer/UnrealVirtualImpl/UnrealVirtualBaseVC.hpp>
#include <Unreal/UnrealInitializer.hpp>

namespace RC::Unreal
{
    FMalloc* GMalloc{};
    FMalloc** FMalloc::UnrealStaticGMalloc{};
    std::unordered_map<File::StringType, uint32_t> FMalloc::VTableLayoutMap;

    template<class T>
    static constexpr T Min(const T A, const T B)
    {
        return (A <= B) ? A : B;
    }

    static uint32 CountTrailingZeros(uint32 Value)
    {
        if (Value == 0)
        {
            return 32;
        }
        unsigned long BitIndex;    // 0-based, where the LSB is 0 and MSB is 31
        _BitScanForward(&BitIndex, Value);    // Scans from LSB to MSB
        return BitIndex;
    }

    template<typename T>
    static void Valswap(T& A, T& B)
    {
        T Tmp = A;
        A = B;
        B = Tmp;
    }

    static void MemswapGreaterThan8(void* Ptr1, void* Ptr2, SIZE_T Size)
    {
        using UPTRINT = SIZE_T;

        union PtrUnion
        {
            void* PtrVoid;
            uint8* Ptr8;
            uint16* Ptr16;
            uint32* Ptr32;
            uint64* Ptr64;
            UPTRINT PtrUint;
        };

        PtrUnion Union1 = {Ptr1};
        PtrUnion Union2 = {Ptr2};

        if (Union1.PtrUint & 1)
        {
            Valswap(*Union1.Ptr8++, *Union2.Ptr8++);
            Size -= 1;
        }
        if (Union1.PtrUint & 2)
        {
            Valswap(*Union1.Ptr16++, *Union2.Ptr16++);
            Size -= 2;
        }
        if (Union1.PtrUint & 4)
        {
            Valswap(*Union1.Ptr32++, *Union2.Ptr32++);
            Size -= 4;
        }

        uint32 CommonAlignment = Min(CountTrailingZeros((uint32)(Union1.PtrUint - Union2.PtrUint)), 3u);
        switch (CommonAlignment)
        {
            default:
                for (; Size >= 8; Size -= 8)
                {
                    Valswap(*Union1.Ptr64++, *Union2.Ptr64++);
                }

            case 2:
                for (; Size >= 4; Size -= 4)
                {
                    Valswap(*Union1.Ptr32++, *Union2.Ptr32++);
                }

            case 1:
                for (; Size >= 2; Size -= 2)
                {
                    Valswap(*Union1.Ptr16++, *Union2.Ptr16++);
                }

            case 0:
                for (; Size >= 1; Size -= 1)
                {
                    Valswap(*Union1.Ptr8++, *Union2.Ptr8++);
                }
        }
    }

    void* FMalloc::Malloc(SIZE_T Count, uint32 Alignment)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, Malloc, void*, PARAMS(SIZE_T, uint32), ARGS(Count, Alignment))
    }

    void* FMalloc::TryMalloc(SIZE_T Count, uint32 Alignment)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, TryMalloc, void*, PARAMS(SIZE_T, uint32), ARGS(Count, Alignment))
    }

    void* FMalloc::Realloc(void* Original, SIZE_T Count, uint32 Alignment)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, Realloc, void*, PARAMS(void*, SIZE_T, uint32), ARGS(Original, Count, Alignment))
    }

    void* FMalloc::TryRealloc(void* Original, SIZE_T Count, uint32 Alignment)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, TryRealloc, void*, PARAMS(void*, SIZE_T, uint32), ARGS(Original, Count, Alignment))
    }

    void FMalloc::Free(void* Original)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, Free, void, PARAMS(void*), ARGS(Original))
    }

    SIZE_T FMalloc::QuantizeSize(SIZE_T Count, uint32 Alignment)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, QuantizeSize, SIZE_T, PARAMS(SIZE_T, uint32), ARGS(Count, Alignment))
    }

    bool FMalloc::GetAllocationSize(void* Original, SIZE_T& SizeOut)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, GetAllocationSize, bool, PARAMS(void*, SIZE_T&), ARGS(Original, SizeOut))
    }

    void FMalloc::Trim(bool bTrimThreadCaches)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, Trim, void, PARAMS(bool), ARGS(bTrimThreadCaches))
    }

    void FMalloc::SetupTLSCachesOnCurrentThread()
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, SetupTLSCachesOnCurrentThread, void)
    }

    void FMalloc::ClearAndDisableTLSCachesOnCurrentThread()
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, ClearAndDisableTLSCachesOnCurrentThread, void)
    }

    void FMalloc::InitializeStatsMetadata()
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, InitializeStatsMetadata, void)
    }

    void FMalloc::UpdateStats()
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, UpdateStats, void)
    }

    void FMalloc::GetAllocatorStats(FGenericMemoryStats& out_Stats)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, GetAllocatorStats, void, PARAMS(FGenericMemoryStats&), ARGS(out_Stats))
    }

    void FMalloc::DumpAllocatorStats(class FOutputDevice& Ar)
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FMalloc, DumpAllocatorStats, void, PARAMS(FOutputDevice&), ARGS(Ar))
    }

    bool FMalloc::IsInternallyThreadSafe() const
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, IsInternallyThreadSafe, bool)
    }

    bool FMalloc::ValidateHeap()
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, ValidateHeap, bool)
    }

    const TCHAR* FMalloc::GetDescriptiveName()
    {
        IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FMalloc, GetDescriptiveName, const TCHAR*)
    }

    static void* Memmove(void* Dest, const void* Src, SIZE_T Count)
    {
        return std::memmove(Dest, Src, Count);
    }

    void* FMemory::Memzero(void* Dest, SIZE_T Count)
    {
        return std::memset(Dest, 0, Count);
    }

    void* FMemory::Malloc(SIZE_T Count, uint32 Alignment)
    {
        if (!GMalloc || !UnrealInitializer::StaticStorage::bVersionedContainerIsInitialized)
        {
            throw std::runtime_error{"Tried to call 'FMemory::Malloc' before the FMalloc instance was found"};
        }

        return GMalloc->Malloc(Count, Alignment);
    }

    void FMemory::Free(void* Original)
    {
        if (!GMalloc || !UnrealInitializer::StaticStorage::bVersionedContainerIsInitialized) { return; }

        GMalloc->Free(Original);
    }

    void* FMemory::Realloc(void* Original, SIZE_T Count, uint32 Alignment)
    {
        if (!GMalloc || !UnrealInitializer::StaticStorage::bVersionedContainerIsInitialized)
        {
            throw std::runtime_error{"Tried to call 'FMemory::Realloc' before the FMalloc instance was found"};
        }

        return GMalloc->Realloc(Original, Count, Alignment);
    }

    void* FMemory::Memcpy(void* Dest, const void* Src, SIZE_T Count)
    {
        return std::memcpy(Dest, Src, Count);
    }

    static void Memswap(void* Ptr1, void* Ptr2, SIZE_T Size)
    {
        switch (Size)
        {
            case 0:
                break;

            case 1:
                Valswap(*(uint8*)Ptr1, *(uint8*)Ptr2);
                break;

            case 2:
                Valswap(*(uint16*)Ptr1, *(uint16*)Ptr2);
                break;

            case 3:
                Valswap(*((uint16*&)Ptr1)++, *((uint16*&)Ptr2)++);
                Valswap(*(uint8*)Ptr1, *(uint8*)Ptr2);
                break;

            case 4:
                Valswap(*(uint32*)Ptr1, *(uint32*)Ptr2);
                break;

            case 5:
                Valswap(*((uint32*&)Ptr1)++, *((uint32*&)Ptr2)++);
                Valswap(*(uint8*)Ptr1, *(uint8*)Ptr2);
                break;

            case 6:
                Valswap(*((uint32*&)Ptr1)++, *((uint32*&)Ptr2)++);
                Valswap(*(uint16*)Ptr1, *(uint16*)Ptr2);
                break;

            case 7:
                Valswap(*((uint32*&)Ptr1)++, *((uint32*&)Ptr2)++);
                Valswap(*((uint16*&)Ptr1)++, *((uint16*&)Ptr2)++);
                Valswap(*(uint8*)Ptr1, *(uint8*)Ptr2);
                break;

            case 8:
                Valswap(*(uint64*)Ptr1, *(uint64*)Ptr2);
                break;

            case 16:
                Valswap(((uint64*)Ptr1)[0], ((uint64*)Ptr2)[0]);
                Valswap(((uint64*)Ptr1)[1], ((uint64*)Ptr2)[1]);
                break;

            default:
                MemswapGreaterThan8(Ptr1, Ptr2, Size);
                break;
        }
    }

    SIZE_T FMemory::QuantizeSize(SIZE_T Count, uint32 Alignment)
    {
        if (!GMalloc || !UnrealInitializer::StaticStorage::bVersionedContainerIsInitialized)
        {
            return Count;
        }

        return GMalloc->QuantizeSize(Count, Alignment);
    }
}
