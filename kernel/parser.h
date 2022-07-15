#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

// this container stores a string split up by whitespace and quotation bodies
struct tokenized_string {
    char* str; // points to the internal tokenized string
    char** indices; // Points to an array of `size` `char *`s, all of which point to the beginning of each subsequent token
    size_t size; // the size index of the indices array (the byte size is calculated as `size * sizeof *indices`)
};

/// frees a `tokenized_string` struct and its subsequent member pointers
void free_tokenized_string(struct tokenized_string *tsp);

/// instantiates a `tokenized_string` with the string passed to it
/// `source_str` is a RHS string that whose copy is assigned as the internal `str` member of the corresponding `tokenized_string`
struct tokenized_string *tokenize_string(const char *source_str);

#endif
