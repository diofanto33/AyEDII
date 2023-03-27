#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

	FILE* fd = NULL;
	unsigned int length;
	fd = fopen(filepath, "r");
	unsigned int scanf_result = fscanf(fd, "%u", &length);
	if (scanf_result <= 0) {
		printf("Error al leer la longitud del arreglo\n");
		exit(EXIT_FAILURE);
	}
	assert(length <= max_size);
	unsigned int i=0;
	while(i<length ){
		scanf_result = fscanf(fd, "%d", &array[i]);
		if (scanf_result <= 0) {
			printf("Error al leer un elemento del arreglo\n");
			exit(EXIT_FAILURE);
		}
		i = i + 1;
	}
	fclose(fd);
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
