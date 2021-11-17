#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int getToken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];


int main() {

  while(getToken() != 'a')
    printf("AGAIN\n");
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if (tokentype != '\n')
      printf("Syntax error!");
    printf("%s: %s %s\n", name, out, datatype);


  return 0;
}

int getToken(void) {
  int c;
  char *p = token;

  while ((c = getchar()) == ' ' || c == '\t')
      ;

  if (c == '(') {
    if ((c = getchar()) == ')') {
      strcpy(token, "()");
      return tokentype =  PARENS;
    } else 
      return tokentype = '(';
  }
  else if (c == '[') {
    for (*p++ = c; (*p++ = getchar()) != ']';)
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  }
  else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getchar());)
      *p++ = c;
    *p = '\0';

    return tokentype = NAME;
  }
  else 
    return tokentype = c;

}

void dcl(void) {
  int ns;

  for (ns = 0; getToken() == '*';) 
    ns++;
  
  dirdcl();

  while (ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')')
      printf("Error Missing: )\n");
  }
  else if (tokentype == NAME)
    strcpy(name, token);
  
  else
    printf("error: expected name or (dcl)\n");
  
  while((type = getToken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}
