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

cpu::CPU::CPU(memory mem) {
    this->cpu_state = state();
    cpu_mem = mem;
    
};

uint16_t cpu::CPU::translate(uint16_t address){
    while (address >= this->cpu_mem.mem_size) {
        address -= this->cpu_mem.mem_size;
    }
    return address;
}

uint8_t cpu::CPU::read_memory(uint16_t address)
{
    uint16_t address = translate(address);
    uint8_t value = this->cpu_mem.mem_location[address];
    return value;
}

int cpu::CPU::write_memory(uint16_t address, uint8_t value) {
    uint16_t address = translate(address);
    if(address < )
    this->cpu_mem.mem_location[address] = value;
}


void cpu::CPU::emulate() {
    
    uint8_t* opcode = &cpu_mem.mem_location[cpu_state.pc];
    switch (opcode[0])
    {
    //NOP
    case 0x00:
        break;
    //LXI B,D
    case 0x01:
        cpu_state.B = opcode[2];
        cpu_state.C = opcode[1];
        cpu_state.pc += 2;
        break;
    //STAX B
    case 0x02:
        write_memory(cpu_state.B,cpu_state.A);
        break;
    case 0x03:
        break;
    case 0x04:
        cpu_state.B++;
        break;
    case 0x05:
        break;
    case 0x06:
        cpu_state.pc++;
        break;
    case 0x07:
        break;
    case 0x08:
        /* code */
        break;
    case 0x09:
        break;
    case 0x0a:
        break;
    case 0x0b:
        break;
    case 0x0c:
        break;
    case 0x0d:
        break;
    case 0x0e:
        cpu_state.pc += 2;
        break;
    case 0x0f:
        break;
    case 0x10:
        /* code */
        break;
    case 0x11:
        cpu_state.D = opcode[2];
        cpu_state.E = opcode[1];
        cpu_state.pc += 2;
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
        cpu_state.pc++;
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
    case 0x1a:
        /* code */
        break;
    case 0x1b:
        /* code */
        break;
    case 0x1c:
        /* code */
        break;
    case 0x1d:
        /* code */
        break;
    case 0x1e:
        cpu_state.pc++;
        break;
    case 0x1f:
        /* code */
        break;
    case 0x20:
        /* code */
        break;
    case 0x21:
        cpu_state.H = opcode[2];
        cpu_state.L = opcode[1];
        cpu_state.pc += 2;
        break;
    case 0x22:
        cpu_state.pc += 2;
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
        cpu_state.pc++;
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
    case 0x2a:
        cpu_state.pc += 2;
        break;
    case 0x2b:
        /* code */
        break;
    case 0x2c:
        /* code */
        break;
    case 0x2d:
        /* code */
        break;
    case 0x2e:
        cpu_state.pc++;
        break;
    case 0x2f:
        /* code */
        break;
    case 0x30:
        /* code */
        break;
    case 0x31:
        cpu_state.sp = (uint16_t)opcode[1];
        cpu_state.pc += 2;
        break;
    case 0x32:
        cpu_state.pc += 2;
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
        cpu_state.pc++;
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
    case 0x3a:
        cpu_state.pc += 2;
        break;
    case 0x3b:
        /* code */
        break;
    case 0x3c:
        /* code */
        break;
    case 0x3d:
        /* code */
        break;
    case 0x3e:
        cpu_state.pc++;
        break;
    case 0x3f:
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
    case 0x4a:
        /* code */
        break;
    case 0x4b:
        /* code */
        break;
    case 0x4c:
        /* code */
        break;
    case 0x4d:
        /* code */
        break;
    case 0x4e:
        /* code */
        break;
    case 0x4f:
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
    case 0x5a:
        /* code */
        break;
    case 0x5b:
        /* code */
        break;
    case 0x5c:
        /* code */
        break;
    case 0x5d:
        /* code */
        break;
    case 0x5e:
        /* code */
        break;
    case 0x5f:
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
    case 0x6a:
        /* code */
        break;
    case 0x6b:
        /* code */
        break;
    case 0x6c:
        /* code */
        break;
    case 0x6d:
        /* code */
        break;
    case 0x6e:
        /* code */
        break;
    case 0x6f:
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
    case 0x7a:
        /* code */
        break;
    case 0x7b:
        /* code */
        break;
    case 0x7c:
        /* code */
        break;
    case 0x7d:
        /* code */
        break;
    case 0x7e:
        /* code */
        break;
    case 0x7f:
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
    case 0x88:
        break;
    case 0x89:
        break;
    case 0x8a:
        break;
    case 0x8b:
        break;
    case 0x8c:
        break;
    case 0x8d:
        break;
    case 0x8e:
        break;
    case 0x8f:
        break;
    case 0x90:
        break;
    case 0x91:
        break;
    case 0x92:
        break;
    case 0x93:
        break;
    case 0x94:
        break;
    case 0x95:
        break;
    case 0x96:
        break;
    case 0x97:
        break;
    case 0x98:
        break;
    case 0x99:
        break;
    case 0x9a:
        break;
    case 0x9b:
        break;
    case 0x9c:
        break;
    case 0x9d:
        break;
    case 0x9e:
        break;
    case 0x9f:
        break;
    case 0xa0:
        break;
    case 0xa1:
        break;
    case 0xa2:
        break;
    case 0xa3:
        break;
    case 0xa4:
        break;
    case 0xa5:
        break;
    case 0xa6:
        break;
    case 0xa7:
        break;
    case 0xa8:
        break;
    case 0xa9:
        break;
    case 0xaa:
        break;
    case 0xab:
        break;
    case 0xac:
        break;
    case 0xad:
        break;
    case 0xae:
        break;
    case 0xaf:
        break;
    case 0xb0:
        break;
    case 0xb1:
        break;
    case 0xb2:
        break;
    case 0xb3:
        break;
    case 0xb4:
        break;
    case 0xb5:
        break;
    case 0xb6:
        break;
    case 0xb7:
        break;
    case 0xb8:
        break;
    case 0xb9:
        break;
    case 0xba:
        break;
    case 0xbb:
        break;
    case 0xbc:
        break;
    case 0xbd:
        break;
    case 0xbe:
        break;
    case 0xbf:
        break;
    case 0xc0:
        break;
    case 0xc1:
        break;
    case 0xc2:
        cpu_state.pc += 2;
        break;
    case 0xc3:
        cpu_state.pc += 2;
        break;
    case 0xc4:
        cpu_state.pc += 2;
        break;
    case 0xc5:
        break;
    case 0xc6:
        cpu_state.pc++;
        break;
    case 0xc7:
        break;
    case 0xc8:
        break;
    case 0xc9:
        break;
    case 0xca:
        cpu_state.pc += 2;
        break;
    case 0xcb:
        break;
    case 0xcc:
        cpu_state.pc += 2;
        break;
    case 0xcd:
        cpu_state.pc += 2;
        break;
    case 0xce:
        cpu_state.pc++;
        break;
    case 0xcf:
        break;
    case 0xd0:
        break;
    case 0xd1:
        break;
    case 0xd2:
        cpu_state.pc += 2;
        break;
    case 0xd3:
        cpu_state.pc++;
        break;
    case 0xd4:
        cpu_state.pc += 2;
        break;
    case 0xd5:
        break;
    case 0xd6:
        cpu_state.pc++;
        break;
    case 0xd7:
        break;
    case 0xd8:
        break;
    case 0xd9:
        break;
    case 0xda:
        cpu_state.pc += 2;
        break;
    case 0xdb:
        cpu_state.pc++;
        break;
    case 0xdc:
        cpu_state.pc += 2;
        break;
    case 0xdd:
        break;
    case 0xde:
        cpu_state.pc++;
        break;
    case 0xdf:
        break;
    case 0xe0:
        break;
    case 0xe1:
        break;
    case 0xe2:
        cpu_state.pc += 2;
        break;
    case 0xe3:
        break;
    case 0xe4:
        cpu_state.pc += 2;
        break;
    case 0xe5:
        break;
    case 0xe6:
        cpu_state.pc++;
        break;
    case 0xe7:
        break;
    case 0xe8:
        break;
    case 0xe9:
        break;
    case 0xea:
        cpu_state.pc += 2;
        break;
    case 0xeb:
        break;
    case 0xec:
        cpu_state.pc += 2;
        break;
    case 0xed:
        break;
    case 0xee:
        cpu_state.pc++;
        break;
    case 0xef:
        break;
    case 0xf0:
        break;
    case 0xf1:
        break;
    case 0xf2:
        cpu_state.pc += 2;
        break;
    case 0xf3:
        break;
    case 0xf4:
        cpu_state.pc += 2;
        break;
    case 0xf5:
        break;
    case 0xf6:
        cpu_state.pc++;
        break;
    case 0xf7:
        break;
    case 0xf8:
        break;
    case 0xf9:
        break;
    case 0xfa:
        cpu_state.pc += 2;
        break;
    case 0xfb:
        break;
    case 0xfc:
        cpu_state.pc += 2;
        break;
    case 0xfd:
        break;
    case 0xfe:
        cpu_state.pc++;
        break;
    case 0xff:
        break;
    default:
        break;
    }
    cpu_state.pc ++;
}