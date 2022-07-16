#include "memory.h"

void *memcpy(void * restrict s1, void * restrict s2, size_t n) {
    for (int i = 0; i < n; i++) {
        *(s1 + i) = *(s2 + i);
    }

    return s1;
}

void *memset(void *s, int c, size_t n) {
    for (uint8_t *t = (uint8_t *)s; n != 0; n--) {
        *t++ = c;
    }

    return s;
}

// this should be computed at link time, but a hardcoded value is fine for now
// remember that the kernel starts at 0x1000 as defined in the Makefile
uint32_t free_memory_address = 0x10000;

void *malloc(size_t size) { // the implementation is just a pointer to some free memory which keeps growing
    // pages are aligned to 4K, or 0x1000
    free_memory_address &= 0xFFFFF000;
    free_memory_address += 0x1000;

    uint32_t ret = free_memory_address;
    free_memory_address += size; // remember to increment the pointer

    return ret;
}