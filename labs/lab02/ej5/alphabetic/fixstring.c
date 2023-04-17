#include <stdbool.h>
#include <assert.h>

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
	else
	{
		unsigned int i = 0;
		unsigned int length =  fstring_length(s1); 
		while(result && i < length)
		{
			result = result && (s1[i] == s2[i]);
			i = i + 1;
		}
	}
	return result;
}

bool
fstring_less_eq(fixstring s1, fixstring s2)
{
	unsigned int min_length;
	min_length = fstring_length(s1) < fstring_length(s2) ? fstring_length(s1) : fstring_length(s2);
	unsigned int i = 0;
	while(i < min_length && s1[i] == s2[i])
	{
		i = i + 1;
	}
	bool result = i == min_length ? fstring_length(s1) <= fstring_length(s2) : s1[i] <= s2[i];
	
	return result;
}

void 
fstring_set(fixstring s1, const fixstring s2)
{
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0')
	{
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) 
{
    fixstring aux;
	fstring_set(aux, s1);
	fstring_set(s1, s2);
	fstring_set(s2, aux);
}