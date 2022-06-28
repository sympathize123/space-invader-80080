#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

struct memory 
{
    memory();    
    memory(uint8_t* location, int size);
    uint8_t* mem_location;
    uint16_t mem_size;
};

#endif