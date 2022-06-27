#include "opcode.h"
#include <cstdio>
#include <string>

using namespace std;

int make_opcode(string code, int pc)
{
    int opbytes = 1;
    printf ("%04x ", pc);
    switch ((unsigned char) code[pc])
    {
    case 0x00:
        printf("NOP\n");
        break;
    case 0x01:
        printf("LXI \n");
        break;
    case 0x02:
        printf("STAX\n");
        break;
    case 0x03:
        printf("INX \n");
        break;
    case 0x04:
        printf("INR \n");
        break;
    case 0x05:
        printf("DCR \n");
        break;
    case 0x06:
        printf("MVI \n");
        break;
    case 0x07:
        printf("RLC\n");
        break;
    case 0x08:
        printf("-	\n");
        break;
    case 0x09:
        printf("DAD \n");
        break;
    case 0x0a:
        printf("LDAX\n");
        break;
    case 0x0b:
        printf("DCX \n");
        break;
    case 0x0c:
        printf("INR \n");
        break;
    case 0x0d:
        printf("DCR \n");
        break;
    case 0x0e:
        printf("MVI \n");
        break;
    case 0x0f:
        printf("RRC\n");
        break;
    case 0x10:
        printf("-	\n");
        break;
    case 0x11:
        printf("LXI \n");
        break;
    case 0x12:
        printf("STAX\n");
        break;
    case 0x13:
        printf("INX \n");
        break;
    case 0x14:
        printf("INR \n");
        break;
    case 0x15:
        printf("DCR \n");
        break;
    case 0x16:
        printf("MVI \n");
        break;
    case 0x17:
        printf("RAL\n");
        break;
    case 0x18:
        printf("-	\n");
        break;
    case 0x19:
        printf("DAD \n");
        break;
    case 0x1a:
        printf("LDAX\n");
        break;
    case 0x1b:
        printf("DCX \n");
        break;
    case 0x1c:
        printf("INR \n");
        break;
    case 0x1d:
        printf("DCR \n");
        break;
    case 0x1e:
        printf("MVI \n");
        break;
    case 0x1f:
        printf("RAR\n");
        break;
    case 0x20:
        printf("RIM\n");
        break;
    case 0x21:
        printf("LXI \n");
        break;
    case 0x22:
        printf("SHLD\n");
        break;
    case 0x23:
        printf("INX \n");
        break;
    case 0x24:
        printf("INR \n");
        break;
    case 0x25:
        printf("DCR \n");
        break;
    case 0x26:
        printf("MVI \n");
        break;
    case 0x27:
        printf("DAA\n");
        break;
    case 0x28:
        printf("-	\n");
        break;
    case 0x29:
        printf("DAD \n");
        break;
    case 0x2a:
        printf("LHLD\n");
        break;
    case 0x2b:
        printf("DCX \n");
        break;
    case 0x2c:
        printf("INR \n");
        break;
    case 0x2d:
        printf("DCR \n");
        break;
    case 0x2e:
        printf("MVI \n");
        break;
    case 0x2f:
        printf("CMA\n");
        break;
    case 0x30:
        printf("SIM\n");
        break;
    case 0x31:
        printf("LXI \n");
        break;
    case 0x32:
        printf("STA \n");
        break;
    case 0x33:
        printf("INX \n");
        break;
    case 0x34:
        printf("INR \n");
        break;
    case 0x35:
        printf("DCR \n");
        break;
    case 0x36:
        printf("MVI \n");
        break;
    case 0x37:
        printf("STC\n");
        break;
    case 0x38:
        printf("-	\n");
        break;
    case 0x39:
        printf("DAD \n");
        break;
    case 0x3a:
        printf("LDA \n");
        break;
    case 0x3b:
        printf("DCX \n");
        break;
    case 0x3c:
        printf("INR \n");
        break;
    case 0x3d:
        printf("DCR \n");
        break;
    case 0x3e:
        printf("MVI \n");
        break;
    case 0x3f:
        printf("CMC\n");
        break;
    case 0x40:
        printf("MOV \n");
        break;
    case 0x41:
        printf("MOV \n");
        break;
    case 0x42:
        printf("MOV \n");
        break;
    case 0x43:
        printf("MOV \n");
        break;
    case 0x44:
        printf("MOV \n");
        break;
    case 0x45:
        printf("MOV \n");
        break;
    case 0x46:
        printf("MOV \n");
        break;
    case 0x47:
        printf("MOV \n");
        break;
    case 0x48:
        printf("MOV \n");
        break;
    case 0x49:
        printf("MOV \n");
        break;
    case 0x4a:
        printf("MOV \n");
        break;
    case 0x4b:
        printf("MOV \n");
        break;
    case 0x4c:
        printf("MOV \n");
        break;
    case 0x4d:
        printf("MOV \n");
        break;
    case 0x4e:
        printf("MOV \n");
        break;
    case 0x4f:
        printf("MOV \n");
        break;
    case 0x50:
        printf("MOV \n");
        break;
    case 0x51:
        printf("MOV \n");
        break;
    case 0x52:
        printf("MOV \n");
        break;
    case 0x53:
        printf("MOV \n");
        break;
    case 0x54:
        printf("MOV \n");
        break;
    case 0x55:
        printf("MOV \n");
        break;
    case 0x56:
        printf("MOV \n");
        break;
    case 0x57:
        printf("MOV \n");
        break;
    case 0x58:
        printf("MOV \n");
        break;
    case 0x59:
        printf("MOV \n");
        break;
    case 0x5a:
        printf("MOV \n");
        break;
    case 0x5b:
        printf("MOV \n");
        break;
    case 0x5c:
        printf("MOV \n");
        break;
    case 0x5d:
        printf("MOV \n");
        break;
    case 0x5e:
        printf("MOV \n");
        break;
    case 0x5f:
        printf("MOV \n");
        break;
    case 0x60:
        printf("MOV \n");
        break;
    case 0x61:
        printf("MOV \n");
        break;
    case 0x62:
        printf("MOV \n");
        break;
    case 0x63:
        printf("MOV \n");
        break;
    case 0x64:
        printf("MOV \n");
        break;
    case 0x65:
        printf("MOV \n");
        break;
    case 0x66:
        printf("MOV \n");
        break;
    case 0x67:
        printf("MOV \n");
        break;
    case 0x68:
        printf("MOV \n");
        break;
    case 0x69:
        printf("MOV \n");
        break;
    case 0x6a:
        printf("MOV \n");
        break;
    case 0x6b:
        printf("MOV \n");
        break;
    case 0x6c:
        printf("MOV \n");
        break;
    case 0x6d:
        printf("MOV \n");
        break;
    case 0x6e:
        printf("MOV \n");
        break;
    case 0x6f:
        printf("MOV \n");
        break;
    case 0x70:
        printf("MOV \n");
        break;
    case 0x71:
        printf("MOV \n");
        break;
    case 0x72:
        printf("MOV \n");
        break;
    case 0x73:
        printf("MOV \n");
        break;
    case 0x74:
        printf("MOV \n");
        break;
    case 0x75:
        printf("MOV \n");
        break;
    case 0x76:
        printf("HLT\n");
        break;
    case 0x77:
        printf("MOV \n");
        break;
    case 0x78:
        printf("MOV \n");
        break;
    case 0x79:
        printf("MOV \n");
        break;
    case 0x7a:
        printf("MOV \n");
        break;
    case 0x7b:
        printf("MOV \n");
        break;
    case 0x7c:
        printf("MOV \n");
        break;
    case 0x7d:
        printf("MOV \n");
        break;
    case 0x7e:
        printf("MOV \n");
        break;
    case 0x7f:
        printf("MOV \n");
        break;
    case 0x80:
        printf("ADD \n");
        break;
    case 0x81:
        printf("ADD \n");
        break;
    case 0x82:
        printf("ADD \n");
        break;
    case 0x83:
        printf("ADD \n");
        break;
    case 0x84:
        printf("ADD \n");
        break;
    case 0x85:
        printf("ADD \n");
        break;
    case 0x86:
        printf("ADD \n");
        break;
    case 0x87:
        printf("ADD \n");
        break;
    case 0x88:
        printf("ADC \n");
        break;
    case 0x89:
        printf("ADC \n");
        break;
    case 0x8a:
        printf("ADC \n");
        break;
    case 0x8b:
        printf("ADC \n");
        break;
    case 0x8c:
        printf("ADC \n");
        break;
    case 0x8d:
        printf("ADC \n");
        break;
    case 0x8e:
        printf("ADC \n");
        break;
    case 0x8f:
        printf("ADC \n");
        break;
    case 0x90:
        printf("SUB \n");
        break;
    case 0x91:
        printf("SUB \n");
        break;
    case 0x92:
        printf("SUB \n");
        break;
    case 0x93:
        printf("SUB \n");
        break;
    case 0x94:
        printf("SUB \n");
        break;
    case 0x95:
        printf("SUB \n");
        break;
    case 0x96:
        printf("SUB \n");
        break;
    case 0x97:
        printf("SUB \n");
        break;
    case 0x98:
        printf("SBB \n");
        break;
    case 0x99:
        printf("SBB \n");
        break;
    case 0x9a:
        printf("SBB \n");
        break;
    case 0x9b:
        printf("SBB \n");
        break;
    case 0x9c:
        printf("SBB \n");
        break;
    case 0x9d:
        printf("SBB \n");
        break;
    case 0x9e:
        printf("SBB \n");
        break;
    case 0x9f:
        printf("SBB \n");
        break;
    case 0xa0:
        printf("ANA \n");
        break;
    case 0xa1:
        printf("ANA \n");
        break;
    case 0xa2:
        printf("ANA \n");
        break;
    case 0xa3:
        printf("ANA \n");
        break;
    case 0xa4:
        printf("ANA \n");
        break;
    case 0xa5:
        printf("ANA \n");
        break;
    case 0xa6:
        printf("ANA \n");
        break;
    case 0xa7:
        printf("ANA \n");
        break;
    case 0xa8:
        printf("XRA \n");
        break;
    case 0xa9:
        printf("XRA \n");
        break;
    case 0xaa:
        printf("XRA \n");
        break;
    case 0xab:
        printf("XRA \n");
        break;
    case 0xac:
        printf("XRA \n");
        break;
    case 0xad:
        printf("XRA \n");
        break;
    case 0xae:
        printf("XRA \n");
        break;
    case 0xaf:
        printf("XRA \n");
        break;
    case 0xb0:
        printf("ORA \n");
        break;
    case 0xb1:
        printf("ORA \n");
        break;
    case 0xb2:
        printf("ORA \n");
        break;
    case 0xb3:
        printf("ORA \n");
        break;
    case 0xb4:
        printf("ORA \n");
        break;
    case 0xb5:
        printf("ORA \n");
        break;
    case 0xb6:
        printf("ORA \n");
        break;
    case 0xb7:
        printf("ORA \n");
        break;
    case 0xb8:
        printf("CMP \n");
        break;
    case 0xb9:
        printf("CMP \n");
        break;
    case 0xba:
        printf("CMP \n");
        break;
    case 0xbb:
        printf("CMP \n");
        break;
    case 0xbc:
        printf("CMP \n");
        break;
    case 0xbd:
        printf("CMP \n");
        break;
    case 0xbe:
        printf("CMP \n");
        break;
    case 0xbf:
        printf("CMP \n");
        break;
    case 0xc0:
        printf("RNZ\n");
        break;
    case 0xc1:
        printf("POP \n");
        break;
    case 0xc2:
        printf("JNZ \n");
        break;
    case 0xc3:
        printf("JMP \n");
        break;
    case 0xc4:
        printf("CNZ \n");
        break;
    case 0xc5:
        printf("PUSH\n");
        break;
    case 0xc6:
        printf("ADI \n");
        break;
    case 0xc7:
        printf("RST \n");
        break;
    case 0xc8:
        printf("RZ	\n");
        break;
    case 0xc9:
        printf("RET\n");
        break;
    case 0xca:
        printf("JZ a\n");
        break;
    case 0xcb:
        printf("-	\n");
        break;
    case 0xcc:
        printf("CZ a\n");
        break;
    case 0xcd:
        printf("CALL\n");
        break;
    case 0xce:
        printf("ACI \n");
        break;
    case 0xcf:
        printf("RST \n");
        break;
    case 0xd0:
        printf("RNC\n");
        break;
    case 0xd1:
        printf("POP \n");
        break;
    case 0xd2:
        printf("JNC \n");
        break;
    case 0xd3:
        printf("OUT \n");
        break;
    case 0xd4:
        printf("CNC \n");
        break;
    case 0xd5:
        printf("PUSH\n");
        break;
    case 0xd6:
        printf("SUI \n");
        break;
    case 0xd7:
        printf("RST \n");
        break;
    case 0xd8:
        printf("RC	\n");
        break;
    case 0xd9:
        printf("-	\n");
        break;
    case 0xda:
        printf("JC a\n");
        break;
    case 0xdb:
        printf("IN D\n");
        break;
    case 0xdc:
        printf("CC a\n");
        break;
    case 0xdd:
        printf("-	\n");
        break;
    case 0xde:
        printf("SBI \n");
        break;
    case 0xdf:
        printf("RST \n");
        break;
    case 0xe0:
        printf("RPO\n");
        break;
    case 0xe1:
        printf("POP \n");
        break;
    case 0xe2:
        printf("JPO \n");
        break;
    case 0xe3:
        printf("XTHL\n");
        break;
    case 0xe4:
        printf("CPO \n");
        break;
    case 0xe5:
        printf("PUSH\n");
        break;
    case 0xe6:
        printf("ANI \n");
        break;
    case 0xe7:
        printf("RST \n");
        break;
    case 0xe8:
        printf("RPE\n");
        break;
    case 0xe9:
        printf("PCHL\n");
        break;
    case 0xea:
        printf("JPE \n");
        break;
    case 0xeb:
        printf("XCHG\n");
        break;
    case 0xec:
        printf("CPE \n");
        break;
    case 0xed:
        printf("-	\n");
        break;
    case 0xee:
        printf("XRI \n");
        break;
    case 0xef:
        printf("RST \n");
        break;
    case 0xf0:
        printf("RP	\n");
        break;
    case 0xf1:
        printf("POP \n");
        break;
    case 0xf2:
        printf("JP a\n");
        break;
    case 0xf3:
        printf("DI	\n");
        break;
    case 0xf4:
        printf("CP a\n");
        break;
    case 0xf5:
        printf("PUSH\n");
        break;
    case 0xf6:
        printf("ORI \n");
        break;
    case 0xf7:
        printf("RST \n");
        break;
    case 0xf8:
        printf("RM	\n");
        break;
    case 0xf9:
        printf("SPHL\n");
        break;
    case 0xfa:
        printf("JM a\n");
        break;
    case 0xfb:
        printf("EI	\n");
        break;
    case 0xfc:
        printf("CM a\n");
        break;
    case 0xfd:
        printf("-	\n");
        break;
    case 0xfe:
        printf("CPI \n");
        break;
    case 0xff:
        printf("RST \n");
        break;
    }
    return opbytes;
}