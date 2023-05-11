#include <stdio.h>
#include <stdlib.h>

typedef int list_elem;

/* Constructores */

/* Crea una lista vacia */
list empty_list(void);

/* Agrega el elemento e por izquierda a la lista l */
list addl_list(list l, list_elem e);

/* Destructor */

/* Libera memoria en caso de ser necesario */
list destroy_list(list l);

/* Operaciones */

/* Devuelve true si la list l es vacia */
bool is_empty_list(list l);

/* Devuelve el primer elemento de la lista l */ 
list_elem head(list l);

/* Elimina el primer elemento de la lista l */
list tail(list l);

/* Agrega el elemento e al final de la lista l */ 
list addr_list(list l, list_elem e);

/* Devuelve la cantidad de elementos de l */
unsigned int length_list(list l);

/* Agrega al final de l todos los elementos de lx en el mismo orden */
list concat_list(list l, list lx);

/* Devuelve el n-esimo elemento de la lista l */
/* PRE: length_list(l) > n */
list_elem index_list(list l);

/* Deja en l solo los primeros n elementos, eliminando el resto */
list take_list(list l, unsigned int n);

/* Elimina los primeros n elementos de l */
list drop_list(list l, unsigned int n);

/* Devuelve una lista copia de l */
list copy_list(list l);
