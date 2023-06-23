
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    priority_t min_pri;
    unsigned int size;
    struct s_node **array;
};

struct s_node {
    pqueue_elem elem;
    struct s_node *next;
};

static struct s_node * create_node(pqueue_elem e) {
    struct s_node* new_node=NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    if (node != NULL){
        node->next = NULL;//no olvidar
        free(node);    
        node = NULL;
    }
    assert(node == NULL);
    return node;
}
/*
En la implementaciòn, los nodos no acarrean su prioridad.
No hay relaciòn entre size y min_priority.
Asumo entonces que el invariante de representaciòn sòlo serà q != NULL.
*/
static bool invrep(pqueue q) {
   return q!=NULL;
}

pqueue pqueue_empty(priority_t min_priority) {
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    q->min_pri = min_priority;
    q->size = 0u;
    q->array = NULL;

    /*   q->array = calloc(max_priority + 1, (sizeof(struct s_node *)));
    for (unsigned int i = 0u; i <= max_priority; i++){
        q->array[i] = NULL;
    }*/
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) {
    assert(invrep(q));
    
    struct s_node *new_node = create_node(e);
    
    if (priority <= q->min_pri){
        if (pqueue_is_empty(q)){
            q->array = calloc(q->min_pri+1, sizeof(struct s_node));//inicializa en 0 los elementos del arreglo  min_pri+1 xq empieza desde 0
            q->array[priority] = new_node;
        } else {
            if (q->array[priority] == NULL){
                q->array[priority] = new_node;
            } else {
                struct s_node *aux = q->array[priority];
                while (aux->next != NULL){
                    aux = aux->next;
                }
                aux->next = new_node;
            }
        }
    }
    q->size +=1;
    assert(invrep(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return (q->size == 0);
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node **aux = q->array;
    priority_t i = 0u;
        while (aux[i] == NULL){    // S� que en algun momento va a frenar pues la queue no es vacia.
            ++i;
        }
        //Busco la primera cola del arreglo que tenga algún elemento
        //Y devuelvo el primer elemento de esa fila 
    return aux[i]->elem;//a[peek_priority(q)]->elem
}

priority_t pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node **aux = q->array;
    priority_t i = 0u;
        while (aux[i] == NULL){    // S� que en algun momento va a frenar pues la queue no es vacia.
            ++i;
        }
    return i;//pñosiciopn de la prio
}

size_t pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node **aux = q->array;
    priority_t i = 0u;
    while (aux[i] == NULL){    // S� que en algun momento va a frenar pues la queue no es vacia.
        ++i;
    }
    struct s_node *killme = aux[i];//aux[i] es el primer elemento de la cola guardada en la posición i del arreglo
    aux[i] = aux[i]->next;//aux[i] next el segundo
    destroy_node(killme);
    q->size -= 1;
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    while (!pqueue_is_empty(q)){
        q = pqueue_dequeue(q);    
    }
    free(q->array);
    free(q);
    q = NULL;
    assert(q==NULL);
    return q;
}

