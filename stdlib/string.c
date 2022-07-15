#include "string.h"

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

bool chrstr(char character, char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == character) {
            return true;
        }
    }

    return false;
}