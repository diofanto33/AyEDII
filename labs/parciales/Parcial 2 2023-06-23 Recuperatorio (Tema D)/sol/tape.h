#ifndef _TAPE_H_
#define _TAPE_H_

#include <stdbool.h>

typedef struct _s_tape * tape_t;

typedef char tape_elem;

tape_t tape_create(void);
/* 
 * Creates a new instance of tape
 *
 * PRE: {true}
 *   tape = tape_create()
 * POST: {tape --> tape_t && tape_at_start(tape) && tape_is_empty(tape)}
 *
*/

tape_t tape_rewind(tape_t tape);
/*
 * Set the cursor on the first element of the tape
 *
 * PRE: {tape --> tape}
 *  tape = tape_rewind(tape);
 * POST: {tape --> tape_t && tape_at_start(tape)}
 *
*/

bool tape_at_start(tape_t tape);
/*
 *
 * Indicates if the cursor of tape <tape> it's pointing to the first element
 *
 */

bool tape_at_stop(tape_t tape);
/* 
 * Indicates if the cursor of tape <tape> falls out the last element
 *
*/

bool tape_is_empty(tape_t tape);
/*
 * Indicates if the tape <tape> has no elements inside
 *
*/

unsigned int tape_length(tape_t tape);
/*
 * Returns how many elements are in the tape
 *
*/


tape_t tape_step(tape_t tape);
/*
 * Moves the cursor one element ahead or stays in the same position if is
 * already in the stop of tape. If the tape's cursor is on the last element,
 * after the call to this function `tape_at_stop(tape)` will return `true`.
 *
*/

tape_t tape_insertl(tape_t tape, tape_elem e);
/*
 * Inserts element <e> in the current position, before the actual element
 *
 * PRE: {tape --> tape_t}
 *   tape = tape_insert(t, e)
 * POST: {tape --> tape_t && !tape_is_empty(tape) && !tape_at_end(tape) && e == tape_read(tape)}
*/

tape_t tape_insertr(tape_t tape, tape_elem e);
/*
 * Inserts element <e> after the actual element
 *
 * PRE: {tape --> tape_t && (!tape_at_stop(tape) || tape_is_empty(tape))}
 *   tape = tape_insert(t, e)
 *
 * POST: {tape --> tape_t && !tape_is_empty(tape) && !tape_at_end(tape) && e == tape_read(tape)}
*/

tape_t tape_erase(tape_t tape);
/*
 * Erase the element in the current position
 *
 * PRE: {tape --> tape_t && !tape_is_empty(tape) && !tape_at_stop(tape)}
 *   tape = tape_erase(tape);
 * POST: {tape --> tape_t}
 *
*/

tape_elem tape_read(tape_t tape);
/*
 * Returns the current element pointed by the cursor
 *
 * PRE: {tape --> tape_t && !tape_is_empty(tape) && !tape_at_end(tape)}
 *
*/

void tape_dump(tape_t tape);
/*
 * Prints the tape on the screen
 *
*/

tape_t tape_copy(tape_t tape);
/* 
 * Creates a copy of <tape> in new memory
 *
 * PRE: {tape --> tape_t}
 *   copy = tape_copy(tape)
 * POS: {copy --> tape_t && copy != tape && tape_at_start(copy) && 
 *       tape_length(tape) == tape_length(copy)}
 *
*/

tape_t tape_destroy(tape_t tape);
/* 
 * Destroys the instance freeing all memory used by <tape>
 *
 * PRE: {tape --> tape_t}
 *   tape = tape_destroy(tape);
 * POST: {tape == NULL}
 *
*/



#endif

