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
    "Cordoba", "Rosario", "Posadas", "Tilcara", "Bariloche"};
static const char* SEASON_NAMES[SEASONS] = {"low", "high"};

void array_dump(BakeryProductTable a)
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

unsigned int best_profit(BakeryProductTable a)
{
    unsigned int max_profit;
    max_profit = (a[0][0].sale_value - (a[0][0].flour_cant * a[0][0].flour_price +
                        a[0][0].yeast_cant * a[0][0].yeast_price +
                        a[0][0].butter_cant * a[0][0].butter_price));

    for (int city = 0; city < CITIES; ++city)
    {

        for (int season= 0; season < SEASONS; ++season)
        {
            if(max_profit < (a[city][season].sale_value - (a[city][season].flour_cant * a[city][season].flour_price + a[city][season].yeast_cant * a[city][season].yeast_price + a[city][season].butter_cant * a[city][season].butter_price))) {
                max_profit = (a[city][season].sale_value - (a[city][season].flour_cant * a[city][season].flour_price + a[city][season].yeast_cant * a[city][season].yeast_price + a[city][season].butter_cant * a[city][season].butter_price));
            }
        }

    }
    return max_profit;
}



void array_from_file(BakeryProductTable array, const char* filepath)
{

    unsigned int citiesRead[CITIES][SEASONS];
    for (int city = 0; city < CITIES; ++city)
    {
        for (int season = 0; season < SEASONS; ++season)
        {
            citiesRead[city][season] = 0u;
        }
    }

    FILE* file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (!(feof(file)) && i < SEASONS*CITIES)
    {
        unsigned int city = 0u;
        unsigned int season = 0u;

        int res = fscanf(file,"##%u??%u ", &city, &season);
        if (res != EXPECTED_DIM_VALUE)
        {
            fprintf(stderr, "Invalid file.\n");
            exit(EXIT_FAILURE);
        }

        if (city >= CITIES || season >= SEASONS) {
            fprintf(stderr,"Invalid format, city must be between 0 and 4 and season between 0 and 1\n");
            exit(EXIT_FAILURE);
        }

        BakeryProduct product = bakery_product_from_file(file);

        if (citiesRead[city][season] == 0 )
        {
            citiesRead[city][season] = 1u;    
        } else {
            fprintf(stderr, "Too many entries for %s city in %s season \n", CITY_NAMES[city], SEASON_NAMES[season]);
        }

        array[city][season] = product;

        ++i;
    }

    fclose(file);
}
