#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stdio.h>

typedef struct _string_t* string_t;

/* Creates a new string copying the characters
 * of the given [word].
 */
string_t string_create(const char *word);

/* Returns the length of the given string [str]
 */
unsigned int string_length(string_t str);

/* Returns true if [str1] is alphabetically before than [str2] (strictly), or
 * false otherwise.
 */
bool string_less(string_t str1, string_t str2);

/* Returns true if [str1] is equal to [str2], or false otherwise. */
bool string_eq(string_t str1, string_t str2);

/* Retuns a clone of the string [str] */
string_t string_clone(string_t str);

/* Destroys the string, freeing all the allocated resources */
string_t string_destroy(string_t str);

/* Returns a reference to the string, as a pointer to a constant sequence
 * of characters. 
*/
const char* string_ref(string_t str);

/* Prints the string in the given [file] */
void string_dump(string_t str, FILE *file);

#endif
