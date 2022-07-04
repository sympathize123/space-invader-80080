#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

struct memory 
{
    memory();    
    memory(uint8_t* location, int size);
    uint16_t translate(uint16_t address);
    uint8_t read_memory(uint16_t in_address);
    void write_memory(uint16_t in_address, uint8_t value);
    uint8_t* mem_location;
    uint16_t mem_size;
};

uint16_t concat_address(uint8_t high, uint8_t low);

#endif