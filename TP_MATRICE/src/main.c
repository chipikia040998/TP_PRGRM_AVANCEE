//inclusion de fichier
#include "../include/matrix.h"
#include "../include/pair.h"

//inclusion de bibliothèque
#include <stdio.h>

//fonction principale
int main()
{
    struct matrix *Matrice = matrixInput("file.txt");
    viewMatrix(Matrice, "recupération de fichier");
    freeMatrix(&M);
    
    return 0;
}