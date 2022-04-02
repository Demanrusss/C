#include <stdio.h>

void square(int, char);

main() {

    int side;
    char fillCharacter;

    printf("Enter a side and a symbol (without space) of square: ");
    scanf("%d%c", &side, &fillCharacter);

    square(side, fillCharacter);

return 0;
}

void square(int x, char c) {

    int i = x, j;

    for (; i >= 1; i--) {
        j = x;

        for (; j >= 1; j--)
            printf("%c", c);

        printf("\n");
    }
}
