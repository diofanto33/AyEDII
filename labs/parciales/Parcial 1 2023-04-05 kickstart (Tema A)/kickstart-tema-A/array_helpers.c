/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

static const int EXPECTED_DIM_VALUE = 2;

static const char* CITY_NAMES[CITIES] = {
					  "Cordoba",
					  "Rosario",
					  "Posadas",
					  "Tilcara",
					  "Bariloche"
	  		                };

static const char* SEASON_NAMES[SEASONS] = {"low", "high"};

static void
init_array(key_t a[CITIES * SEASONS])
{
    for(unsigned int i = 0u; i < CITIES * SEASONS; i = i + 1)
    {
        a[i]._code = CITIES;   	// cualquier verdura que no pertencezca a [0,4]
	a[i]._season = SEASONS; // cualquier verdura que no pertencezca a [0,1]
    }
}

static int
array_value_count(key_t a[CITIES * SEASONS], key_t value)
{
    unsigned int count = 0u;
    for (unsigned int i = 0u; i < CITIES * SEASONS; i = i + 1)
    {
    	if (a[i]._code == value._code && a[i]._season == value._season)
	{
	    count = count + 1;
        }
    }
    return count;
}

void 
array_dump(BakeryProductTable a)
{
    for (unsigned int city = 0u; city < CITIES; ++city)
    {
        for (unsigned int season = 0u; season < SEASONS; ++season)
        {
            fprintf(stdout, "%s in %s season: flour (%u,%u) Yeast (%u,%u) Butter (%u,%u) Sales value %u",
                    CITY_NAMES[city], SEASON_NAMES[season], a[city][season].flour_cant,
                    a[city][season].flour_price, a[city][season].yeast_cant,
                    a[city][season].yeast_price, a[city][season].butter_cant,
                    a[city][season].butter_price, a[city][season].sale_value);
            fprintf(stdout, "\n");
        }
    }
}

unsigned int 
best_profit(BakeryProductTable a)
{
    unsigned int max_profit = 0u;
    for(unsigned int code = 0u; code < CITIES; code = code + 1)
    {	
        unsigned int aux = 0u;
	for(unsigned int season = 0u; season < SEASONS; season = season + 1)
	{
	    aux = a[code][season].flour_cant*a[code][season].flour_price +
		  a[code][season].yeast_cant*a[code][season].yeast_price +
		  a[code][season].butter_cant*a[code][season].butter_price;
	    aux = a[code][season].sale_value - aux;
	    if(max_profit <= aux)
	    {
	        max_profit = aux;
	    }
	}
    }
    return max_profit;
}

void 
array_from_file(BakeryProductTable array, const char* filepath)
{
    FILE* file = NULL;
    
    file = fopen(filepath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    
    key_t a[CITIES * SEASONS];
    init_array(a);
	
    int res = 0;
    unsigned int code;
    unsigned int season;
    unsigned int i = 0;
    
    while (!feof(file) && i < CITIES * SEASONS )
    {
        res = fscanf(file, " ##%u??%u ", &code, &season);
		
        if (res != EXPECTED_DIM_VALUE)
        {
            fprintf(stderr, "Invalid file.\n");
            exit(EXIT_FAILURE);
        }
	if(CITIES <= code || (season != 0 && season != 1))
	{
	    perror("index too large. \n");
	    exit(EXIT_FAILURE);
	}
        /* COMPLETAR: Leer y guardar product en el array multidimensional*/
        /* Agregar las validaciones que considere necesarias*/
	BakeryProduct lista = bakery_product_from_file(file);
	a[i]._code = code;
	a[i]._season = season;
	key_t key;
	key._code = code;
	key._season = season;
	if(array_value_count(a, key) >= EXPECTED_DIM_VALUE)
	{	
	    perror("ERROR: Hay dos entradas distintas para la combinacion ciudad-temporada. \n");
	    exit(EXIT_FAILURE);
	}
	array[code][season] = lista;
	i = i + 1;
    }
    fclose(file);
}
