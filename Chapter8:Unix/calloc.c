#include <stdio.h>
#include <stdlib.h>

void *callocM(unsigned objects, unsigned size);

int main() {

  int *teste;

  if ((teste = callocM(5, sizeof teste)) == NULL){
    printf("Cannot alocate space");
    return -1;
  }

  printf("\n%d\n", teste[8]);

  return 0;
}

void *callocM(unsigned objects,unsigned size){
    int i;
    char *p,*set;
    
    if (objects > 0) 
      if((set = p = malloc(objects * size)) != NULL)
        for(i = 0; i < objects * size; i++)
            *p++ = 0;

    return p;
}