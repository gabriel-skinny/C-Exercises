#include <stdio.h>

#define MAXCHAR 20

int getlineModified(char [], int);
void reverse(char[], int, int);

int main(){

    int len = 1;
    char lineArray[MAXCHAR];

    
    while (len > 0) {
        len = getlineModified(lineArray, MAXCHAR);
        reverse(lineArray, 0, len - 1);

        printf("%s\n\n", lineArray);
    }

    return 0;
}

int getlineModified(char line[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n' && c!= ' '; i++) 
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';

    return i;
}

void reverse(char line[], int start, int end) {
    int tmp;

    if (start < end){
        tmp = line[start];
        line[start] = line[end];
        line[end] = tmp; 

        reverse(line, start + 1, end - 1);
    }
 
}