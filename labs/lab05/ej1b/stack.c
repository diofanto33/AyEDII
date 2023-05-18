#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

/*
 *  @invrep():
 * 	
 * 	La pila no puede tener mas de MAX_STACK_SIZE elementos
 *  
 *  0 <= s->size < MAX_STACK_SIZE
 *
 * */

#define MAX_STACK_SIZE 100

struct _s_stack {
	stack_elem array[MAX_STACK_SIZE];
	unsigned int size;
};

stack
stack_empty()
{
	stack s = calloc(1, sizeof(struct _s_stack));
	s->size = 0;
	return(s);
}

stack
stack_push(stack s, stack_elem e)
{
	assert(s->size < MAX_STACK_SIZE);
	s->array[s->size] = e;
	s->size = s->size + 1;

	return(s);
}

stack
stack_pop(stack s)
{
	assert(s->size != 0);	
	s->size = s->size - 1;
	return(s);
}

unsigned int 
stack_size(stack s)
{
	return(s->size);
}

stack_elem
stack_top(stack s)
{
	assert(s->size != 0);
	return(s->array[s->size - 1]);
}

bool stack_is_empty(stack s)
{
	return(s->size == 0);
}

stack_elem 
*stack_to_array(stack s)
{
	stack_elem *a = NULL;
	if(s->size)
	{
		unsigned int n = stack_size(s);	
		a = calloc(n, sizeof(stack_elem));
		while( n != 0)
		{
			a[n-1] = s->array[n-1];
			n = n - 1u;
		}
	}
	return(a);
}

stack 
stack_destroy(stack s)
{
	s->size = 0;	
	return(s);
}
