#ifndef SCREEN_H
#define SCREEN_H

// constants
#define VIDEO_ADDRESS 0xb8000
#define WHITE_ON_BLACK 0x0f

#define MAX_ROWS 25
#define MAX_COLUMNS 80

#define REG_SCREEN_CONTROL 0x3d4
#define REG_SCREEN_DATA 0x3d5

// functions
int get_cursor_offset();
void set_cursor_offset(int offset);

int get_offset(int column, int row);

int get_offset_row(int offset);
int get_offset_col(int offset);

int kprint_char(char character, int column, int row, char attributes);
int kprint_char_offset(char character, int offset, char attributes);
void kprint_at(char *string, int column, int row);

void kprint(char *string);
void kprintln(char *string);
void kclear();

#endif