#include "string.h"
#include "stdlib.h"

int atoi(const char *nptr) {
    int number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

int32_t atol(const char *nptr) {
    int32_t number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

int64_t atoll(const char *nptr) {
    int64_t number = 0;

    for (int multiplier = 1, i = strlen(nptr) - 1; i >= 0; multiplier *= 10, i--) {
        number += (nptr[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}

static uint16_t const __vitaut_str100p[100] = {
    0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830, 0x3930,
    0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731, 0x3831, 0x3931,
    0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632, 0x3732, 0x3832, 0x3932,
    0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533, 0x3633, 0x3733, 0x3833, 0x3933,
    0x3034, 0x3134, 0x3234, 0x3334, 0x3434, 0x3534, 0x3634, 0x3734, 0x3834, 0x3934,
    0x3035, 0x3135, 0x3235, 0x3335, 0x3435, 0x3535, 0x3635, 0x3735, 0x3835, 0x3935,
    0x3036, 0x3136, 0x3236, 0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3836, 0x3936,
    0x3037, 0x3137, 0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 0x3837, 0x3937,
    0x3038, 0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 0x3838, 0x3938,
    0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 0x3839, 0x3939
};

char *__vitaut_itoa(int32_t val, char *buf) {
    uint32_t comp_val = val;
    bool negative = false;
    if (val < 0) {
        comp_val = -1 * val;
        negative = true;
    }

    char *p = buf + 11;
    *p = '\0';

    while (comp_val >= 100) {
        const uint32_t old = comp_val;
        p -= 2;
        comp_val /= 100;
        memcpy(p, &__vitaut_str100p[old - (comp_val * 100)], sizeof(uint16_t));
    }

    p -= 2;
    memcpy(p, &__vitaut_str100p[comp_val], sizeof(uint16_t));

    char *ret = &p[comp_val < 10];
    if (negative) {
        --ret;
        *ret = '-';
    }
    return ret;
}

char *itoa(int32_t val, char *buf) {
    return __vitaut_iota(val, buf);
}

// this should be computed at link time, but a hardcoded value is fine for now
// remember that the kernel starts at 0x1000 as defined in the Makefile
uint32_t free_memory_address = 0x10000;

void *malloc(size_t size) { // the implementation is just a pointer to some free memory which keeps growing
    // pages are aligned to 4K, or 0x1000
    free_memory_address &= 0xFFFFF000;
    free_memory_address += 0x1000;

    uint32_t ret = free_memory_address;
    free_memory_address += size; // remember to increment the pointer

    return ret;
}
