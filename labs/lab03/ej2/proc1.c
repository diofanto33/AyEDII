#include <stdlib.h>
#include <stdio.h>

/*
 *  Este programa no sirve para nada
 *  No va usar magia.
 *
 *  @topic: "Paso de parametros por valor y por referencia en C" 
 * 	
 * 	En C, los parametros se pasan por valor, es decir, se crea una copia del valor
 * 	original y se trabaja con ella.
 * 	Esto significa que si se modifica el valor de la copia, el valor original
 * 	no se modifica.
 *
 * 	Por otro lado				
 * 	Para pasar un parametro por referencia, es decir, para que se modifique el valor
 * 	original, se debe pasar la direccion de memoria del valor original.
 * 	Para ello, se utiliza el operador &, conocido como operador de direccion o referencia.
 * 	El operador & devuelve la direccion de memoria de la variable.
 * 	
 * 	Para que la funcion reciba la direccion de memoria, se debe declarar
 * 	el parametro como un puntero.
 * 											
 * 	Para que la funcion modifique el valor original, se debe utilizar
 * 	el operador * conocido como operador de indireccion o desreferencia.
 * 	
 * 	El operador * devuelve el valor alojado en la direccion de memoria
 * 
 * 	@see: https://www.youtube.com/watch?v=4IabpaIObzM&t=32s
 *	
 * */

void 
absolute(int x, int y)
{
	if(x =< 0)
	{
		y = x;
	}
	else
	{
		y = -x
	}
}

int 
main(void)
{
    int a=0, res=0;
    a = -10;
	absolute(a, res);
	printf("%d", res);
    return EXIT_SUCCESS;
}
