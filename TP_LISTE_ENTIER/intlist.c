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

/* @brief Le type abstrait d'un _élément_ de liste:
 * + x - un entier,
 * + suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */
struct lst_elm_t 
{
	int x;
	struct lst_elm_t * suc;
};
/**
	* DÉCLARATION DES FONCTIONS ASSOCIÉES
	**/
/* @brief Créer un élément de liste et y ranger la valeur entière value */
struct lst_elm_t * new_lst_elm(int value);
/* @brief Supprimer un élément de liste et mettre son pointeur à NULL */
void del_lst_elm(struct lst_elm_t ** ptrE);
/* @brief Renvoyer la valeur entière de l'élément */
int getX ( struct lst_elm_t * E );
/* @brief Renvoyer le pointeur sur le successeur de l'élément */
struct lst_elm_t * getSuc ( struct lst_elm_t * E );
/* @brief Modifier la valeur entière de l'élément */
void setX (struct lst_elm_t * E, int v );
/* @brief Modifier le pointeur sur le successeur de l'élément */
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );


/* @brief Le type abstrait d'une _liste_:
 * + head - le premier élément de la liste
 * + tail - le dernier élément de la liste
 * + numelm - le nombre d'élément dans la liste
 */
struct lst_t {
	struct lst_elm_t * head;
	struct lst_elm_t * tail;
	int numelm;
};
/**
	* DÉCLARATION DES FONCTIONS ASSOCIÉES
	**/
/* @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t * L);
/* @brief Construire une liste vide */
struct lst_t * new_lst();
/* @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t * L, int v);
/* @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t * L );
/* @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t ** ptrL );


/**
	* ALGORITHME (FONCTION PRINCIPALE)
	**/
int main() {
	int v;
	struct lst_t * L = new_lst();
	scanf("%d",&v);
	while( v > 0 ) {
		cons(L,v);
		scanf("%d",&v);
	}
	print_lst(L);
	del_lst(&L);
	return EXIT_SUCCESS;
}

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

//libère mémoire de la liste
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

//regarde si liste vide
bool empty_lst(const struct lst_t * L ) {
	assert(L);
	return L->numelm == 0;
}

/** Ajoute en tête d eliste la valeur
* @param lst_t liste a modifier
* @param v valeur a mettre en tête de liste
* */
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

//affiche les élément de la liste
void print_lst(struct lst_t * L ) {
	printf( "[ " );
	for(struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}