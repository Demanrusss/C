#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, sum;
    int array[13] = {0};
    long int i;

    srand(time(NULL));

    for (i = 0; i <= 36000; i++) {
        num1 = rand() % 6 + 1;
        num2 = rand() % 6 + 1;

        ++array[num1+num2];
    }

    printf("After 36000 rolls we have:\n");
    printf("%5s%8s\n", "Sum", "Times");
    for (i = 2; i <= 12; i++)
        printf("%5ld - %5d\n", i, array[i]);

return 0;
}
