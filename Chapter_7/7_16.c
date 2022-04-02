#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void shuffle(int [][13]);
void printArray(const int [][13]);
void deal(const int [][13], const char *[], const char *[], int *, int);

int main(void) {

    char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[4][13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                      14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                      27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                      40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
    int card = 1, quantity = 5;
    int player[SIZE] = {0};
    int *cardPtr = &card;

    srand(time(NULL));
    shuffle(deck);
    printArray(deck);

    deal(deck, (const char **) face, (const char **) suit, cardPtr, quantity);

return 0;
}

void shuffle(int wDeck[][13]) {

    int row, column, r, c, hold;

    for (row = 0; row <= 4 - 1; row++)
        for (column = 0; column <= 13 - 1; column++) {
            r = rand() % 4;
            c = rand() % 13;

            hold = wDeck[row][column];
            wDeck[row][column] = wDeck[r][c];
            wDeck[r][c] = hold;
    }
}

void printArray(const int wDeck[][13]) {

    int row, column;

    for (row = 0; row <= 4 - 1; row++) {
        for (column = 0; column <= 13 - 1; column++)
            printf("%d ", wDeck[row][column]);

        printf("\n");
    }

}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], int *wCardPtr, int wQuantity){

    int row, column;

    for (; *wCardPtr <= wQuantity; (*wCardPtr)++)
        for (row = 0; row <= 3; row++)
            for (column = 0; column <= 12; column++)
                if (wDeck[row][column] == *wCardPtr) {
                    printf("%5s of %-8s\n", wFace[column], wSuit[row]);
                    row = 3 + 1;
                    column = 12 +1;
                }
}
