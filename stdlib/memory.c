#include "memory.h"

void memcpy(char *destination, char *source, int amount) {
    for (int i = 0; i < amount; i++) {
        *(destination + i) = *(source + i);
    }
}

void memset(u8 *destination, u8 value, u32 amount) {
    for (u8 *temporary = (u8 *)destination; amount != 0; amount--) {
        *temporary++ = value;
    }
}