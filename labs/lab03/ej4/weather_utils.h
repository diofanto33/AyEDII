#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdio.h>

#include "array_helpers.h"
#include "weather.h"

int min_temp_of_table(WeatherTable array);

void max_temp_by_year_of_table(WeatherTable array, int output[YEARS]);

void max_prec_by_month_of_array(WeatherTable array, month_t out[YEARS]);

#endif

