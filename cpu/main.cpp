#include "cpu.h"
#include "state.h"
#include "../memory/memory.h"

int main() {
    uint8_t* location = new uint8_t[4000]();
    memory memory(location,4000);
    cpu::CPU cpu(memory);
    cpu.emulate();
}