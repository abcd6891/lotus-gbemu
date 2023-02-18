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
SUB_FUNC_DECLARE(subFuncMemReadPC);
SUB_FUNC_DECLARE(subFuncMemReadIndirect);
SUB_FUNC_DECLARE(subFuncMemWriteHL);
SUB_FUNC_DECLARE(subFuncLDR_MEMVAL);
SUB_FUNC_DECLARE(subFuncLDA_MEMVAL);

}

#endif // LOTUSGB_INST_SUB_FUNC_HPP