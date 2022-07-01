#include "state.h"
#include "../memory/memory.h"

flags::flags() : all(0) {

}

void flags::reset() {
    all = 0;
}

uint8_t state::parity(uint8_t state) {
    uint8_t result = 0;
    uint8_t mask = 0x1;
    for(int i = 0;i < 8;i++, mask <<= 1){
        state & mask ? result = 1 : result = 0;
        state >>= 1;
    };
    return result;
}

state::state() {
    this->B = 0;
    this->C = 0;
    this->D = 0;
    this->E = 0;
    this->H = 0;
    this->L = 0;
    this->A = 0;
    this->sp = 0;
    this->pc = 0;
    this->enable = 0;
    this->flag = flags();
}

