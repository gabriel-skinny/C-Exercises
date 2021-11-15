#include <stdio.h>
#include <string.h>

#define MAXLINES 200

char *lineptr[MAXLINES];
char arrMax[MAXLINES];

int readlines(char *[], int, char *);
void writelines(char *[], int);

void qsort(char *[], int, int);

int main() {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES, arrMax)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    printf("Error to much input");
    return 1;
  }

}

#define MAXCHAR 200

int getLineM (char *, int);

int readlines(char *lineptr[], int maxlines, char arrMax[]) {
  int len, nlines;
  char *p, line[MAXCHAR], *lineStop;
  p = arrMax;
  lineStop = arrMax + MAXLINES;

  nlines = 0;

  while((len = getLineM(line, MAXCHAR)) > 0)
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

void writelines(char *linesArr[], int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *linesArr++);
  }
}

void qsort(char *v[], int left, int rigth) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= rigth) {
    return;
  }

  swap(v, left, (left + rigth) / 2);
  last = left;

  for (i = left + 1; i <= rigth; i++) 
    if (strcmp(v[i], v[left]) < 0)
        swap(v, ++last, i);
    
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, rigth);

}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;

}

int getLineM(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n' && c!='p'; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;   
}