#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef unsigned int ListSize;
typedef unsigned int elem;
typedef struct _list* list;

/* Constructors */

/**
 * @brief Crea una nueva lista vacía
 *
 * @return list Lista vacía creada
 */
list list_empty();

/**
 * @brief Agrega un elemento por izquierda
 *
 * @param l Lista a la que se le agregará el elemento
 * @param e Nuevo elemento a ser agregado
 * @return list La lista que contiene el nuevo elemento al principio
 */
list list_addl(list l, elem e);

/**
 * @brief Agrega un nuevo elemento e por derecha a la lista l
 *
 * @param l Lista a la que se le agregará el elemento
 * @param e Elemento nuevo a ser agregado
 * @return list List que contiene el nuevo elemento al final
 */
list list_addr(list l, elem e);

/* Operations */

/**
 * @brief Devuelve 'True' si la lista l es vacía
 *
 * @param l Lista a ser verificada
 * @return true Si la lista L es vacía
 * @return false Si la listaa L no es vacía
 */
bool list_is_empty(list l);

/**
 * @brief Retorna la cabeza de la lista. NO DEBE modificar la lista (Solo lectura)
 *        PRECONDICION: La lista no puede ser vacía
 *
 *
 * @param l Lista
 * @return elem Elemento presente al principio de la lista
 */
elem list_head(list l);

/**
 * @brief Retorna la cabeza de la lista.
 *        Esta función MODIFICA la lista borrando el primer nodo.
 *
 * @param l Lista
 * @return list Retorna la lista sin la 'cabeza'
 */
list list_tail(list l);

/**
 * @brief Retorna el tamaño de la lista. DEBE ser de orden constante
 *
 * @param l List
 * @return ListSize Tamaño de de la lista
 */
ListSize list_length(list l);

/**
 * @brief Imprime una lista por stdout
 *
 * @param l Lista
 */
void list_print(list l);

/**
 * @brief Libera los recursos de la lista l
 *
 * @param l Lista
 * @return list retorna una lista "destruida" (NULL)
 */
list list_destroy(list l);

/* Funciones anexas */

/**
 * @brief Devuelva una NUEVA lista con los elementos de l que
 *        cumplen la condición de ser > a 'n'. La lista retornada
 *        DEBE ser en memoria 'nueva' por lo tanto no modifica la lista l.
 *
 * @param l Lista
 * @param n Número para filtrar los mayores que en la lista l
 * @return list Nueva lista filtrada
 */
list list_greater_than(list l, unsigned int n);

/**
 * @brief Devuelve la cantidad de elementos que cumplen con la condición de ser
 *        mayores que 'n'.
 *
 * @param l Lista
 * @param n Número para contar los mayores que en la lista l
 * @return unsigned int Cantidad de elementos mayores que 'n'
 */
unsigned int list_greater_than_count(list l, unsigned int n);

/**
 * @brief Inserta un elemento 'e' nuevo en la posición 'position'
 *        PRECONDICION: 0 <= position < list_length(l)
 *
 * @param l Lista
 * @param position Posición donde se insertará el elemento nuevo
 * @param e Nuevo elemento a agregar
 * @return list Lista con el nuevo elemento agregado en la posición indicada
 */
list list_insert_at(list l, unsigned int position, elem e);

#endif
