#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0,
};

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

int getword(char *, int);
struct key *binarySearch(char *, struct key *, int);

int main() {
  int n;
  char word[MAXWORD];
  struct key *p;

  while ((getword(word, MAXWORD)) != EOF)
    if (isalpha(word[0])) 
      if ((p = binarySearch(word, keytab, NKEYS)) >= 0){
        p -> count++;
        printf("\nCount: %d Word: %s\n\n", p -> count, p -> word);
      }

  return 0;
}

struct key *binarySearch(char *word, struct key *tab, int n) {
  int cond;
  struct key *low, *high, *mid;

  low = &tab[0];
  high = &tab[n];

  while(low <= high) {
      mid = low + (high - low) / 2;
      if ((cond = strcmp(word, mid -> word)) < 0)
        high = mid; 
      else if (cond > 0)
        low = mid + 1;
      else 
        return mid;
  }

  return NULL;
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