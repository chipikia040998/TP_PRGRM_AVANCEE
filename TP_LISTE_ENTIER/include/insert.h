#pragma once

#include "../include/lst.h"
#include "../lst_elm.h"

#include <stdbool.h>

/** @brief fonction qui insère après une position une valeur dans une liste
 * @param L list qui va être modifier
 * @param value insertion de la valeur
 * @param place emplacement après lequel on met la valeur
 */
void insert_after(struct lst_t * L, const int value, struct lst_elm_t * place);

/******************************************************************************/

/** @brief insère dans l'ordre croissant uen valeur
 * 
 * @param L Liste ou on opère les modification
 * @param value valeur a insérer
 */
void insert_ordered(struct lst_t * L, const int value);