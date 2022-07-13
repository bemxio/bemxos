#ifndef UTILITIES_H
#define UTILITIES_H

#include "../cpu/types.h"
#include <stdbool.h>

void memory_copy(char *source, char *destination, int nbytes);
void memory_set(u8 *destination, u8 value, u32 length);

void itoa(int value, char string[]);
void strrev(char string[]);
int strlen(char string[]);
bool charinstr(char character, char *string);

#endif