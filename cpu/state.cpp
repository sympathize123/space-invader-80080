#include "state.h"
#include "memory.h"

flags::flags() : all(0) {

}

void flags::reset() {
    all = 0;
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
    this->cpu_mem = memory();
    this->flag = flags();
}

