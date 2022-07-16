#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>

int strlen(char string[]);
void strrev(char string[]);
char* strcpy(char *to, const char *from);

void itoa(int value, char string[]);

bool chrinstr(char character, char *string);
int findsubstr(char **source, char *substring, size_t length);
int strint(char *string);
bool strcmp(char *first, char *second);

#endif