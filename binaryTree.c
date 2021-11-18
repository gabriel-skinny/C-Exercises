#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *rigth;
};

struct tnode *addTree(struct tnode*, char *);
void treeprint(struct tnode*);
int getword(char *, int);

int main() {
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while ((getword(word, MAXWORD)) != EOF) 
    if (isalpha(word[0])){
      root = addTree(root, word);
    }
  
  treeprint(root);

  return 0;
}

struct tnode* talloc(void);
char *strdupM(char *);

struct tnode *addTree(struct tnode *p, char *w) {
  int cond;


  if (p == NULL) {
    p = talloc();
    p -> word = strdupM(w);
    p -> count = 1;
    p -> left = p -> rigth = NULL;
  }
  
  else if( (cond = strcmp(w, p -> word)) == 0)
    p -> count++;
  
  
  else if (cond < 0)
    p -> left = addTree(p -> left, w);

  else  
    p -> rigth = addTree(p -> rigth, w);  

  

  return p;
}

void treeprint(struct tnode *p) {
  if (p != NULL){
    treeprint(p -> left);
    printf("Word: %s Count: %d\n", p -> word, p -> count);
    treeprint(p -> rigth);
  }
}

#include <stdlib.h>

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}


char *strdupM(char *s){
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  
  return p;
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