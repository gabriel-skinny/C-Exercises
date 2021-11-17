#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 50

int readLines(char *[], int);
void writelines(char *[], int, int);
int getLineModified(char s[], int lim);
char *alloc(int n);

int main(int argc, char *argv[]) {
  char c;
  int nlines, linesToWrite = 5, i = 0;
  char *lines[MAXLINES], str[10];

  while(--argc > 0 && (*++argv)[0] == '-') 
      while(*++argv[0])
        str[i++] = **argv;
    
    linesToWrite = atoi(str);

    
  if ((nlines = readLines(lines, MAXLINES)) <= 0) 
    printf("Error input too big");
  
  writelines(lines, linesToWrite, nlines - 1);

  return 0;
}

#define MAXLINE 50

int readLines(char *lines[], int maxlines){
  int c, len, nlines = 0;
  char *p, line[MAXLINE];

  while ((len = getLineModified(line, MAXLINE)) > 0)
    if (nlines > maxlines | (p = alloc(len)) == NULL)
      return -1;
    
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lines[nlines++] = p;
    }

  return nlines;
}

void writelines(char *lines[], int linesToRead, int nlines){
  char **lineStart;

  if (linesToRead >= nlines)
    lineStart = lines;
  else  
    lineStart = (lines + nlines - linesToRead + 1);

  while(lineStart <= (lines + nlines))
    printf("\nRestults: %s\n", *lineStart++);
}


int getLineModified(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n' && c != '['; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;   
}

#define MAX_SIZE 200

static char allocbuf[MAX_SIZE];
static char *aloocP = allocbuf;

char *alloc(int n) {

  if (allocbuf + MAX_SIZE - aloocP >= n){
    aloocP += n;
    return aloocP - n; //Where N starts
  }
  else 
    return NULL;
}