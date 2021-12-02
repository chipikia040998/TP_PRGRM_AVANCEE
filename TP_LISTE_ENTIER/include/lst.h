#pragma once
#include <stdbool.h>
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

/**************************************************************/

/*************************************/
/*DÉCLARATION DES FONCTIONS ASSOCIÉES*/
/*************************************/

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