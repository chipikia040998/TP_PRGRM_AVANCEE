#include <stdlib.h>
#include <stdio.h>

/**********************
      PARTIE I
  TA et déclarations
**********************/
/*				1
Déclaration de structure
*/



//structure definissant un segment


/*				2
Déclaration de fonction
*/



/**********************
      PARTIE III
  La fonction principale
**********************/
int main() {
  struct point2d P = newPoint2d();
  struct segment2d S = newSegment2d();
	
  viewPoint2d(P);
  viewSegment2d(S);
  return 0;
}

/*************************
        PARTIE IV
      Définitions des
  fonctions et procédures
**************************/

//Crée un nouveaux point P
struct point2d newPoint2d() 
{
  struct point2d P = {1.1 , 2.2};
  return P;
}

//crée un segment
struct segment2d newSegment2d() 
{
  struct segment2d S = { {2.2 , 3.3} , {3.3 , 2.2} };
  return S;
}

//affiche coordonnéesdu point P
void viewPoint2d(struct point2d P) 
{
  printf("Le point de coordonnées (%.1lf, %.1lf)\n", P.x, P.y);
}

//affiche le segment avec comme point d'origine et comme point d'extremité
void viewSegment2d(struct segment2d S) 
{
  printf("Le segment\n\td'origine : (%g, %g)", S.E.y, S.E.y);
	printf("Le segment d'extremité : (%g, %g)", S.O.x, S.O.y);
}
