#include "state.h"
#include "cpu.h"
#include <iostream>

using namespace std;

void cpu::CPU::unmapped_instruction(unsigned char opcode){
    cout << "no intructions for the opcode " << opcode << endl;
}

cpu::CPU::CPU() {
    this->cpu_state = state();
};

void cpu::CPU::emulate() {
    uint8_t* opcode = &cpu_state.mem[cpu_state.pc];
    switch (opcode[0])
    {
    //NOP
    case 0x00:
        break;
    //LXI B,D
    case 0x01:
        cpu_state.B = opcode[2];
        cpu_state.C = opcode[1];
        break;
    case 0x02:
        
        break;
    case 0x03:
        /* code */
        break;
    case 0x04:
        /* code */
        break;
    case 0x05:
        /* code */
        break;
    case 0x06:
        /* code */
        break;
    case 0x07:
        /* code */
        break;
    case 0x08:
        /* code */
        break;
    case 0x09:
        /* code */
        break;
    case 0x10:
        /* code */
        break;
    case 0x11:
        cpu_state.D = opcode[2];
        cpu_state.E = opcode[1];
        break;
    case 0x12:
        /* code */
        break;
    case 0x13:
        /* code */
        break;
    case 0x14:
        /* code */
        break;
    case 0x15:
        /* code */
        break;
    case 0x16:
        /* code */
        break;
    case 0x17:
        /* code */
        break;
    case 0x18:
        /* code */
        break;
    case 0x19:
        /* code */
        break;
    case 0x20:
        /* code */
        break;
    case 0x21:
        cpu_state.H = opcode[2];
        cpu_state.L = opcode[1];
        break;
    case 0x22:
        /* code */
        break;
    case 0x23:
        /* code */
        break;
    case 0x24:
        /* code */
        break;
    case 0x25:
        /* code */
        break;
    case 0x26:
        /* code */
        break;
    case 0x27:
        /* code */
        break;
    case 0x28:
        /* code */
        break;
    case 0x29:
        /* code */
        break;
    case 0x30:
        /* code */
        break;
    case 0x31:
        cpu_state.sp = (uint16_t)opcode[1];
        break;
    case 0x32:
        /* code */
        break;
    case 0x33:
        /* code */
        break;
    case 0x34:
        /* code */
        break;
    case 0x35:
        /* code */
        break;
    case 0x36:
        /* code */
        break;
    case 0x37:
        /* code */
        break;
    case 0x38:
        /* code */
        break;
    case 0x39:
        /* code */
        break;
    case 0x40:
        /* code */
        break;
    case 0x41:
        /* code */
        break;
    case 0x42:
        /* code */
        break;
    case 0x43:
        /* code */
        break;
    case 0x44:
        /* code */
        break;
    case 0x45:
        /* code */
        break;
    case 0x46:
        /* code */
        break;
    case 0x47:
        /* code */
        break;
    case 0x48:
        /* code */
        break;
    case 0x49:
        /* code */
        break;
    case 0x50:
        /* code */
        break;
    case 0x51:
        /* code */
        break;
    case 0x52:
        /* code */
        break;
    case 0x53:
        /* code */
        break;
    case 0x54:
        /* code */
        break;
    case 0x55:
        /* code */
        break;
    case 0x56:
        /* code */
        break;
    case 0x57:
        /* code */
        break;
    case 0x58:
        /* code */
        break;
    case 0x59:
        /* code */
        break;
    case 0x60:
        /* code */
        break;
    case 0x61:
        /* code */
        break;
    case 0x62:
        /* code */
        break;
    case 0x63:
        /* code */
        break;
    case 0x64:
        /* code */
        break;
    case 0x65:
        /* code */
        break;
    case 0x66:
        /* code */
        break;
    case 0x67:
        /* code */
        break;
    case 0x68:
        /* code */
        break;
    case 0x69:
        /* code */
        break;
    case 0x70:
        /* code */
        break;
    case 0x71:
        /* code */
        break;
    case 0x72:
        /* code */
        break;
    case 0x73:
        /* code */
        break;
    case 0x74:
        /* code */
        break;
    case 0x75:
        /* code */
        break;
    case 0x76:
        /* code */
        break;
    case 0x77:
        /* code */
        break;
    case 0x78:
        /* code */
        break;
    case 0x79:
        /* code */
        break;
    case 0x80:
        /* code */
        break;
    case 0x81:
        /* code */
        break;
    case 0x82:
        /* code */
        break;
    case 0x83:
        /* code */
        break;
    case 0x84:
        /* code */
        break;
    case 0x85:
        /* code */
        break;
    case 0x86:
        /* code */
        break;
    case 0x87:
        /* code */
        break;
    default:
        break;
    }
}