#include <stdio.h>

void main(){

    int c, nl, blanks, tabs;
    nl = 0; blanks = 0; tabs = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++nl;
            printf("%s", "\n");
        }

        else if (c == '\t'){
            ++ tabs;
            printf("%s", "\t");
        }

        
        else if (c == ' ')
            ++ blanks;

        else if (c == '\b'){

            printf("%s", "\b");
        }



        printf("%d\n %d\n %d\n\n\n", nl, blanks, tabs);}

    
}