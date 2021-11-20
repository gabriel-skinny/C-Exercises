#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char []);

int main(){ 

    char hexa[] = "0x44A";

    printf("\nThe result is %d\n\n", htoi(hexa));

    return 0;
}

int htoi(char hexaArr[10]) {
    int sum, len;

    len = strlen(hexaArr);
    sum = 0;

    for (int i = len - 1; i >= 2; i--) {
        if (hexaArr[i] >= 'A' && hexaArr[i] <= 'F')
            sum+= ((hexaArr[i] - 'A') + 10) * (int)(pow(16, len - i - 1));

        else 
            sum += (hexaArr[i] - '0') * (pow(16, len - i - 1));
    }

    return sum;
}