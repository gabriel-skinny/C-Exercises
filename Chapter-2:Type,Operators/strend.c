#include <stdio.h>
#include <string.h>


int strend(char *s, char *t);
void strncpyM (char *s, char *t, int n);

int main(){

  char s[5];
  char t[] = "phrasel gigante taligado mermapo";

  strncpyM(s, t, 25);

  printf("\n\nArray S: %s\n\n", s);

  return 0;
}

int strend(char *s, char *t){

  int count;
  char *realS, *realT;
  
  *realS = *s;
  *realT = *t;
  count = 0;

  /* printf("\n\nS: %c \n\n", *(t)); */

  while (*(s++ + strlen(realS)) == *(t++))
    count++;

  

  if (count == strlen(realT))
    return 1;

  return 0;
}

void strncpyM (char *s, char *t, int n) {

  char *startT = t;

  while (t++ - startT <= n - 1 && *(t - 1) != '\0')
    *s++ = *(t - 1);

  *s = '\0';
}