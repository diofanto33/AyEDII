#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue
{
    unsigned int size;
    struct s_node *first;
};

struct s_node
{
    pqueue_elem elem;
    float average_grade;
    unsigned int approved_courses;
    float priority;
    struct s_node *next;
};

static float 
calculate_priority(float average_grade,
                   unsigned int approved_courses)
{
    float ag_div_mg = 0.5*(average_grade/MAX_GRADE);
    float ac_div_tc = 0.5*(approved_courses/TOTAL_COURSES);
    float priority = ag_div_mg + ac_div_tc;

    return(priority)
}

static struct s_node 
*create_node(pqueue_elem e,
             float average_grade,
             unsigned int approved_courses)
{

    struct s_node *new_node = NULL;
    float priority = calculate_priority(average_grade, approved_courses);
    new_node = malloc(sizeof(struct s_node));
    assert(new_node != NULL);
    
    new_node->priority = priority;
    new_node->elem = e;
    new_node->average_grade = average_grade;
    new_node->approved_courses = approved_courses;
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
 *     invrep debe cumplir tres propiedades fundamentales 
 * 
 * 1) Existencia, pqueue dede estar inicializada
 * 
 * 2) Definicion de cola de prioridad, sus elementos estan
 *    ordenados de mayor a menor prioridad 
 *
 * 3) Consistencia, no esta demas agregar que la cantidad
 *    de nodos es consistente con la longitud calculada
 * 
 * Todo objeto que cumpla estas tres propiedades, sera 
 * entonces una instancia de este TAD
 *
 * */

static bool
invrep(pqueue q)
{
    bool res = (q != NULL);
    if(res && q->next != NULL && q->size != 0u)
    {
        struct s_node *ps = NULL;
        unsigned int length = 1u;
        ps = q->first;
        while(ps->next != NULL && res)
        {
            res = res && ps->priority >= ps->priority->next;
            length = length + 1u;
            ps = ps->next;
        }
        res = res && length==q->size;
    }

    return(res);
}

pqueue 
pqueue_empty(void)
{
    pqueue q = NULL;
    q = malloc(sizeof(struct s_pqueue));
    assert(q != NULL);

    q->first = NULL;
    q->size = 0u;
    
    assert(invrep(q));

    return(q);
}

pqueue 
pqueue_enqueue(pqueue q,
               pqueue_elem e,
               float average_grade,
               unsigned int approved_courses)
{
    assert(invrep(q));
    struct s_node *new_node = create_node(e, average_grade, approved_courses);
    float priority = calculate_priority(average_grade, approved_courses);

    if(q->size == 0u)
    {
        q->first = new_node;
    }
    else
    {
        struct s_node *ps = NULL;
        struct s_node *prev = NULL;
        ps = q->first;
        while(ps->next != NULL && ps->priority >= priority)
        {
            prev = ps;
            ps = ps->next;
        }
        if(ps->priority < priority)
        {
            new_node->next = ps;
            if(prev != NULL)
            {
                prev->next = new_node;
                prev = NULL;
            }
            else 
            {
                q->first = new_node;
            }
        }
        else
        {
            ps->next = new_node;
        }
        ps = NULL;
   }
    q->size = q->size + 1u;
    assert(invrep(q));
    return(q);
}

bool pqueue_is_empty(pqueue q)
{
    /*
    * COMPLETAR
    */
}


pqueue_elem pqueue_peek(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->elem;
}

float pqueue_peek_average_grade(pqueue q)
{
     /*
    * COMPLETAR
    */
}

unsigned int pqueue_peek_approved_courses(pqueue q)
{
     /*
    * COMPLETAR
    */
}

float pqueue_peek_priority(pqueue q)
{
     /*
    * COMPLETAR
    */
}

unsigned int pqueue_size(pqueue q)
{
    assert(invrep(q));
    unsigned int size = 0;
     /*
    * COMPLETAR
    */

    return size;
}

pqueue pqueue_copy(pqueue q)
{
    assert(invrep(q));
     /*
    * COMPLETAR
    */
}

pqueue pqueue_dequeue(pqueue q)
{
    assert(invrep(q));
     /*
    * COMPLETAR
    */
}

pqueue pqueue_destroy(pqueue q)
{
     /*
    * COMPLETAR
    */
    assert(q == NULL);
    return q;
}
