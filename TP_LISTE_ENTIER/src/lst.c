#include "../include/lst.h"
#include "../include/lst_elm.h"

struct lst_t * new_lst() 
{
	/* @note : calloc fonctionne de manière identique à malloc
		et de surcroît met à NULL(0) tous les octets alloués */
	struct lst_t * L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}

/**************************************************************/

void del_lst(struct lst_t ** ptrL ) 
{
	assert(ptrL && *ptrL) ;
	for( struct lst_elm_t * E = (*ptrL)->head ; E!=NULL ; )
	{
		struct lst_elm_t * T = E ;
		E = E->suc ;
		del_lst_elm_t(&T) ;
	}

	free(*ptrL) ;
	(*ptrL) = NULL ;
}

/**************************************************************/

bool empty_lst(const struct lst_t * L ) 
{
	assert(L);
	return L->numelm == 0;
}

/**************************************************************/

void cons(struct lst_t * L, int v) 
{
	assert(L) ;
	struct lst_elm_t *E = new_lst_elm(v) ;
	assert(E) ;
	E->suc = L->head ;
	L->head = E ;
	if ( L->numelm == 0 )
	{
		L->tail = E ;
	}
	L->numelm += 1 ;
}

/**************************************************************/

void print_lst(struct lst_t * L ) 
{
	printf( "[ " );
	for(struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}
