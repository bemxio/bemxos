#include "string.h"
#include "stdlib.h"

int atoi(const char *nptr) {
    int number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

long int atol(const char *nptr) {
    long int number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

long long int atoll(const char *nptr) {
    long long int number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

void itoa(int value, char string[]);

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