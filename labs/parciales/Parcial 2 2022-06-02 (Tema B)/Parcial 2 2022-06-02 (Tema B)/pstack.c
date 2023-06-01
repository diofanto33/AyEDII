#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    unsigned int size;
    struct s_node *first;
};

struct s_node {
    pstack_elem elem;
    priority_t _priority;
    struct s_node *next;
};

static struct s_node 
*create_node(pstack_elem e, priority_t priority)
{
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->next = NULL;
    new_node->elem = e;
    new_node->_priority = priority;
    
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

/* invrep: pstack -> bool
 *
 * @desc:
 * 
 * El invariante se cumple si la pila esta inicializada, si el tamaño
 * de la pila es igual al número de nodos que tiene y si los nodos
 * están ordenados de mayor a menor prioridad
 * 
 * @param: s Puntero a la pila
 * @return: true si el invariante se cumple, false en caso contrario
 *
 * */

static bool 
invrep(pstack s) 
{
    bool res = (s != NULL);
    if(res && s->size != 0u && s->first != NULL)
    {
        struct s_node *sp = NULL;
        sp = s->first;
        unsigned int length = 1u;
        while(sp->next != NULL)
        {
            length = length + 1u;
            res = res && sp->_priority >= sp->next->_priority;
            sp = sp->next;
        }
        res = res && length==s->size;
        sp = NULL;
    }

    return(res);
}

pstack
pstack_empty(void) 
{
    pstack s = NULL;
    s = malloc(sizeof(struct s_pstack));
    assert(s != NULL);
    s->first = NULL;
    s->size = 0u;
		
    return(s);
}

pstack 
pstack_push(pstack s, pstack_elem e, priority_t priority)
{
    assert(invrep(s));
    struct s_node *new_node = create_node(e, priority);
    if(s->size == 0u && s->first == NULL)
    {
        s->first = new_node;
    }
    else
	{
	    struct s_node *sp = NULL;
        struct s_node *prev = NULL;
        sp = s->first;
        while(sp->next != NULL && sp->_priority > new_node->_priority)
        {
            prev = sp;
            sp = sp->next;
        }
        if(sp->_priority <= new_node->_priority)
        {
            new_node->next = sp;
            if(prev != NULL)
            {
                prev->next = new_node;
                prev = NULL;
            }
            else
            {
                s->first = new_node;
            }
        }
        else 
        {
            sp->next = new_node;
        }
        sp = NULL;
    }
    s->size = s->size + 1u;
    assert(invrep(s));

    return(s);
}

bool 
pstack_is_empty(pstack s)
{ 
    assert(invrep(s));
    bool res = (s->size == 0u);
   
    return(res);
}

pstack_elem
pstack_top(pstack s) 
{
    assert(invrep(s) && !pstack_is_empty(s));
    
    return(s->first->elem);
}

priority_t 
pstack_top_priority(pstack s) 
{
    assert(invrep(s) && !pstack_is_empty(s));
    
    return(s->first->_priority);
}

unsigned int 
pstack_size(pstack s)
{
    assert(invrep(s));
    
    return(s->size);
}

pstack
pstack_pop(pstack s)
{ 
    assert(invrep(s) && !pstack_is_empty(s));
    struct s_node *killme = NULL;
    killme = s->first;
    s->first = s->first->next;
    s->size = s->size - 1u;
    killme = destroy_node(killme);
    assert(invrep(s));

    return(s);
}

pstack
pstack_destroy(pstack s)
{
    assert(invrep(s));
    struct s_node *ps = NULL;
    ps = s->first;
    while(ps != NULL)
    {
        s->first = s->first->next;
        ps = destroy_node(ps);
        ps = s->first;
    }
    free(s);
    s = NULL;

    return(NULL);
}
