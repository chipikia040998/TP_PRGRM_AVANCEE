#include "point2d.h"
#include "segment2d.h"

int main() {
  struct point2d P = newPoint2d();
  struct segment2d S = newSegment2d();
	
  viewPoint2d(P);
  viewSegment2d(S);
  return 0;
}