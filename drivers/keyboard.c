#include "../cpu/isr.h"
#include "../kernel/utilities.h"

#include "keyboard.h"
#include "screen.h"
#include "ports.h"

#include <stdbool.h>

bool capitalized = false;
char buffer[64] = {};

static void keyboard_callback(registers_t registers) {
    u8 code = port_byte_in(0x60); // the PIC leaves us the scancode in port 0x60

    if (code >= 128) { // 'keyup' event corresponds to the 'keydown' + 0x80 
        process_key(code - 128, true);
    } else {
        process_key(code, false);
    }
}

/*
static void test_keyboard_callback(registers_t registers) {
    u8 code = port_byte_in(0x60);
    
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

void handle_input(); // TODO: handle input

void process_key(u8 code, bool state) {
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

            key = bindings[code][0];

            if (!capitalized && charinstr(key, capitalizable)) {
                key += 32;
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