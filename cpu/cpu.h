#ifndef __CPU_H__
#define __CPU_H__

#include "state.h"

void unmapped_instruction();
void emulate(state state);

#endif