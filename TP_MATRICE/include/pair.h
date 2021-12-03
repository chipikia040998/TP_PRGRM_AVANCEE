#pragma once
#include "matrix.h"

struct pair
{
    int l;
    int c;
};
/**************************************/
/* DÉCLARATION DES FONCTIONS ASSOCIÉES*/
/**************************************/

struct pair * consPair(int l, int c);

/**************************************************************/

struct pair * copyPair(struct pair * Pair);

/**************************************************************/

void freePair(struct pair ** Pair);

/**************************************************************/

int pair2ind(struct pair * Pair, struct matrix * Matrice);

/**************************************************************/

struct pair * ind2pair(int k, struct matrix * MAtrice);