#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

void charge_array(int arr[], unsigned int length){
	unsigned int i = 0;
	while(i < length){
		printf("Ingrese el valor de la posicion %u: ", i);
		scanf("%d", &arr[i]);
		i = i+1;
	}
}


struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;   
	res.is_upperbound = true;
	res.is_lowerbound = true;
	res.exists = false;
	res.where = -1;
	unsigned int i = 0;
	while(i < length && (res.is_lowerbound || res.is_upperbound)){
		res.is_lowerbound = arr[i] >= value && res.is_lowerbound;
		res.is_upperbound = arr[i] <= value && res.is_upperbound;
		if(arr[i] == value){
			res.exists = true;
			res.where = i;
		}
		i = i+1;
	}
	return res;
}

int charge_value(){
	int value;
	printf("Ingrese el valor a buscar: ");
	scanf("%d", &value);
	return value;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    charge_array(a, ARRAY_SIZE);
    value = charge_value();
	struct bound_data result = check_bound(value, a, ARRAY_SIZE);
	
  	if(result.is_lowerbound){
		printf("El valor %d es cota inferior del arreglo.\n", value);
		if(result.exists){
			printf("El valor %d existe en la posicion %u i.e. es el minimo.\n", value, result.where);
		}
	} if(result.is_upperbound){
			printf("El valor %d es cota superior del arreglo.\n", value);
			if(result.exists){
				printf("El valor %d existe en la posicion %u i.e. es el maximo.\n", value, result.where);
			}
	}
	return EXIT_SUCCESS;
}

