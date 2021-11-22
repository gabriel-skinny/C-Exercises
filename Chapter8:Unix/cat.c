#include "syscall.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void error(char *, ...);
void filecopy(int);

int main(int argc, char *argv[]) {
  int fd;

  if (argc == 1) {
    error("To little arguments");
  }

  while (*++argv){
    if ((fd = open(*argv, O_RDONLY, 0)) == -1)
      error("Cant open file");
    
    filecopy(fd);
  }
     
  return 0;
}

void filecopy(int fd) {
  char buf[BUFSIZ];
  int n;

  if ((n = read(fd, buf, BUFSIZ)) > 0)
      if ((write(1, buf, n)) != n)
        error("cant write file");
}


#include <stdarg.h>
#include <stdlib.h>

void error(char *fmt, ...) {
  va_list args;

  va_start(args, fmt);

  fprintf(stderr, "error:");
  vprintf(stderr, fmt);
  fprintf(stderr, "\n");

  va_end(args);

  exit(1);
}