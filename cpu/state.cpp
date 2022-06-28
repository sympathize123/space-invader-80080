#include "state.h"

flags::flags() : all(0) {

}

memory::memory() {
    this->mem_location = 0;
    this->mem_size = 0;
}

memory::memory(uint8_t* location, int size) {
    this->mem_location = location;
    this->mem_size = size;
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
    this->cpu_mem = memory();
    this->flag = flags();
}

