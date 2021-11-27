#include "syscall.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int toLower(int fd1, int fd2);

int main(int argc, char *argv[]) {
  int fd1, fd2;


  if (argc <= 2) {
    fprintf(stderr, "At leats 2 arguments");
    return -1;
  }

  if ((fd1 = open(argv[1], O_RDONLY, 0)) < 0){
    fprintf(stderr, "Cannot open the input file\n");
    return -1;
  }
  
  if ((fd2 = open(argv[2], O_WRONLY, 0)) < 0){
    fprintf(stderr, "Cannot open the output file\n");
    return -1;  
  }

  if (toLower(fd1, fd2) < 0)
    fprintf(stderr, "Error on tolower function\n");
    return -1;  

  return 0;
}

#define BUFSIZE 8192

int toLower(int fd1, int fd2) {

  char buffer[BUFSIZE];
  char *bufp = buffer;
  int covertToLower = 'a' - 'A';
  int buffersize;

  if ((buffersize = read(fd1, buffer, BUFSIZE)) < 0){
    fprintf(stderr, "Cannot read file");
    return -1;
  }

  int bufferWrite = buffersize;

  while(--buffersize > 0){
    if (*bufp >= 'A' && *bufp <= 'Z')   
      *bufp += covertToLower;
    *bufp++;
    }


  if (write(fd2, buffer, bufferWrite) < 0) {
    fprintf(stderr, "Cannot write on file");
    return -1;
  }

  return 0;
}