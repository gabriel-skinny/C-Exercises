#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MAXWORDROOTS 20

struct group {
  struct word *word;
  struct group *left;
  struct group *rigth;
};

struct word {
  char *word;
  struct word *rigth;
  struct word *left;
};


struct word *addWord(struct word *, char *);
struct group *addGroup(struct group *, char *);
int getword(char *, int);

void printTreeGroup(struct group *, struct word *);
void printWord(struct word *);

int main() {
  struct word *rootWord;
  struct group *rootGroup;

  struct word *arrayStructRoots[MAXWORDROOTS];

  int new, i;

  char word[MAXSIZE] = "teste";

  rootWord = NULL;
  rootGroup = NULL;
  i = 0;


  while ((getword(word, MAXSIZE)) != EOF) 
      if (isalpha(word[0])){
        rootGroup = addGroup(rootGroup, word);
        rootWord = rootGroup -> word;
      }
      
      
  printf("\n\nThree: \n\n");
  printTreeGroup(rootGroup, rootWord);
  printf("\n\nFinished!!!!!!!!\n\n");
  
  return 0;
}


struct word *talloc(void);
struct group *galloc(void);
char *strdupM(char *);

struct word *addWord(struct word *p, char * word) {
  int compr;    

  if (p == NULL){
    p = talloc();
    p -> word = strdupM(word);
    p -> rigth = p -> left = NULL;
  }

  else if ((compr = strcmp(word, p -> word)) < 0) 
    p -> left = addWord(p -> left, word);
  
  else if(compr > 0)
    p -> rigth = addWord(p -> rigth, word);
    
  return p;
}

struct group *addGroup(struct group *pGroup, char *word) {
  int compr;
  char *copyFirstSixLetters(char *);

  if (pGroup == NULL) {
    struct word *pWord = NULL;
    pGroup = galloc();
    pGroup -> word = addWord(pWord, word);
    pGroup -> rigth = pGroup -> left = NULL;
  }
 
  else if ((compr = strcmp(copyFirstSixLetters(pGroup -> word -> word), copyFirstSixLetters(word))) == 0)
    pGroup -> word = addWord(pGroup -> word, word);

  else if (compr < 0)
    pGroup -> left = addGroup(pGroup -> left, word);
  

  else
    pGroup -> rigth = addGroup(pGroup -> rigth, word);
    

  return pGroup;
}

char *copyFirstSixLetters(char *word) {
  char *newWord;
  int length = 6;
  newWord = (char *) malloc(length);
	
  while (length-- > 0)
	*newWord++ = *word++;
  
  *newWord = '\0';

  return newWord;
}

void printTreeGroup(struct group *group, struct word *p) {
    if (group != NULL)
      printTreeGroup(group -> left, p);
      printWord(group -> word);
      printTreeGroup(group -> rigth, p);
}

void printWord(struct word *word) {
  if (word != NULL)
      printWord(word -> left);
      printf("Word: %s", word -> word);
      printWord(word -> rigth);
}

int getword(char *word, int lim) {
  int c, getchM(void);
	void ungetchM(int);
	char *w = word;

	while (isspace(c = getchM()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getchM())) {
			ungetchM(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

char buffer[MAXSIZE];
int countp;

int getchM(void) {
  return (countp > MAXSIZE) ? buffer[--countp] : getchar();
}

void ungetchM(int c) {
  if (countp < MAXSIZE)
    buffer[++countp] = c;
  else  
    printf("To much characters");
}


struct word *talloc(void) {
  return (struct word *) malloc(sizeof(struct word));
}

struct group *galloc(void) {
  return (struct group *) malloc(sizeof(struct group));
}


char *strdupM(char *s){
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  
  return p;
}
