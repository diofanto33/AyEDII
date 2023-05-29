#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;
	struct s_node *first;
};

struct s_node {
	pqueue_elem elem;
	unsigned int _priority;
	struct s_node *next;
};

static struct s_node 
*create_node(pqueue_elem e, unsigned int priority)
{
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
	new_node->_priority = priority;
	new_node->next = NULL;
    return(new_node);
}

static struct s_node 
*destroy_node(struct s_node *node) 
{
    assert(node != NULL);
    free(node);
    node = NULL;
    return(node);
}

static bool
invrep(pqueue q) 
{
    bool res = (q != NULL);
    if(res && q->size != 0u && q->first != NULL)
	{
		struct s_node *cp = NULL;
		cp = q->first;
		unsigned int length = 1u;
		while(cp->next != NULL)
		{
			res = res && cp->_priority <= cp->next->_priority;
			length = length + 1u;
			cp = cp->next;
		}
		res = res && length==q->size;
	}
    return(res);
}

pqueue
pqueue_empty(void)
{
    pqueue q=NULL;
   	q = malloc(sizeof(struct s_pqueue));
	q->size = 0u;
	q->first = NULL;
	assert(invrep(q));
    return(q);
}

pqueue 
pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority)
{
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
	if(q->size == 0u && q->first == NULL)
	{
		q->first = new_node;
	}
	else
	{
		struct s_node *cp = NULL;
		struct s_node *prev = NULL;
		cp = q->first;
		while(cp->next != NULL && cp->_priority <= priority)
		{	
			prev = cp;
			cp = cp->next;
		}
		if(cp->_priority > priority)
		{
			new_node->next = cp;
			if(prev != NULL)
			{
				prev->next = new_node;
			}
			else
			{
				q->first = new_node;
			}
		}
		else
		{
			new_node->next = cp->next;
			cp->next = new_node;
		}
		cp = NULL;
		prev = NULL;
	}
	q->size = q->size + 1u;
    assert(invrep(q));
    return(q);
}

bool
pqueue_is_empty(pqueue q)
{	
	assert(invrep(q));
	bool res = (q->size == 0u && q->first == NULL);    
    return(res);
}

pqueue_elem
pqueue_peek(pqueue q)
{
	assert(!pqueue_is_empty(q) && invrep(q));
	return(q->first->elem);
}

unsigned int 
pqueue_peek_priority(pqueue q)
{	
	assert(invrep(q) && !pqueue_is_empty(q));
	return(q->first->_priority);
}

unsigned int 
pqueue_size(pqueue q) 
{
    assert(invrep(q));
    return(q->size);
}

pqueue
pqueue_dequeue(pqueue q)
{
 	assert(!pqueue_is_empty(q));
	struct s_node *cp = NULL;
	cp = q->first;
	q->first = cp->next;
	cp = destroy_node(cp);
    q->size = q->size -1u;
	assert(invrep(q));

	return(q);
}

pqueue 
pqueue_destroy(pqueue q) 
{
    assert(invrep(q));
   	struct s_node *cp = NULL;
	struct s_node *prev = NULL;
	cp = q->first;
	while(cp != NULL)
	{
		prev = cp;
		cp = cp->next;
		prev = destroy_node(prev);
	}
	free(q);
	q = NULL;
    
	return(q);
}
