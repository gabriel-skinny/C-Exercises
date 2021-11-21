#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]){
  static int i, c;

  while((s[0] = c = getchar()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c !='.' && c != '-')
    return c;

  i = 0;

  if (isdigit(c))
    while(isdigit(s[++i] = c = getchar()))
      ;

  if (c == '.')
    while(isdigit(s[++i] = c = getchar()))
      ;

  s[i] = '\0';

  return NUMBER; 
}