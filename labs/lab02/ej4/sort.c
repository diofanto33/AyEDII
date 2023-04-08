#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int 
min_pos_from(int a[], unsigned int i, unsigned int length)
{
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) 
	{
        if (!goes_before(a[min_pos],a[j])) 
		{
            min_pos = j;
        }
    }
    return (min_pos);
}

void 
selection_sort(int a[], unsigned int length)
{
    for (unsigned int i = 0u; i < length; ++i)
	{
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void 
insert(int a[], unsigned int i)
{
	unsigned int j = i;
	while(j > 0 && goes_before(a[j], a[j-1]))
	{
		swap(a, j-1, j);
		j = j - 1;
	}
}

void 
insertion_sort(int a[], unsigned int length)
{
    for (unsigned int i = 1u; i < length; ++i)
	{
        insert(a, i);
    	assert(array_is_sorted(a, i));
	}
}

static unsigned int 
partition(int a[], unsigned int izq, unsigned int der)
{
	unsigned int ppiv = izq;
	unsigned int i = izq + 1u;
	unsigned int j = der;
	while(i <= j)
	{
		if(goes_before(a[i], a[ppiv]))
		{
			i = i + 1u;
		}
		else if(goes_before(a[ppiv], a[j]))
		{
			j = j - 1u;
		}
		else if(goes_before(a[ppiv], a[i]) && goes_before(a[j], a[ppiv]))
		{
			swap(a, i, j);
			i = i + 1u;
			j = j - 1u;
		}
	}
	swap(a, ppiv, j);
	ppiv = j;
	return ppiv;
}

static void 
quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
	if(der > izq)
	{
		unsigned int ppiv = partition(a, izq, der);
		quick_sort_rec(a, izq, ppiv == 0u ? 0u : ppiv - 1u);
		quick_sort_rec(a, ppiv+1, der);
	}
}

void 
quick_sort(int a[], unsigned int length) 
{
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
