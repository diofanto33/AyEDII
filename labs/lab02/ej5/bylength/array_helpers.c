#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "fixstring.h"

#define STR_VALUE(x) STR(x)
#define STR(x) #x

void array_copy(fixstring copy[], fixstring array[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        fstring_set(copy[i], array[i]);
    }
}

unsigned int array_value_count(fixstring a[], unsigned int length, fixstring value) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < length; i++) {
        if (fstring_eq(a[i], value)) {
            count++;
        }
    }
    return (count);
}

void array_dump(fixstring a[], unsigned int length) {
    fprintf(stdout, "%u\n", length);
    for (unsigned int i = 0; i < length; i++) {
        fprintf(stdout, "%s", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}


bool array_is_permutation_of(fixstring a[], fixstring b[], unsigned int length) {
    unsigned int i = 0;
    bool result = true;
    while (i < length && result) {
        unsigned int a_count = array_value_count(a, length, a[i]);
        unsigned int b_count = array_value_count(b, length, a[i]);
        result = (a_count == b_count);
        i++;
    }
    return (result);
}

unsigned int array_from_file(fixstring array[],
                 unsigned int max_size,
                 const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0;
    unsigned int size = 0;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    if (size > max_size) {
        fprintf(stderr, "Allowed size is %d.\n", max_size);
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        res = fscanf(file," %" STR_VALUE(FIXSTRING_MAX) "s ", array[i]);
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    fclose(file);
    return (size);
}
