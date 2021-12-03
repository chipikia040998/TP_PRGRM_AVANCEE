//inclusion de fichier
#include "../include/matrix.h"
#include "../include/pair.h"

//inclusion de bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct pair * consPair(int l, int c)
{
    struct pair *Pair=(struct pair*)calloc(1,sizeof(struct pair));
    Pair->l=l ;
    Pair->c=c;

    return Pair;
}

/**************************************************************/

struct pair * copyPair(struct pair * Pair)
{
    assert(Pair);
    return consPair(Pair->l,Pair->c);
}

/**************************************************************/

void freePair(struct pair ** Pair)
{
    free(*Pair);
    (*Pair)=NULL;
}

/**************************************************************/

int pair2ind(struct pair * Pair, struct matrix * Matrice)
{
    return (Pair->l * Matrice->n + Pair->c);
}

/**************************************************************/

struct pair * ind2pair(int k, struct matrix * MAtrice)
{
    return consPair(k/MAtrice->n,k%MAtrice->n);
}