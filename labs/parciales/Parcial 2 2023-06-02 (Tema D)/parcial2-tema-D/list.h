#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct _list_t * list_t;
typedef char list_value;

list_t list_empty(void);
/* Creates an empty list
 *
 * PRE: {true}
 *   list = list_empty();
 * POS: {list --> list_t /\ list_length(list) == 0}
 */

 bool list_is_empty(list_t list);
 /* Indicates if the list [list] is empty.
  *
  * PRE: {list --> list_t}
  * b = list_is_empty(list);
  *
 */

list_t list_add(list_t list, unsigned int key, char value);
/* Adds value and its key in the list.
 * If [key] is already in the list, its value is replaced by [value].
 *
 * PRE: {list --> list_t /\ key --> int /\ value --> char}
 *  list = list_add(list, key, value);
 * POS: {list --> list_t /\ key_eq(value, list_search(list, key))}
 */

char list_search(list_t list, unsigned int key);
/* Returns the value of the given [key], or NULL if [key] is not in
 * the list.
 *
 * PRE: {list --> list_t /\ key --> int}
 *   value = list_search(list, key);
 * POS: {(value != NULL) == list_exists(list, key)}
 */

bool list_exists(list_t list, unsigned int key);
/* Returns true if the given key exists in the list, and false
 * otherwise.
 *
 * PRE: {list --> list_t /\ key --> int}
 *   b = list_exists(list, key);
 * POS: {list --> list_t}
 */

unsigned int list_length(list_t list);
/* Returns the number of keys contained in the list.
 *
 * PRE: {list --> list_t}
 *  n = list_length(list)
 *
 */

list_t list_remove(list_t list, unsigned int key);
/* Removes the given key from the list. If
 * [key] is not in the list, it does nothing and
 * returns the list unchanged.
 *
 * PRE: {list --> list_t /\ key --> int}
 *  list = list_remove(list, key);
 * POS: {list --> list_t /\ !list_exists(list, key)}
 *
 */

list_t list_remove_all(list_t list);
/* Removes all the keys from the list.
 *
 * PRE: {list --> list_t}
 *  list = list_remove_all(list);
 * POS: {list --> list_t /\ list_length(list) == 0}
 */

list_value* list_to_array(list_t list);
/* Return an array with all values that belong to [list], in key order.
 *
 *
 * PRE: {list --> list_t}
 *  array = list_to_array(list);
 * POS: {list --> list_t && !list_is_emtpy(s)}
 */

list_t list_destroy(list_t list);
/* Destroys the given list, freeing all the allocated resources.
 *
 * PRE: {list --> list_t}
 *   list = list_destroy(list);
 * POS: {list == NULL}
 */

#endif
