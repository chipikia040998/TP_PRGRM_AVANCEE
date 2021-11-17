#ifndef _SEGMENT2D_
#define _SEGMENT2D_

#include "point2d.h"

//structure d'un segment
struct segment2d {
  struct point2d O, E;
};

//création d'un nouveau segment
struct segment2d newSegment2d();

//affiche un segment
void viewSegment2d(struct segment2d S);

#endif // _SEGMENT2D_