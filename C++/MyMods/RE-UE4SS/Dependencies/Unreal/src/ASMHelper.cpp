#include <bit>

#include <Unreal/ASMHelper.hpp>
#include <DynamicOutput/DynamicOutput.hpp>
#include <Zydis/Zydis.h>

namespace RC::Unreal
{
    void* ResolveFunctionAddressFromPotentialJmp(void* FunctionPtr)
    {
        auto Data = std::bit_cast<ZyanU8*>(FunctionPtr);
        ZydisDecoder Decoder;
        ZydisDecoderInit(&Decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_ADDRESS_WIDTH_64);
        ZyanU64 RuntimeAddress = std::bit_cast<ZyanU64>(Data);
        ZyanUSize Offset = 0;
        ZydisDecodedInstruction Instruction;
        while (ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&Decoder, Data + Offset, 8 - Offset, &Instruction)))
        {
            if (Instruction.mnemonic == ZYDIS_MNEMONIC_JMP)
            {
                ZyanU64 ResultAddress{};
                if (ZYAN_SUCCESS(ZydisCalcAbsoluteAddress(&Instruction, &Instruction.operands[0], RuntimeAddress, &ResultAddress)))
                {
                    return ResolveFunctionAddressFromPotentialJmp(std::bit_cast<void*>(ResultAddress));
                }
                else
                {
                    Output::send<LogLevel::Warning>(STR("Was unable to resolve JMP instruction @ {:016X}"), RuntimeAddress);
                    return nullptr;
                }
            }
            else
            {
                return FunctionPtr;
            }

            Offset += Instruction.length;
            RuntimeAddress += Instruction.length;
        }
    }
}
