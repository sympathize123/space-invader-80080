#ifndef __CPU_H__
#define __CPU_H__

#include "state.h"
#include "../memory/memory.h"

namespace cpu
{
    class CPU
    {
        public:
            state cpu_state;
            memory cpu_mem;

        public:
            CPU();
            CPU(memory mem);
            void unmapped_instruction(unsigned char opcode);
            void emulate();
    };
};

#endif