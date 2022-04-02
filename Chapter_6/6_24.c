#include <stdio.h>
#define SIZE 8

void printDesk(int [SIZE][SIZE], int);

int main() {

    int board[SIZE][SIZE] = {0};
    int accessibility[SIZE][SIZE] = {{2, 3, 4, 4, 4, 4, 3, 2},
                                     {3, 4, 6, 6, 6, 6, 4, 3},
                                     {4, 6, 8, 8, 8, 8, 6, 4},
                                     {4, 6, 8, 8, 8, 8, 6, 4},
                                     {4, 6, 8, 8, 8, 8, 6, 4},
                                     {4, 6, 8, 8, 8, 8, 6, 4},
                                     {3, 4, 6, 6, 6, 6, 4, 3},
                                     {2, 3, 4, 4, 4, 4, 3, 2}};
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8]   = {-1, -2, -2, -1, 1, 2, 2, 1};
    int currentRow = 0, currentColumn = 0, moveNumber, moveNumber2, counter, minimum, minimum2, move;

    accessibility[currentRow][currentColumn] = 0;


    for (counter = 1; counter <= 63; counter++) {
        minimum = 8;
        minimum2 = 8;

        for (moveNumber = 0; moveNumber <= 7; moveNumber++) {
            currentRow += vertical[moveNumber];
            currentColumn += horizontal[moveNumber];

            if (currentRow >= 0 && currentColumn >= 0 && currentRow <= 7 && currentColumn <= 7)
                if (accessibility[currentRow][currentColumn] <= minimum && accessibility[currentRow][currentColumn] != 0) {
                    if (accessibility[currentRow][currentColumn] == minimum) {
                        for (moveNumber2 = 0; moveNumber2 <= 7; moveNumber2++) {
                            currentRow += vertical[moveNumber2];
                            currentColumn += horizontal[moveNumber2];

                            if (currentRow >= 0 && currentColumn >= 0 && currentRow <= 7 && currentColumn <= 7)
                                if (accessibility[currentRow][currentColumn] <= minimum2 && accessibility[currentRow][currentColumn] != 0) {
                                    move = moveNumber;
                                    minimum2 = accessibility[currentRow][currentColumn];
                                }

                            currentRow -= vertical[moveNumber2];
                            currentColumn -= horizontal[moveNumber2];
                        }
                    }
                    else {
                        move = moveNumber;
                        minimum = accessibility[currentRow][currentColumn];
                    }
                }

            currentRow -= vertical[moveNumber];
            currentColumn -= horizontal[moveNumber];
        }

        accessibility[currentRow][currentColumn] = 0;

        for (moveNumber = 0; moveNumber <= 7; moveNumber++) {
            currentRow += vertical[moveNumber];
            currentColumn += horizontal[moveNumber];

            if (currentRow >= 0 && currentColumn >= 0 && currentRow <= 7 && currentColumn <= 7 && accessibility[currentRow][currentColumn] != 0)
                --accessibility[currentRow][currentColumn];

            currentRow -= vertical[moveNumber];
            currentColumn -= horizontal[moveNumber];
        }

        currentRow += vertical[move];
        currentColumn += horizontal[move];

        board[currentRow][currentColumn] = counter;
    }

    printDesk(board, SIZE);

return 0;
}

void printDesk(int b[SIZE][SIZE], int size) {

    int i, j;

    for (i = 0; i <= size - 1; i++) {
        for (j = 0; j <= size - 1; j++)
            printf("%2d ", b[i][j]);

        printf("\n");
    }
}
