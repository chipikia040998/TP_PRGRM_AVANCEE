#ifndef _OUTILS_
#define _OUTILS_

#include <stdbool.h>

/** @brief affiche une valeur entière
* @param i entier a afficher
*/
void printInteger(int * i);

/******************************************************************************/

/** @brief suppression d'une mémoire de type entier
* @param i entier dont on souhaite liberer la mémoire
*/
void rmInteger (int * i);

/******************************************************************************/

/** @brief Comparaison de 2 entier
* @param i entier 1
* @param j entier 2
*/
void intcmp(int * i, int * j);

/******************************************************************************/

/** @brief affiche une valeur réelle
* @param d reel a afficher
*/
void printDouble(double * d);

/******************************************************************************/

/** @brief supprime la mémoire de type réelle
* @param d reelle dont on souhaite supprimer la mémoire
*/
void rmDouble(double * d);

/******************************************************************************/

/** @brief comparaison de deux reel
* @param u reel 1
* @param v reel 2
*/
void reelcmp(double * u, double * v);

#endif // _OUTILS_