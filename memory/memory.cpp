#include "memory.h"

memory::memory() {
    this->mem_location = 0;
    this->mem_size = 0;
}

memory::memory(uint8_t* location, int size) {
    this->mem_location = location;
    this->mem_size = size;
}

uint16_t memory::translate(uint16_t address){
    while (address >= this->mem_size) {
        address -= this->mem_size;
    }
    return address;
}

uint8_t memory::read_memory(uint16_t in_address)
{
    uint16_t address = translate(in_address);
    uint8_t value = this->mem_location[address];
    return value;
}

void memory::write_memory(uint16_t in_address, uint8_t value) {
    uint16_t address = translate(in_address);
    if(address < this->mem_size)
        this->mem_location[address] = value;
}