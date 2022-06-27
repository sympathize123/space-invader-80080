#ifndef __REGISTER_H__
#define __REGISTER_H__

#include <stdint.h>
#include "conditional_code.h"

namespace registers {
    typedef struct __16Bregister {
        uint8_t B;
        uint8_t C;
        uint8_t D;
        uint8_t E;
        uint8_t H;
        uint8_t L;
        uint8_t A;
        uint16_t sp;
        uint16_t pc;
        flags flag;
    };
}
#endif