#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

struct tokenized_string {
    char* str;
    char** indices;
    size_t size;
};

/*
void free_tokenized_string(struct tokenized_string *tsp);
void free_tokenized_string(struct tokenized_string tsv);
*/

struct tokenized_string *tokenize_string(const char *source_str);

#endif