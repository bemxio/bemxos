#include "../cpu/ports.h"
#include "../lib/string.h"
#include "screen.h"

// cursor offset stuff
int get_cursor_offset() {
    port_byte_out(REG_SCREEN_CONTROL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8;
    
    port_byte_out(REG_SCREEN_CONTROL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);

    return offset * 2;
}

void set_cursor_offset(int offset) {
    offset /= 2;

    port_byte_out(REG_SCREEN_CONTROL, 14);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));

    port_byte_out(REG_SCREEN_CONTROL, 15);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

// general functions for offset calculations
int get_offset(int column, int row) {
    return 2 * (row * MAX_COLUMNS + column);
}

int get_offset_row(int offset) {
    return offset / (2 * MAX_COLUMNS);
}

int get_offset_col(int offset) {
    return (offset - (get_offset_row(offset) * 2 * MAX_COLUMNS)) / 2;
}

// functions for printing something on the screen
int kprint_char(char character, int column, int row, char attributes) {
    unsigned char *memory = (unsigned char*) VIDEO_ADDRESS;
    int offset;
    
    if (column >= 0 && row >= 0) {
        offset = get_offset(column, row);
    } else {
        offset = get_cursor_offset();
    }

    if (character == '\n') {
        row = get_offset_row(offset);
        offset = get_offset(0, row + 1);
    } else {
        memory[offset] = character;
        memory[offset + 1] = attributes;

        offset += 2;
    }

    if (offset >= MAX_ROWS * MAX_COLUMNS * 2) {
        for (int i = 1; i < MAX_ROWS; i++) {
            memcpy(
                get_offset(0, i - 1) + VIDEO_ADDRESS,
                get_offset(0, i) + VIDEO_ADDRESS,
                MAX_COLUMNS * 2
            );
        }

        char *last_line = get_offset(0, MAX_ROWS - 1) + VIDEO_ADDRESS;

        for (int i = 0; i < MAX_COLUMNS * 2; i++) {
            last_line[i] = 0;
        }
        
        offset -= 2 * MAX_COLUMNS;
    }

    set_cursor_offset(offset);
    return offset;
}

int kprint_char_offset(char character, int offset, char attributes) {
    return kprint_char(character, get_offset_col(offset), get_offset_row(offset), attributes);
}

void kprint_at(char *string, int column, int row) {
    int offset;
    int i = 0;
    
    if (column >= 0 && row >= 0)
        offset = get_offset(column, row);
    else {
        offset = get_cursor_offset();

        row = get_offset_row(offset);
        column = get_offset_col(offset);
    }

    while (string[i] != 0) {
        offset = kprint_char(string[i++], column, row, WHITE_ON_BLACK);
        
        row = get_offset_row(offset);
        column = get_offset_col(offset);
    }
}

void kprint(char *string) {
    kprint_at(string, -1, -1);
}

void kprintln(char *string) {
    kprint(string);
    kprint("\n");
}

// a function for clearing the screen
void kclear() {
    int screen_size = MAX_COLUMNS * MAX_ROWS;
    char *screen = VIDEO_ADDRESS;

    for (int i = 0; i < screen_size; i++) {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE_ON_BLACK;
    }

    set_cursor_offset(get_offset(0, 0));
}