#include <stdio.h>
#define SIZE 8

int main() {

    int board[SIZE][SIZE] = {0};
    int accessibility[SIZE][SIZE] = {{22, 22, 22, 22, 22, 22, 22, 22},
                                     {22, 24, 24, 24, 24, 24, 24, 22},
                                     {22, 24, 26, 26, 26, 26, 24, 22},
                                     {22, 24, 26, 28, 28, 26, 24, 22},
                                     {22, 24, 26, 28, 28, 26, 24, 22},
                                     {22, 24, 26, 26, 26, 26, 24, 22},
                                     {22, 24, 24, 24, 24, 24, 24, 22},
                                     {22, 22, 22, 22, 22, 22, 22, 22}};
    int i, j, x, y, count, min;

    for (count = 1; count <= 8; count++) {
        min = 28;

        for (i = 0; i <= SIZE - 1; i++)
            for (j = 0; j <= SIZE - 1; j++)
                if (accessibility[i][j] < min && board[i][j] != 0) {
                    x = i;
                    y = j;
                    min = accessibility[i][j];
                }

        if (min != 28) {
            board[x][y] = count;

            for (i = )
        }
    }

return 0;
}
