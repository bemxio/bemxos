#ifndef MEMORY_H
#define MEMORY_H

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