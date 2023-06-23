#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

static bool 
invrep(stack s)
{	
    return(s != NULL && s->elems != NULL && s->size <= s->capacity);
}

stack 
stack_empty()
{
    stack s = NULL;
    s = malloc(sizeof(struct _s_stack));
	
    s->elems = NULL;
    s->elems = calloc(10, sizeof(stack_elem));
	
    s->size = 0u;
    s->capacity = 10u;
	
    assert(invrep(s));
	
    return(s);
}

stack
stack_push(stack s, stack_elem e)
{
    assert(invrep(s));
    if(s->size == s->capacity)
    {
        unsigned int double_capacity = (s->capacity)*2;
	    s->elems = realloc(s->elems, double_capacity*sizeof(stack_elem));
	    s->elems[s->size] = e;
	    s->size = s->size + 1;
	    s->capacity = double_capacity;
    }
    else
    {
	    s->elems[s->size] = e;
	    s->size = s->size + 1;
    }
    assert(invrep(s));
    return(s);
}

/*  No liberamos memoria del array.
 *  Suprimimos los elementos decrementando s->size
 */

stack
stack_pop(stack s)
{
    assert(invrep(s) && s->size != 0);
    s->size = s->size - 1u;
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
    assert(invrep(s) && s->size != 0);
    stack_elem *p = NULL;
    p = s->elems;
    unsigned int i = s->size - 1u;
    while(i != 0)
    {
	    p = p + 1;
	    i = i - 1u;
    }
    return(*p);
}

bool
stack_is_empty(stack s)
{
    return(s->size == 0);
}

stack_elem
*stack_to_array(stack s)
{
    stack_elem *sp = NULL;
    if(s->size != 0)
    {
	    sp = calloc(s->size, sizeof(stack_elem));
	    unsigned int i = 0u;
	    while(i < s->size)
	    {
	        sp[i] = s->elems[i];
	        i = i + 1;
	    }
    }
    return(sp);
}

stack 
stack_destroy(stack s)
{
    assert(invrep(s));
    free(s->elems);
    s->elems = NULL;
    free(s);
    s = NULL;
    return(s);
}
