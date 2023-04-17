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
	// length(s1) == length(s2)
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
	bool result;
	unsigned int len_s1 = fstring_length(s1);
	unsigned int len_s2 = fstring_length(s2);	
	unsigned int min_length = len_s1 < len_s2 ? len_s1 : len_s2;
	unsigned int i = 0;
	while(i < min_length && s1[i] == s2[i])
	{
		i = i + 1;
	}
	result = i == min_length ? len_s1 <= len_s2 : s1[i] <= s2[i];
	
	return result;
}

/*
 * very slow implementation
 *
bool
fstring_less_eq(fixstring s1, fixstring s2)
{
	bool result;
	if(fstring_prefix(s1, s2))
	{
		result = true;
	}
	else if(fstring_prefix(s2, s1))
	{
		result = false;
	}
	else 
	{	
		bool guard = false;
		unsigned int i = 0;
		result = true;
		while( !guard && s1[i] != '\0' && s2[i] != '\0') 
		{
			if(s1[i] == s2[i])
			{
				result = true;
			} 
			else if(s1[i] < s2[i])
			{
				guard = true;
				result = true;
			}
			else
			{
				guard = true;
				result = false;
			}
			i = i + 1;
		}
	}
	return result;
}

bool 
fstring_prefix(fixstring s1, fixstring s2)
{
	bool result;
	if(fstring_length(s1) <= fstring_length(s2))
	{	
		result = true;
		unsigned int i=0;
		while(i < fstring_length(s1))
		{
			result = result && s1[i] == s2[i];
			i = i + 1;
		}
	}
	else 
	{
		result = false;
	}
	return result;
}
*/
