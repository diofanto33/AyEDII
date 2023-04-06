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
    bool less_eq = true;
    unsigned int i = 0;
    unsigned int length1 = fstring_length(s1);
    unsigned int length2 = fstring_length(s2);
	
	// If we are not at the end of one of the strings, continue 
    while ( (s1[i] != '\0') && 
        (s2[i] != '\0') && 
        (i < FIXSTRING_MAX - 1)) 
    {
        // If the number i character in the string s1 is
        // less than his counterpart in s2, it means it's
        // alphabeticaly less in order
        if (s1[i] < s2[i]) {
            return true;
        // If the i position in the string 1 is greater
        // than his counterpart, then its alphabeticaly
        // bigger in order   
        } else if (s1[i] > s2[i]) {
            return false;
        }
		
		// Add one to i so we check the next character inline
        i++;
    
    }

	// Assuming we landed here after finishing one of the strings
	// it means that the first i characters are equal, so if one of
	// the strings left has more characters than the other, it means
	// that its alphabetically bigger, since a character its always bigger
	// than an empty space
    if (length1 > length2) {
        return false;
    // Else if the length of 2nd string is bigger or equal to the 1st string
    // it means that the 1st string is less or equal than the 2nd string
    } else {
    	return true;
    }
}

