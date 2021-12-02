#include "../include/insert.h"
#include "../include/lst.h"
#include "../include.lst_elm.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void insert_after(struct lst_t * L, const int value, struct lst_elm_t * place)
{
    assert(Li && place);

    if(place == NULL)
    {
        cons(Li, value);
    }
    else
    {
        struct lst_elm_t * NewLi = new_lst_elm(value);
        NewLi->suc = place->suc;
        place->suc = NewLi;
    }
}

/********************************************************************************/

void insert_ordered(struct lst_t * L, const int value)
{
    assert(L);

    if (empty_lst(L))
    {
        cons(L,value);
    }
    else if (L->head->x > value)
    {
        cons(L,value);
    }
    else if (L->tail->x >value)
    {
        insert_after(L,value,L->tail);
    }
    else
    {
        for (struct lst_elm_t * E = L->head; E->suc; E = E->suc)
        {
            if (E->suc->x >value)
            {
                insert_after(L,value,E);
                break; //afin de ne pas inserer plusieurs fois
            }
        }
    }
}