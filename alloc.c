#include <stdio.h>

char *alloc(int);
void afree(char*);
void strcpyM(char*, char*);

int main(){

  int n = 2;
  char *p;

  char t[4] = "alos";
  char s[4];

  char *tc = "alo";

  p = alloc(n);

  printf("\nThe space allocated was %p\n ", p);

  printf("Value of te space allocated was %d \n\n", *(p + 5));

  afree(p + 3);

  strcpyM(s, t);

  printf("\n\nArray copy %s", s);

  printf("\n\nArray change %s", s);

  printf("\nPointer string constas %s \n\n\n", tc);

  return 0;
}

#define MAX_SIZE 20

static char allocbuf[MAX_SIZE] = {1, 5, 2, 4, 6, 7, 8, 9, 19};
static char *aloocP = allocbuf;

char *alloc(int n) {

  if (allocbuf + MAX_SIZE - aloocP >= n){
    aloocP += n;
    return aloocP - n; //Where N starts
  }
  else 
    return NULL;
}

void afree(char *p) {

  if (p >= allocbuf && p <= allocbuf + MAX_SIZE)
    aloocP = p;

}

void strcpyM(char*s, char*t) { 
  while(*s++ = *t++)
    ;
}