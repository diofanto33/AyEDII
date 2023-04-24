#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "weather_utils.h"

int 
min_temp_of_table(WeatherTable array)
{	
	int min_temp = array[0][0][0]._min_temp;
	for(year_t k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{
		for(month_t k_month = january; k_month <= december; k_month = k_month + 1)
		{
			for(day_t k_day = FST_DAY; k_day <= DAYS; k_day = k_day + 1)
			{
				if(min_temp > array[k_year-FST_YEAR][k_month][k_day-FST_DAY]._min_temp)
				{
					min_temp = array[k_year-FST_YEAR][k_month][k_day-FST_DAY]._min_temp;
				}
			}
		}
	}
	return min_temp;
}
 
void
max_temp_by_year_of_table(WeatherTable array, int output[YEARS])
{
	for(year_t k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{	
		int max_temp = array[k_year - FST_YEAR][january][0]._max_temp;
		for(month_t k_month = january; k_month <= december; k_month = k_month + 1)
		{
			for(day_t k_day = FST_DAY; k_day <= LST_DAY; k_day = k_day + 1)
			{
				int elem = array[k_year - FST_YEAR][k_month][k_day-1]._max_temp; 
				if(max_temp < elem)
				{
					max_temp = elem; 
				}
			}			
		}
		output[k_year -FST_YEAR] = max_temp;
	}
}

void
max_prec_by_month_of_array(WeatherTable array, month_t out[YEARS])
{
	for(year_t k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{	
		unsigned int sum_by_month_aux = 0;
		for(month_t k_month = january; k_month <= december; k_month = k_month + 1)
		{	
			unsigned int sum_by_month = 0;
			for(day_t k_day = FST_DAY; k_day <= LST_DAY; k_day = k_day + 1)
			{
				sum_by_month = array[k_year-FST_YEAR][k_month][k_day-FST_DAY]._rainfall + sum_by_month;
			}
			if(sum_by_month > sum_by_month_aux)
			{
				sum_by_month_aux = sum_by_month;
				out[k_year-FST_YEAR] = k_month; 
			}
		}
	}
}
