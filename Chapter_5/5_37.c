#include <stdio.h>

long int power(int, int);

int main() {

    int base, exponent;

    printf("Enter base and exponent for finding the result of base^exponent: ");
    scanf("%d%d", &base, &exponent);

    printf("%d^%d = %ld", base, exponent, power(base, exponent));

return 0;
}

long int power(int b, int e) {

    if (e == 1)
        return b;
    else
        return b * power(b, e - 1);

}
