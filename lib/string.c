#include "string.h"

size_t strlen(const char *s) {
    int i = 0;

    while (s[i] != '\0') {
        ++i;
    }

    return i;
}

char *strcpy(char * restrict s1, const char * restrict s2) {
    while ((*s1 = *s2) != '\0') {
        ++s2;
        ++s1;
    }

    return s1;
}

int atoi(const char *nptr) {
    int number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

size_t findsubstr(char **source, char *substring, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (strcmp(source[i], substring) == 0) {
            return i;
        }
    }

    return -1;
}