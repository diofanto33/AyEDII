#include "clone_ptr.h"

char
*string_clone(const char *str, size_t length) 
{
    char *clone = NULL;
	if(str != NULL && length > 0 && length < strlen(str))
	{
		clone = calloc(length + 1, sizeof(char)); // +1 for '\0'
    	if (clone == NULL) 
		{
			perror("Error en la reserva de memoria");
			exit(EXIT_FAILURE);
		}
    	for (size_t i=0; i<length; i++)
		{
        	clone[i] = str[i];
    	}
    	clone[length] = '\0';
	}
	return(clone);
}
