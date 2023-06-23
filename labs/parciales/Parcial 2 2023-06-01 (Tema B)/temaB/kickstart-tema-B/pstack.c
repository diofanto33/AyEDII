#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    /*
     * COMPLETAR
     */
    struct s_node *front;
};

struct s_node {
    pstack_elem elem;
    float average_grade;
    unsigned int approved_courses;
    float priority;
    struct s_node *next;
};


static float calculate_priority(float average_grade,
                                unsigned int approved_courses)
{
    /*
     * COMPLETAR
     *
     */
}

static struct s_node *create_node(pstack_elem e,
                                  float average_grade,
                                  unsigned int approved_courses)
{
    struct s_node *new_node = NULL;
    float priority = calculate_priority(average_grade, approved_courses);
    // Completar
    assert(new_node != NULL);
    /*
     * COMPLETAR
     */
    return new_node;
}

static struct s_node *destroy_node(struct s_node *node)
{
    assert(node != NULL);
    /*
     * COMPLETAR
     *
     */
    assert(node == NULL);
    return node;
}

static bool invrep(pstack s)
{
    /*
     * COMPLETAR
     *
     */    
    return inv;
}

pstack pstack_empty(void)
{
    pstack s=NULL;
    /*
     * COMPLETAR
     *
     */
    return s;
}

pstack pstack_push(pstack s,
                   pstack_elem e,
                   float average_grade,
                   unsigned int approved_courses)
{
    assert(invrep(s));
    struct s_node *new_node = create_node(e, average_grade, approved_courses);
    /*
     * COMPLETAR
     *
     */
    return s;
}

bool pstack_is_empty(pstack s) 
{
    /*
    * COMPLETAR
    */
}

pstack_elem pstack_top(pstack s) 
{
    assert(invrep(s) && !pstack_is_empty(s));
    return s->front->elem;
}

float pstack_top_average_grade(pstack s) 
{
    /*
     * COMPLETAR
     */
}

unsigned int pstack_top_approved_courses(pstack s) 
{
    /*
     * COMPLETAR
     */
}

float pstack_top_priority(pstack s) 
{
    /*
     * COMPLETAR
     */
}

unsigned int pstack_size(pstack s) 
{
    assert(invrep(s));
    unsigned int size=0;
    /*
     * COMPLETAR
     */

    return size;
}

pstack pstack_copy(pstack s)
{
    assert(invrep(s));
    /*
     * COMPLETAR
     */
}

pstack pstack_pop(pstack s) {
    assert(invrep(s));
    /*
     * COMPLETAR
     */
}

pstack pstack_destroy(pstack s) 
{
    /*
     * COMPLETAR
     */
    assert(s == NULL);
    return s;
}
