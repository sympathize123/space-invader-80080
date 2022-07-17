#include "state.h"
#include "cpu.h"
#include <iostream>
#include "../memory/memory.h"
#include <cstring>
#include "../disassembler/opcode.h"

using namespace std;

void cpu::CPU::unmapped_instruction(unsigned char opcode)
{
    cout << "no intructions for the opcode " << opcode << endl;
}

cpu::CPU::CPU()
{
    this->cpu_state = state();
};

cpu::CPU::CPU(memory mem)
{
    this->cpu_state = state();
    cpu_mem = mem;
};

void cpu::CPU::emulate()
{
    uint8_t *opcode = &cpu_mem.mem_location[cpu_state.pc];

    make_opcode(opcode, cpu_state.pc);

    cpu_state.pc++;

    switch (opcode[0])
    {
    // NOP
    case 0x00:
        break;
    // LXI B
    case 0x01:
    {
        cpu_state.B = opcode[2];
        cpu_state.C = opcode[1];
        cpu_state.pc += 2;
    }
    break;
    // STAX B
    case 0x02:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x03:
    {
        unmapped_instruction(opcode[0]);
        exit(0);
    }
    break;
    case 0x04:
        cpu_state.B++;
        break;
    case 0x05:
    {
        cpu_state.B--;
        if ((cpu_state.B & 0xff) == 0)
            cpu_state.flag.z = 1;
        if ((cpu_state.B & 0x80 >> 3) == 1)
            cpu_state.flag.s = 1;
        if (cpu_state.parity(cpu_state.B))
            cpu_state.flag.p = 1;
        if ((cpu_state.B | 0x1000 << 4 >> 7) == 1)
            cpu_state.flag.auxc = 1;
    }
    break;
    case 0x06:
        cpu_state.B = opcode[1];
        cpu_state.pc++;
        break;
    case 0x07:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x08:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x09:
    {
        uint32_t hl = concat_address(cpu_state.H, cpu_state.L);
        uint32_t bc = concat_address(cpu_state.B, cpu_state.C);
        uint32_t res = hl + bc;
        cpu_state.H = (res & 0xff00) >> 8;
        cpu_state.L = res & 0xff;
        cpu_state.flag.c = ((res & 0xffff0000) > 0);
    }
    break;
    case 0x0a:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x0b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x0c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // DCR C
    case 0x0d:
    {
        uint8_t result = --cpu_state.C;
        cpu_state.flag.z = (result == 0);
        cpu_state.flag.s = ((result & 0x80) == 0x80);
        cpu_state.flag.p = cpu_state.parity(result);
        cpu_state.flag.auxc = ((result | 0x1000 << 4 >> 7) == 1);
        break;
    }
    // MVI C,D8
    case 0x0e:
    {
        cpu_state.C = opcode[1];
        cpu_state.pc += 2;
    }
    break;
    // RRC
    case 0x0f:
    {
        cpu_state.flag.c = (cpu_state.A & 0x1);
        cpu_state.A = (cpu_state.A >> 1 | cpu_state.flag.c << 7);
    }
    break;
    case 0x10:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // LXI D
    case 0x11:
    {
        cpu_state.D = opcode[2];
        cpu_state.E = opcode[1];
        cpu_state.pc += 2;
    }
    break;
    case 0x12:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // INX D
    case 0x13:
    {
        cpu_state.E++;
        if (cpu_state.E == 0)
            cpu_state.D++;
    }
    break;
    case 0x14:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x15:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x16:
        cpu_state.pc++;
        break;
    case 0x17:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x18:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // DAD D
    case 0x19:
    {
        uint32_t hl = concat_address(cpu_state.H, cpu_state.L);
        uint32_t bc = concat_address(cpu_state.H, cpu_state.L);
        uint32_t res = hl + bc;
        cpu_state.H = (res & 0xff00) >> 8;
        cpu_state.L = res & 0xff;
        cpu_state.flag.c = ((res & 0xffff0000) > 0);
    }
    break;
    case 0x1a:
    {
        uint16_t address = concat_address(cpu_state.D, cpu_state.E);
        address = cpu_mem.translate(address);
        cpu_state.A = cpu_mem.mem_location[address];
    }
    break;
    case 0x1b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x1c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x1d:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x1e:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x1f:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x20:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // LXI H
    case 0x21:
    {
        cpu_state.H = opcode[2];
        cpu_state.L = opcode[1];
        cpu_state.pc += 2;
    }
    break;
    case 0x22:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x23:
    {
        cpu_state.L++;
        if (cpu_state.L == 0)
            cpu_state.H++;
    }
    break;
    case 0x24:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x25:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MVI H,D8
    case 0x26:
        cpu_state.H = opcode[1];
        cpu_state.pc++;
        break;
    case 0x27:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x28:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // DAD H
    case 0x29:
    {
        uint32_t hl = concat_address(cpu_state.H, cpu_state.L);
        hl *= 2;
        cpu_state.H = (hl & 0xff00) >> 8;
        cpu_state.L = hl & 0xff;
        cpu_state.flag.c = ((hl & 0xffff0000) > 0);
    }
    break;
    case 0x2a:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x2b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x2c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x2d:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x2e:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x2f:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x30:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // LXI sp
    case 0x31:
    {
        cpu_state.sp = (opcode[2] << 8) | opcode[1];
        cpu_state.pc += 2;
    }
    break;
    case 0x32:
    {
        uint16_t address = concat_address(opcode[2], opcode[1]);
        cpu_mem.mem_location[address] = cpu_state.A;
        cpu_state.pc += 2;
    }
    break;
    case 0x33:

        break;
    case 0x34:

        break;
    case 0x35:

        break;
    // MVI M,D8
    case 0x36:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_mem.mem_location[address] = opcode[1];
        cpu_state.pc++;
    }
    break;
    case 0x37:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x38:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x39:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x3a:
    {
        uint16_t address = concat_address(opcode[2], opcode[1]);
        cpu_state.A = cpu_mem.mem_location[address];
        cpu_state.pc += 2;
    }
    break;
    case 0x3b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x3c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x3d:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MVI A,D8
    case 0x3e:
        cpu_state.A = opcode[1];
        cpu_state.pc++;
        break;
    case 0x3f:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x40:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x41:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x42:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x43:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x44:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x45:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x46:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x47:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x48:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x49:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x4a:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x4b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x4c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x4d:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x4e:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x4f:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x50:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x51:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x52:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x53:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x54:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x55:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MOV D,M
    case 0x56:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.D = cpu_mem.mem_location[address];
    }
    break;
    case 0x57:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x58:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x59:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x5a:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x5b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x5c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x5d:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MOV E,M
    case 0x5e:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.E = cpu_mem.mem_location[address];
    }
    break;
    case 0x5f:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x60:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x61:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x62:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x63:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x64:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x65:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MOV H,M
    case 0x66:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.H = cpu_mem.mem_location[address];
    }
    break;
    case 0x67:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x68:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x69:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x6a:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x6b:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x6c:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x6d:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x6e:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MOV L,A
    case 0x6f:
    {
        cpu_state.L = cpu_state.A;
    }
    break;
    case 0x70:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x71:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x72:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x73:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x74:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x75:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x76:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MOV M,A
    case 0x77:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_mem.mem_location[address] = cpu_state.A;
    }
    /* code */
    break;
    case 0x78:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x79:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    // MOV A,D
    case 0x7a:
        cpu_state.A = cpu_state.D;
        break;
    // MOV A,E
    case 0x7b:
        cpu_state.A = cpu_state.E;
        break;
    // MOV A,H
    case 0x7c:
        cpu_state.A = cpu_state.H;
        break;
    case 0x7d:
        break;
    // MOV A,M
    case 0x7e:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.A = cpu_mem.mem_location[address];
    }
    break;
    case 0x7f:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x80:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x81:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x82:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x83:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x84:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x85:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x86:
        unmapped_instruction(opcode[0]);
        exit(0);
        break;
    case 0x87:
        unmapped_instruction(opcode[0]);
        exit(0);
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
    // ANA A
    case 0xa7:
        cpu_state.A &= cpu_state.A;
        cpu_state.flag.c = 0;
        cpu_state.flag.z = (cpu_state.A == 0);
        cpu_state.flag.s = ((cpu_state.A & 0x80) == 0x80);
        cpu_state.flag.p = cpu_state.parity(cpu_state.A);
        cpu_state.flag.auxc = ((cpu_state.A | 0x1000 << 4 >> 7) == 1);
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
    // XRA A
    case 0xaf:
        cpu_state.A ^= cpu_state.A;
        cpu_state.flag.c = 0;
        cpu_state.flag.z = (cpu_state.A == 0);
        cpu_state.flag.s = ((cpu_state.A & 0x80) == 0x80);
        cpu_state.flag.p = cpu_state.parity(cpu_state.A);
        cpu_state.flag.auxc = ((cpu_state.A | 0x1000 << 4 >> 7) == 1);
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
    // POP B
    case 0xc1:
        cpu_state.C = cpu_mem.mem_location[cpu_state.sp];
        cpu_state.B = cpu_mem.mem_location[cpu_state.sp + 1];
        cpu_state.sp += 2;
        break;
    case 0xc2:
        if (cpu_state.flag.z)
            cpu_state.pc = concat_address(opcode[2], opcode[1]);
        else
            cpu_state.pc += 2;
        break;
    case 0xc3:
        cpu_state.pc = concat_address(opcode[2], opcode[1]);
        break;
    case 0xc4:
        unmapped_instruction(opcode[0]);
        exit(1);
        break;
    case 0xc5:
        cpu_mem.mem_location[cpu_state.sp - 1] = cpu_state.B;
        cpu_mem.mem_location[cpu_state.sp - 2] = cpu_state.C;
        cpu_state.sp -= 2;
        break;
    case 0xc6:
    {
        uint16_t res = cpu_state.A + opcode[1];
        cpu_state.flag.z = ((res & 0xff) == 0);
        cpu_state.flag.s = (0x80 == (res & 0x80));
        cpu_state.flag.p = cpu_state.parity(res & 0xff);
        cpu_state.flag.c = (res > 0xff);
        cpu_state.A = (uint8_t)res;
        cpu_state.pc++;
        cpu_state.pc++;
    }
    break;
    case 0xc7:
        break;
    case 0xc8:
        break;
    case 0xc9:
        cpu_state.pc = cpu_mem.mem_location[cpu_state.sp] | (cpu_mem.mem_location[cpu_state.sp + 1] << 8);
        cpu_state.sp += 2;
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
    {
        cpu_state.pc = concat_address(opcode[2], opcode[1]);
        uint16_t ret = cpu_state.pc + 2;
        cpu_mem.mem_location[cpu_state.sp - 1] = (ret >> 8) & 0xff;
        cpu_mem.mem_location[cpu_state.sp - 2] = (ret & 0xff);
        cpu_state.sp = cpu_state.sp - 2;
    }
    break;
    case 0xce:
        break;
    case 0xcf:
        break;
    case 0xd0:
        break;
    case 0xd1:
        cpu_state.D = cpu_mem.mem_location[cpu_state.sp];
        cpu_state.E = cpu_mem.mem_location[cpu_state.sp + 1];
        cpu_state.sp += 2;
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
        cpu_mem.mem_location[cpu_state.sp - 1] = cpu_state.D;
        cpu_mem.mem_location[cpu_state.sp - 2] = cpu_state.E;
        cpu_state.sp -= 2;
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
        cpu_state.H = cpu_mem.mem_location[cpu_state.sp];
        cpu_state.L = cpu_mem.mem_location[cpu_state.sp + 1];
        cpu_state.sp += 2;
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
        cpu_mem.mem_location[cpu_state.sp - 1] = cpu_state.H;
        cpu_mem.mem_location[cpu_state.sp - 2] = cpu_state.L;
        cpu_state.sp -= 2;
        break;
    case 0xe6:
    {
        cpu_state.A = cpu_state.A & opcode[1];
        cpu_state.flag.c = cpu_state.flag.auxc = 0;
        cpu_state.flag.z = (cpu_state.A == 0);
        cpu_state.flag.s = (0x80 == (cpu_state.A & 0x80));
        cpu_state.flag.p = cpu_state.parity(cpu_state.A);
        cpu_state.pc++;
    }
    break;
    case 0xe7:
        break;
    case 0xe8:
        break;
    case 0xe9:
        break;
    case 0xea:
        break;
    case 0xeb:
    {
        uint8_t temp1 = cpu_state.D;
        uint8_t temp2 = cpu_state.E;
        cpu_state.D = cpu_state.H;
        cpu_state.E = cpu_state.L;
        cpu_state.H = temp1;
        cpu_state.L = temp2;
    }
    break;
    case 0xec:
        break;
    case 0xed:
        break;
    case 0xee:
        break;
    case 0xef:
        break;
    case 0xf0:
        break;
    case 0xf1:
    {
        cpu_state.A = cpu_mem.mem_location[cpu_state.sp + 1];
        uint8_t psw = cpu_mem.mem_location[cpu_state.sp];
        cpu_state.flag.z = (0x01 == (psw & 0x01));
        cpu_state.flag.s = (0x02 == (psw & 0x02));
        cpu_state.flag.p = (0x04 == (psw & 0x04));
        cpu_state.flag.c = (0x05 == (psw & 0x08));
        cpu_state.flag.auxc = (0x10 == (psw & 0x10));
        cpu_state.sp += 2;
    }
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
    {
        cpu_mem.mem_location[cpu_state.sp - 1] = cpu_state.A;
        uint8_t psw = (cpu_state.flag.z |
                       cpu_state.flag.s << 1 |
                       cpu_state.flag.p << 2 |
                       cpu_state.flag.c << 3 |
                       cpu_state.flag.auxc << 4);
        cpu_mem.mem_location[cpu_state.sp - 2] = psw;
        cpu_state.sp = cpu_state.sp - 2;
    }
    break;
    case 0xf6:

        break;
    case 0xf7:
        break;
    case 0xf8:
        break;
    case 0xf9:
        break;
    case 0xfa:
        break;
    case 0xfb:
        break;
    case 0xfc:
        break;
    case 0xfd:
        break;
    case 0xfe:
        break;
    case 0xff:
        break;
    }
    printf("\t");
    printf("%c", cpu_state.flag.z ? 'z' : '.');
    printf("%c", cpu_state.flag.s ? 's' : '.');
    printf("%c", cpu_state.flag.p ? 'p' : '.');
    printf("%c", cpu_state.flag.c ? 'c' : '.');
    printf("%c  ", cpu_state.flag.auxc ? 'a' : '.');
    printf("A $%02x B $%02x C $%02x D $%02x E $%02x H $%02x L $%02x SP %04x\n", cpu_state.A, cpu_state.B, cpu_state.C,
           cpu_state.D, cpu_state.E, cpu_state.H, cpu_state.L, cpu_state.sp);
}