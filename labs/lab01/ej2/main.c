/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
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
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_stdin(int array[], unsigned int max_size) {
	unsigned int length;
	int fscanf_result;
	fprintf(stdout, "Ingresa el tamaño del arreglo: ");
	fscanf_result = fscanf(stdin, "%u", &length);
	if(fscanf_result <= 0 || length > max_size)
	{
		exit(EXIT_FAILURE);	
	}

	unsigned int i =0;
	while(i < length)
	{
		fprintf(stdout,
				"Ingresa el elemento correspondiente a la posicion %u: ",
				i);
		fscanf_result = fscanf(stdin, "%d", &array[i]);
		if(fscanf_result <= 0)
		{
			exit(EXIT_FAILURE);
		}
		i = i + 1;
	}
	return length;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
	unsigned int i=0;
	while(i < length){
		if(i != length - 1){
			printf("%d, ", a[i]);
		} else {
			printf("%d]\n", a[i]);
		}
		i = i + 1;
	}
}


int main(void) {
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
	fprintf(stdout, "El arreglo es: \n");

    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
