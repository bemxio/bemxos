#include "../drivers/screen.h"
#include "commands.h"

void help(struct tokenized_string *tokens) {
    kprintln("All of the commands:");
    kprintln("`help` - shows this list");
    kprintln("`echo` - prints the first argument that is provided");
}

void echo(struct tokenized_string *tokens) {
    kprintln(tokens->indices[1]);
}