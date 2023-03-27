#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath);


void array_dump(int a[], unsigned int length);

#endif /* ARRAY_HELPERS_H */
