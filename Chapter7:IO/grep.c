#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100

void formatFileLine(char *, char*);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  char fileLine[MAXLINE];
  long lineno = 0;
  int c, expect = 0, number = 0, found = 0;
  FILE *fp;

  if (argc > 3) {
    fprintf(stderr, "Not enough arguments");
    return 1;
  }
  else 
    if ((fp = fopen(*++argv, "r")) == NULL)
      fprintf(stderr, "Cant open file");

  /* while (--argc > 0 && (*++argv)[0] == '-')
    while(c = *++argv[0])
      switch (c){
      case 'x':
        expect = 1;
        break;

      case 'n':
        number = 1;
        break;

      default:
        printf("finded ilgeal arguments");
        argc = 0;
        found = -1;
        break;
      } */



  while(fgets(fileLine, MAXLINE, fp) != NULL) {
    lineno++;
    char formatedLine[MAXLINE];
    formatFileLine(formatedLine, fileLine);

   /*  printf("\nFileline: %s", formatedLine); */

    if (strstr(*(argv + 1), formatedLine) != NULL) {
      if (number)
        printf("\nLinha:%ld", lineno);

      printf("\nFound:%s\n\n", formatedLine);
      found++;
    }
  }
  

  return 0;
}

void formatFileLine(char *formatedLine, char *fileline){
    int len = strlen(fileline);

    while(len-- > 0)
      *formatedLine++ = *fileline++;

    printf("\nFileline: %s", formatedLine);
        
}