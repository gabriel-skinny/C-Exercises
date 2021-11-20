#include <stdio.h>

void expand(char[], char[]);

#define MAX_LENGTH 80

int main() {

    char s1[MAX_LENGTH] = "1-15";
    char s2[MAX_LENGTH];


    expand(s1, s2);

    printf("\nThe result is %s\n\n", s2);

    return 0;
}

void expand(char s1[], char s2[]) {

    int firstLetter, lastLetter;

    firstLetter = lastLetter = 0;

    for (int i = 0; i < MAX_LENGTH; i++) {

        if (s1[i] >= 'A' && s1[i] <= 'z'){

            if (!firstLetter)
                firstLetter = s1[i];
            else
                lastLetter = s1[i];
        }

        else if (s1[i] >= '0' && s1[i] <= '9')
        
            if (!(firstLetter >= 0 && firstLetter <= 9))
                firstLetter = s1[i] - '0';
            else
                lastLetter = s1[i] - '0';

    }

    int j, i;

    for (i = 0, j = firstLetter; j <= lastLetter && i < MAX_LENGTH; i++, j++) {
        
        if (j <= 9)
            s2[i] = j + '0';
        else
            s2[i] = j;

        if (lastLetter >= 'a' && j == 'Z') 
            j+= 6;
        
    }

    s2[i++] = '\0' ;

    char alo = 'Z';

    printf("First Letter: %d \n Last Letter: %d \n", firstLetter, lastLetter);

}