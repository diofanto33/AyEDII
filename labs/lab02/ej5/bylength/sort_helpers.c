#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void
swap(fixstring a[], unsigned int i, unsigned int j)
{
	fstring_swap(a[i], a[j]);
}

bool
goes_before(fixstring x, fixstring y)
{
	bool res;
	unsigned int x_len = fstring_length(x);
	unsigned int y_len = fstring_length(y);
	res = x_len <= y_len;
	return res;
}

bool
array_is_sorted(fixstring array[], unsigned int length)
{
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i]))
	{
        i++;
    }
    return (i >= length);
}
