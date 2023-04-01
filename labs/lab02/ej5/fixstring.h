#ifndef _FIXSTRING_H_
#define _FIXSTRING_H_

#include <stdbool.h>

#define FIXSTRING_MAX 100

typedef char fixstring [FIXSTRING_MAX];

unsigned int fstring_length(fixstring s);
/*
 * Returns the length of the string <s>
 *
 */


bool fstring_eq(fixstring s1, fixstring s2);
/*
 * Indicates if <s1> has the same content than string <s2>
 *
 */

bool fstring_less_eq(fixstring s1, fixstring s2);
/*
 * Indicates if string <s1> is less than string <s2> using alphabetical order
 *
 */


void fstring_set(fixstring s1, const fixstring s2);
/*
 * Sets the string <s1> with the content of <s2>
 *
 */

void fstring_swap(fixstring s1,  fixstring s2);
/*
 * Swap the contents of string <s1> and <s2>
 *
 */




#endif

