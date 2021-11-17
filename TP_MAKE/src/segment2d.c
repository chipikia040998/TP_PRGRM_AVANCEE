#include "segment2d.h"
#include <stdio.h>

//crée un segment
struct segment2d newSegment2d() 
{
  struct segment2d S = { {2.2 , 3.3} , {3.3 , 2.2} };
  return S;
}

//affiche le segment avec comme point d'origine et comme point d'extremité
void viewSegment2d(struct segment2d S) 
{
  printf("Le segment\n\td'origine : (%g, %g)", S.E.y, S.E.y);
	printf("Le segment d'extremité : (%g, %g)", S.O.x, S.O.y);
}