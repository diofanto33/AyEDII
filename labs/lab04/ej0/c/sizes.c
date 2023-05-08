#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int
main(void)
{
    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name),
		   							   sizeof(messi.age),
		  							   sizeof(messi.height),
									   sizeof(messi));
	
	data_t pru;
	printf("\ndata_t-size of pru: %lu bytes\n", sizeof(pru));
	printf("name-size of pru  : %lu bytes\n", sizeof(pru.name));
	
	char c;
	printf("\nchar-size: %lu bytes\n", sizeof(c));
	
	char a[10];
	printf("\nchar[10]-size: %lu bytes\n", sizeof(a));

    return EXIT_SUCCESS;
}

