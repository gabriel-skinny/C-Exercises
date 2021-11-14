#include <stdio.h>

int main(){
    int c, countBlank;
    char lineArray[20];

    countBlank = 0;

    for (int i = 0; i <= 20; i++) {
        lineArray[i] = 0;
    }

    for (int i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        if (c == ' ') {
            countBlank++;
        }

        if (countBlank == 4) {
            int j = i;

            while(i > j - 3){
                lineArray[i] = 0;
                printf("Teste %d", i);
                i--;
            }  

            lineArray[i] = '\t';
            printf("Substitui");
        }

        lineArray[i] = c;
    }

    printf("\nLinha: %s\n\n", lineArray);

    return 0;
}
