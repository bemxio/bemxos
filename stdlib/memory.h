#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

void memcpy(char *destination, char *source, int amount);
void memset(u8 *destination, u8 value, u32 amount);

#endif