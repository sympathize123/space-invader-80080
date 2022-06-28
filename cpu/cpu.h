#ifndef __CPU_H__
#define __CPU_H__

#include "state.h"

namespace cpu
{
    class CPU
    {
        protected:
            state cpu_state;
            memory cpu_mem;

        public:
            CPU();
            CPU(memory mem);
            uint16_t translate(uint16_t address);
            uint8_t read_memory(uint16_t address);
            int write_memory(uint16_t address, uint8_t value);
            void unmapped_instruction(unsigned char opcode);
            void emulate();
    };
};

#endif