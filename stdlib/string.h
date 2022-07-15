#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

int strlen(char string[]);
void strrev(char string[]);
char* strcpy(char *to, const char *from);

void itoa(int value, char string[]);

bool chrinstr(char character, char *string);
int strint(char *string);

#endif