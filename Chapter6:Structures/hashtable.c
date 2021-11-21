#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHIZE 100
#define MAXWORD 100

struct nlist {
  struct nlist *next;
  char *name;
  char *value;
} static *hastab[HASHIZE];

struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void undef (char *);
int getVar(char *, char *, int);


int main() {

  char name[MAXWORD];
  char value[MAXWORD];

  while(getVar(name, value, MAXWORD) != EOF)
    if (isalpha(name[0]))
      install(name, value);
      
  
    
  printf("\n\nConstant criated: %s, their value: %s", name, lookup(name) -> value);

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

    if (list -> next != NULL) {
      list -> next = list -> next -> next;
      list = list -> next;
    } else {
      hastab[hashValue] = NULL;
      free ((void *) list);
    }
  }
  else
    printf("Variable not found");
}

unsigned hash(char *name) {
  unsigned hashNumber;

  for (hashNumber = 0; *name != '\0'; name++)
    hashNumber = *name + 36 * hashNumber;

  return hashNumber % HASHIZE;
}

int getVar(char * name, char *value, int limit) {
  int c, getchM(void);
	void ungetchM(int);
	char *nameP = name;
  char *valueP = value;
  
  while (isspace(c = getchM()))
    ;

  if (c = '#')
    while ((c = getchM()) != ' ')
      ;

  if ((c = getchM()) != EOF)
    *nameP++ = c;
  
  if (!isalpha(c)) {
    *nameP = '\0';
    return c;
  }

  for (; --limit > 0; nameP++) 
    if (!isalnum(*nameP = getchM())) {
      ungetchM(*nameP);
      break;
    }
    else if (*nameP == ' '){
      *nameP = '\0';
      break;
    }

  while ((*valueP++ = getchM()) != '\n')
    ;

  *valueP = '\0';

  return name[0];
}

char buffer[MAXWORD];
int countp;

int getchM(void) {
  return (countp > MAXWORD) ? buffer[--countp] : getchar();
}

void ungetchM(int c) {
  if (countp < MAXWORD)
    buffer[++countp] = c;
  else  
    printf("To much characters");
}