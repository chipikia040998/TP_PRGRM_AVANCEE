/**
	@note
			Compiler avec : gcc -Wall -std=c11 -o intlist intlist.c
	@brief
		Conception d'un type pour les listes d'entiers et des fonctions associées
	@TODO
		Ajoutez les fonctions de consultation des éléments de liste :
		+ new_lst_elm
		+ del_lst_elm
		+ getX
		+ getSuc
		+ setX
		+ setSuc
		Puis, séparez les éléments afin qu'apparaissent :
		+ Un fichier d'entêtes (.h) de la bibliothèque élément de liste d'entiers,
		+ Un fichier d'entêtes (.h) de la bibliothèque liste d'entiers,
		+ Les fichiers de définitions (.c) correspondant aux déclarations du fichier d'entête
		+ Un fichier main.c ne contenant que la fonction principale.
		Enfin, construisez le Makefile
*/
#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions


/**
	* LES TYPES ABSTRAITS
**/

/** @brief Le type abstrait d'un _élément_ de liste:
* @param x  un entier,
* @param suc un pointeur sur son successeur (ou NULL s'il n'y en a pas)
*/
struct lst_elm_t 
{
	int x;
	struct lst_elm_t * suc;
};

/*
	* DÉCLARATION DES FONCTIONS ASSOCIÉES
**/

/** @brief Créer un élément de liste et y ranger la valeur entière value 
* @param value valeur a ranger dans le nouvel élément de liste
*/
struct lst_elm_t * new_lst_elm(int value);

/**************************************************************/

/** @brief Supprimer un élément de liste et mettre son pointeur à NULL
* @param ptrE élément a supprimer et poiteur a NULL
*/
void del_lst_elm(struct lst_elm_t ** ptrE);

/**************************************************************/

/** @brief Renvoyer la valeur entière de l'élément 
* @param E Element dont on veux la valeur
*/
int getX ( struct lst_elm_t * E );

/**************************************************************/

/** @brief Renvoyer le pointeur sur le successeur de l'élément 
* @param E Element dont on veux le successeur
*/
struct lst_elm_t * getSuc ( struct lst_elm_t * E );

/**************************************************************/

/** @brief Modifier la valeur entière de l'élément 
* @param E élément a modifier
* @param v nouvelle valeur
*/
void setX (struct lst_elm_t * E, int v );

/**************************************************************/

/** @brief Modifier le pointeur sur le successeur de l'élément 
* @param E élément de départ 
* @param S successeur dont on change le pointeur
*/
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );

/**************************************************************/

/** @brief Le type abstrait d'une _liste_:
* @param head le premier élément de la liste
* @param tail le dernier élément de la liste
* @param numelm le nombre d'élément dans la liste
*/
struct lst_t {
	struct lst_elm_t * head;
	struct lst_elm_t * tail;
	int numelm;
};


/**
	* DÉCLARATION DES FONCTIONS ASSOCIÉES
**/

/** @brief Vérifier si la liste L est vide ou pas 
* @param L liste dont on veux savoir si vide ou non
*/
bool empty_lst(const struct lst_t * L);

/**************************************************************/

/** @brief Construire une liste vide
*/
struct lst_t * new_lst();

/**************************************************************/

/** @brief Ajouter en tête de la liste L la valeur v
* @param L liste a modifier
* @param v valeur a ajouter en tête
*/
void cons(struct lst_t * L, int v);

/**************************************************************/

/** @brief Visualiser les éléments de la liste L 
* @param L liste dont on veux afficher les élément
*/
void print_lst(struct lst_t * L );

/**************************************************************/

/** @brief Libèrer la mémoire occupée par la liste
* @param ptrL liste dont on veux libérer la mémoire 
*/
void del_lst(struct lst_t ** ptrL );


/**
	* ALGORITHME (FONCTION PRINCIPALE)
**/



/**
	* DÉFINITIONS DES FONCTIONS
	**/
/* @ToDo Créez les fonctions:
 * new_lst_elm, del_lst_elm, getX, getSuc, setX, setSuc
*/

struct lst_t * new_lst() {
	/* @note : calloc fonctionne de manière identique à malloc
		et de surcroît met à NULL(0) tous les octets alloués */
	struct lst_t * L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}

/**************************************************************/

void del_lst(struct lst_t ** ptrL ) {
	assert(ptrL && *ptrL) ;
	for( struct lst_elm_t * E = (*ptrL)->head ; E!=NULL ; )
	{
		struct lst_elm_t * T = E ;
		E = E->suc ;
		del_lst_elm_t(&T) ;
	}

	free(*ptrL) ;
	(*ptrL) = NULL ;
}

/**************************************************************/

bool empty_lst(const struct lst_t * L ) {
	assert(L);
	return L->numelm == 0;
}

/**************************************************************/

void cons(struct lst_t * L, int v) 
{
	assert(L) ;
	struct lst_elm_t *E = new_lst_elm(v) ;
	assert(E) ;
	E->suc = L->head ;
	L->head = E ;
	if ( L->numelm == 0 )
	{
		L->tail = E ;
	}
	L->numelm += 1 ;
}

/**************************************************************/

void print_lst(struct lst_t * L ) {
	printf( "[ " );
	for(struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}

/**************************************************************/

struct lst_elm_t * new_lst_elm(int value);
{
	struct lst_elm_t * Li = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
	Li->x = value;
	Li->suc = NULL;
	return Li;
}

/**************************************************************/

void del_lst_elm(struct lst_elm_t ** ptrE);
{
	assert(ptrE && *ptrE);
	free(*ptrE);
	(*ptrE) = NULL;
}

/**************************************************************/

int getX ( struct lst_elm_t * E );
{
	assert(E);
	return E->x;
}

/**************************************************************/

struct lst_elm_t * getSuc ( struct lst_elm_t * E );
{
	assert(E);
	return E->suc;
}

/**************************************************************/

void setX (struct lst_elm_t * E, int v );
{
	assert(E);
	E->x = v;
}

/**************************************************************/

void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );
{
	assert(E);
	assert(S);
	E->suc = S;
}