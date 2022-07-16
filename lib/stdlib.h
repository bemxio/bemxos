#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>
#include <stdint.h>

// ISO/IEC 9899:TC3 (C99) - 7.20.1.2
//
// DESCRIPTION
// The `atoi`, `atol`, and `atoll` functions convert the initial portion of the string pointed
// to by `nptr` to `int`, `long int`, and `long long int` representation, respectively.
// Except for the behavior on error, they are equivalent to:
//      `atoi: (int)strtol(nptr, (char **)NULL, 10)`
//      `atol: strtol(nptr, (char **)NULL, 10)`
//      `atoll: strtoll(nptr, (char **)NULL, 10)`
//
// RETURNS
// The `atoi`, `atol`, and `atoll` functions return the converted value.
int atoi(const char *nptr);
long int atol(const char *nptr);
long long int atoll(const char *nptr);

// TODO: rewrite `itoa()` to not use `strrev()`
void itoa(int value, char string[]);

// ISO/IEC 9899:TC3 (C99) - 7.21.6.1
//
// DESCRIPTION
// The `malloc` function allocates space for an object whose size is specified by `size` and
// whose value is indeterminate.
//
// RETURNS
// The malloc function returns either a null pointer or a pointer to the allocated space.
void *malloc(size_t size);

#endif