#include <stdio.h>

#define SUM(x, y) (x) + (y)

int main(void) {

    int x = 6, y = 7;

    printf("The sum of %d and %d is %d\n", x, y, SUM(x, y));

return 0;
}
