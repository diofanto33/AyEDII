/* author: diofanto33 
 * date: 2023-06-22
 * time: 18:52
 *
 * two spaces indentation
 *
 */

#include "list.h"


#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct _list
{
  struct _node* head;
  ListSize size;
};

struct _node
{
  elem e;
  struct _node* next;
};

/**
 * @brief Invariante de represetación
 *    Verifica que se cumplan:
 *   
 *   1) Existencia: Inicializacion
 *   2) Consistencia: el campo size en relacion
 *      con la cantidad de nodos de la lista.
 *
 * @param: l Lista
 * @return: true Si se cumplen 1 y 2, false si no.
 */
static bool 
invrep(list l)
{
  bool check = (l != NULL);
  ListSize check_size = 0u;
  if(check)
  {
    struct _node * sp = l->head;
    while(sp != NULL)
    {
      check_size = check_size + 1u;
      sp = sp->next;
    }
  }
  check = check && (check_size==l->size);

  return(check); 
}

/**
 * @brief Crea un nodo de la lista nuevo
 *
 * @param e Elemento que contendrá el nodo
 * @return struct _node* Nuevo nodo creado o NULL si no hay memoria
 */
static
struct _node* 
create_node(elem e)
{
  struct _node* res = malloc(sizeof(struct _node));
  if(res != NULL)
  {
    res->e = e;
    res->next = NULL;
  }

  return(res);
}

/**
 * @brief Destruye el nodo node
 *
 * @param node Nodo a ser destruido
 * @return struct _node* Devuelve NULL si el nodo se destruyó correctamente
 */
static struct _node*
destroy_node(struct _node* killme)
{
  if (killme != NULL)
  {
    free(killme);
    killme = NULL;
  }
  assert(killme == NULL);

  return(killme);
}

list 
list_empty()
{
  list res = NULL;
  res = malloc(sizeof(struct _list));
  assert(res != NULL);
  res->head = NULL;
  res->size = 0u;
  assert(invrep(res));

  return(res);
}

list 
list_addl(list l, elem e)
{
  assert(invrep(l));
  struct _node *new_node = create_node(e);
  new_node->next = l->head;
  l->head = new_node;

  /*    if(l->size==0u)
        {
        l->head = new_node;
        }
        else 
        {
        new_node->next = l->head;
        l->head = new_node;
        }
        */ 
  l->size = l->size + 1u;
  assert(invrep(l));

  return(l);
}

list list_addr(list l, elem e)
{
  assert(invrep(l));
  struct _node* new_node = create_node(e);
  if(l->size != 0u)
  {
    struct _node* sp = l->head;
    while(sp->next != NULL)
    {
      sp = sp->next;
    }
    sp->next = new_node;
  }
  else 
  {
    l->head = new_node;
  }
  l->size = l->size + 1u;
  assert(invrep(l));

  return(l);
}

bool 
list_is_empty(list l)
{
  assert(invrep(l));
  return(l->size==0u);
}

elem
list_head(list l)
{
  assert(l != NULL && invrep(l) && !list_is_empty(l));

  return(l->head->e);
}

list 
list_tail(list l)
{
  assert(invrep(l) && !list_is_empty(l));
  struct _node *killme = l->head;
  l->head = l->head->next;
  killme = destroy_node(killme);
  l->size = l->size -1u;
  assert(invrep(l));

  return(l);
}

ListSize 
list_length(list l)
{
  assert(l != NULL);

  return(l->size);
}

void 
list_print(list l)
{
  assert(invrep(l));
  if(l->size != 0u)
  {
    fprintf(stdout, "[");
    struct _node *sp = l->head;
    while(sp != NULL)
    {
      fprintf(stdout, " %u, ", sp->e);
      sp = sp->next;
    }
    fprintf(stdout, "]");
  }
  else 
  {
    fprintf(stdout, "[]\n");
  }
  assert(invrep(l));
}

list
list_destroy(list l)
{
  assert(l != NULL && invrep(l));
  struct _node *sp = l->head;
  while(l->head != NULL)
  {
    sp = l->head->next;
    l->head = destroy_node(l->head);
    l->head = sp;
  }
  free(l);
  l = NULL;
  assert(l==NULL);

  return(l);
}

/* Funciones Anexas */

list
list_greater_than(list l, unsigned int n)
{
  assert(invrep(l));
  struct _list *list = list_empty(); 
  struct _node *sp = l->head;
  while(sp != NULL)
  {
    if(sp->e > n)
    {
      list = list_addl(list, sp->e);
    }
    sp = sp->next;
  }
  assert(invrep(list) && invrep(l));
  
  return(list);
}

unsigned int 
list_greater_than_count(list l, unsigned int n)
{
  assert(invrep(l));
  struct _node *sp = l->head;
  unsigned int count = 0u;
  while(sp != NULL)
  {
    if(sp->e > n)
    {
      count = count + 1u;
    }
    sp = sp->next;
  }
  assert(invrep(l));

  return(count);
}

list 
list_insert_at(list l, unsigned int position, elem e)
{
  assert(invrep(l));
  struct _node *sp = l->head;
  struct _node *prev = NULL;
  unsigned int i = 0u;
  while(i < position)
  {
    prev = sp;
    sp = sp->next;
    i = i + 1u;
  }
  struct _node *new_node = create_node(e);
  if(prev != NULL)
  {
    prev->next = new_node;
    new_node->next = sp;
  }
  else
  {
    l->head = new_node;
    new_node->next = sp;
  }
  l->size = l->size + 1u;
  prev = NULL;
  sp = NULL;
  assert(invrep(l));
    
  return(l);
}
