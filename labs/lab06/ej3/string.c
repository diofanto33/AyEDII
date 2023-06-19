#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

struct _s_string {
    char *content;
    unsigned int length;
};

static bool 
invrep(string str) 
{   
    bool res = str != NULL;

    return(res);
}


string 
string_create(const char *word)
{
    string str = NULL;
    str = calloc(1, sizeof(struct _s_string));
    assert(str != NULL);
    str->length = strlen(word);
    str->content = calloc(str->length + 1, sizeof(char));
    assert(str->content != NULL);
    str->content = strncpy(str->content, word, str->length + 1u);
    
    assert(invrep(str));

    return (str);
}
 
unsigned int 
string_length(string str)
{   
    assert(invrep(str));

    return (str->length);
}

bool
string_less(const string str1, const string str2)
{   
    assert(invrep(str1) && invrep(str2));
    
    bool result;
	unsigned int len_s1 = str1->length;
	unsigned int len_s2 = str2->length;
	unsigned int min_length = len_s1 < len_s2 ? len_s1 : len_s2;
	unsigned int i = 0;
	while(i < min_length && str1->content[i] == str2->content[i])
	{
		i = i + 1;
	}
	result = i == min_length ? len_s1 <= len_s2 : str1->content[i] <= str2->content[i];

    return(result);
}   

bool 
string_eq(const string str1, const string str2)
{
    assert(invrep(str1) && invrep(str2));
    int cmp = strcmp(str1->content, str2->content);
   
    return (cmp == 0);
}

string 
string_clone(const string str)
{
    assert(invrep(str));
    return (string_create(str->content));
}

string 
string_destroy(string str)
{
    assert(invrep(str));
    free(str->content);
    free(str);
    str = NULL;
    return (str);
}

void
string_dump(string str, FILE *file)
{   
    assert(invrep(str));
    fprintf(file, "%s ", str->content);
}

const char 
*string_ref(string str)
{
    assert(invrep(str));
    return (str->content);
}
