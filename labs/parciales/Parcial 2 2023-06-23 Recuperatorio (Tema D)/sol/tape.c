#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "tape.h"

struct _s_node {
    tape_elem elem;
    struct _s_node *next;
};

typedef struct _s_node * node_t;

struct _s_tape {
    unsigned int size;
    node_t cursor;  // Puntero al elemento actual
    node_t start;   // Puntero al primer nodo de la cinta
};

/*
 * @desc:	Chequea que se cumplan:
 * 
 *	1) Existencia: El tad fue inicializado correctamente
 *	2) Consistencia: debe ser consistente la relacion entre 
 * 		el size y la cantidad de nodos calculada.
 */

static bool 
invrep(tape_t tape)
{	
	bool check = (tape != NULL);
    if(check)
    {
    	node_t sp = tape->start;
    	unsigned int len = 0u;
		while(sp != NULL)
		{
			len = len + 1u;
			sp = sp->next;
		}
		check = (len==tape->size);	
	}

	return(check);
}

static node_t 
create_node(tape_elem e)
{
    struct _s_node *new_node=malloc(sizeof(struct _s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;

    return(new_node);
}

static node_t 
destroy_node(node_t killme)
{
    killme->next=NULL;
    free(killme);
    killme=NULL;

    return(killme);
}

tape_t 
tape_create(void) 
{
	tape_t tape=NULL;
    
    tape = malloc(sizeof(struct _s_tape));
    assert(tape != NULL);
    tape->cursor = NULL;
    tape->start = NULL;
    tape->size = 0u;
	assert(invrep(tape) && tape_is_empty(tape) && tape_at_start(tape));
    
    return(tape);
}

tape_t 
tape_rewind(tape_t tape) 
{	
	assert(invrep(tape));
	tape->cursor = tape->start;
	assert(invrep(tape) && tape_at_start(tape));

	return(tape);
}


bool 
tape_at_start(tape_t tape) 
{
	assert(invrep(tape));
	
	return(tape->cursor==tape->start);
}

bool 
tape_at_stop(tape_t tape)
{
	assert(invrep(tape));
	bool stop = (tape->cursor==NULL && !tape_is_empty(tape));

	return(stop);
}

bool 
tape_is_empty(tape_t tape) 
{
	assert(invrep(tape));

	return(tape->size==0u);   
}

unsigned int 
tape_length(tape_t tape) 
{	
	assert(invrep(tape));
	return(tape->size);
}

tape_t 
tape_step(tape_t tape) 
{
	assert(invrep(tape));
	if(tape->cursor != NULL)
	{
		tape->cursor = tape->cursor->next;
	}
	assert(invrep(tape));

	return(tape);
}

tape_t 
tape_insertl(tape_t tape, tape_elem e) 
{
    assert(invrep(tape));
    node_t new_node = create_node(e);
    if(tape_is_empty(tape))
    {
    	tape->start = new_node;
    	tape->cursor = new_node;
    }
    else
    {	
    	node_t sp = tape->start;
    	node_t prev = NULL;
    	while(sp != tape->cursor)
    	{
    		prev = sp;
    		sp = sp->next;
    	}
    	if(prev != NULL)
    	{
    		prev->next = new_node;
    		new_node->next = sp;
    	}
    	else
    	{
    		tape->start = new_node;
    		new_node->next = sp;
    	}
    	tape->cursor = new_node;
    }
  	tape->size = tape->size + 1u;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));

    return(tape);
}

tape_t tape_insertr(tape_t tape, tape_elem e) {
    assert(invrep(tape) && (!tape_at_stop(tape) || tape_is_empty(tape)));
    node_t new_node=create_node(e);
    if (tape->start!= NULL) {
        new_node->next = tape->cursor->next;
        tape->cursor->next = new_node;
        tape->cursor = new_node;
    } else {
        tape->start = new_node;
        tape->cursor = new_node;
    }
    tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t 
tape_erase(tape_t tape) 
{
	assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape));

	node_t killme = tape->start;
	node_t prev = NULL;
	while(killme != tape->cursor)
	{	
		prev = killme;
		killme = killme->next;
	}
	tape->cursor = tape->cursor->next;
	if(prev != NULL)
	{
		prev->next = killme->next;
	}
	else
	{
		tape->start = tape->start->next;
	}
	killme = destroy_node(killme);
	tape->size = tape->size -1u;
	prev = NULL;
	assert(invrep(tape));

	return(tape);
}

tape_elem 
tape_read(tape_t tape)
{
 	assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape));

 	return(tape->cursor->elem);
}

void tape_dump(tape_t tape) {
    assert(invrep(tape));
    node_t node=tape->start;
    printf("#");
    while (node != NULL) {
        if (node != tape->cursor) {
            printf("-%c-", node->elem);
        } else {
            printf("-[%c]-", node->elem);
        }
        node = node->next;
    }
    if (tape->cursor==NULL) {
        printf("-[]-");
    }
    printf("#\n");
}

tape_t 
tape_copy(tape_t tape) 
{
  tape_t copy = tape_create();
  copy->cursor = NULL;
  copy->start = NULL;
  node_t sp = tape->start;
  while(sp != NULL)
  {
  	copy = tape_insertr(copy, sp->elem);
  	sp = sp->next;
  }
  copy = tape_rewind(copy); 
  assert(copy != tape && tape_at_start(copy) && 
         tape_length(tape) == tape_length(copy));

  return(copy);
}

tape_t 
tape_destroy(tape_t tape) 
{
 	assert(invrep(tape));
    node_t killme = tape->start;
    while(tape->start != NULL)
	{
        tape->start = tape->start->next;
        killme = destroy_node(killme);
        killme = tape->start;
    }
    free(tape);
    tape = NULL;
    assert(tape == NULL);

    return(tape);
}