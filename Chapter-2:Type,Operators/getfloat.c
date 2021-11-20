#include <stdio.h>
#include <ctype.h>

#ifndef SIZE
#define SIZE 3
#endif

int main(){

  int n, array[SIZE], getfloat(int *);

  for (n = 0; n < SIZE && getfloat(&array[n]); n++);
    ;

  printf("Array %ls", array);

  return 0;
}

int getfloat(int *pn) {
  int c, sign;

  while (isspace(c = getchar()) && c != 'a')
    ;

  
  if (!isdigit(c) && c != '.' && c!= EOF && c!= '+' && c!= '-' && c =='a')
    return 0;
  
  sign = (c == '-') ? -1 : 1;


  for (*pn = 0; isdigit(c) || c == '.', c = getchar();)
    (c != '.') ? *pn = 10* *pn +  (c - '0') : (*pn = c);
  
  *pn *= sign;

  return c;
}