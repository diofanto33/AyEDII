#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

struct _node_t {
  unsigned int key;
  list_value value;
  struct _node_t *next;
};

typedef struct _node_t * node_t;

struct _list_t {
  // COMPLETAR
  node_t elems;
};

static bool invrep(list_t list) {
  // COMPLETAR
  return true;
}

static struct _node_t * create_node(unsigned int key, list_value value) {
  // COMPLETAR
}

static struct _node_t * destroy_node(struct _node_t *node) {
  // COMPLETAR
}

list_t list_empty(void) {
  // COMPLETAR
}

list_t list_add(list_t list, unsigned int key, list_value value) {
// COMPLETAR
}

unsigned int list_length(list_t list) {
  // COMPLETAR
}

bool list_is_empty(list_t list) {
  // COMPLETAR
}

bool list_exists(list_t list, unsigned int key) {

  assert(invrep(list));
  node_t cursor = list->elems;
  while (cursor != NULL && cursor->key < key) {
    cursor = cursor->next;
  }
  return cursor != NULL && cursor->key == key;
}


char list_search(list_t list, unsigned int key) {
  // COMPLETAR
}

list_t list_remove(list_t list, unsigned int key) {
  // COMPLETAR
}

list_t list_remove_all(list_t list) {
  // COMPLETAR
}


list_value* list_to_array(list_t list) {
  // COMPLETAR
}

list_t list_destroy(list_t list) {
  // COMPLETAR
}
