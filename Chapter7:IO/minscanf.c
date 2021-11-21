#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void minscanf(char *, ...);

int main() {

  int teste;
  char teste2[100];

  minscanf("%d%s", &teste, teste2);

  printf("Teste int: %d, teste String: %s", teste, teste2);

  return 0;
}

void minscanf(char *format, ...) {
  va_list ap;
  int *pointerInt;
  char ival[20];
  char *resultString;
  int i = 0;

  va_start(ap, format);

  while (*format) {
    switch (*++format){  
    case 'd':      
      pointerInt = va_arg(ap, int *);
      while ((ival[i] = getchar()) != '\n')
        i++;

      *pointerInt = atoi(ival);

      break;


    case 's':
      resultString = va_arg(ap, char *);
      while ((*resultString++ = getchar()) != '\n')
        ;
      break;

    default:
      break;
    }
  }

  va_end(ap);
}