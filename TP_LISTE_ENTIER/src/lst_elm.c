#include "../include/lst_elm.h"
#include "../include/lst.h"

#include <stdlib.h> //librairie standard
#include <stdio.h> //librairie des inpout/outpout
#include <stdbool.h> //librairie du type Booléen
#include <assert.h> //librairie d'assertio

struct lst_elm_t * new_lst_elm(int value)
{
	struct lst_elm_t * Li = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
	Li->x = value;
	Li->suc = NULL;
	return Li;
}

/**************************************************************/

void del_lst_elm(struct lst_elm_t ** ptrE)
{
	assert(ptrE && *ptrE);
	free(*ptrE);
	(*ptrE) = NULL;
}

/**************************************************************/

int getX ( struct lst_elm_t * E )
{
	assert(E);
	return E->x;
}

/**************************************************************/

struct lst_elm_t * getSuc ( struct lst_elm_t * E )
{
	assert(E);
	return E->suc;
}

/**************************************************************/

void setX (struct lst_elm_t * E, int v )
{
	assert(E);
	E->x = v;
}

/**************************************************************/

void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S )
{
	assert(E);
	assert(S);
	E->suc = S;
}