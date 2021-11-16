#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int getLineModified(char [], int);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  int found = 0;

  if (argc != 2) {
    printf("More or less arguments than expected!!");
  }
  else {
    while(getLineModified(line, MAXLINE) > 0) {

      if (strstr(line, argv[1]) != NULL) {
        printf("Found:%s", line);
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