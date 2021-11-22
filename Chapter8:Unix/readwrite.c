#include "syscall.h"

#define BUFFSIZE 1

int main() {
  char buf[BUFFSIZE];
  int n;

  while ((n = read(0, buf, BUFFSIZE)) > 0)
    write(1, buf, BUFFSIZE);
  
  return 0;
}