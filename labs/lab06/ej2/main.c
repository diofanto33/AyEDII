
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int
main(int argc, char *argv[])
{
  if(argc != 3)
  {
    perror("Error: Cantidad de argumentos invalida\n"); 
    exit(EXIT_FAILURE);
  }
  
  string str1 = string_create(argv[1]);
  string str2 = string_create(argv[2]);
  
  if(string_eq(str1, str2))
  {
    printf("%s es igual a %s\n", argv[1], argv[2]);
  }
  else if(string_less(str1, str2)) 
  {
    printf("%s es menor que %s\n", argv[1], argv[2]);
  } 
  else
  {
    printf("%s es mayor que %s\n", argv[1], argv[2]);
  }

  string_destroy(str1);
  string_destroy(str2);
  
  return(EXIT_SUCCESS);
}
