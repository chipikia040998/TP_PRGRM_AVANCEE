//incluson de fichier
#include "../include/lst.h"
#include "../include/lst_elm/h"

//inclusion des bibliothèque
#include <stdlib.h> //librairie standard
#include <stdio.h> //librairie des inpout/outpout
#include <stdbool.h> //librairie du type Booléen
#include <assert.h> //librairie d'assertion

/** fonction principale
	@note
			Compiler avec : gcc -Wall -std=c11 -o intlist intlist.c
	@brief
		Conception d'un type pour les listes d'entiers et des fonctions associées
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