#include <stdio.h>

int main(){
    int c, tabs;
    char lineArray[20];

    tabs = 0;

    for (int i = 0; i <= 20; i++) {
        lineArray[i] = 0;
    }

    for (int i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        if (c == '\t'){
            lineArray[i] = '    ';
            tabs++;    
        }

        lineArray[i] = c;
    }

    printf("\nO tab foi apertado %d vezes", tabs);
    printf("\nLinha: %s\n\n", lineArray);

    return 0;
}
