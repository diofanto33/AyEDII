#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};

pair_t
pair_new(int x, int y)
{
	pair_t p = malloc(sizeof(pair_t));
	p->fst = x;
	p->snd = y;
	return p;
}

int
pair_first(pair_t p)
{
	return p->fst;
}

int
pair_second(pair_t p)
{
	return p->snd;
}

pair_t
pair_swapped(pair_t p)
{
	pair_t q = malloc(sizeof(pair_t));
	q->fst = p->snd;
	q->snd = p->fst;

	return q;
}

pair_t 
pair_destroy(pair_t p)
{
	free(p);
	p = NULL;
	return p;
}
