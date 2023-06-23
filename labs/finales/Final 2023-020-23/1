#include <stdlib.h>     /* malloc(), free()... */
#include <stdbool.h>    /* bool type           */
#include <assert.h>     /* assert()            */
#include "key_value.h"  /* key_t               */
#include "dict.h"       /* intarface           */

struct _s_dict {
  unsigned int size; 
  struct _node_t * first;
};

// Internal structure
struct _node_t {
  key_t key;
  value_t value;
  struct _node_t *next;
};

struct _node_t 
*create_node(key_t k, value_t v)
{
  struct _node_t *new_node=malloc(sizeof(struct _node_t));
  new_node->key=k;
  new_node->value=v;
  new_node->next=NULL;

  return(new_node);
}

struct _node_t 
*destroy_node(struct _node_t *node) 
{
  node->key = key_destroy(node->key);
  node->value = value_destroy(node->value);
  free(node);
  node=NULL;

  return(node);
}

/*
 * @brief: decrease the value of size in 1.
 * * @param: dict, instance of dict_t.
 * @return: void.
 * @pre: dict != NULL.
 * @post: dict->size = dict->size - 1.
 * @invariant dict->size >= 0.
 */

static void 
decrease_size(dict_t dict)
{
  dict->size = dict->size - 1u;
}

/*
 * @brief: increase the value of size in 1.
 * @param: dict, instance of dict_t.
 * @return: void.
 * @pre: dict != NULL.
 * @post: dict->size = dict->size + 1.
 * @invariant dict->size >= 0.
 */ 

static void
increase_size(dict_t dict)
{
  dict->size = dict->size + 1u;
}

/*
 * @brief: para toda instancia de dict_t se ve cumplir
 *
 *  1) Existencia (inicializacion).
 *  2) Consistencia de la cantidad de nodos en ralacion con size.
 *  
 * @param: dict, instancia de dict_t.
 * @return: true si se cumple la invariante, false en caso contrario.
 */ 

static bool
invrep(dict_t dict) 
{   
  bool res = (dict != NULL);
  if(res)
  {   
    unsigned int length = 0u;
    struct _node_t *sp = dict->first;
    while(sp != NULL)
    {
      length = length + 1u;
      sp = sp->next;
    }
    res = res && (length==dict->size);
  }
    
  return(res);
}
// --- Interface functions ---

dict_t
dict_empty(void)
{
  struct _s_dict *dict = NULL;
  dict = malloc(sizeof(struct _s_dict));
  assert(dict != NULL);
  dict->first = NULL;
  dict->size = 0u;
  assert(invrep(dict));

  return(dict);
}

dict_t 
dict_add(dict_t dict, key_t word, value_t def)
{
  assert(invrep(dict));
  struct _node_t *new_node = create_node(word, def); 
  if(dict->size==0u)
  {
    dict->first = new_node;
    increase_size(dict);
  }
  else
  {
    struct _node_t *sp = dict->first;
    struct _node_t *prev = NULL;
    while(sp->next != NULL && !string_eq(word, sp->key))
    {
      prev = sp;
      sp = sp->next;
    }
    if(string_eq(word, sp->key))
    { 
      if(prev != NULL)
      {
        prev->next = new_node;
      }
      else
      {
        dict->first = new_node;
      }
      new_node->next = sp->next;
      sp = destroy_node(sp);
    }
    else 
    {
      sp->next = new_node;
      increase_size(dict);
    }
    sp = NULL;
  }
  assert(invrep(dict));

  return(dict);
}

value_t 
dict_search(dict_t dict, key_t word)
{
  assert(invrep(dict));
  value_t def = NULL;
  if(dict_length(dict)!=0u)
  {
    struct _node_t *sp = dict->first;
    bool stop = false;
    while(sp != NULL && !stop)
    {
      if(string_eq(sp->key, word))
      {
        def = sp->value;
        stop = true;
      }
      sp = sp->next;
    }
    sp = NULL;
  }
  assert(invrep(dict) && (def != NULL)==dict_exists(dict, word));

  return(def);
}

bool 
dict_exists(dict_t dict, key_t word)
{
  assert(invrep(dict));
  bool exists = false;
  if(dict_length(dict) != 0u)
  {
    struct _node_t *sp = dict->first;
    while(sp != NULL && !exists)
    {
      if(string_eq(sp->key, word))
      {
        exists = true;
      }
      sp = sp->next;
    }
    sp = NULL;
  }
  assert(invrep(dict));

  return(exists);
}

unsigned int
dict_length(dict_t dict)
{
  return(dict->size);
}

dict_t 
dict_remove(dict_t dict, key_t word) 
{
  assert(invrep(dict));
  if(dict_length(dict)!=0u)
  {
    struct _node_t *sp = dict->first;
    struct _node_t *prev = NULL;
    while(sp->next != NULL && !string_eq(sp->key, word))
    {
      prev = sp;
      sp = sp->next;
    }
    if(string_eq(sp->key, word))
    {
      if(prev != NULL)
      {
        prev->next = sp->next;
      }
      else
      {
        dict->first = sp->next; 
      }
      sp = destroy_node(sp);
      dict->size = dict->size -1u;
    }
    sp = NULL;
  }
  assert(invrep(dict));

  return(dict);
}

void
dict_dump(dict_t dict, FILE *file)
{
  assert(invrep(dict));
  for(struct _node_t *check=dict->first; check!=NULL; check=check->next) 
  {
    fprintf(file, "key: ");
    key_dump(check->key, file);
    fprintf(file, "\n");
    fprintf(file, "value: ");
    value_dump(check->value, file);
    fprintf(file, "\n\n");
  }
}

dict_t 
dict_remove_all(dict_t dict)
{
  assert(invrep(dict));
  struct _node_t *sp = dict->first;
  while(sp != NULL)
  {
    dict->first = dict->first->next;
    sp = destroy_node(sp);
    sp = dict->first;
    decrease_size(dict);  
  }
  assert(invrep(dict) && dict_length(dict)==0u && dict->first==NULL);

  return(dict);
}

dict_t dict_destroy(dict_t dict) { 
    assert(invrep(dict));
    dict = dict_remove_all(dict);
    free(dict);
    dict=NULL;
    assert(dict==NULL);

    return(dict);
}

