#include <stdio.h>
#define SIZE 3

int main() {

    int table[SIZE][SIZE] = {0};
    int x, y;

    for (x = 0; x <= SIZE - 1; x++)
        for (y = 0; y <= SIZE - 1; y++)
            table[x][y] = x + y;

    for (x = 0; x <= SIZE - 1; x++) {
        for (y = 0; y <= SIZE - 1; y++)
            printf("%d  ", table[x][y]);

        printf("\n");
    }

return 0;
}
