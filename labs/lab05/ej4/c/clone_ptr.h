#ifndef CLONE_PTR_H 
#define CLONE_PTR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * @brief: Clones a string into a new memory location.
 * @param: str - The string to clone.
 * @param: length - The length of the string to clone.
 * @return: A pointer to the new string.
 * @note: The caller is responsible for freeing the memory.
 * @note: If the string is NULL, NULL is returned.
 * @note: If the length is 0, NULL is returned.
 * @note: If the string is not NULL and the length is 0, 
 * NULL is returned.
 */

char
*string_clone(const char *str, size_t length);

#endif
