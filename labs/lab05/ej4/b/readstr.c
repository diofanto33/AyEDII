#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int
main(void) 
{
	char user_input[MAX_LENGTH];

	// Pedimos el nombre y apellido
    printf("Ingrese su nombre y apellido: ");
	// Leemos el nombre y apellido
    fgets(user_input, MAX_LENGTH, stdin);

	// Eliminamos el salto de linea
	user_input[strlen(user_input) - 1] = '\0';
    
	// Imprimimos el mensaje de bienvenida
	printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    return EXIT_SUCCESS;
}

