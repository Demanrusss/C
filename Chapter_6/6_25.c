#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

int set(void);
void printDesk(int [SIZE][SIZE], int);

int main() {

    int i, j, count = 0;
    int results[64] = {0};

    srand(time(NULL));

//    for (i = 0; i <= 10000; i++)
//        ++results[set()];

    do {
        count = set();
        ++results[count];
    } while (count != 63);

    for (i = 1; i <= 25; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 1; i <= 25; i++)
        printf("%4d", results[i]);

    printf("\n\n");

    for (i = 26; i <= 50; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 26; i <= 50; i++)
        printf("%4d", results[i]);

    printf("\n\n");

    for (i = 51; i <= 63; i++)
        printf("%4d", i);

    printf("\n");

    for (i = 51; i <= 63; i++)
        printf("%4d", results[i]);

    printf("\n");

return 0;
}

int set(void) {

    int board[SIZE][SIZE] = {0};
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8]   = {-1, -2, -2, -1, 1, 2, 2, 1};
    int currentRow = 0, currentColumn = 0, moveNumber, counter, move, i;

    for (counter = 1; counter <= 63; counter++) {
        move = 0;

        for (i = 0; i <= 10; i++) {
            moveNumber = rand() % 8;

            currentRow += vertical[moveNumber];
            currentColumn += horizontal[moveNumber];

            if (currentRow >= 0 && currentColumn >= 0 && currentRow <= 7 && currentColumn <= 7 && board[currentRow][currentColumn] == 0) {
                board[currentRow][currentColumn] = counter;
                move = 1;
                i = 10 + 1;
            }
            else {
                currentRow -= vertical[moveNumber];
                currentColumn -= horizontal[moveNumber];
            }
        }

        if (move == 0) {
//            printDesk(board, SIZE);
            return counter - 1;
        }
    }
}

void printDesk(int b[SIZE][SIZE], int size) {

    int i, j;

    for (i = 0; i <= size - 1; i++) {
        for (j = 0; j <= size - 1; j++)
            printf("%2d ", b[i][j]);

        printf("\n");
    }
}
