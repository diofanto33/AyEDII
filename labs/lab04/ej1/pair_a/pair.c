#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

pair_t
pair_new(int x, int y)
{
	pair_t res;
	
	res.fst = x;
	res.snd = y;

	return res;
}

int
pair_fist(pair_t p)
{
	return p.fst;
}

int
pair_second(pair_t p)
{
	return p.snd;
}

pair_t
pair_swapped(pair_t p)
{
	pair_t q;
	q.fst = p.snd;
	q.snd = p.fst;
	
	return q;
}

pair_t
pair_destroy(pair_t p)
{
	return p;
}
