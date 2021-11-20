#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHIZE 100

struct nlist {
  struct nlist *next;
  char *name;
  char *value;
} static *hastab[HASHIZE];

struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void undef (char *);



int main() {

  char *nameVariables[] = {"ALUNOS", "PROFESSORES", "MANES"};
  char *values[] = {"15", "45", "31"};

  for (int i = 0; i < 3; i++) {
    install(nameVariables[i], values[i]);
  }


  printf("\n\nFound the value of this variable name: %s", "PROFESSORES");
  printf("\nValue: %s\n\n", lookup("PROFESSORES") -> value);

  undef("PROFESSORES");

  printf("\nPrint deleted variable value: %p\n", lookup("PROFESSORES"));

  printf("\n\nFound the value of this variable name: %s", nameVariables[0]);
  printf("\nValue: %s\n\n", lookup(nameVariables[0]) -> value);

  return 0;
}

unsigned hash(char *);

struct nlist *lookup(char *name) {
  struct nlist *list;

  for (list = hastab[hash(name)]; list != NULL; list = list -> next)
    if (strcmp(list -> name, name) == 0)
      return list;

  return NULL;
}

struct nlist *install(char *name, char *value) {
  struct nlist *list;
  unsigned hashVal;

  if ((list = lookup(name)) == NULL) {
    list = (struct nlist *) malloc(sizeof(struct nlist));

    if (list == NULL || (list -> name = strdup(name)) == NULL)
      return NULL;

    hashVal = hash(name);
    list -> next = hastab[hashVal];
    hastab[hashVal] = list;
  }
  else 
    free((void *) list -> value);
  
  if ((list -> value = strdup(value)) == NULL)
    return NULL;

  return list;
}

void undef (char *name) {
  struct nlist *list;
  unsigned hashValue;

  if ((list = lookup(name)) != NULL) {
    hashValue = hash(name);
    hastab[hashValue] = list -> next;
    free((void *)  list);
  }
  else  
    printf("VARIABLE NOT FOUND");

}

unsigned hash(char *name) {
  unsigned hashNumber;

  for (hashNumber = 0; *name != '\0'; name++)
    hashNumber = *name + 36 * hashNumber;

  return hashNumber % HASHIZE;
}