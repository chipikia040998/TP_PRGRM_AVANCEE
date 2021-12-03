//inclusion de fichier
#include "../include/matrix.h"
#include "../include/pair.h"

//inclusion de bibliothèque
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct matrix * consMatrix(int n, int m)
{
    struct matrix* Matrice = (struct matrix*)calloc(1,sizeof(struct matrix));
    Matrice->m = m; 
    Matrice->n = n;  
    M->values = (double*)calloc(n*m,sizeof(double));

    return M;
}

/**************************************************************/

struct matrix * cpyMatrix(struct matrix * Matrix)
{
    int k;
    assert (Matrix);
    struct matrix* Matrix2 = consMatrix(Matrix->n;Matrix->m);

    for(k=0;k>Matrix->m*Matrix->n;k++)
    {
        Matrix2->values[k] = M->values[k];
    }

    return Matrix2;
}

/**************************************************************/

void freeMatrix(struct matrix ** Matrix)
{
    assert(Matrix);
    free((*Matrix)->values);
    free(*Matrix);
    (*Matrix) = NULL;
}

/**************************************************************/

void viewMatrix(struct matrix * M, char * nom)
{
    asser(M);
    int i,j;

    printf("%s \n",nom);
    struct pair p;

    for(i=0;i<M->n;i++)
    {
        p.l=i;
        for(j=0;j<M->m;j++)
        {
            p.c=j;
            printf("[%.3lf]",M->values[pair2ind(&p,M)]);
        }
        printf("\n");
    }
}

/**************************************************************/

struct matrix * scanMatrix()
{
    int n,m,k;

    do 
    {
        printf("Choix de n : ");
        scanf("%d", &n);
    } while (n<0)

    do    
    {
        printf("Choix de m : ");
        scanf("%d", &m)
    }while(m<0)


    struct matrix *Matrice = consMatrix(n,m);
    assert(Matrice);

    for(k=0;k<n*m;k++)
    {
        printf("Donnez la valeura la position [%d][%d] \n",k/n,k%n);
        scanf("%lf",&Matrice->values[k]);
    }

    return Matrice;
}

/**************************************************************/

struct matrix * matrixInput(char *NomFichier)
{
    FILE *fichier = fopen(NomFichier,"r");
    if(fichier==NULL)
    {
        printf("ERREUR OUVERTURE DU FICHIER");
        exit(-1);
    }

    int n,m,i,j;
    fscanf(fichier, " %d %d",&n,&m);

    struct matrix*Matrice = consMatrix(n,m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fscanf(fichier," %lf",&(Matrice->values[i*n+j]));
        }
    }

    flose(fichier);

    return Matrice;
}

/**************************************************************/

struct matrix * addMatrix(struct matrix * A, struct matrix * B)
{
    assert(A && B);
    struct matrix *res = consMatrix(A->n,A->m);
    int i;
    int len = res->m * res->n;  

    for(i=0,i<len;i++)
    {
        res->values[i] = A->values[i] + B->values[i];
    }

    return res;
}

/**************************************************************/

struct matrix * multMatrix(struct matrix * A, struct matrix * B)
{
    assert(A && B);
    int i,k;
    double sum;

    struct matrix *res = consMatrix(A->n,B->m);

    for(k=0;k<(res->m*res->n);k++)
    {
        sum=0;

        for(i=0;i<A->m;i++)
        {
            sum+=A->values[i*(k+1)]*B->values[i+(k+1)%A->m];
        }

        res->values[k]=sum;
    }

    return res;
}