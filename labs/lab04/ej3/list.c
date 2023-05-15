#include "list.h"

struct e_node_ {
	list_elem value;
	struct e_node_ *next;
};

list
empty_list(void)
{
	list l = NULL;	
	return(l);
}

list 
addl_list(list l, list_elem e)
{
	list p = malloc(sizeof(struct e_node_));
	p->value = e;
	p->next = l;
	l = p;
	return(l);
}

list 
destroy_list(list l)
{	
	list p;
	while(l != NULL)
	{
		p = l;
		l = l->next;
		free(p);
	}
	return(l);	
}

bool
is_empty_list(list l)
{
	bool b = (l == NULL);
	return(b);
}

list_elem
head(list l)
{
	return(l->value);
}

list 
tail(list l)
{
	assert(!is_empty_list(l));
	list p = l;
	l = l->next;
	free(p);
	return(l);
}

list
addr_list(list l, list_elem e)
{
	list p = malloc(sizeof(struct e_node_));
	p->value = e;
	p->next = NULL;
	if(!is_empty_list(l))
	{	
		list q = l;
		while(q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
	else
	{
		l = p;
	}
	return(l);
}

unsigned int
length_list(list l)
{
	unsigned int length = 0;
	list p = l;
	while(p != NULL)
	{
		p = p->next;
		length = length + 1;
	}
	return(length);
}

list 
concat_list(list l, list lx)
{		
	if(!is_empty_list(l))
	{		
		list p = l;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = lx;
	}
	else
	{
		l = lx;
	}
	return(l);
}

list_elem 
index_list(list l, unsigned int n)
{
	assert(n < length_list(l));
	list p = l;
	unsigned int k = 0;
	while(k < n)
	{
		p = p->next;
		k = k + 1;
	}
	return(p->value);
}

list 
take_list(list l, unsigned int n)
{	
	list p = l;
	if(n < length_list(l))
	{  
		unsigned int k = 1;
		while(k < n)
		{
			p = p->next;
			k = k + 1;
		}
		list q = p->next;	
		p->next = NULL;
		destroy_list(q);
	} 
	p = l;
	return(p);
}

list
drop_list(list l, unsigned int n)
{
	list p = l;
	if(n < length_list(l))
	{
		list q = p->next;
		while(n != 0)
		{
			free(p);
			p = q;
			q = q->next;
			n = n - 1;
		}
	}
	else
	{
		p = NULL;
		destroy_list(l);
	}
	return(p);
}

list 
copy_list(list l)
{
	list lx = empty_list();
	list p = l;
	while(p != NULL)
	{
		lx = addr_list(lx, p->value);
		p = p->next;
	}
	return(lx);
}
