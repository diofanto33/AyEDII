/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "list.h"
#include "list_helpers.h"


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads element given in a file in disk into a list.\n"
           "\n"
           "The input file must have the following format:\n"
           " * One line that must contain pairs of key value"
           " separated by one or more spaces. Each key must be an integer., each value a char"
           "\n\n"
           "In other words, the file format is:\n"
           "<key_1> <value_1> <key_2> <value_2> ... <key_N> <value_N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* parse the file to fill the array and obtain the list */
  list_t list = list_from_file(filepath);

  /* create a copy of the array, to do some checks later */
  unsigned int size = list_length(list);
  printf("La lista '%s' tiene los siguientes %u valores: \n", filepath, size);
  list_dump(list);

  int delete_count = 2;
  while (argc > delete_count) {
    list = list_remove (list, atoi(argv[delete_count]));
    delete_count++;
  }

  printf("La lista '%s' tiene los siguientes %u valores luego de remover los seleccionados: \n", filepath, list_length(list));
  list_dump(list);

  list = list_destroy(list);
  return EXIT_SUCCESS;
}
