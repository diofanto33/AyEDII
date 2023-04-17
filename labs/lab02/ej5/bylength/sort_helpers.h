#ifndef _SORT_HELPERS_H
#define _SORT_HELPERS_H

#include <stdbool.h>

#include "fixstring.h"

bool goes_before(fixstring x, fixstring y);
/* Abstract total order for sorting algorithms */

bool array_is_sorted(fixstring a[], unsigned int length);
/* Checks if the array 'a' is in ascending order */

void swap(fixstring a[], unsigned int i, unsigned int j);
/* Exchanges elements of array 'a' in the given positions 'i' and 'j'
   Array remains the same if the two positions are the same
*/

#endif
