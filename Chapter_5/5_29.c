#include <stdio.h>

int gcd(int, int);

int main() {

    int num1, num2;

    printf("Enter two numbers to find gcd: ");
    scanf("%d%d", &num1, &num2);

    printf("The GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

return 0;
}

int gcd(int n1, int n2) {

    int i, min;

    if (n1 < n2)
        min = n1;
    else
        min = n2;

    for (i = min; i >= 1; i--)
        if ((n1 % i == 0) && (n2 % i == 0))
            return i;

return 1;
}
