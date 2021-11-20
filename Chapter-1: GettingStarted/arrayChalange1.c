#include <stdio.h>


void main(){
    
    int c, words;

    words = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            for (int i = 0; i < words; i++) {
                printf("*");
            }

            words = 0;
        }

				else if (c == '\t' || c == ' ')
					;

        else {
            words++;
        }
    }
}
