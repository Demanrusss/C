#include <stdio.h>
#define SIZE 10


int main(void) {

    float numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    float *nPtr;
    int i;

    for (i = 0; i <= SIZE - 1; i++)
        printf("%.1f   ", numbers[i]);

    printf("\n");

    nPtr = numbers;
    nPtr = &numbers[0];

    for (i = 0; i <= SIZE - 1; i++)
        printf("%.1f   ", *(nPtr + i));

    printf("\n");

    for (i = 0; i <= SIZE - 1; i++)
        printf("%.1f   ", *(numbers + i));

    printf("\n");

    printf("%.1f   %.1f   %.1f   %.1f\n", numbers[3], *(numbers + 3), nPtr[3], *(nPtr + 3));

    printf("%.1f\n", *(nPtr + 8));

    nPtr = &numbers[5];
    printf("%.1f\n", *(nPtr -= 4));

 return 0;
}
