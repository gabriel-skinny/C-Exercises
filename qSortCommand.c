#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 200

char *lineptr[MAXLINES];
char arrMax[MAXLINES];

int readlines(char *[], int, char *, int);
void writelines(char *[], int, int);

void qsortM(void *[], int, int, int (*)(void *, void *));

int numcmp(char *, char *);

int main(int argc, char *argv[]) {
  int nlines, c;
  int numeric = 0, reverse = 0, ignoreCapital = 0;    

  while(--argc > 0 && (*++argv)[0] == '-')
    while(c = *++argv[0])
      switch(c){
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        case 'f':
          ignoreCapital = 1;
          break;
        default:
          printf("Argumment unknow");
          break;
      }


  if ((nlines = readlines(lineptr, MAXLINES, arrMax, ignoreCapital)) >= 0) {
    qsortM(lineptr, 0, nlines - 1, 
      (int (*)(void*, void*))(numeric ? numcmp : strcmp));

    writelines(lineptr, nlines, reverse);
    return 0;
  }
  else {
    printf("Error to much input");
    return 1;
  }

}

#define MAXCHAR 200

int getLineM (char *, int, int);

int readlines(char *lineptr[], int maxlines, char arrMax[], int ignoreCapital) {
  int len, nlines;
  char *p, line[MAXCHAR], *lineStop;
  p = arrMax;
  lineStop = arrMax + MAXLINES;

  nlines = 0;

  while((len = getLineM(line, MAXCHAR, ignoreCapital)) > 0)
    if ((nlines >= maxlines) || (p + len  > lineStop))
      return -1;
    
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }

  return nlines;
}

void writelines(char *linesArr[], int nlines, int reverse) {
  if (reverse){
    while (nlines-- > 0) {
      printf("%s\n", *(linesArr + nlines));
    }
  }else {
    while (nlines-- > 0) {
      printf("%s\n", *linesArr++);
    }
  }
}

void qsortM(void *v[], int left, int rigth, int (*cmpr)(void *, void *)) {
  int i, last;
  void swap(void *v[], int i, int j);

  if (left >= rigth) {
    return;
  }

  swap(v, left, (left + rigth) / 2);
  last = left;

  for (i = left + 1; i <= rigth; i++) 
    if ((*cmpr)(v[i], v[left]) < 0)
        swap(v, ++last, i);
    
  swap(v, left, last);
  qsortM(v, left, last - 1, cmpr);
  qsortM(v, last + 1, rigth, cmpr);

}

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)    
    return -1;
  else if (v1 > v2)
    return 1;
  else  
    return 0;
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;

}

int getLineM(char s[], int lim, int ignoreCapital) {
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n' && c!='p'; i++)
        if (ignoreCapital && c >= 'A' && c <= 'Z')
          s[i] = 'a' - 'A' + c;
        else  
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;   
}