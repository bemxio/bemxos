#include "../drivers/screen.h"
#include "commands.h"

void help(struct tokenized_string *tokens) {
    kprintln("All of the commands:");

    kprintln("`help` - shows this list");
    kprintln("`echo` - prints arguments that were provided for the command");
    kprintln("`clear` - clears the screen");
}

void echo(struct tokenized_string *tokens) {
    char **it = tokens->indices;
    ++it; // so that it skips the first token
    
    while (it < tokens->indices + tokens->size) {
        kprintln(*it);
        ++it;
    }
}

void clear(struct tokenized_string *tokens) {
    kclear();
}