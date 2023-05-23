#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "clone_ptr.h"

int
main(void)
{
	char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                     Episode IV \n\n"
         "                     A NEW HOPE \n\n"
         "                     It is a period of civil war. Rebel\n"
         "spaceships, striking from a hidden base, have won their\n"
         "first victory against the evil Galactic Empire. During the\n"
         "battle, Rebel spies managed to steal secret plans to the\n"
         "Empire’s ultimate weapon, the DEATH STAR, an armored space\n"
         "station with enough power to destroy an entire planet.\n"
         "Pursued by the Empire’s sinister agents, Princess Leia\n"
         "races home aboard her starship, custodian of the stolen\n"
         "plans that can save her people and restore freedom to the\n"
         "galaxy...\n";
	char *copy=NULL;

    copy = string_clone(original, strlen(original));
    printf("Original: %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   : %s\n", copy);
	free(copy);

    return EXIT_SUCCESS;
}

/*
 * 1. ¿Qué hace la función string_clone?
 *   	
 *   	Copia una cadena de caracteres en otra.
 *   	La función recibe como parámetros un puntero a char y un entero sin signo.
 *   	El puntero a char apunta a la cadena de caracteres que se quiere copiar.
 *   	El entero sin signo indica la longitud de la cadena de caracteres.
 *   	La función devuelve un puntero a char que apunta a la cadena de 
 *   	caracteres copiada.
 * 	
 * 		La función reserva memoria para la cadena de caracteres copiada.
 *		Que luego es liberada en el main.	
 *
 *		Errores:
 * 	
 * 		char 
 * 		*string_clone(const char *str, size_t length)
 * 		{
 *  		char clone[length + 1];
 *   		char *output=clone;
 *   		for (size_t i=0; i<length; i++)
 *   		{
 *      		clone[i] = str[i];
 *   		}
 *   		clone[length] = '\0';
 *   		return output;
 *		}
 * 		
 * 		La funcion crea un arreglo local de caracteres llamado clone 
 * 		que solo existe dentro de la función. Luego devuelve un puntero
 * 		a ese arreglo local. Cuando la función termina, el arreglo local
 * 		es destruido y el puntero apunta a una dirección de memoria que 
 * 		no existe más. Por lo tanto, el puntero apunta a una dirección 
 * 		de memoria inválida.
 *		
 *		Por otro lado
 * 		Cuando se llamaba en main a la función string_clone, se le pasaba como
 * 		parámetros la cadena de caracteres original y la longitud incorrecta de 
 * 		la cadena de caracteres original. sizeof(original)/sizeof(char) devuelve
 *   	8 mientras que la longitud de la cadena de caracteres original es 1453.
 *   	Por lo tanto usamos strlen(original)  de la librería string.h que devuelve
 *   	la longitud de la cadena
 *   
 * */





