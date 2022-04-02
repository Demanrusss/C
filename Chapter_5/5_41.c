#include <stdio.h>

long factorial(long);

int main() {

    int i;

    for (i = 1; i <= 10; i++)
        printf("%2d != %ld\n", i, factorial(i));

return 0;
}

long factorial(long number) {

    int j;

    if (number <= 1)
        return 1;
    else {
        for (j = 1; j <= number; j++)
            printf(" ");

        printf("%ld! = %ld * %ld!\n", number, number, number - 1);
        return (number * factorial(number - 1));
    }
}
