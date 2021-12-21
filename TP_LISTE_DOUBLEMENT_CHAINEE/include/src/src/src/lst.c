#include "../include/lst.h"
#include "../include/outils.h"
#include "../include/lst_elm.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include<assert.h>

struct lst_t * new_lst ()
{
    struct lst_t * L =(struct lst_t *)calloc(1,sizeof(struct  lst_t));
    assert(L);
    return L;
}

/**************************************************************/

void del_lst ( struct lst_t ** ptrL , void (* ptrFct ) () )
{
    assert(ptrL && *ptrL);

    if ( (*ptrFct) != NULL )
    {
        for (struct lst_elm_t * E = (*ptrL)->head;E;)
        {
            struc lst_elm_t * T = E ;
            E = E->suc; 
            (*ptrFct)=(T->datum);
            free(T);
        }
    }
    else
    {
        for (struct lst_elm_t *E = (*ptrL)->head;E;)
        {
            struct lst_elm_t *T = E;
            E = E->suc;   
            free(T);
        }
    }

    free(*ptrL);
    (*ptrL) = NULL;
}

/**************************************************************/

bool empty_lst ( const struct lst_t * L)
{
    return (L->numelm == 0);
}

/**************************************************************/

void cons ( struct lst_t * L , void * datum )
{
    assert(L);
    struct lst_elm_t *E = new_lst_elm(datum);
    assert(E);

    E->succ = L->head;
    L->head = E;
    if ( L->numelm == 0)
    {
        L->tail=E;
    }
    L->numelm +=1;
}

/**************************************************************/

void queue ( struct lst_t * L , void * datum )
{
    assert(L);
    struct lst_elm_t *newtail=new_lst_elm(datum);
    L->tail->suc = newtail;
}

/**************************************************************/

void insert_ordered ( struct lst_t * L , void * datum , bool (* ptrFct ) () )
{
    assert(L);

    if(empty_lst(L))
    {
        cons(L,datum);
    }
    else if ( (*ptrFct)(datum,L->head->datum))
    {
        cons(L,datum);
    }
    else if ( (*ptrFct)(L->tail->datum,datum))
    {
        queue(L,datum);
    }
    else
    {
        for (struct lst_elm_t *E=L->head;E->suc;E=E->suc)
        {
            if((*ptrFct)(datum,E->suc->datum))
            {
                insert_after(L,datum,E);
                break;
            }
        }
    }
}

/**************************************************************/

struct lst_elm_t * getHead ( struct list * L)
{
    return L->head;
}

/**************************************************************/

struct lst_elm_t * getTail ( struct list * L)
{
    return L->tail;
}

/**************************************************************/

int getNumelm ( struct list * L)
{
    return L->numelm;
}

/**************************************************************/

int setNumelm ( struct list * L , int numElm )
{
    L->numelm =numElm;
    return numElm;
}

/**************************************************************/

void view_lst ( struct lst_t * L , void (* ptrFct ) () )
{
    printf("[ ");
    for (struct lst_elm_t *E,=L->head;E;E=E->suc)
    {
        (*ptrFct)(E->datum);
    }
    print("]\n\n()");
}