#include <stdlib.h>
#include <stdio.h>

void 
absolute(int x, int *y)
{
    if(x >= 0)
	{
		*y = x;
	}
	else
	{
		*y = - x;
	}
}

int 
main(void) 
{
    int a=0, res=0;  
	a=-10;
	absolute(a, &res);
	printf("%d", res);
    return EXIT_SUCCESS;
}

/*
 * Al declarar absolute(int x, int *y) estamos haciendo paso por referencia
 * a la variable (y) i.e. la funcion toma la direccion de memoria de la 
 * variable (y) para asi poder modificarla, de esta manera decimos que el 
 * parametro int *y es de la forma in/out.
 *
 * Por otro lado la variable (x) se pasa como valor, la funcion recibe una
 * copia de (x), es capaz de usar esa copia pero no de modificar la variable
 * (x) 
 *
 * */
