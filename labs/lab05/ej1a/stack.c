#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

struct _s_stack {
	stack_elem value;
	struct _s_stack *next;
};

stack
stack_empty()
{
	stack s = NULL;
	
	return(s);
}

stack
stack_push(stack s, stack_elem e)
{
	stack sp = malloc(sizeof(stack));
	sp->value = e;
	sp->next = s;

	return(sp);
}

stack
stack_pop(stack s)
{
	assert(s != NULL);
	
	stack sp = s;
	s = s->next;
	free(sp);
	
	return(s);
}

unsigned int 
stack_size(stack s)
{
	unsigned int length = 0;
	while(s != NULL)
	{
		length = length + 1;
		s = s->next;
	}
	return(length);
}

stack_elem
stack_top(stack s)
{
	assert(s != NULL);
	return(s->value);
}

bool stack_is_empty(stack s)
{
	bool b = (s == NULL);
	return(b);
}

stack_elem 
*stack_to_array(stack s)
{
	stack_elem *array = NULL;
	if(s != NULL)
	{	
		stack sp = s;
		unsigned int n = stack_size(s);	
		array = calloc(n, sizeof(stack_elem));
		while(n != 0)
		{
			array[n-1] = sp->value;
			sp = sp->next;
			n = n - 1;
		}
		sp = NULL;
	}
	return(array);
}

stack 
stack_destroy(stack s)
{
	stack p;
	while(s != NULL)
	{
		p = s;
		s = s->next;
		free(p);
	}
	return(s);
}
