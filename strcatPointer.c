#include <stdio.h>

void strcatP(char *, char *);

int main() {

  char s[15] = "sim";
  char j[5] = "end";

  printf("\n\n O valor de S: é %s \n De J é: %s \n\n", s, j);

  strcatP(s, j);

  printf("O novo valor de S é: %s\n\n", s);

  return 0;
}

void strcatP(char *s, char *t) {
  while (*s++ != '\0')
    ;

  while ( *(s++ - 1) = *t++ )
    ;
}