#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

#include "../lib/string.h"
#include "../cpu/isr.h"

#include "commands.h"
#include "parser.h"

#define FUNC_AMOUNT 3
#define PROMPT "$ "

char *names[FUNC_AMOUNT] = {"help", "echo", "clear"};
void (*addresses[FUNC_AMOUNT])(struct tokenized_string *) = {&help, &echo, &clear};

void command_error(char *exception) {
    kprint("error: ");
    kprintln(exception);
}

void input_callback(char *buffer) {
    struct tokenized_string *tokens = tokenize_string(buffer);
    char *name = tokens->indices[0]; // the command name
    int index = -1;

    if (strlen(name) == 0) { // nothing got typed in
        return kprint(PROMPT);
    } else {
        index = findsubstr(names, name, FUNC_AMOUNT);
    }
    
    if (index == -1) { // command name not found
        command_error("command not found");
    } else {
        (*addresses[index])(tokens);
    }

    kprint(PROMPT);
}

void kernel_main() {
    kclear();

    kprintln("\nbemxOS v0.2.3 (very early beta tester alpha verison!!!)");
    kprintln("type 'help' to check all of the commands :)\n");

    kprint(PROMPT);
    
    isr_install();
    irq_install();
}