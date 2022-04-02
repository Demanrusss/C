#include <stdio.h>

long int gcd(int, int);

int main(){

    int integer1, integer2;

    printf("Enter two integers: ");
    scanf("%d%d", &integer1, &integer2);

    printf("The %ld is gcd of %d and %d.\n", gcd(integer1, integer2), integer1, integer2);

return 0;
}

long int gcd(int x, int y) {

    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
