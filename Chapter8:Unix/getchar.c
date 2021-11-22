#include "syscall.h"
#include <stdio.h>

#define BUFFSIZE 1

int getcharM(void);

int main() {

  char charTeste;

  charTeste = getchar();

  printf("\nTeste: %c\n", charTeste);

  return 0;
}

int getcharM(void) {
  static char buf[BUFFSIZE];
  static char *bufp = buf;
  static int n;

  if (n == 0) {
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }

  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}