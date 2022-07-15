#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

/// This container stores a string split up by whitespace
/// and quotation canaries in order to tokenize the
/// internal string by allowing it to be treated
/// as multiple smaller strings by virtue of the
/// indices provided by the struct.
///
/// The `str` member contains the internal string, and
/// the `indices` member points to an array of `char *`
/// which point to each token within the internal `str`.
/// The size attribute describes the size of the array
/// pointer to by `indices`.
struct tokenized_string {
    char* str;
    char** indices;
    size_t size;
};

/// frees a `tokenized_string` struct and its subsequent member pointers
void free_tokenized_string(struct tokenized_string *tsp);

/// Instantiates a `tokenized_string` with the string passed to it.
/// The string passed to this factory function is a RHS string that
/// is copied within the function. The `str` member of `tokenized_string`
/// is the copied string.
struct tokenized_string *tokenize_string(const char *source_str);

#endif
