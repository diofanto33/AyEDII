#ifndef _LIST_HELPERS_H
#define _LIST_HELPERS_H

#include <stdbool.h>

void list_dump(list_t list);
/*
    Write the content of the list_t 'list' into stdout.
*/


list_t list_from_file(const char *filepath);
/*
    Each element is read from the file located at 'filepath'.
    The file must exist in disk and must have its contents in the following
    format:

    <key_1> <value_2> <key_2> <value_2> ... <key_N> <value_N>

    Those elements are stored in a new instance of list.

    If something goes wrong in loading process, the funciton aborts.

    Returns the instance of list where the elements were loaded.

*/

#endif
