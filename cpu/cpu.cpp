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

    make_opcode(opcode[0], cpu_state.pc);

    cpu_state.pc++;

    switch (opcode[0])
    {
    // NOP
    case 0x00:
        break;
    // LXI B
    case 0x01:
        cpu_state.B = opcode[2];
        cpu_state.C = opcode[1];
        cpu_state.pc += 2;
        break;
    // STAX B
    case 0x02:
        cpu_mem.write_memory(cpu_state.B, cpu_state.A);
        break;
    case 0x03:
        break;
    case 0x04:
        cpu_state.B++;
        break;
    case 0x05:
        cpu_state.B--;
        if ((cpu_state.B & 0xff) == 0)
            cpu_state.flag.z = 1;
        if ((cpu_state.B & 0x80 >> 3) == 1)
            cpu_state.flag.s = 1;
        if (cpu_state.parity(cpu_state.B))
            cpu_state.flag.p = 1;
        if ((cpu_state.B | 0x1000 << 4 >> 7) == 1)
            cpu_state.flag.auxc = 1;
        break;
    case 0x06:
        cpu_state.B = opcode[1];
        cpu_state.pc++;
        break;
    case 0x07:
        break;
    case 0x08:
        /* code */
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
        break;
    case 0x0b:
        break;
    case 0x0c:
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
        cpu_state.C = opcode[1];
        cpu_state.pc += 2;
        break;
    // RRC
    case 0x0f:
        cpu_state.flag.c = (cpu_state.A & 0x1);
        cpu_state.A = (cpu_state.A >> 1 | cpu_state.flag.c << 7);
        break;
    case 0x10:
        /* code */
        break;
    // LXI D
    case 0x11:
        cpu_state.D = opcode[2];
        cpu_state.E = opcode[1];
        cpu_state.pc += 2;
        break;
    case 0x12:
        /* code */
        break;
    // INX D
    case 0x13:
    {
        uint16_t result = concat_address(cpu_state.D, cpu_state.E);
        cpu_state.D = (result & 0xff00) >> 8;
        cpu_state.E = (result & 0xff);
    }
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
    /* code */
    break;
    // LDAX D
    case 0x1a:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        address = cpu_mem.translate(address);
        cpu_mem.mem_location[address] = cpu_state.A;
    }
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
    // LXI H
    case 0x21:
        cpu_state.H = opcode[2];
        cpu_state.L = opcode[1];
        cpu_state.pc += 2;
        break;
    case 0x22:
        cpu_state.pc += 2;
        break;
    case 0x23:
    {
        uint16_t result = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.H = (result & 0xff00) >> 8;
        cpu_state.L = (result & 0xff);
    }
    break;
    case 0x24:
        /* code */
        break;
    case 0x25:
        /* code */
        break;
    // MVI H,D8
    case 0x26:
        cpu_state.H = opcode[1];
        cpu_state.pc++;
        break;
    case 0x27:
        /* code */
        break;
    case 0x28:
        /* code */
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
    // LXI sp
    case 0x31:
        cpu_state.sp = (uint16_t)opcode[1];
        cpu_state.pc += 2;
        break;
    case 0x32:
    {
        uint16_t address = concat_address(opcode[2], opcode[1]);
        cpu_mem.mem_location[address] = cpu_state.A;
        cpu_state.pc += 2;
    }
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
    // MVI M,D8
    case 0x36:
    {
        uint16_t *address = new uint16_t();
        memcpy(address, &cpu_state.L, 1);
        memcpy((uint8_t *)address + 1, &cpu_state.H, 1);
        this->cpu_mem.translate(*address);
        cpu_state.pc++;
        delete address;
    }
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
    {
        uint16_t address = concat_address(opcode[2], opcode[1]);
        cpu_state.A = cpu_mem.mem_location[address];
        cpu_state.pc += 2;
    }
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
    // MVI A,D8
    case 0x3e:
        cpu_state.A = opcode[1];
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
    // MOV D,M
    case 0x56:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.D = cpu_mem.mem_location[address];
    }
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
    // MOV E,M
    case 0x5e:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.E = cpu_mem.mem_location[address];
    }
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
    // MOV H,M
    case 0x66:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.H = cpu_mem.mem_location[address];
    }
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
    // MOV L,A
    case 0x6f:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_state.L = cpu_mem.mem_location[address];
    }
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
    // MOV M,A
    case 0x77:
    {
        uint16_t address = concat_address(cpu_state.H, cpu_state.L);
        cpu_mem.mem_location[address] = cpu_state.A;
    }
    /* code */
    break;
    case 0x78:
        /* code */
        break;
    case 0x79:
        /* code */
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
        cpu_state.pc += 2;
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
        cpu_state.pc++;
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