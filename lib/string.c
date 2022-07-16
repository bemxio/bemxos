#include "string.h"

void *memcpy(void * restrict s1, void * restrict s2, size_t n) {
    char *destination = s1;
    const char *source = s2;

    while (n--) {
        *destination++ = *source++;
    }
    
    return s1;
}

void *memset(void *s, int c, size_t n) {
    for (uint8_t *t = (uint8_t *)s; n != 0; n--) {
        *t++ = c;
    }

    return s;
}

size_t strlen(const char *s) {
    size_t i = 0;

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