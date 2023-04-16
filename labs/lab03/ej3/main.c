#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void 
dump(char a[], unsigned int length)
{
    printf("\"");
    for (unsigned int j=0u; j < length; j++)
	{
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int 
data_from_file(const char *path,
			   unsigned int indexes[],
			   char letters[],
			   unsigned int max_size)
{
	FILE *fd = NULL;
	unsigned int fscanf_result = 0;
	unsigned int length = 0;
	fd = fopen(path, "r");
	if(fd == NULL)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	while(!feof(fd) && length < max_size)
	{
		fscanf_result = fscanf(fd, "%d -> *%c*\n", &indexes[length], &letters[length]);
		if(fscanf_result != 2)
		{
			perror("Error: el archivo no tiene el formato correcto");
			exit(EXIT_FAILURE);
		}
		length = length + 1;
	}
	if(length == max_size)
	{
		perror("Error: el archivo es demasiado grande");
		exit(EXIT_FAILURE);
	}
	fclose(fd);
	return length;
}

void
sort_letters_by_index(unsigned int length,
					  unsigned int indexes[],
					  char letters[],
					  char sorted[])
{
	unsigned int j=0;
	unsigned int k=0;
	while(k < length)
	{
		j = indexes[k];
		if(j >= length)
		{
			perror("Error: el archivo tiene un indice fuera de rango");
			exit(EXIT_FAILURE);
		}
		sorted[j] = letters[k];
		k = k + 1;
	}
}

int 
main(int argc, char *argv[])
{
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;

	length = data_from_file(argv[1], indexes, letters, MAX_SIZE);

	sort_letters_by_index(length, indexes, letters, sorted);

	dump(letters, length);

	dump(sorted, length);

    return EXIT_SUCCESS;
}
