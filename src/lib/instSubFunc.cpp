#include <iostream>
#include <cstddef>
#include <cstdint>
#include "include/instSubFunc.hpp"
#include "include/instruction.hpp"
#include "include/gb_reg.hpp"

namespace LOTUSGB {

#define INCPC() (++(pReg->getRefPC()))

static inline uint8_t* _getReg(const int &number, Reg *pReg) {
    switch (number) {
        case 0: return &pReg->getRefB();
        case 1: return &pReg->getRefC();
        case 2: return &pReg->getRefD();
        case 3: return &pReg->getRefE();
        case 4: return &pReg->getRefH();
        case 5: return &pReg->getRefL();
        // 6: HL is handled in 16bit LD instruction
        case 7: return &pReg->getRefA();
        default:
            return nullptr;
    }
}

static uint8_t* getRegLHS(const uint8_t &op, Reg *pReg) {
    constexpr uint8_t MASK = 0x3F;
    const int num = ((op&MASK)>>3U);
    auto ret = _getReg(num, pReg);
    if (!ret)
        std::cerr << "invalid OP code, reg not support" << (int)op << std::endl;
    return ret;
}

static uint8_t* getRegRHS(const uint8_t &op, Reg *pReg) {
    constexpr uint8_t MASK = 0x07;
    const int num = (op & MASK);
    auto ret = _getReg(num, pReg);
    return ret;
}


subFunMapType getSubFuncMap() {
    subFunMapType map;
    // TODO: codegen?
    map["subFuncNOP"] = subFuncNOP();
    map["subFuncLDRR"] = subFuncLDRR();
    map["subFuncMemReadPC"] = subFuncMemReadPC();
    map["subFuncMemReadIndirect"] = subFuncMemReadIndirect();
    map["subFuncLDR_MEMVAL"] = subFuncLDR_MEMVAL();
    map["subFuncLDA_MEMVAL"] = subFuncLDA_MEMVAL();
    map["subFuncMemWriteHL"] = subFuncMemWriteHL();
    return map;
}


SUB_FUNC_IMPL(subFuncNOP){
    return;
}

SUB_FUNC_IMPL(subFuncLDRR) {
    // TODO: error handling
    const uint8_t &op = pInstState->opcode;
    uint8_t *lhs = getRegLHS(op, pReg);
    uint8_t *rhs = getRegRHS(op, pReg);
    if (lhs && rhs)
        *lhs = *rhs;
}

SUB_FUNC_IMPL(subFuncMemReadPC) {
    // notify CPU to read immediate value
    pInstState->memMode = MEM_MODE_READ;
    pInstState->memAddr = pReg->getRefPC();
    INCPC(); // inc by immdeiate value is read
}

SUB_FUNC_IMPL(subFuncMemReadIndirect) {
    pInstState->memMode = MEM_MODE_READ;
    // TODO: remove hard code?
    switch(pInstState->opcode) {
        case 0x0A:
            pInstState->memAddr = pReg->getRefBC();
            break;
        case 0x1A:
            pInstState->memAddr = pReg->getRefDE();
            break;
        default:
            pInstState->memAddr = pReg->getRefHL();
            break;
    }
}

SUB_FUNC_IMPL(subFuncMemWriteHL) {
    pInstState->memMode = MEM_MODE_WRITE;
    pInstState->memAddr = pReg->getRefHL();
    uint8_t *rhs = getRegRHS(pInstState->opcode, pReg);
    if (rhs)
        pInstState->memValue = *rhs;
}

SUB_FUNC_IMPL(subFuncLDR_MEMVAL) {
    uint8_t *lhs = getRegLHS(pInstState->opcode, pReg);
    if (lhs)
        *lhs = pInstState->memValue;
}

SUB_FUNC_IMPL(subFuncLDA_MEMVAL) {
    pReg->getRefA() = pInstState->memValue;
}

}