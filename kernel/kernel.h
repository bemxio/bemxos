#ifndef KERNEL_H
#define KERNEL_H

// this header exists so that keyboard.c can include it and
// execute the input_callback() function when the ENTER key is pressed
void input_callback(char *buffer);

#endif