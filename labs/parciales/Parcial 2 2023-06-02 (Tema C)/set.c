#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"

struct s_node {
    set_elem elem;
    struct s_node *next;
};

typedef struct s_node * node_t;

struct s_set {
    unsigned int size;
    node_t first;
};


/*
* @desc: invrep verifica que se cumpla lo siguiente  
*
*       1)Existencia: inicializacion
*       2)Orden: todos los elementos estan ordenados de menor
*         a mayor de izquierda a derecha resp.
*       3)Unicidad: los elementos son unicos, no se pueden repetir
*       4)Consistencia: no esta demas verificar que el cardinal 
*         es consistente con la longitud verificada.
*
* invrep :: set -> bool
*/

static bool
invrep(set s)
{
    bool res = (s != NULL);
    if(res && s->size != 0u)
    {
        node_t sp = NULL;
        sp = s->first;
        unsigned int length = 1u;
        while(sp->next != NULL && res)
        {
            res = res && sp->elem < sp->next->elem;
            length = length + 1u;
            sp = sp->next;
        }
        res = res && length==s->size;
        sp = NULL;
    } 
    return(res);
}

static struct s_node *
create_node(set_elem e)
{
    node_t new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;

    return(new_node);
}

static struct s_node *
destroy_node(struct s_node *node)
{
    assert(node != NULL);
    node->next = NULL;
    free(node);
    node = NULL;

    return(node);   
}

/* CONSTRUCTORS */

set 
set_empty(void) 
{
    set s = NULL;   
    s = malloc(sizeof(struct s_set));
    assert(s != NULL);
    s->first = NULL;
    s->size = 0u;
    
    assert(invrep(s) && set_is_empty(s)); 
    return(s);
}

set 
set_add(set s, set_elem e)
{  
    assert(invrep(s)); 
    node_t new_node = NULL;
    new_node = create_node(e);
    if(s->size == 0u)
    {
        s->first = new_node;
        s->size = s->size + 1u;
    }
    else
    {   
        node_t sp = s->first;
        node_t prev = NULL;
        while(sp->next != NULL && sp->elem < e)
        {
            prev = sp;
            sp = sp->next;
        }   
        if (sp->elem==e)
        {   
            new_node = destroy_node(new_node);
        }
        else if(sp->elem < e)
        {   
            sp->next = new_node;
            s->size = s->size + 1u;
        }
        else if (sp->elem > e)
        {       
            new_node->next = sp;
            if(prev != NULL)
            {
                prev->next = new_node;
            }    
            else
            {   
                new_node->next = s->first;
                s->first = new_node;
            }
            s->size = s->size + 1u;
        }
        sp = NULL;
        prev = NULL;    
    }
    assert(invrep(s) && !set_is_empty(s));

    return(s);
}


unsigned int 
set_cardinal(set s)
{
    return(s->size);
}

bool 
set_is_empty(set s)
{
    assert(invrep(s));
    return(s->size==0u);
}

bool 
set_member(set_elem e, set s) 
{
    assert(invrep(s));
    node_t node=s->first;
    bool res = false;
    while(node!=NULL && !res)
    {   
        if(node->elem==e)
        {
            res = true;
        }
        node = node->next;
    }

    return(res);
}


set 
set_elim(set s, set_elem e)
{
    assert(invrep(s));
    node_t node = NULL;
    node_t prev = NULL;
    node = s->first;
    while(node->next != NULL && node->elem != e)
    {   
        prev = node;
        node = node->next;
    }
    if(node->elem==e)
    {
        if(prev != NULL)
        {
            prev->next = node->next;
        } 
        else
        {
            s->first = node->next;
        }
        node = destroy_node(node);
        s->size = s->size -1u;
    }
    node = NULL;
    prev = NULL;
    assert(invrep(s));

    return(s);
}

set_elem 
set_get(set s) 
{
    assert(invrep(s) && !set_is_empty(s));
    return s->first->elem;
}

set_elem*
set_to_array(set s) 
{
    assert(invrep(s) && !set_is_empty(s));
    set_elem *array = NULL;
    unsigned int length = s->size;
    /* me gusta calloc */
    array = calloc(length, sizeof(set_elem));
    assert(array != NULL);
    node_t node = NULL;
    node = s->first;
    unsigned int i = 0u;
    while(node != NULL)
    {
        array[i] = node->elem;
        node = node->next;
        i = i + 1u; 
    }
    assert(invrep(s) && array != NULL);

    return(array);
}

set 
set_destroy(set s)
{
assert(invrep(s));
    node_t ps = NULL;
    ps = s->first;
    while(ps != NULL)
    {
        s->first = s->first->next;
        ps = destroy_node(ps);
        ps = s->first;
    }
    free(s);
    s = NULL;

    return(s);
}

