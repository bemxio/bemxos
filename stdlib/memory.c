#include "memory.h"

void memcpy(char *destination, char *source, int amount) {
    for (int i = 0; i < amount; i++) {
        *(destination + i) = *(source + i);
    }
}

void memset(uint8_t *destination, uint8_t value, uint32_t amount) {
    for (uint8_t *temporary = (uint8_t *)destination; amount != 0; amount--) {
        *temporary++ = value;
    }
}

// this should be computed at link time, but a hardcoded value is fine for now
// remember that the kernel starts at 0x1000 as defined in the Makefile
uint32_t free_memory_address = 0x10000;

uint32_t malloc(uint32_t size, int align, uint32_t *physical_address) { // the implementation is just a pointer to some free memory which keeps growing
    // pages are aligned to 4K, or 0x1000
    if (align == 1 && (free_memory_address & 0xFFFFF000)) {
        free_memory_address &= 0xFFFFF000;
        free_memory_address += 0x1000;
    }
    
    // also save the physical address
    if (physical_address) {
        *physical_address = free_memory_address;
    }

    uint32_t ret = free_memory_address;
    free_memory_address += size; // remember to increment the pointer

    return ret;
}