#include <stdio.h>

long int integerPower(int, unsigned);

main() {

    int base;
    unsigned exponent;

    printf("Enter base to calculate base^exponent: ");
    scanf("%d", &base);
    printf("Enter exponent to calculate base^exponent: ");
    scanf("%u", &exponent);

    printf("%d^%u = %ld\n", base, exponent, integerPower(base, exponent));

return 0;
}

long int integerPower(int b, unsigned e) {

    long int res = 1;

    for (; e >= 1; e--)
        res *= (long int)b;

return res;
}
