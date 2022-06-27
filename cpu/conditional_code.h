#ifndef __CONDITIONAL_CODE_H__
#define __CONDITIONAL_CODE_H__

#include <stdint.h>

struct flags {
    flags();

    void reset();

    union {
        struct {
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

#endif