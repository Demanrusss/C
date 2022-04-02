#include <stdio.h>

float fahrenheit(int);
float celsius(int);

int main() {

    int degree;

    printf("Datasheet of Celsius to Fahrenheit\n");
    for (degree = 0; degree <= 100; degree++) {
        printf("%3d - %5.1f ", degree, fahrenheit(degree));

        if (degree % 10 == 0)
            printf("\n");
    }

    printf("Datasheet of Fahrenheit to Celsius\n");
    for (degree = 32; degree <= 212; degree++) {
        printf("%3d - %5.1f ", degree, celsius(degree));

        if (degree % 10 == 0)
            printf("\n");
    }

return 0;
}

float fahrenheit(int d) {

return (float)d * 1.8 + 32;
}

float celsius(int d) {

return ((float)d - 32) / 1.8;
}
