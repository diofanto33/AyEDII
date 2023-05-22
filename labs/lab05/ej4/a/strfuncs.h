#ifndef STRFUNCS_H
#define STRFUNCS_H 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * @brief: calculate the length of a string 
 * @param: str, the string to be calculated
 * @return: the length of the string 
 */

size_t string_length(const char *str);


/*
 * @brief: create a new string in heap containing
 * the same characters as the given string str, not 
 * containing the given character c.
 * 
 * @brief: filter the character c from the string str
 *
 * @param: str, the string to be copied
 * @param: c, the character to be filtered
 * @return: the new string without the character c
 */

char *string_filter(char *str, char c);

#endif // STRFUNCS_H
