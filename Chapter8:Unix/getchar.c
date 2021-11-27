#include "syscall.h"
#include <stdio.h>
#include <fcntl.h>

int getcharM(void);

int main() {

  char charTeste;

  charTeste = getchar();

  printf("\nTeste: %c\n", charTeste);

  return 0;
}

int getcharM(void) {
  static char buf[BUFSIZ];
  static char *bufp = buf;
  static int n;

  if (n == 0) {
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }

  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}