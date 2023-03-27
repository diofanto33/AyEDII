#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

#include <stdbool.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath);


void array_dump(int a[], unsigned int length);

bool array_is_sorted(int a[], unsigned int length);

void array_swap(int a[], unsigned int i, unsigned int j);

void reverse_array(int a[], unsigned int length);

#endif /* ARRAY_HELPERS_H */
