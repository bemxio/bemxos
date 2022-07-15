#ifndef STRING_H
#define STRING_H

#include "boolean.h"

int strlen(char string[]);
void strrev(char string[]);
void itoa(int value, char string[]);

bool chrstr(char character, char *string);

#endif