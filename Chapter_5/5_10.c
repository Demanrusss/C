#include <stdio.h>
#include <math.h>

main() {

int i;
float x, y;

for (i = 1; i <= 5; i++) {
    printf("Enter an integer: ");
    scanf("%f", &x);

    y = floor(x + .5);

    printf("Your integer %.1f after rounding to the nearest is %.1f\n", x, y);
}

return 0;
}
