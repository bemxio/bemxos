#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>

// ISO/IEC 9899:TC3 (C99) - 7.21.2.1
//
// DESCRIPTION
// The `memcpy` function copies `n` characters from the object pointed to by `s2` into the
// object pointed to by `s1`. If copying takes place between objects that overlap, the behavior
// is undefined.
//
// RETURNS
// The `memcpy` function returns the value of `s1`.
void *memcpy(void * restrict s1, void * restrict s2, size_t n);

// ISO/IEC 9899:TC3 (C99) - 7.21.6.1
//
// DESCRIPTION
// The memset function copies the value of `c` (converted to an `unsigned char`) into
// each of the first `n` characters of the object pointed to by `s`.
//
// RETURNS
// The `memset` function returns the value of `s`.
void *memset(void *s, int c, size_t n);

// ISO/IEC 9899:TC3 (C99) - 7.21.6.3
//
// DESCRIPTION
// The `strlen` function computes the length of the string pointed to by `s`.
// 
// RETURNS
// The `strlen` function returns the number of characters that precede the terminating null character.
size_t strlen(const char *s);

// ISO/IEC 9899:TC3 (C99) - 7.21.2.3
//
// DESCRIPTION
// The `strcpy` function copies the string pointed to by `s2` (including the terminating null
// character) into the array pointed to by `s1`. If copying takes place between objects that
// overlap, the behavior is undefined.
//
// RETURNS
// The `strcpy` function returns the value of `s1`.
char *strcpy(char * restrict s1, const char * restrict s2);
 
// ISO/IEC 9899:TC3 (C99) - 7.21.4.2
//
// DESCRIPTION
// The strcmp function compares the string pointed to by s1 to the string pointed to by s2.
//
// RETURNS
// The strcmp function returns an integer greater than, equal to, or less than zero,
// accordingly as the string pointed to by s1 is greater than, equal to, or less than the string
int strcmp(const char *s1, const char *s2);

// NON-STANDARD FUNCTION
//
// DESCRIPION
// The `findsubstr` function will iterate over the array of strings pointed to by `source`.
// If it finds a string in the array that matches the string pointed to by `substring`, it
// will return an index of the said string.
//
// RETURNS
// The `findsubstr` function returns the index of the string in
// the array of strings.
size_t findsubstr(char **source, char *substring, size_t length);

#endif