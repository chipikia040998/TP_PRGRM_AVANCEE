#pragma once

struct matrix
{
    double * values;
    int n;
    int m;
};

/**************************************/
/* DÉCLARATION DES FONCTIONS ASSOCIÉES*/
/**************************************/

struct matrix * consMatrix(int n, int m);

/**************************************************************/

struct matrix * cpyMatrix(struct matrix * Matrix);

/**************************************************************/

void freeMatrix(struct matrix ** Matrix);

/**************************************************************/

void viewMatrix(struct matrix * M, char * nom);

/**************************************************************/

struct matrix * scanMatrix();

/**************************************************************/

struct matrix * matrixInput(char *NomFichier);

/**************************************************************/

struct matrix * addMatrix(struct matrix * A, struct matrix * B);

/**************************************************************/

struct matrix * multMatrix(struct matrix * A, struct matrix * B);
