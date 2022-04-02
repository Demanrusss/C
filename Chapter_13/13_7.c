#include <stdio.h>

#define MINIMUM2(x, y) (x) < (y) ? (x) : (y)
#define MINIMUM3(x, y, z) (MINIMUM2(x, y)) > (z) ? (z) : MINIMUM2(x, y)

int main(void) {

    int integer1, integer2, integer3;

    printf("Enter three integers: ");
    scanf("%d%d%d", &integer1, &integer2, &integer3);

    printf("%d is the smallest one between %d and %d and %d.\n",
           MINIMUM3(integer1, integer2, integer3), integer1, integer2, integer3);

return 0;
}
