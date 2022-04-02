#include <stdio.h>

#define MINIMUM2(x, y) (x) < (y) ? (x) : (y)

int main(void) {

    int integer1, integer2;

    printf("Enter two integers: ");
    scanf("%d%d", &integer1, &integer2);

    printf("%d is the smallest one between %d and %d.\n", MINIMUM2(integer1, integer2),
           integer1, integer2);

return 0;
}
