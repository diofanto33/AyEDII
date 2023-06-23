#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "string.h"

struct _dict_t {
  /* COMPLETAR */
};

struct _node_t {
  /* COMPLETAR */
};

static bool invrep(dict_t d) {
  /* COMPLETAR */
}

// returns the amount of nodes to skip when adding a new word
static int nodes_to_skip(dict_t dict, string word) {
  unsigned int numberToSkip = 0;

  /* COMPLETAR */

  return numberToSkip;
}

// returns the position of the word on the list of nodes (0 being the first node)
// returns -1 if the word is not on the dict
static int find_index_of_key(dict_t dict, string word) {
  int index = 0;

  /* COMPLETAR */

  return index;
}

dict_t dict_empty(void) {

    /* COMPLETAR */

}

static node_t create_node(string elem) {

    /* COMPLETAR */

}

static node_t destroy_node(node_t node) {

    /* COMPLETAR */

}

dict_t dict_add(dict_t dict, string word, string def) {

    /* COMPLETAR */

}

string dict_search(dict_t dict, string word) {

    /* COMPLETAR */

}

bool dict_exists(dict_t dict, string word) {

    /* COMPLETAR */

}

unsigned int dict_length(dict_t dict) {

    /* COMPLETAR */

}

// removes the "index" element of the "list" list of nodes
static node_t remove_on_index(node_t list, int index) {

    /* COMPLETAR */

}

dict_t dict_remove(dict_t dict, string word) {
  assert(invrep(dict));
  int index = find_index_of_key(dict, word);
  if (index != -1) {
    dict->words = remove_on_index(dict->words, index);
    dict->definitions = remove_on_index(dict->definitions, index);
    dict->size--;
  }
  assert(invrep(dict));
  return dict;
}

dict_t dict_remove_all(dict_t dict) {

    /* COMPLETAR */

}

void dict_dump(dict_t dict, FILE *file) {

    /* COMPLETAR */
    /* tip: use fprintf(file, "%s : %s\n", string_ref(word), string_ref(def)); to save to file  */

}

dict_t dict_destroy(dict_t dict) {
  dict = dict_remove_all(dict);
  free(dict);
  dict = NULL;
  return dict;
}
