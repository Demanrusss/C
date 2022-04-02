#include <stdio.h>

int perfect(long int);

int main() {

    long int number, count;

    for (number = 1; number <= 100000; number++)
        if (perfect(number) == 1) {
            printf("%ld is perfect number!\n", number);
            printf("%ld = ", number);

            for (count = number - 1; count >= 1; count--) {
                if (count == 1)
                    printf("%ld\n", count);
                else
                    if (number % count == 0)
                        printf("%ld + ", count);
            }
        }

return 0;
}

int perfect(long int x) {

    long int i, sum = 0;

    for (i = x - 1; i >= 1; i--)
        if (x % i == 0)
            sum += i;

    if (sum == x)
        return 1;
    else
        return 0;
}
