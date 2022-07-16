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

// NON-STANDARD FUNCTION (BemxOS extension)
//
// DESCRIPTION
// The `itoa` function converts a signed 32-bit into a string pointed to by `buf`.
// A `char` buffer of at least size 12 must be passed to `itoa`, otherwise its
// behavior is undefined.
//
// RETURNS
// The `itoa` function returns a pointer to the beginning of the new numerical string.
// If the returned `char *` is not used in place of the passed `char` buffer, its
// behavior is undefined.
char *itoa(char *buf, int32_t val);

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
