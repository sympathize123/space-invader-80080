#include "cpu.h"
#include "state.h"
#include "../memory/memory.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int ReadFileIntoMemoryAt(cpu::CPU &state, char *filename, uint32_t offset)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("error: Couldn't open %s\n", filename);
        exit(1);
    }
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    uint8_t *buffer = &state.cpu_mem.mem_location[offset];
    fread(buffer, fsize, 1, f);
    fclose(f);
    return offset + fsize;
}

int main()
{
    int eof;
    uint8_t *location = new uint8_t[0x10000]();
    memory memory(location, 0x10000);
    cpu::CPU cpu(memory);
    ReadFileIntoMemoryAt(cpu, "../invaders.h", 0);
    ReadFileIntoMemoryAt(cpu, "../invaders.g", 0x800);
    ReadFileIntoMemoryAt(cpu, "../invaders.f", 0x1000);
    eof = ReadFileIntoMemoryAt(cpu, "../invaders.e", 0x1800);
    while (cpu.cpu_state.pc != eof)
        cpu.emulate();
}