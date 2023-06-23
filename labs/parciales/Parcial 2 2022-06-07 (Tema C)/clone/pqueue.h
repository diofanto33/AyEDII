#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <stdbool.h>

typedef struct s_pqueue * pqueue;

typedef unsigned int pqueue_elem;

typedef unsigned int priority_t;

pqueue pqueue_empty(priority_t min_priority);
/*
 * DESC: Creates a new instance of pqueue with 'min_priority' limit
 *       This pqueue couldn't store elements with priority > min_priority
 *
 * PRE: {true}
 *  q = pqueue_empty();
 * POS: {q --> pqueue && pqueue_is_empty(q)}
 *
 */

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority);
/*
 * DESC: Adds element 'e' into the pqueue 'q' with the given 'priority'
 *
 * PRE: {q --> pqueue && priority <= q--> min_priority}
 *  q = pqueue_enqueue(q, e, priority);
 * POS: {q --> pqueue && !pqueue_is_empty()}
 *
 */

bool pqueue_is_empty(pqueue q);
/*
 * DESC: Indicates whether the pqueue 'q' is empty or not
 *
 */

size_t pqueue_size(pqueue q);
/*
 * DESC: Return the number of elements inside the pqueue 'q'
 *
 */

pqueue_elem pqueue_peek(pqueue q);
/*
 * DESC: Return the element with the most urgent prioritiy of the pqueue 'q'
 *
 * PRE: {q --> pqueue && !pqueue_is_empty(q)}
 *  e = pqueue_peek(q);
 * POS: {q --> pqueue}
 */

priority_t pqueue_peek_priority(pqueue q);
/*
 * DESC: Return the priority that is most urgent from the pqueue 'q'
 *
 * PRE: {q --> pqueue && !pqueue_is_empty(q)}
 *  priority = pqueue_peek_priority(q);
 * POS: {q --> pqueue}
 */

pqueue pqueue_dequeue(pqueue q);
/*
 * DESC: Remove the element with the most urgent priority of the pqueue 'q'
 *
 * PRE: {q --> pqueue && !pqueue_is_empty(q)}
 *  q = pqueue_dequeue(q);
 * POS: {q --> pqueue}
 *
 */

pqueue pqueue_destroy(pqueue q);
/*
 * DESC: Destroy instance of pqueue, freeing all memory used by 'q'.
 *
 * PRE: {q --> pqueue}
 *  q = pqueue_destroy(q);
 * POS: {q == NULL}
 *
 */

#endif
