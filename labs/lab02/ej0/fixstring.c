#include <assert.h>
#include <stdbool.h>

#include "fixstring.h"

unsigned int
fstring_length(fixstring s)
{
	unsigned int length = 0;
	while(s[length] != '\0')
	{
		length = length + 1;
	}
	return length;
}

bool
fstring_eq(fixstring s1, fixstring s2)
{
	bool result = true;
	if(fstring_length(s1) != fstring_length(s2))
	{
		result = false;
	}
	unsigned int i = 0;
	unsigned int length =  fstring_length(s1); 
	while(result && i < length)
	{
		result = result && (s1[i] == s2[i]);
		i = i + 1;
	}
	return result;
}

bool
fstring_less_eq(fixstring s1, fixstring s2)
{
	
}

