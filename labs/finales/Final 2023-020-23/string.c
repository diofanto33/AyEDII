#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

struct _string_t {
    char *content;
    unsigned int length;
};

string_t string_create(const char *word) {
    string_t str = NULL;
    str = calloc(1, sizeof(struct _string_t));
    str->length = strlen(word);
    str->content = calloc(str->length + 1, sizeof(char));
    str->content = strncpy(str->content, word, str->length + 1);
    return (str);
}

unsigned int string_length(string_t str) {
    return (str->length);
}

bool string_eq(const string_t str1, const string_t str2) {
    int cmp = strcmp(str1->content, str2->content);
    return (cmp == 0);
}

string_t string_clone(const string_t str) {
    return (string_create(str->content));
}


string_t string_destroy(string_t str) {
    free(str->content);
    free(str);
    str = NULL;
    return (str);
}

const char* string_ref(string_t str) {
    return str->content;
}

void string_dump(string_t str, FILE *file) {
    fprintf(file, "%s", str->content);
}
