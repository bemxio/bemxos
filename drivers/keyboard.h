#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../stdlib/types.h"

// binding for scancodes
char *bindings[] = {
    "ERROR",
    "ESC",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    "-",
    "=",
    "BACKSPACE",
    "TAB",
    "Q",
    "W",
    "E",
    "R",
    "T",
    "Y",
    "U",
    "I",
    "O",
    "P",
    "[",
    "]",
    "\n",
    "LCTRL",
    "A",
    "S",
    "D",
    "F",
    "G",
    "H",
    "J",
    "K",
    "L",
    ";",
    "'",
    "`",
    "LSHIFT",
    "\\",
    "Z",
    "X",
    "C",
    "V",
    "B",
    "N",
    "M",
    ",",
    ".",
    "/",
    "RSHIFT",
    "PRTSC",
    "ALT",
    " "
};
char *capitalizable = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void init_keyboard();

#endif