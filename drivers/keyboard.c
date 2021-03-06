#include "../kernel/kernel.h"

#include "../cpu/ports.h"
#include "../cpu/isr.h"

#include "../lib/string.h"
#include <stdbool.h>

#include "keyboard.h"
#include "screen.h"

// bindings for scancodes
char *bindings[] = {
    "ERROR", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", 
    "-", "=", "BACKSPACE", "\t", "q", "w", "e", "r", "t", "y", "u",
    "i", "o", "p", "[", "]", "ENTER", "LCTRL", "a", "s", "d", "f",
    "g", "h", "j", "k", "l", ";", "'", "`", "LSHIFT", "\\", "z",
    "x", "c", "v", "b", "n", "m", ",", ".", "/", "RSHIFT", "PRTSC",
    "ALT", " "
};
char *alt_bindings[] = {
    "ERROR", "ESC", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", 
    "_", "+", "BACKSPACE", "\t", "Q", "W", "E", "R", "T", "Y", "U",
    "I", "O", "P", "{", "}", "ENTER", "LCTRL", "A", "S", "D", "F",
    "G", "H", "J", "K", "L", ":", "\"", "~", "LSHIFT", "|", "Z",
    "X", "C", "V", "B", "N", "M", "<", ">", "?", "RSHIFT", "PRTSC",
    "ALT", " "
};

bool capitalized = false;
char buffer[64] = {};

void process_key(uint8_t code, bool state) {
    int length;
    char key;

    switch (code) {
        case 0:
        case 1:
        case 29:
        case 55:
        case 56:
            break;
        
        case 42:
        case 54: // shift keys
            capitalized = !capitalized;
            break;
        
        case 28: // enter key
            if (state) {
                break;
            }
            
            kprint("\n");

            input_callback(buffer);
            buffer[0] = '\0';
        
        case 14: // backspace
            if (state || strlen(buffer) == 0) { // key up or the buffer is empty
                break;
            }

            int offset = get_cursor_offset();
            offset -= 2; // shift the offset by a cell

            kprint_char_offset('\0', offset, WHITE_ON_BLACK); // clear the cell
            set_cursor_offset(offset);

            length = strlen(buffer);

            buffer[length - 1] = '\0';
            break;
        
        default:
            if (state || strlen(buffer) >= 63) { // key up or buffer too big
                break;
            }

            if (!capitalized) {
                key = bindings[code][0];
            } else {
                key = alt_bindings[code][0];
            }

            kprint_char(key, -1, -1, WHITE_ON_BLACK);

            length = strlen(buffer);
            
            //buffer[length] = key[0]; // so that we take the char out of the string
            buffer[length] = key;
            buffer[length + 1] = '\0';

            //println(buffer);

            break;
    }
}

static void keyboard_callback(registers_t registers) {
    uint8_t code = port_byte_in(0x60); // the PIC leaves us the scancode in port 0x60

    if (code >= 128) { // 'keyup' event corresponds to the 'keydown' + 0x80 
        process_key(code - 128, true);
    } else {
        process_key(code, false);
    }
}

/*
static void test_keyboard_callback(registers_t registers) {
    uint8_t code = port_byte_in(0x60);
    
    if (code >= 128) {
        code -= 128;
    }

    for (int i = 7; i >= 0; i--) {
        if (code & (1 << i)) {
            kprint("1");
        } else {
            kprint("0");
        }
    }

    kprint("\n");
}
*/

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback); 
    //register_interrupt_handler(IRQ1, test_keyboard_callback);
}