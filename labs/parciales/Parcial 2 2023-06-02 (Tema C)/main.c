/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "set.h"
#include "set_helpers.h"


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads element given in a file in disk into a set.\n"
           "\n"
           "The input file must have the following format:\n"
           " * One line that must contain the elements"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<elem_1> <elem_2> ... <elem_N>\n\n",
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

  /* parse the file to fill the array and obtain the actual length */
  set s = set_from_file(filepath);

  /* create a copy of the array, to do some checks later */
  unsigned int size=set_cardinal(s);
  set_dump(s);
  printf("El archivo '%s' tiene %u elementos únicos\n", filepath, size);

  s = set_destroy(s);
  return EXIT_SUCCESS;
}
