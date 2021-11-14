#include <stdio.h>

int power(int, int);

void main() {
    
    printf("\nA potencia de %d sobre %d é igual a %d\n\n", 7, 2, power(7, 2)); 


}

int power(int base, int n) {
    int p = 1;

    for (int i = 1; i <= n; i++) {
        p = p * base;
    }   

    return p;
}