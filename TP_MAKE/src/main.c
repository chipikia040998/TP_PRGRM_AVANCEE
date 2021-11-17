#include "../include/point2d.h"
#include "../include/segment2d.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct point2d P = newPoint2d();
  struct segment2d S = newSegment2d();
	
  viewPoint2d(P);
  viewSegment2d(S);
  return 0;
}