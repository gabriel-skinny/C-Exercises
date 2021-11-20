#include <stdio.h>

void main(){

    int c, nwhite, nother;
    int numericalDigit[10];

    for (int i = 0; i < 10; i++) {
        numericalDigit[i] = 0;
    }

    nwhite = nother = 0;

    while ((c = getchar()) != 'a') {
        if (c >= '0' && c <='9') 
            ++numericalDigit[c-'0'];
        
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        
        else 
            ++nother;
        
    }

    printf("\n\nDigitos:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d", numericalDigit[i]);

        printf("\nForam digitados %d essa quantidade %d", i, numericalDigit[i]);
    }

    printf("\nwhitespace = %d, other = %d\n", nwhite, nother);
    

}