#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printInteger(int * i)
{
    printf("La valeur entiere vaut : %d \n", (*i));
}

/**************************************************************/

void rmInteger (int * i)
{
    free(i);
}

/**************************************************************/

void intcmp(int * i, int * j)
{
    return ( (*i) < (*j) );
}

/**************************************************************/

void printDouble(double * d);
{
    printf("La valeur relle vaut : %lf \n", (*d));
}

/**************************************************************/

void rmDouble(double * d)
{
    free (d);
}

/**************************************************************/

void reelcmp(double * u, double * v)
{
    return ( (*u) < (*v) );
}
