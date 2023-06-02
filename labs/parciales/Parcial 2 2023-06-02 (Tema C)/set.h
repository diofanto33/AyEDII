#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>            /* Definition of bool      */

typedef int set_elem;

typedef struct s_set *set;

/* CONSTRUCTORS */

set set_empty(void);
/*
  Creates a new empty set
 
  s = set_empty()
 
  POS: {s --> set && set_is_empty(s)}
 
*/

set set_add(set s, set_elem e);
/*
 Adds element <e> element to the set <s>. If <e> was already in <s>
 the function makes no changes.

 PRE: {s --> set}
 
 s = set_add(s, e);

 POS: {s --> set && !set_is_emtpy(s)}
*/

/* OPERATIONS   */

bool set_is_empty(set s);
/*
 Indicates if the set <s> is empty.

 PRE: {s --> set}

 b = set_is_empty(s);

*/

unsigned int set_cardinal(set s);
/*
 Returns how many elements are in <s>

 PRE: {s --> set}

 n = set_cardinal(s);

 POS: {(n == 0) == set_is_empty(s)}
*/

bool set_member(set_elem e, set s);
/*
 Indicates if the element <e> belongs to the set <s>.

 PRE: {s --> set}

 b = set_member(e, s);

*/

set set_elim(set s, set_elem e);
/*
 Eliminates element <e> of the set <s>. If <e> was not present in <s>
 the function makes no changes.

 {s --> set}

 s = set_elim(s, e);

 {s --> set && !set_member(e)}

*/

set_elem set_get(set s);
/*
 Returns some element of the set <s>

 PRE: {s --> set && !set_is_empty(s)}

 e = set_get(s);

 POS: {set_member(s, e)}
*/

set_elem * set_to_array(set s);
/*
 Return an array with all elements that belong to <s>.

 The returned array is stored in dynamic memory and has enough room for
 `set_cardinal(s)` elements. The caller must free the memory.

 PRE: {s --> set}

 array = set_to_array(s);

 POS: {!set_is_empty(s) ==> (array!=NULL)
 
*/

set set_destroy(set s);
/*
 Destroy the set <s> freeing all memory used by the data structure

 PRE: {s --> set}
 s = set_destroy(s);

 POS: {s == NULL}
*/

#endif
