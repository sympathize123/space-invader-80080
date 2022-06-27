#ifndef __STATE_H__
#define __STATE_H__

#include <stdint.h>

struct flags
{
    flags();

    void reset();

    union
    {
        struct
        {
            uint8_t z : 1;
            uint8_t c : 1;
            uint8_t auxc : 1;
            uint8_t p : 1;
            uint8_t s : 1;
            uint8_t pad : 3;
        };
        uint8_t all;
    };
};

struct state
{
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
    uint8_t *mem;
    uint8_t enable;
};
#endif