#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 30

float toCelcius(int);

void main() {

    int farh;

    for (farh = LOWER; farh <= UPPER; farh += STEP) {
        printf("Farenhegith: %d  Celcius: %.2f \n", farh, toCelcius(farh));
    }
}

float toCelcius(int farh) {
    float celc;

    celc = (5.0/9.0) * (farh-32);

    return celc;
}