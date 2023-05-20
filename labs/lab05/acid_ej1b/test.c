#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

void 
array_dump(int a[], unsigned int length)
{
	if( a == NULL)
	{
		fprintf(stdout, "[]\n");
    }
    else 
    {
		fprintf(stdout, "[");
		for (unsigned int i = 0u; i < length; ++i)
		{
			fprintf(stdout, "%d", a[i]);
			if (i < length - 1)
			{
				fprintf(stdout, ", ");
			} 
			else
			{
				fprintf(stdout, "]\n");
			}
		}
	}
}

int
main(void)
{
	/* creamos una pila vacia */ 
	stack s = stack_empty();
	
	/* insertamos 5 elementos */ 
	s = stack_push(s, 1);
	s = stack_push(s, 2);
	s = stack_push(s, 3);
	s = stack_push(s, 4);
	s = stack_push(s, 5);
	
	/* calculamos cuantos elementos tiene la pila s y imprimimos*/ 
	unsigned int n = stack_size(s);
	printf("%d\n", n);
	
	/* creamos un puntero de tipo */
	stack_elem *array = NULL;
	/* copiamos los elementos de la pila en el array de forma inversa */
	array = stack_to_array(s);
	/* Imprimimos el array */
	array_dump(array, n);

	/*Vaciamos la pila*/	
	s = stack_pop(s);
	s = stack_pop(s);
	s = stack_pop(s);
	s = stack_pop(s);
	s = stack_pop(s);
	
	/* Calculamos cuantos elementos tiene la pila */
	n = stack_size(s);
	
	/* Obtenemos el boolaneo de ser pila vacia y imprimimos */
	bool b = stack_is_empty(s);
	printf("%d\n", b);
	
	/* Copiamos la pila en un nuevo arreglo */
	stack_elem *arraypru = stack_to_array(s);
	/* Imprimimos el nuevo arreglo */ 
	array_dump(arraypru, n);
	
	/* Agregamos un elemento a la pila vacia */
	s = stack_push(s, 1000);
	/* Obtenemos el elemento de la pila */
	stack_elem valor = stack_top(s);
	printf("%u", valor);
	/* destruimos la pila */
	stack_destroy(s);

	/* Notar que no se esta liberando memoria para ambos arreglos */
	/* Este programa deberia generar Memory Leakes */

	return(0);
}
