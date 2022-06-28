#include "memory.h"

memory::memory() {
    this->mem_location = 0;
    this->mem_size = 0;
}

memory::memory(uint8_t* location, int size) {
    this->mem_location = location;
    this->mem_size = size;
}