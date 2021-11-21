#if !defined(OLAMUNDO)
#define OLAMUNDO 2
#endif

#ifndef STDIO
#include <stdio.h>
#endif

int i;

#define swap(t, x, y) {t tmp = x; x = y; y = tmp;}

static int z = 5;

int main() {

  void local();

  local();

  register int registerVar = 0;

  int x, y;

  x = 5;
  y = 4;

  swap(int, x, y)

  printf("X:%d\n Y:%d", x, y);

  printf("\n\n %d \n\n", OLAMUNDO);

  printf("\n\n External: %d \n Register variable: %d \n\n", i, registerVar);

  return 0;
}
  
void local() {
  static int l;

  printf("\n\n\n Static Local fund: %d", l);
  printf("\n\n Z static: %d", z);
}