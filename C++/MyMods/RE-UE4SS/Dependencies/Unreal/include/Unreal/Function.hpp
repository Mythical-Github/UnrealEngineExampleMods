#ifndef RC_UNREAL_FUNCTION_HPP
#define RC_UNREAL_FUNCTION_HPP

#define NUM_TFUNCTION_INLINE_BYTES 32
#define TFUNCTION_INLINE_SIZE         NUM_TFUNCTION_INLINE_BYTES
#define TFUNCTION_INLINE_ALIGNMENT    16

#include <Unreal/TypeCompatibleBytes.hpp>

namespace RC::Unreal
{
    struct FFunctionStorage
    {
        void* HeapAllocation;
        TAlignedBytes<TFUNCTION_INLINE_SIZE, TFUNCTION_INLINE_ALIGNMENT> InlineAllocation;
    };

    // A temporary placeholder implementation that assumes:
    // TFunction == class TFunction final : public UE::Core::Private::Function::TFunctionRefBase<UE::Core::Private::Function::TFunctionStorage<false>, FuncType>
    template<typename T>
    class TFunction
    {
    private:
        void* TempFuncPtr{};
        FFunctionStorage TempStorage{};

    public:
        TFunction() = default;
    };
}

#endif //RC_UNREAL_FUNCTION_HPP
