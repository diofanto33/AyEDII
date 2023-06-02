#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    struct s_node **array;
    priority_t _max_priority_;
    unsigned int size;
};

struct s_node {
    pstack_elem elem;
    struct s_node *next;
};

static struct s_node 
*create_node(pstack_elem e) 
{
    struct s_node *new_node = NULL;
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


static bool 
invrep(pstack s) 
{
    bool res = (s != NULL); 
    
    return(res);
}

pstack
pstack_empty(priority_t max_priority)
{
    pstack s=NULL;
    s = malloc(sizeof(struct s_pstack));
    assert(s != NULL);

    s->array = NULL;
    /* 0 - max_priority */ 
    s->array = calloc(max_priority + 1, sizeof(struct s_node *));
    assert(s->array != NULL);
    
    s->_max_priority_ = max_priority;
    s->size = 0u;
    
    /* inicializa cada nodo en NULL */
    priority_t i = 0u;
    priority_t max = s->_max_priority_;
    while(i <= max)
    {
        s->array[i] = NULL;
        i = i + 1u;
    }
    
    assert(invrep(s) && pstack_is_empty(s));

    return(s);
}

pstack
pstack_push(pstack s, pstack_elem e, priority_t priority) 
{
    assert(invrep(s) && priority <= s->_max_priority_);
    struct s_node *new_node = create_node(e);
    new_node->next = s->array[priority];
    s->array[priority] = new_node;
    s->size = s->size + 1u;

    assert(invrep(s) && !pstack_is_empty(s));
    return(s);
}

bool 
pstack_is_empty(pstack s)
{
    assert(invrep(s));
    
    return(s->size == 0u);
}

pstack_elem
pstack_top(pstack s) 
{
    assert(invrep(s) && !pstack_is_empty(s));
    priority_t i = s->_max_priority_;
    while(s->array[i] == NULL)
    {
        i = i - 1u;
    }
    assert(invrep);
    return(s->array[i]->elem);
}

priority_t 
pstack_top_priority(pstack s)
{
    assert(invrep(s) && !pstack_is_empty(s));
    priority_t i = s->_max_priority_;
    while(s->array[i] == NULL)
    {
        i = i - 1u;
    }
    assert(invrep);

    return(i);
}

size_t 
pstack_size(pstack s)
{
    assert(invrep(s));
    
    return(s->size);
}

pstack 
pstack_pop(pstack s)
{
    assert(invrep(s) && !pstack_is_empty(s));
    priority_t i = s->_max_priority_;
    while(s->array[i] == NULL)
    {
        i = i - 1u;
    }
    struct s_node *p = s->array[i];
    s->array[i] = s->array[i]->next;
    p = destroy_node(p);
 
    s->size = s->size - 1u;
    assert(invrep(s));
    
    return(s);
}

pstack 
pstack_destroy(pstack s)
{
    assert(invrep(s));
    
    while(s->size != 0u)
    {
        s = pstack_pop(s);
    }
    free(s->array);
    free(s);
    s = NULL;

    return s;
}
