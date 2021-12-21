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

/** @brief
* @param l
* @param c
*/
struct pair * consPair(int l, int c);

/**************************************************************/

/** @brief 
* @param Pair
*/
struct pair * copyPair(struct pair * Pair);

/**************************************************************/

/** @brief
* @param Pair
*/
void freePair(struct pair ** Pair);

/**************************************************************/

/** @brief
* @param Pair
* @param Matrice
int pair2ind(struct pair * Pair, struct matrix * Matrice);

/**************************************************************/

/** @brief
* @param k
* @param MAtrice
*/
struct pair * ind2pair(int k, struct matrix * MAtrice);