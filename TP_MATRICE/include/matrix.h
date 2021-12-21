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

/** @brief 
* @param n 
* @param m 
*/
struct matrix * consMatrix(int n, int m);

/**************************************************************/

/** @brief 
* @param Matrix 
*/
struct matrix * cpyMatrix(struct matrix * Matrix);

/**************************************************************/

/** @brief 
* @param Matrix 
*/
void freeMatrix(struct matrix ** Matrix);

/**************************************************************/

/** @brief 
* @param M
* @param nom 
*/
void viewMatrix(struct matrix * M, char * nom);

/**************************************************************/

/** @brief
*/
struct matrix * scanMatrix();

/**************************************************************/

/** @brief
* @param NomFichier
*/
struct matrix * matrixInput(char *NomFichier);

/**************************************************************/

/** @brief
* @param A
* @param B
*/
struct matrix * addMatrix(struct matrix * A, struct matrix * B);

/**************************************************************/

/** @brief
* @param A
* @param B
*/
struct matrix * multMatrix(struct matrix * A, struct matrix * B);
