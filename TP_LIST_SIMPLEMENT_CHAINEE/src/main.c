#include "../include/lst/h"
#include "../include/outils.h"
#include "../include/lst_elm.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main()
{
    struct lst_t *L new_lst();

    if (empty_lst(L))
    {
        printf("La liste est vide \n");
    }

    int *a = (int*)calloc(1,sizeof(int));
    int *b = (int*)calloc(1,sizeof(int));
    int *c = (int*)calloc(1,sizeof(int));
    int *d = (int*)calloc(1,sizeof(int));

    (*a)=4;
    (*b)=1;
    (*c)=8;
    (*d)=3;

    cons (L,a);
    cons (L,b);
    queue(L,c);

    insert_ordered(L,d,&intcmp);

    if(!empty_lst(L))
    {
        printf ("La liste n'est plus vide");
    }
    else
    {
        printf("Liste toujours vide");
    }

    view_lst(L,&printInteger);

    del_lst(&L,&rmInteger);
    
    return 0;
}