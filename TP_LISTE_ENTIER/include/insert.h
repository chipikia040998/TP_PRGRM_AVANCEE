#pragma once

#include "../include/lst.h"
#include "../lst_elm.h"

#include <stdbool.h>

void insert_after(struct lst_t * L, const int value, struct lst_elm_t * place);

/******************************************************************************/

void insert_ordered(struct lst_t * L, const int value);