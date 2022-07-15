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

// this should be computed at link time, but a hardcoded value is fine for now
// remember that the kernel starts at 0x1000 as defined in the Makefile
u32 free_memory_address = 0x10000;

u32 malloc(u32 size, int align, u32 *physical_address) { // the implementation is just a pointer to some free memory which keeps growing
    // pages are aligned to 4K, or 0x1000
    if (align == 1 && (free_memory_address & 0xFFFFF000)) {
        free_memory_address &= 0xFFFFF000;
        free_memory_address += 0x1000;
    }
    
    // also save the physical address
    if (physical_address) {
        *physical_address = free_memory_address;
    }

    u32 ret = free_memory_address;
    free_memory_address += size; // remember to increment the pointer

    return ret;
}