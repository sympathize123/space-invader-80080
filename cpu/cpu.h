#ifndef __CPU_H__
#define __CPU_H__

#include "state.h"

namespace cpu
{
    class CPU
    {
        protected:
            state cpu_state;

        public:
            CPU();
            void unmapped_instruction(unsigned char opcode);
            void emulate();
    };
};

#endif