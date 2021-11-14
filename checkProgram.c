#include <stdio.h>

#define MAXLINE 50

int verifyClosed(char[], int);

int main(){
    int c, len;
    char lineArr[MAXLINE];

    len = 0;

    for (int i = 0; i < MAXLINE; i++)
        lineArr[i] = 0; 

    for(int i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        lineArr[i] = c;
        len++;
    }

    
    int code = verifyClosed(lineArr, len);

    if (!code) {
        return 0;
    }
 

    printf("\nCommand = %s\n\n", lineArr);

    return 0;
}


int verifyClosed(char lineArr[], int len) {
    
    char openTypeTest[3] = {'(', '{', '['};
    char closeTypeTest[3] = {')', '}', ']'};

    for (int k = 0; k <= 3; k++) {
        for (int i = 0; i < len; i++){
            if (lineArr[i] == openTypeTest[k]) {
            
                for (int j = i; j < len; j++) 
                    if (lineArr[j] != closeTypeTest[k]){
                        printf("\n\nSyntax ERROR!\n"); 
                        return 0;           
                }
            }
        }
    }


    return 1;
}