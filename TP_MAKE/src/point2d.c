#include "../include/point2d.h"
#include <stdio.h>

//Crée un nouveaux point P
struct point2d newPoint2d() 
{
  struct point2d P = {1.1 , 2.2};
  return P;
}

/**************************************************************/

//affiche coordonnées du point P
void viewPoint2d(struct point2d P) 
{
  printf("Le point de coordonnées (%.1lf, %.1lf)\n", P.x, P.y);
}