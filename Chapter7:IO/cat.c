#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0];

  if (argc == 1)
    filecopy(stdin, stdout);
  else 
    while(--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr ,"%s: Cant open %s\n",prog, *argv);
        exit(1);
      }
      else {
        filecopy(fp, stdout);
        fclose(fp);
      }
    
    if (ferror(stdout)) {
      fprintf(stderr, "%s: error wirting stdout\n", prog);
      exit(2);
    }

  exit(0);
}

void filecopy(FILE *inputFile, FILE *outputFile) {
  int c;

  while (( c = getc(inputFile)) != EOF)
    putc(c, outputFile);
}