#include <stdio.h>
#include <stdarg.h>

void minprintf(char *, ...);

int main() {

  int teste = 9;
  char teste2[10] = "alo galera";

  minprintf("\nVoce é bossal namoral %o e string %p\n", teste, teste2);

  return 0;
}

void minprintf(char *fmt, ...) {
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;
  unsigned oval;
  char *pval;

  va_start(ap, fmt);

  for (p = fmt; *p; p++) {
    if (*p != '%'){
      putchar(*p);
      continue;
    }

    switch(*++p) {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++)
          putchar(*sval);
        break;
      
      case 'o':
        oval = va_arg(ap, int);
        printf("%o", oval);
        break;

      case 'p':
        pval = va_arg(ap, char*);
        printf("%p", pval);
        break;

      default:
        putchar(*p);
        break;
    }
  }

  va_end(ap);

}