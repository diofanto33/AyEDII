#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "string.h"

struct _dict_t {
  struct _node_t *words;
  struct _node_t *definitions;
  unsigned int size;
};

struct _node_t {
  string elem;
  struct _node_t *next;
};

/*  @brief: Verifica que para todo diccionario se cumplan:
 *  
 *  1) Inicializacion: existencia
 *  2) Orden con relacion a string_less (orden alfabetico)
 *  3) Consistencia en la cantidad de nodos de ambas listas
 *  4) Consistencia size en relacion length 
 *
 *  @param: dict_t
 *  @return: bool 
 */

static bool 
invrep(dict_t d)
{
  bool res = (d != NULL); 
  unsigned int len_w = 0u;
  unsigned int len_d = 0u;
  if(res && d->words != NULL)
  {
    struct _node_t *ps = d->words;
    len_w = len_w + 1u;
    while(res && ps->next != NULL)
    {
      res = res && string_less(ps->elem, ps->next->elem);
      len_w = len_w + 1u;
      ps = ps->next;
    }
    ps = NULL;
    res = res && (len_w==d->size);
  }
  if(res && d->definitions != NULL)
  {
    struct _node_t *sp = d->definitions;
    len_d = len_d + 1u;
    while(sp->next != NULL)
    {
      len_d = len_d + 1u;
      sp = sp->next;
    }
    sp = NULL;
    res = res && (len_d==d->size);
  }
  res = res && (len_d==len_w) && (len_d==d->size);

  return(res);
}

// returns the amount of nodes to skip when adding a new word
/*
static int 
nodes_to_skip(dict_t dict, string word) 
{
    unsigned int numberToSkip = 0;
    struct _node_t *sp = dict->words;
    while(sp->words != NULL && string_less(dict->words, word))
    {
        numberToSkip = numberToSkip + 1u;
    }
    sp = NULL;

    return(numberToSkip);
}
*/ 
// returns the position of the word on the list of nodes (0 being the first node)
// returns -1 if the word is not on the dict

static int 
find_index_of_key(dict_t dict, string word)
{
  int index = 0;
  struct _node_t *sp_w = dict->words;
  bool res = string_eq(word, sp_w->elem); 
  while(sp_w->next != NULL && !res)
  {   
    res = string_eq(word, sp_w->elem);
    if(!res)
    {
      index = index + 1;
    }
    sp_w = sp_w->next;
  }
  sp_w = NULL; 
  index = !res ? -1 : index;

  return(index);
}

dict_t
dict_empty(void)
{
  struct _dict_t *d = NULL;
  d = malloc(sizeof(struct _dict_t));
  assert(d != NULL);
  d->words = NULL;
  d->definitions = NULL;
  d->size = 0u;
  assert(invrep(d));

  return(d);
}

static node_t 
create_node(string elem) 
{
  struct _node_t *new_node = NULL;
  new_node = malloc(sizeof(struct _node_t));
  assert(new_node!=NULL);
  new_node->elem = elem;
  new_node->next = NULL;
    
  return(new_node);
}

static node_t 
destroy_node(node_t killme) 
{
  assert(killme != NULL);
  killme->elem = string_destroy(killme->elem);
  free(killme);
  killme = NULL;
 
  return(killme);   
}

dict_t 
dict_add(dict_t dict, string word, string def)
{
  assert(invrep(dict));
  struct _node_t *new_node_w = NULL;
  struct _node_t *new_node_d = NULL;
  new_node_w = create_node(word);
  new_node_d = create_node(def);
  if(dict->size==0u)
  {
    dict->words = new_node_w;
    dict->definitions = new_node_d;
    dict->size = dict->size + 1u;
  }
  else
  {
    struct _node_t *sp_w = dict->words;
    struct _node_t *sp_d = dict->definitions;
    struct _node_t *prev_w = NULL;  
    struct _node_t *prev_d = NULL;
    while(sp_w->next != NULL && string_less(sp_w->elem, word))
    {
      prev_w = sp_w;
      prev_d = sp_d;
      sp_w = sp_w->next;
      sp_d = sp_d->next;
    }
    if(string_eq(sp_w->elem, word))
    {   
      if(prev_w != NULL)
      {
        prev_w->next = new_node_w;
        prev_d->next = new_node_d;
      }
      else 
      {
        dict->words = new_node_w; 
        dict->definitions = new_node_d;
      }
      new_node_w->next = sp_w->next;
      new_node_d->next = sp_d->next;
      sp_d = destroy_node(sp_d);
      sp_w = destroy_node(sp_w);
    }
    else if (string_less(sp_w->elem, word))
    {
      sp_d->next = new_node_d;
      sp_w->next = new_node_w;
      dict->size = dict->size +1u;
    }
    else 
    {
      new_node_w->next = sp_w;
      new_node_d->next = sp_d; 
      if(prev_w != NULL)
      {
        prev_w->next = new_node_w;
        prev_d->next = new_node_d;
      }
      else 
      {
        dict->words = new_node_w;
        dict->definitions = new_node_d;
      }
      dict->size = dict->size + 1u;
    }
    sp_w = NULL;
    sp_d = NULL;
  }
  assert(invrep(dict));
        
  return(dict);
}
  
string
dict_search(dict_t dict, string word)
{
  assert(invrep(dict));
  struct _node_t *sp_w = dict->words;
  struct _node_t *sp_d = dict->definitions;
  string def = NULL;
  bool res = false;
  while(sp_w != NULL && !res)
  {   
    if(string_eq(word, sp_w->elem))
    {
      res = true;
      def = sp_d->elem;
    }
    sp_w = sp_w->next;
    sp_d = sp_d->next;
  }
  sp_d = NULL;
  sp_w = NULL;
  assert(invrep(dict) && (def!=NULL)==dict_exists(dict, word));
    
  return(def);
}

bool 
dict_exists(dict_t dict, string word) 
{
  struct _node_t *sp_w = dict->words;
  bool res = false;
  while(sp_w != NULL && !res)
  {
    res = string_eq(sp_w->elem, word);
    sp_w = sp_w->next;
  }
  sp_w = NULL;
  assert(invrep(dict));

  return(res);
}

unsigned int 
dict_length(dict_t dict) 
{   
  assert(invrep(dict));

  return(dict->size);
}

// removes the "index" element of the "list" list of nodes
static node_t 
remove_on_index(node_t list, int index)
{
  node_t sp = list;
  node_t prev = NULL;
  int i = 0;
  while(sp != NULL && i < index)
  {   
    prev = sp;
    sp = sp->next;
    i = i + 1;
  }
  if(prev != NULL)
  {
    prev->next = sp->next;
    sp = destroy_node(sp);
  }
  else 
  {
    list = sp->next;
    sp = destroy_node(sp);
  }
  sp = NULL;

  return(list);
}

dict_t 
dict_remove(dict_t dict, string word)
{
  assert(invrep(dict));
  int index = find_index_of_key(dict, word);
  if (index != -1)
  {
    dict->words = remove_on_index(dict->words, index);
    dict->definitions = remove_on_index(dict->definitions, index);
    dict->size--;
  }
  assert(invrep(dict));
  
  return(dict);
}

dict_t 
dict_remove_all(dict_t dict) 
{   
  assert(invrep(dict));
  struct _node_t *sp_w = dict->words;
  struct _node_t *sp_d = dict->definitions;
  while(dict->words != NULL)
  {
    dict->words = dict->words->next;
    dict->definitions = dict->definitions->next;
    sp_w = destroy_node(sp_w);
    sp_d = destroy_node(sp_d);
    sp_w = dict->words;
    sp_d = dict->definitions;
    dict->size = dict->size - 1u;
  }
    
  assert(invrep(dict) && dict_length(dict)==0u);

  return(dict);
}

/* tip: use fprintf(file, "%s : %s\n", string_ref(word), string_ref(def));
 * to save to file  */

void 
dict_dump(dict_t dict, FILE *file) 
{
  assert(invrep(dict));
  struct _node_t *sp_w = dict->words;
  struct _node_t *sp_d = dict->definitions;
  while(sp_w != NULL)
  {
    fprintf(file, "%s : %s\n", string_ref(sp_w->elem), string_ref(sp_d->elem));
    sp_d = sp_d->next;
    sp_w = sp_w->next;
  }
  assert(invrep(dict));
}

dict_t 
dict_destroy(dict_t dict) 
{
  dict = dict_remove_all(dict);
  free(dict);
  dict = NULL;

  return(dict);
}
