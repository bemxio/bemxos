#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "parser.h"


void text_mode() {
    isr_install();
    irq_install();

    kclear();
    
    kprintln("\nbemxOS v0.1.0 (very early beta tester alpha verison!!!)");
    kprintln("for now, this is only a text editor with no option to save lmao");
    kprintln("but still, hope you have fun :3\n");

    init_keyboard();
}

void parser_test() {
    kclear();

    struct tokenized_string *ts = tokenize_string("this is \"a string\" in quotes");

    for (char **it = ts->indices; it < ts->indices + ts->size; ++it) {
        kprintln(*it);
    }
}

void kernel_main() {
    text_mode();
    //parser_test();
}