#include <stdio.h>

void square(int, char);
void squareHole(int, char);
void triangle(int, char);

main() {

    int side;
    char fillCharacter;

    printf("Enter a side and a symbol (without space) of square: ");
    scanf("%d%c", &side, &fillCharacter);

    square(side, fillCharacter);
    squareHole(side, fillCharacter);
    triangle(side, fillCharacter);

return 0;
}

void square(int x, char c) {

    int i, j;

    for (i = x; i >= 1; i--) {
        for (j = x; j >= 1; j--)
            printf("%c", c);

        printf("\n");
    }
}

void squareHole(int x, char c) {

    int i, j;

    for (i = x; i >= 1; i--) {
        for (j = x; j >= 1; j--)
            if (i == x || i == 1)
                printf("%c", c);
            else
                if (j == x || j == 1)
                    printf("%c", c);
                else
                    printf(" ");

        printf("\n");
    }
}

void triangle(int x, char c) {

    int i, j;

    for (i = x; i >= 1; i--) {
        for (j = i; j >= 1; j--)
            printf("%c", c);

        printf("\n");
    }
}
