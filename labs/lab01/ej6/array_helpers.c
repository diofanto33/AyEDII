#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int 
array_from_file(int array[],
                unsigned int max_size,
                const char *filepath) 
{

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

void 
array_dump(int a[], unsigned int length) 
{
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

bool 
array_is_sorted(int a[], unsigned int length)
{
	bool result = true;
	unsigned int i = 0;
	while(i < length - 1 && result){
		result = a[i] <= a[i+1];
		i = i + 1;
	}
	return result;
}

void 
array_swap(int a[], unsigned int i, unsigned int j)
{	
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void
reverse_array(int a[], unsigned int length)
{
	unsigned int i = 0;
	unsigned int j = length - 1;
	unsigned int length_div_2 = length/2;
	while(i < length_div_2)
	{
		array_swap(a, i, j);
		i = i + 1;
		j = j - 1;
	}
}







