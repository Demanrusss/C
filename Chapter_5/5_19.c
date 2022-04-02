#include <stdio.h>

void square(int);

main() {

    int side;

    printf("Enter a side of square: ");
    scanf("%d", &side);

    square(side);

return 0;
}

void square(int x) {

    int i = x, j;

    for (; i >= 1; i--) {
        j = x;

        for (; j >= 1; j--)
            printf("*");

        printf("\n");
    }
}
