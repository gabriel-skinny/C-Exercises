#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MAXLINES 20

struct lines {
  char *word;
  char *lineNumbers;
  struct lines *rigth;
  struct lines *left;
  int times;
};

struct lines *addLine(struct lines *, char *, char);
int getword(char *, int);
void printTree(struct lines *);

int main() {
  char word[MAXSIZE];
  char lineNumber;
  struct lines *lineRoot;

  lineRoot = NULL;
  lineNumber = 0;

  while (getword(word, MAXSIZE) != EOF){
    lineNumber++;
    if (isalpha(word[0]))
      lineRoot = addLine(lineRoot, word, lineNumber);
  }


  printTree(lineRoot);

}

char *strdupM(char *);
struct lines *talloc(void);
char  *ialloc(void);

struct lines *addLine(struct lines* line, char *word, char lineNumber){
  int compr;

  if (line == NULL){
    line = talloc();
    line -> lineNumbers = ialloc();
    line -> word = strdupM(word);
    line -> lineNumbers[0] = lineNumber;
    line -> times = 0;
    line -> rigth = line -> left = NULL;
  }

  else if ((compr = strcmp(line -> word, word)) == 0){
    line -> times++;
    line -> lineNumbers[line -> times] = lineNumber;
  }
    

  else if (compr < 0)
    line -> left = addLine(line -> left, word, lineNumber);

  else
    line -> rigth = addLine(line -> rigth, word, lineNumber);

  return line;
}

void printTree(struct lines *line) {
  if (line != NULL) {
    printTree(line -> left);
    printf("\nWord: %s", line -> word);
    printf(", Line:");
    for (int i = 0; line -> lineNumbers[i]; i++)
      printf(" %d,", line -> lineNumbers[i]);
    printTree(line -> rigth);
  }
}

char *strdupM(char *word) {
  char *newWord;

  newWord = (char *) malloc(strlen(word) + 1);

  if (word != NULL);
    strcpy(newWord, word);


  return newWord;
} 

struct lines* talloc(void) {
  return (struct lines *) malloc(sizeof(struct lines));
}

char *ialloc(void) {
  return (char *) malloc(20);
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