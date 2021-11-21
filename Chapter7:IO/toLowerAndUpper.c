#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c;

  printf("\nARgv: %s\n", argv[1]);

  while ((c = getchar()) != EOF)
    if (!strcmp(argv[1], "lower") && isupper(c))
      putchar(tolower(c));

    else if (!strcmp(argv[1], "upper") && islower(c))
      putchar(toupper(c));
    
    else 
      putchar(c);

  return 0;
} 