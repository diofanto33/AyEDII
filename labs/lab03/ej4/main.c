/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

void max_temp_by_year_of_table_print(int a[YEARS])
{
	printf("\n");
  	unsigned int year = FST_YEAR;
	while(year <= LST_YEAR)
	{
		printf("For year %d the maximum temperature is: %d\n", year, a[year - FST_YEAR]);
		year = year + 1;
	}
	printf("\n");
}
 
void max_rainfall_by_month_of_table_print(month_t a[YEARS])
{
    char const* months[] = {"January",
							"February", 
							"March",
							"April",
							"May",
							"June",
							"July",
							"August",
							"September",
							"October",
    						"November",
							"December" };
	
	for(year_t k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{
		printf("For year %d, the month with the highest monthly amount of rainfall is: %s\n",k_year ,months[a[k_year-FST_YEAR]]);
	}
}


/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
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

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array with the type of tclimate */
    WeatherTable array;

    /* parse the file to fill the array and obtain the actual length */
    array_from_file(array, filepath);

    /* show the ordered array in the screen */
    array_dump(array);

	/* show the historical maximum temperature */ 

	printf("\n\nThe historical minimum temperature is: %d\n", min_temp_of_table(array));
	
	/* calculate the historical maximum temperature */
	int out[YEARS];
	max_temp_by_year_of_table(array, out);
	/* show the historical maximum temperature */
	max_temp_by_year_of_table_print(out);

	/* calculate the historical maximum precipitation */
	month_t outp[YEARS];
	max_rainfall_by_month_of_table(array, outp);
	/* show the historical maximum precipitation */
	max_rainfall_by_month_of_table_print(outp);

    return (EXIT_SUCCESS);
}
