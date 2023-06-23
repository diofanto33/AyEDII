#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t list_from_file(const char *filepath) {
    FILE *file = NULL;
    list_t output = list_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(file)) {
        unsigned int key;
        char value;
        int res = fscanf(file," %u %c ", &key, &value);
        if (res != 2) {
            fprintf(stderr, "Invalid list.\n");
            exit(EXIT_FAILURE);
        }
        output = list_add(output, key, value);
    }
    fclose(file);
    assert(output != NULL);
    return output;
}

void list_dump(list_t list) {
    unsigned int size = list_length(list);
    if (size > 0) {
        list_value* elems = list_to_array(list);
        printf("[ ");
        for (unsigned int i=0; i + 1 < size; i++) {
            printf("%c, ", elems[i]);
        }
        printf("%c ]\n\n", elems[size - 1]);
        free(elems);
    } else {
        printf("{}");
    }
}
