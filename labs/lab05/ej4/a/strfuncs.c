#include "strfuncs.h"

size_t 
string_length(const char *str)
{
	size_t length = 0;
	while(str[length] != '\0')
	{
		length = length + 1;
	}
	return(length);
}

char
*string_filter(char *str, char c)
{	
	char *out = calloc(string_length(str), sizeof(char));
	unsigned int index_str = 0u;
	unsigned int index_out = 0u;
	while(str[index_str] != '\0')
	{
		if(str[index_str] != c)
		{
			out[index_out] = str[index_str];
			index_out = index_out + 1;
		}
		index_str = index_str + 1;		
	}
	return(out);
}
