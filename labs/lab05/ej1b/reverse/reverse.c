/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "../stack.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
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
    return (result);
}

stack 
array_to_stack(int array[], unsigned int length)
{
	stack s = stack_empty();
	unsigned int i = 0;
	while(i < length)
	{
		s = stack_push(s, array[i]);
		i = i + 1;
	}
	return(s);
}

int 
*stack_to_array_(stack s)
{
	int *array = NULL;
	if( s != NULL)
	{
		unsigned int n = stack_size(s);
		array = calloc(n, sizeof(int));
		unsigned int i = 0;
		while(i < n)
		{
			array[i] = stack_top(s);
			s = stack_pop(s);
			i = i + 1;
		}
	}
	return(array);
}

int
main(int argc, char *argv[])
{
	char *filepath = NULL;

	/* parse the filepath given in command line arguments */
	filepath = parse_filepath(argc, argv);

	/* create an array of MAX_SIZE elements */
	int array[MAX_SIZE];

	/* parse the file to fill the array and obtain the actual length */
	unsigned int length = array_from_file(array, MAX_SIZE, filepath);
	printf("Original: ");
	array_dump(array, length);

	int *new_array=NULL;
  	 
	stack s = array_to_stack(array, length);
	new_array = stack_to_array_(s);
    s = stack_destroy(s);	
    
	printf("Reversed: ");
	array_dump(new_array, length);
    free(new_array);
    new_array = NULL;

    return (EXIT_SUCCESS);
}
