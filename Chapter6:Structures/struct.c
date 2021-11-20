#include <stdio.h>

struct point makepoint(int, int);
struct point addpoints(struct point p1, struct point p2);

 struct point {
    int x;
    int y;
  } pt ={ 1, 2 };

int main(){

  struct point pt1;
  struct point pt2;
  struct point result;
  struct point *pointer;

  pointer = &result;

  pt1 = makepoint(10, 8);
  pt2 = makepoint(4, 2);

  result = addpoints(pt1, pt2);

  printf("\nX: %d y: %d\n\n", pointer -> x, pointer -> y);
  printf("\nX: %d y: %d\n\n", pt.x, pt.y);
  
  return 0;
}

struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;

  return temp;
}

struct point addpoints(struct point pt1, struct point pt2) {

  pt1.x+= pt2.x;
  pt1.y+= pt2.y;

  return pt1;
}