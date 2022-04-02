#include <stdio.h>
#include <math.h>

int simple(int);

int main() {

    int number;

    printf("Here are simple numbers:\n");

    for (number = 1; number <= 10000; number++)
        if (simple(number) == 0)
            printf("%d ", number);

return 0;
}

int simple(int x) {

    int i;

    for (i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 1;
return 0;
}
