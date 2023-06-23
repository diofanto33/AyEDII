#ifndef DICT_H
#define DICT_H

#include <stdio.h>
#include <stdbool.h>
#include "string.h"

/* COMPLETAR: definicion de tipos con typedef */
typedef struct _dict_t * dict_t;
typedef struct _node_t * node_t;

dict_t dict_empty(void);
/* Creates an empty dictionary
 *
 * PRE: {true}
 *   dict = dict_empty();
 * POS: {dict --> dict_t /\ dict_length(dict) == 0}
 */

dict_t dict_add(dict_t dict, string word, string def);
/* Adds a [word] and its definition [def] in the dictionary.
 * If [word] is already in the dictionary, its definition is replaced by [def].
 *
 * PRE: {dict --> dict_t /\ word --> string /\ def --> string}
 *  dict = dict_add(dict, word, def);
 * POS: {dict --> dict_t /\ key_eq(def, dict_search(dict, word))}
 */

string dict_search(dict_t dict, string word);
/* Returns the definition of the given [word], or NULL if [word] is not in
 * the dictionary.
 *
 * Note: Returns a reference to the string owned by the dictionary (not a copy).
 *
 * PRE: {dict --> dict_t /\ word --> string}
 *   def = dict_search(dict, word);
 * POS: {(def != NULL) == dict_exists(dict, word)}
 */

bool dict_exists(dict_t dict, string word);
/* Returns true if the given word exists in the dictionary, and false
 * otherwise.
 *
 * PRE: {dict --> dict_t /\ word --> string}
 *   b = dict_exists(dict, word);
 * POS: {dict --> dict_t}
 */

unsigned int dict_length(dict_t dict);
/* Returns the number of words contained in the dictionary.
 *
 * PRE: {dict --> dict_t}
 *  n = dict_length(dict)
 *
 */

dict_t dict_remove(dict_t dict, string word);
/* Removes the given word from the dictionary. If
 * [word] is not in the dictionary, it does nothing and
 * returns the dict unchanged.
 *
 * PRE: {dict --> dict_t /\ word --> string}
 *  dict = dict_remove(dict, word);
 * POS: {dict --> dict_t /\ !dict_exists(dict, word)}
 *
 */

dict_t dict_remove_all(dict_t dict);
/* Removes all the words from the dictionary.
 *
 * PRE: {dict --> dict_t}
 *  dict = dict_remove_all(dict);
 * POS: {dict --> dict_t /\ dict_length(dict) == 0}
 */

void dict_dump(dict_t dict, FILE *file);
/* Prints all the words and its definitions in order
 *
 *
 * PRE: {dict --> dict_t}
 *  dict_dump(dict);
 *
 */

dict_t dict_destroy(dict_t dict);
/* Destroys the given dictionary, freeing all the allocated resources.
 *
 * PRE: {dict --> dict_t}
 *   dict = dict_destroy(dict);
 * POS: {dict == NULL}
 */

#endif
