#include <stdio.h>  

char printd(int);

int main() {

  int n = 55;

  printf("The %d is equal to the characther %c", n, printd(n));

  return 0;
}

char printd(int n) {

  if (n < 0) {
    n = -n;
  }

  
  return (char)(n + '0');
}