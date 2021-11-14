#include <stdio.h>

#define ARRAYLIMIT 50

int main() {
    int c, i;
    char s[ARRAYLIMIT] = "Teste \t\t\t\t\t Balaco \n";
    char t[ARRAYLIMIT];

    for (int j = 0; j < ARRAYLIMIT; j++)
        t[j] = 0;


    for (i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\n':
                t[i] = '\\';
                t[++i] = 'n';
                break;
            case '\t':
                t[i] = '\\';
                t[++i] = 't';
                break;
            default:
                t[i] = s[i];
                break;
        }
    }

    t[++i] = '\0';

    printf("\nArray result: %s \n\n", t);

    return 0;
}