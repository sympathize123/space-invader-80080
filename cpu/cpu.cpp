#include "state.h"
#include <iostream>

using namespace std;

void unmapped_instruction(unsigned char opcode);
void

namespace cpu
{
    class CPU:
    {
        CPU(){};
        void unmapped_instruction(unsigned char opcode)
        {
            cout << "no intructions for the opcode " << opcode << endl;
        }

        void emulate(int pc)
        {
        }
    }
}