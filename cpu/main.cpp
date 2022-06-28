#include "cpu.h"

int main() {
    unsigned char opcode = 0x55;
    cpu::CPU cpu;
    cpu.unmapped_instruction(opcode);
}