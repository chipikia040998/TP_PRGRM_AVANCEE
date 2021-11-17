#ifndef _POINT2D_
#define _POINT2D_

//structure definissant un point
struct point2d 
{
  double x, y;
};

//crée un nouvea point
struct point2d newPoint2d();

//affiche le point
void viewPoint2d(struct point2d P);

#endif //_POINT2D_