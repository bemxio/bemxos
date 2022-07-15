#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

void memcpy(char *destination, char *source, int amount);
void memset(uint8_t *destination, uint8_t value, uint32_t amount);
uint32_t malloc(uint32_t size, int align, uint32_t *physical_address);

#endif