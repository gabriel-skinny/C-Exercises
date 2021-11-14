#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 30

void main() {
    int farenheith;

    for (farenheith = UPPER; farenheith > LOWER; farenheith = farenheith - STEP){
        printf("%3f %6d \n", (5.0/9.0) * (farenheith-32), farenheith);
    }
}
 