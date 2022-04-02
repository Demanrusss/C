#include <stdio.h>
#define SIZE 10

int main() {

    int x;
    float fractions[SIZE] = {0};

    fractions[5] = 1.667;
    fractions[6] = 3.333;

    printf("fractions[6] - %.2f\nfractions[9] - %.2f\n", fractions[6], fractions[9]);

    for (; x <= SIZE - 1; x++)
        printf("%.2f   ", fractions[x]);

return 0;
}
