#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int getLineModified(char [], int);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int c, expect = 0, number = 0, found = 0;


  while (--argc > 0 && (*++argv)[0] == '-')
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
      }

  if (argc != 1) {
    printf("Usage: find -x -n pattern\n");
  } 
  else {
    while(getLineModified(line, MAXLINE) > 0) {
      lineno++;

      if ((strstr(line, *argv) != NULL) != expect) {
        if (number)
          printf("\nLinha:%ld", lineno);

        printf("\nFound:%s", line);
        found++;
      }
    }
  }

  return found;
}

int getLineModified(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;   
}