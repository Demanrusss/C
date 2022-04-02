#include <stdio.h>

double fibonacci(int);

int main() {

    int number;

    printf("Enter desired Fibonacci number: ");
    scanf("%d", &number);

    printf("%d of the Fibonacci number - %lf\n", number, fibonacci(number));

return 0;
}

double fibonacci(int n) {

    int i;
    double n1 = 0, n2 = 1, sum = 0;

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    for (i = 3; i <= n; i++) {
        sum = n2 + n1;
        n1 = n2;
        n2 = sum;
    }

return sum;
}
