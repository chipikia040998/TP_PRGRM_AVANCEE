#include "../include/lst_elm.h"
#include "../include/lst.h"
#include "../include/outils.h"

#include <stio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct lst_elm_t * new_lst_elm ( void * datum)
{
    struct lst_elm_t * E = (struct lst_elm_t *)calloc(1,sizeof(struct lst_elm_t));
    assert(E);
    E->datum = datum;
    return E;
}

/**************************************************************/

void del_lst_elm (struct lst_elm_t ** ptrE)
{
    assert(ptrE && * ptrE);
    free(*ptrE);
    (*ptrE) = NULL;
}

/**************************************************************/

void * getDatum ( struct lst_elm_t * E)
{
    assert(E);
    return E->datum;
}

/**************************************************************/

struct lst_elm_t * getSuc ( struct lst_elm_t * E )
{
    assert(E);
    return E->suc;  
}

/**************************************************************/

void setDatum ( struct lst_elm_t * E , void * datum )
{
    assert(E);
    E->datum = datum;
}

/**************************************************************/

void setSuc ( struct lst_elm_t * E , struct lst_elm_t * S )
{
    assert(E);
    E->suc = S;
}
