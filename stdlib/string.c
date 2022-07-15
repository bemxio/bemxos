#include "string.h"

// functions present in the original stdlib
int strlen(char string[]) {
    int length = 0;

    while (string[length] != '\0') {
        ++length;
    }

    return length;
}

void strrev(char string[]) {
    char character;
    int length = strlen(string) - 1;

    for (int index = 0; index < length; index++) {
        character = string[index];
        string[index] = string[length];
        string[length] = character;
    }
}

void itoa(int value, char string[]) {
    int i = 0, sign;

    if ((sign = value) < 0) {
        value = -value;
    }

    do {
        string[i++] = value % 10 + '0';
    } while ((value /= 10) > 0);

    if (sign < 0) {
        string[i++] = '-';
    }

    string[i] = '\0';

    strrev(string);
}

char* strcpy(char *to, const char *from) {
    char *save = to;

    while ((*to = *from) != '\0') {
        ++from;
        ++to;
    }

    return save;
}

// my AWESOME and COOL functions (very cool and awesome)
bool chrinstr(char character, char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == character) {
            return true;
        }
    }

    return false;
}

int strint(char *string) {
    int number = 0;

    for (int multiplier = 1, i = strlen(string) - 1; i >= 0; multiplier *= 10, i--) {
        number += (string[i] - 48) * multiplier; // 48 is the ASCII code for '0'
    }

    return number;
}