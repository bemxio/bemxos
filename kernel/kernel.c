#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

#include "../stdlib/string.h"
#include "../cpu/isr.h"

#include "commands.h"
#include "parser.h"

#define PROMPT "$ "

char **names[2] = {"help", "echo"};
int (*addresses[2])(struct tokenized_string *) = {&help, &echo};

void command_error(char *exception) {
    kprint("error: ");
    kprintln(exception);
}

void input_callback(char *buffer) {
    struct tokenized_string *tokens = tokenize_string(buffer);
    char *name = tokens->indices[0]; // the command name

    int index = findsubstr(names, name, 2);

    if (index == -1) { // command name not found
        command_error("command not found");
    } else {
        (*addresses[index])(tokens);
    }

    kprint(PROMPT);
}

void kernel_main() {
    kclear();

    kprintln("\nbemxOS v0.2.0 (very early beta tester alpha verison!!!)");
    kprintln("type 'help' to check all of the commands :)\n");

    kprint(PROMPT);
    
    isr_install();
    irq_install();

    init_keyboard();
}