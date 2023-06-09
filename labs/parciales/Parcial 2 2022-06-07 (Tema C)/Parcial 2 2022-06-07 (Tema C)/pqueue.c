#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    struct s_node **array;
    unsigned int size;
    priority_t _min_priority;
};

struct s_node {
    pqueue_elem elem;
    struct s_node *next;
};

static struct s_node 
*create_node(pqueue_elem e)
{
    struct s_node* new_node=NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;

    return(new_node);
}

static struct s_node 
*destroy_node(struct s_node *node)
{   
    assert(node != NULL);
    node->next = NULL;
    free(node);
    node = NULL;
    
    return(node);
}

/*
 * @DESC:
 *      Es una instancia de este TAD si se cumple
 *      
 *      1) Existencia: La cola esta inicializada
 * */

static bool 
invrep(pqueue q) 
{
    bool res = (q != NULL);

    return(res);
}

pqueue 
pqueue_empty(priority_t min_priority) 
{
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    assert(q != NULL);
    q->_min_priority = min_priority;
    q->size = 0u;
    q->array = calloc(min_priority + 1u, sizeof(struct s_node));
    assert(q->array != NULL);

    priority_t i = 0u;
    while(i <= min_priority)
    {
        q->array[i] = NULL;
        i = i + 1u;
    }

    assert(invrep(q) && pqueue_is_empty(q));
    return(q);
}

pqueue 
pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority)
{
    assert(invrep(q) && priority <= q->_min_priority);
    struct s_node *new_node = NULL;
    new_node = create_node(e);
   
    if(q->array[priority] == NULL)
    {
        q->array[priority] = new_node;
    }
    else
    {
        struct s_node *ps = NULL;
        ps = q->array[priority];
        while(ps->next != NULL)
        {
            ps = ps->next;
        }
        ps->next = new_node;
        ps = NULL;
    }

    q->size = q->size +1u;
    assert(invrep(q) && !pqueue_is_empty(q));
    return(q);
}

bool 
pqueue_is_empty(pqueue q)
{
    assert(invrep(q));

    return(q->size == 0u);
}

pqueue_elem 
pqueue_peek(pqueue q) 
{
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t i = 0u;
    while(q->array[i] == NULL)
    {
        i = i + 1u;
    }
    
    return(q->array[i]->elem); 
}

priority_t 
pqueue_peek_priority(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t max_p = 0u;
    while(q->array[max_p] == NULL)
    {
        max_p = max_p + 1u;
    }

    return(max_p); 
}

size_t 
pqueue_size(pqueue q)
{
    assert(invrep(q));
    return(q->size);
}

pqueue 
pqueue_dequeue(pqueue q) 
{
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t i = 0u;
    while(q->array[i] == NULL)
    {
        i = i + 1u;
    }
    struct s_node *ps = NULL;
    ps = q->array[i];
    q->array[i] = ps->next;
    ps = destroy_node(ps);
    q->size = q->size -1u;

    assert(invrep(q));
    return(q);
}

pqueue
pqueue_destroy(pqueue q)
{
    assert(invrep(q) );
    while (!pqueue_is_empty(q))
    {
        q = pqueue_dequeue(q);    
    }
    free(q->array);
    q->array = NULL;
    free(q);
    q = NULL;
    assert(q==NULL);
    return q;
}
