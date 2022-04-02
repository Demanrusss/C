#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[], int *, int);
void sort(int [][5], int);
int couple(const int [][5], int);
int twoCouples(const int [][5], int);
int triple(const int [][5], int);
int quads(const int [][5], int);
int flash(const int [][5], int);
int street(const int [][5], int);

int main(void) {

    char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[4][13] = {0}, card = 0, quantity = 5;
    int player[SIZE] = {0};
    int *cardPtr = &card;

    srand(time(NULL));
    shuffle(deck);

    deal(deck, face, suit, cardPtr, quantity);

return 0;
}

void shuffle(int wDeck[][13]) {

    int card, row, column;

    for (card = 1; card <= 52; card++) {
        row = rand() % 4;
        column = rand() % 13;

        while (wDeck[row][column] != 0) {
            row = rand() % 4;
            column = rand() % 13;
        }

        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], int *wCardPtr, int wQuantity){

    int row, column;

    for (; *wCardPtr <= wQuantity; (*wCardPtr)++)
        for (row = 0; row <= 3; row++)
            for (column = 0; column <= 12; column++)
                if (wDeck[row][column] == *wCardPtr)
                    printf("%5s of %-8s\n", wFace[column], wSuit[row]);
}

int couple(const int wPlayer[][5], int size) {

    int i, j;

    for (i = 0; i <= size - 2; i++)
        for (j = i + 1; j <= size - 1; j++)
            if (wPlayer[1][i] == wPlayer[1][j])
                return 1;

 return 0;
}

int twoCouples(const int wPlayer[][5], int size) {

    int i, j, counter = 0;

    for (i = 0; i <= size - 2; i++)
        for (j = i + 1; j <= size - 1; j++)
            if (wPlayer[1][i] == wPlayer[1][j]) {
                ++counter;
                break;
            }

    if (counter == 2)
        return 1;

 return 0;
}

int triple(const int wPlayer[][5], int size) {

    int i, j, k, counter = 0;

    for (i = 0; i <= size - 2; i++)
        for (j = i + 1; j <= size - 1; j++)
            for (k = j + 1; k <= 4; k++)
                if (wPlayer[1][i] == wPlayer[1][j] == wPlayer[1][k])
                    return 1;

 return 0;
}

int quads(const int wPlayer[][5], int size) {

    int i, j, counter = 0;

    for (i = 0; i <= size - 2; i++)
        if (wPlayer[1][i] != wPlayer[1][i + 1])
            ++counter;

    if (counter == 2)
        return 1;

 return 0;
}

int flash(const int wPlayer[][5], int size) {

    int i;

    for (i = 0; i <= size - 2; i++)
        if (wPlayer[0][i] != wPlayer[0][i + 1])
            return 0;

 return 1;
}

int street(const int wPlayer[][5], int size) {

    int i, j, hold, min;
    int array[SIZE] = {0};

// Copy info about cards to array

    for (i = 0; i <= size - 1; i++)\
        array[i] = wPlayer[1][i];

// Sorting array

    for (i = 0; i <= size - 2; i++) {
        min = i;

        for (j = i + 1; j <= size - 1; j++)
            if (array[min] > array[j])
                min = j;

        array[i] = hold;
        array[i] = array[j];
        array[j] = hold;
    }

// Main action to find if the array is street

    for (i = 0; i <= size - 2; i++)
        if (array[i + 1] - array[i] != 1)
            return 0;

return 1;
}
