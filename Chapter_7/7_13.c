#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[], int *, int, int [][SIZE]);
int costOfPlayersCards(const int [][SIZE]);
int couple(const int [][SIZE]);
int twoCouples(const int [][SIZE]);
int triple(const int [][SIZE]);
int quads(const int [][SIZE]);
int flash(const int [][SIZE]);
int street(const int [][SIZE]);

int main(void) {

    char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[4][13] = {0}, card = 1, quantity = 5, costOfCards1 = 0, costOfCards2 = 0;
    int player1[2][SIZE] = {0}, player2[2][SIZE] = {0};
    int *cardPtr = &card;

    srand(time(NULL));
    shuffle(deck);

    deal(deck, (const char **) face, (const char **) suit, cardPtr, quantity, player1);
    deal(deck, (const char **) face, (const char **) suit, cardPtr, quantity, player2);

    costOfCards1 = costOfPlayersCards(player1);
    costOfCards2 = costOfPlayersCards(player2);

    if (costOfCards1 > costOfCards2)
        printf("\nPlayer1's cards are better than Player2's cards!\n");
    else
        if (costOfCards1 < costOfCards2)
            printf("\nPlayer2's cards are better than Player1's cards!\n");
        else
            printf("\nBoth players' cards are equal!\n");

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

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], int *wCardPtr, int wQuantity, int wPlayer[][SIZE]){

    int row, column, i;

    for (i = 0; i <= wQuantity - 1; i++) {
        for (row = 0; row <= 3; row++)
            for (column = 0; column <= 12; column++)
                if (wDeck[row][column] == *wCardPtr) {
                    printf("%5s of %-8s\n", wFace[column], wSuit[row]);
                    wPlayer[0][i] = row;
                    wPlayer[1][i] = column;
                }
        ++(*wCardPtr);
    }

    printf("\n");
}

int costOfPlayersCards(const int wPlayer[][SIZE]) {

    int cost = 0;

    if ((cost = street(wPlayer)) == 0)
        if ((cost = flash(wPlayer)) == 0)
            if ((cost = quads(wPlayer)) == 0)
                if ((cost = triple(wPlayer)) == 0)
                    if ((cost = twoCouples(wPlayer)) == 0)
                        if ((cost = couple(wPlayer)) == 0)
 return cost;
}

int couple(const int wPlayer[][SIZE]) {

    int i, j;

    for (i = 0; i <= SIZE - 2; i++)
        for (j = i + 1; j <= SIZE - 1; j++)
            if (wPlayer[1][i] == wPlayer[1][j])
                return 100 + wPlayer[1][i];

 return 0;
}

int twoCouples(const int wPlayer[][SIZE]) {

    int i, j, counter = 0, sumOfCouples = 0;

    for (i = 0; i <= SIZE - 2; i++)
        for (j = i + 1; j <= SIZE - 1; j++)
            if (wPlayer[1][i] == wPlayer[1][j]) {
                ++counter;
                sumOfCouples += wPlayer[1][i];
                break;
            }

    if (counter == 2)
        return 200 + sumOfCouples;

 return 0;
}

int triple(const int wPlayer[][SIZE]) {

    int i, j, k;

    for (i = 0; i <= SIZE - 2; i++)
        for (j = i + 1; j <= SIZE - 1; j++)
            for (k = j + 1; k <= 4; k++)
                if (wPlayer[1][i] == wPlayer[1][j] && wPlayer[1][j] == wPlayer[1][k])
                    return 300 + wPlayer[1][i];

 return 0;
}

int quads(const int wPlayer[][SIZE]) {

    int i, counter = 0;

    for (i = 0; i <= SIZE - 2; i++)
        if (wPlayer[1][i] != wPlayer[1][i + 1])
            ++counter;

    if (counter == 2)
        return 400 + wPlayer[1][i];

 return 0;
}

int flash(const int wPlayer[][SIZE]) {

    int i, max = 0;

    for (i = 0; i <= SIZE - 2; i++)
        if (wPlayer[0][i] != wPlayer[0][i + 1])
            return 0;

    for (i = 0; i <= SIZE - 2; i++)
        if (wPlayer[1][i] > max)
            max = wPlayer[1][i];

 return 500 + max;
}

int street(const int wPlayer[][SIZE]) {

    int i, j, hold, min;
    int array[SIZE] = {0};

// Copy info about cards to array

    for (i = 0; i <= SIZE - 1; i++)
        array[i] = wPlayer[1][i];

// Sorting array

    for (i = 0; i <= SIZE - 2; i++) {
        min = i;

        for (j = i + 1; j <= SIZE - 1; j++)
            if (array[min] > array[j])
                min = j;

        hold = array[i];
        array[i] = array[j];
        array[j] = hold;
    }

// Main action to find if the array is street

    for (i = 0; i <= SIZE - 2; i++)
        if (array[i + 1] - array[i] != 1)
            return 0;

return 600 + array[SIZE - 1];
}
