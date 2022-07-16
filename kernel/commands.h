#ifndef COMMANDS_H
#define COMMANDS_H

#include "parser.h"

void help(struct tokenized_string *tokens);
void echo(struct tokenized_string *tokens);
void clear(struct tokenized_string *tokens);

#endif