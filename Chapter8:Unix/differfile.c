#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparefiles(FILE *, FILE *);

int main(int argc, char *argv[]) {
  int i;
  FILE *fp1, *fp2;

  if (argc < 3) {
    fprintf(stderr, "Not enough arguments");
    exit(1);
  }

  if ((fp1 = fopen(argv[1], "r")) == NULL ){
      fprintf(stderr, "Error open file");
      exit(2); 
  }
  else if ((fp2 = fopen(argv[2], "r")) == NULL) {
      fprintf(stderr, "Error open file");
      exit(3);
  }
  else {
    comparefiles(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
  }

  exit(0);
}

#define MAXSIZE 100

void comparefiles(FILE  *fp1, FILE *fp2){
  char fp1Char[MAXSIZE], fp2Char[MAXSIZE];

  while (fgets(fp1Char, MAXSIZE, fp1) != NULL && fgets(fp2Char, MAXSIZE, fp2) != NULL){    
    if (strcmp(fp1Char, fp2Char) != 0){
      fputs(fp2Char, stdout);
    } 
  }
}