/*
References:
Gameboy CPU (LR35902) instruction set
https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html

Game Boy: Complete Technical Referenc
https://gekkio.fi/files/gb-docs/gbctr.pdf

Game BoyTM CPU Manual
http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf
*/
#ifndef LOTUSGB_INST_SUB_FUNC_HPP
#define LOTUSGB_INST_SUB_FUNC_HPP
#include <string>
#include <unordered_map>
#include "Iinstruction.hpp"
#include "instruction.hpp"

// flows of instruction per memory-cycles
// TODO: codegen? how to handle function not implemented?
namespace LOTUSGB {

#define SUB_FUNC_DECLARE(x) \
struct x {\
SUB_FUNC_OP_RET SUB_FUNC_OP;\
};

#define SUB_FUNC_IMPL(x) SUB_FUNC_OP_RET x::SUB_FUNC_OP

using subFunMapType = std::unordered_map<std::string, Instruction::FUNC_TYPE>;
subFunMapType getSubFuncMap();

SUB_FUNC_DECLARE(subFuncNOP);
SUB_FUNC_DECLARE(subFuncLDRR);
SUB_FUNC_DECLARE(subFuncLD_R_MEMVAL);
// TODO: get the realy GB pipeline, is there a subFuncLD_A_MEMVAL?
SUB_FUNC_DECLARE(subFuncLD_A_MEMVAL);
SUB_FUNC_DECLARE(subFuncLD_R16_MEM16);
// TODO: check why LD SP, HL need 2 cycles
SUB_FUNC_DECLARE(subFuncLD_SP_HL);
// TODO: check why don't PUSH Reg16 start writing from the first cycle?
SUB_FUNC_DECLARE(subFuncPUSH_LD_A16_RR);
SUB_FUNC_DECLARE(subFuncPOP_LD_R16_MEM16);
SUB_FUNC_DECLARE(subFuncMemReadPC);
SUB_FUNC_DECLARE(subFuncMemReadIndirectHL);
SUB_FUNC_DECLARE(subFuncMemReadIndirectHLDec);
SUB_FUNC_DECLARE(subFuncMemReadIndirectHLInc);
SUB_FUNC_DECLARE(subFuncMemReadIndirectBC_DE);
SUB_FUNC_DECLARE(subFuncMemReadIndirectA16);
SUB_FUNC_DECLARE(subFuncReadHighC);
SUB_FUNC_DECLARE(subFuncMemWriteIndirectHL);
SUB_FUNC_DECLARE(subFuncMemWriteIndirectHLDec);
SUB_FUNC_DECLARE(subFuncMemWriteIndirectHLInc);
SUB_FUNC_DECLARE(subFuncMemWriteIndirectBC_DE);
SUB_FUNC_DECLARE(subFuncMemWriteIndirectA16);
SUB_FUNC_DECLARE(subFuncMemWriteSPA16LSB);
SUB_FUNC_DECLARE(subFuncMemWriteSPA16MSB);
SUB_FUNC_DECLARE(subFuncWriteHighC);
SUB_FUNC_DECLARE(subFuncReadA16LSB);
SUB_FUNC_DECLARE(subFuncReadA16MSB);
SUB_FUNC_DECLARE(subFuncPUSH_A16_MSB);
SUB_FUNC_DECLARE(subFuncPUSH_A16_LSB);
SUB_FUNC_DECLARE(subFuncPOP_LD_A16_LSB);
SUB_FUNC_DECLARE(subFuncPOP_LD_A16_MSB);
SUB_FUNC_DECLARE(subFuncAddA_R);
SUB_FUNC_DECLARE(subFuncAddA_MEMVAL);
SUB_FUNC_DECLARE(subFuncAddA_R_Carry);
SUB_FUNC_DECLARE(subFuncAddA_MEMVAL_Carry)
SUB_FUNC_DECLARE(subFuncSubA_R);
SUB_FUNC_DECLARE(subFuncSubA_MEMVAL);
SUB_FUNC_DECLARE(subFuncSubA_R_Carry);
SUB_FUNC_DECLARE(subFuncSubA_MEMVAL_Carry);
SUB_FUNC_DECLARE(subFuncCmpA_R);
SUB_FUNC_DECLARE(subFuncCmpA_MEMVAL);
SUB_FUNC_DECLARE(subFuncIncR);
SUB_FUNC_DECLARE(subFuncMemIncWriteIndirectHL);
SUB_FUNC_DECLARE(subFuncDecR);
SUB_FUNC_DECLARE(subFuncMemDecWriteIndirectHL);
SUB_FUNC_DECLARE(subFuncAndA_R);
SUB_FUNC_DECLARE(subFuncAndA_MEMVAL);
SUB_FUNC_DECLARE(subFuncOrA_R);
SUB_FUNC_DECLARE(subFuncOrA_MEMVAL);
SUB_FUNC_DECLARE(subFuncXorA_R);
SUB_FUNC_DECLARE(subFuncXorA_MEMVAL);
SUB_FUNC_DECLARE(subFuncCCF);
SUB_FUNC_DECLARE(subFuncSCF);
SUB_FUNC_DECLARE(subFuncDAA);
SUB_FUNC_DECLARE(subFuncCPL);
SUB_FUNC_DECLARE(subFuncLD_PC_MEM16);
SUB_FUNC_DECLARE(subFuncLD_PC_HL);
SUB_FUNC_DECLARE(subFuncCondLD_PC_MEM16);
SUB_FUNC_DECLARE(subFuncJR);
SUB_FUNC_DECLARE(subFuncCondJR);
SUB_FUNC_DECLARE(subFuncSwapPC_MEM16);
SUB_FUNC_DECLARE(subFuncCondSwapPC_MEM16);
// TODO: why GB need idle at this mem clock?
// TODO: let SP value correct in every clock.
SUB_FUNC_DECLARE(subFuncBubble);
SUB_FUNC_DECLARE(subFuncCondPOP_LD_A16_LSB);
SUB_FUNC_DECLARE(subFuncLD_PC_MEM16_RETI);
SUB_FUNC_DECLARE(subFuncLD_MEM16_PC);
SUB_FUNC_DECLARE(subFuncRST);
SUB_FUNC_DECLARE(subFuncHalt);
SUB_FUNC_DECLARE(subFuncStop);
SUB_FUNC_DECLARE(subFuncStopWorkaround);
SUB_FUNC_DECLARE(subFuncDI);
SUB_FUNC_DECLARE(subFuncEI);
// TODO: get correct pipeline spec of 16bit inst
// TODO: implment all add & sub only by 8bit adder?
SUB_FUNC_DECLARE(subFuncIncRR);
SUB_FUNC_DECLARE(subFuncDecRR);
SUB_FUNC_DECLARE(subFuncAdd_HL_RR);
SUB_FUNC_DECLARE(subFuncAdd_SP_R8);
SUB_FUNC_DECLARE(subFuncAdd_HL_SP_R8);
SUB_FUNC_DECLARE(subFuncRLCA);
SUB_FUNC_DECLARE(subFuncRLA);
SUB_FUNC_DECLARE(subFuncRRCA);
SUB_FUNC_DECLARE(subFuncRRA);

}

#endif // LOTUSGB_INST_SUB_FUNC_HPP