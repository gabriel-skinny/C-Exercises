#include <stdio.h>

#define MAXLINE 5        

int getLineModified(char[], int);
void copy (char[], char[]);

int main(){
    
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;

    while((len = getLineModified(line, MAXLINE)) > 0) 
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    
    if (max > 0) 
        printf("%s", longest);

        if (max > MAXLINE) {
            printf("Maximum caracter excedded\n");
            printf("The lenght of the string is %d", 5);
        }


    return 0;
}

int getLineModified(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n' && c != 'a'; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;   
}

void copy(char *to, char *from) {
    while (*to++ = *from++)
        ;
}