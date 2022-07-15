#include "../stdlib/memory.h"
#include "../stdlib/string.h"
#include "parser.h"

/*
// frees a `tokenized_string` struct and its subsequent member pointers
void free_tokenized_string(struct tokenized_string *tsp) {
    free(tsp->str);
    free(tsp->indices);
    free(tsp);
}

// frees the subsequent pointers of a `tokenized_string` struct
void free_tokenized_string(struct tokenized_string tsv) {
    free(tsv.str);
    free(tsv.indices);
}
*/

struct tokenized_string *tokenize_string(const char *source_str) {
    char *str = (char *)malloc(strlen(source_str) + 1, 1, NULL);
    
    strcpy(str, source_str);

    const size_t _len = strlen(str);
    size_t indices_arraysize = 1;

    for (char *c = str; c < str + _len; ++c) {
        if (*c == ' ') {
            *c = '\0';
            ++indices_arraysize;
        } else if (*c == '\"') {
            if ((c == str || *(c - 1) != '\\') && c != (str + _len)) {
                char *d = c + 1;
                if (*d != '\0') {
                    while (d <= str + _len) {
                        if (*d == '\"') {
                            break;
                        }

                        ++d;
                    }

                    if (d <= str + _len) {
                        *c = '\2';
                        *d = '\3';
                        c = d;
                    }
                }
            }
        }
    }

    char **indices = (char **)malloc(sizeof(*indices) * indices_arraysize, 1, NULL);
    size_t idx = 0;
    indices[idx++] = str;

    for (char *c = str; c < str + _len; ++c) {
        if (*c == '\0') {
            if (*(c + 1) == '\2') {
                indices[idx++] = c + 2;
            } else {
                indices[idx++] = c + 1;
            }
        }

        if (*c == '\3') {
            *c = '\0';
        }
    }

    if (indices[0][0] == '\2') {
        indices[0] += 1;
    }

    struct tokenized_string *ts = (struct tokenized_string *)malloc(sizeof(*ts), 1, NULL);

    ts->str = str;
    ts->indices = indices;
    ts->size = indices_arraysize;

    return ts;
}