#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

struct _s_stack_node {
    stack_elem elem;
    struct _s_stack_node* next;
};

struct _s_stack {
    unsigned int size;
 	struct _s_stack_node* first_node;
};

/* @brief 
 * Private function to check the representation invariant of the stack ADT
 * @param s A stack 
 * @return true if the representation invariant holds
 * @return false otherwise
 */

static bool 
invrep(stack s)
{	
	bool b = (s != NULL);
	if(b)
	{	
		struct _s_stack_node *p = s->first_node;
		unsigned int length = 0u;
		while(p != NULL)
		{
			length = length + 1u;
			p = p->next;
		}
		b = (s->size == length);
	}
	return(b);
}

stack
stack_empty()
{	
	stack s = calloc(1, sizeof(stack));
	s->first_node = NULL;

	assert(invrep(s));

	return(s);
}

stack
stack_push(stack s, stack_elem e)
{
	assert(invrep(s));

	struct _s_stack_node *sp = malloc(sizeof(struct _s_stack_node));
	sp->elem = e;
	sp->next = s->first_node;
	s->first_node = sp;
	s->size = s->size + 1u;	

	assert(invrep);

	return(s);
}

stack
stack_pop(stack s)
{
	assert(invrep(s));	

	struct _s_stack_node *sp = NULL;
	sp = s->first_node;
	s->first_node = s->first_node->next;
	s->size = s->size -1u;
	free(sp);
	sp = NULL;

	return(s);
}

unsigned int 
stack_size(stack s)
{
	assert(invrep(s));
	return(s->size);
}

stack_elem
stack_top(stack s)
{
	assert(invrep(s));
	return(s->first_node->elem);
}

bool stack_is_empty(stack s)
{
	return(s->size == 0);
}

stack_elem 
*stack_to_array(stack s)
{
	stack_elem *a = NULL;
	if(invrep(s) && !stack_is_empty(s))
	{
		a = calloc(s->size, sizeof(stack_elem));
		unsigned int n = s->size;
		struct _s_stack_node *sp = NULL;
		sp = s->first_node;
		while(n != 0)
		{
			a[n-1u] = sp->elem;
			sp = sp->next;
			n = n -1u;
		}
	}
	return(a);
}

stack 
stack_destroy(stack s)
{	
	assert(invrep(s));
	struct _s_stack_node *sp = NULL;
	sp = s->first_node;
	while(sp != NULL)
	{	
		s->first_node = s->first_node->next;
		free(sp);
		sp = s->first_node;
	}
	sp = NULL;
	free(s);
	s = NULL;
	return(s);
}
