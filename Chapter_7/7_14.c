#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[], int *, int, int [][SIZE]);
void sorting(int [][SIZE]);
int costOfPlayersCards(const int [][SIZE]);
int couple(const int [][SIZE]);
int twoCouples(const int [][SIZE]);
int triple(const int [][SIZE]);
int quads(const int [][SIZE]);
int flash(const int [][SIZE]);
int street(const int [][SIZE]);
void showCards(const char *[], const char *[], const int [][SIZE]);
int analizingCards(int [][SIZE], const int);

int main(void) {

    char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[4][13] = {0}, card = 1, quantity = 5, costOfCards1 = 0, costOfCards2 = 0;
    int player1[2][SIZE] = {0}, player2[2][SIZE] = {0};
    int *cardPtr = &card;
    int i, numberOfCard;

    srand(time(NULL));
    shuffle(deck);

    deal(deck, (const char **) face, (const char **) suit, cardPtr, quantity, player1);
    printf("Card1\nCard2\nCard3\nCard4\nCard5\n\n");

    deal(deck, (const char **) face, (const char **) suit, cardPtr, quantity, player2);
    showCards((const char **) face, (const char **) suit, player2);

    costOfCards1 = costOfPlayersCards(player1);
    costOfCards2 = costOfPlayersCards(player2);

    if (costOfCards1 > costOfCards2)
        printf("\nPlayer1's cards are better than Player2's cards!\n");
    else
        if (costOfCards1 < costOfCards2)
            printf("\nPlayer2's cards are better than Player1's cards!\n");
        else
            printf("\nBoth players' cards are equal!\n");

    printf("\nDude, how much cards would you like to change (maximum - 3): ");
    do {
        scanf("%d", &quantity);

    } while (quantity < 0 && quantity > 3);

    if (quantity != 0) {
        printf("Now, tell me what numbers are they (1-5): ");

        for (i = 0; i <= quantity - 1; i++) {
            scanf("%d", &numberOfCard);

            if (numberOfCard >= 1 && numberOfCard <= 5 && player2[0][numberOfCard - 1] != -1)
                player2[0][numberOfCard - 1] = -1;
            else {
                printf("There are two ways: you tried to change either nonexistent card or already chosen card.\nTry again!\n");
                --i;
            }
        }
    }
    printf("\nOK, buddy! Now it's my turn!\nLet me think what can I do with my cards...\n");

    sorting(player1);
    quantity = analizingCards(player1, costOfCards1);
    printf("\nHey, it looks like I'm gonna change %d of my cards.\n", quantity);
    printf("They are: ");
    for (i = 0; i <= SIZE - 1; i++)
        if (player1[0][i] == -1)
            printf("%d   ", i + 1);

    deal(deck, (const char **) face, (const char **) suit, cardPtr, quantity, player1);
    showCards((const char **) face, (const char **) suit, player1);

    costOfCards1 = costOfPlayersCards(player1);

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

    int row, column, i, j;

    for (i = 0; i <= wQuantity - 1; i++) {
        for (row = 0; row <= 3; row++)
            for (column = 0; column <= 12; column++)
                if (wDeck[row][column] == *wCardPtr) {
                    if (wQuantity <= 3) {
                        for (j = 0; j <= SIZE - 1; j++)
                            if (wPlayer[0][j] == -1) {
                                wPlayer[0][j] = row;
                                wPlayer[1][j] = column;
                                break;
                            }
                    }
                    else {
                        wPlayer[0][i] = row;
                        wPlayer[1][i] = column;
                    }
                }
        ++(*wCardPtr);
    }

    printf("\n");
}

void sorting(int wPlayer[][SIZE]) {

    int i, j, min, holdSuit, holdFace;

    for (i = 0; i <= SIZE - 2; i++) {
        min = i;

        for (j = i + 1; j <= SIZE - 1; j++)
            if (wPlayer[1][min] > wPlayer[1][j])
                min = j;

        if (wPlayer[1][i] > wPlayer[1][min]) {
            holdSuit = wPlayer[0][i];
            holdFace = wPlayer[1][i];
            wPlayer[0][i] = wPlayer[0][min];
            wPlayer[1][i] = wPlayer[1][min];
            wPlayer[0][min] = holdSuit;
            wPlayer[1][min] = holdFace;
        }
    }
}

int costOfPlayersCards(const int wPlayer[][SIZE]) {

    int cost = 0;

    if ((cost = street(wPlayer)) == 0)
        if ((cost = flash(wPlayer)) == 0)
            if ((cost = quads(wPlayer)) == 0)
                if ((cost = triple(wPlayer)) == 0)
                    if ((cost = twoCouples(wPlayer)) == 0)
                        if ((cost = couple(wPlayer)) == 0)
                            ;
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

    int i, counter = 0, cost;

    for (i = 0; i <= SIZE - 2; i++)
        if (wPlayer[1][i] == wPlayer[1][i + 1]) {
            ++counter;
            cost = wPlayer[1][i];
        }

    if (counter == 3)
        return 400 + cost;

 return 0;
}

int flash(const int wPlayer[][SIZE]) {

    int i, max = 0;

    for (i = 0; i <= SIZE - 2; i++)
        if (wPlayer[0][i] != wPlayer[0][i + 1])
            return 0;

    for (i = 0; i <= SIZE - 1; i++)
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

        if (array[i] > array[min]) {
            hold = array[i];
            array[i] = array[min];
            array[min] = hold;
        }
    }

// Main action to find if the array is street

    for (i = 0; i <= SIZE - 2; i++)
        if (array[i + 1] - array[i] != 1)
            return 0;

return 600 + array[SIZE - 1];
}

void showCards(const char *wFace[], const char *wSuit[], const int wPlayer[][SIZE]) {

    int i;

    for (i = 0; i <= SIZE - 1; i++)
        printf("%5s of %-8s\n", wFace[wPlayer[1][i]], wSuit[wPlayer[0][i]]);

}

int analizingCards(int wPlayer[][SIZE], const int wCost) { // Use only after sorting!

    int i, count;

    if (wCost >= 400 && wCost < 500) {                      //Player has quads
        count = 1;

        for (i = 0; i <= SIZE - 1; i++)
            if (wPlayer[1][i] != (wCost - 400)) {
                wPlayer[0][i] = -1;
                return count;
            }
    }

    if (wCost >= 300 && wCost < 400) {                      //Player has triple
        count = 2;

        for (i = 0; i <= SIZE - 1; i++)
            if (wPlayer[1][i] != (wCost - 300))
                wPlayer[0][i] = -1;

        return count;
    }

    if (wCost >= 200 && wCost < 300) {                      //Player has two couples
        count = 1;

        if (wPlayer[1][0] != wPlayer[1][1] && wPlayer[1][1] == wPlayer[1][2]) {
            wPlayer[0][0] = -1;
            return count;
        }

        if (wPlayer[1][2] != wPlayer[1][3] && wPlayer[1][3] == wPlayer[1][4]) {
            wPlayer[0][2] = -1;
            return count;
        }

        wPlayer[0][4] = -1;
        return count;
    }

    if (wCost >= 100 && wCost < 200) {                      //Player has a couple
        count = 3;

        for (i = 0; i <= SIZE - 1; i++)
            if (wPlayer[1][i] != wPlayer[1][i + 1])
                wPlayer[0][i] = -1;
            else
                ++i;

        if (wPlayer[1][SIZE - 2] != wPlayer[1][SIZE - 1])
            wPlayer[0][SIZE - 1] = -1;

        return count;
    }

    if (wCost < 100) {
        count = 3;

        for (i = 0; i <= count - 1; i++)
            wPlayer[0][i] = -1;

        return count;
    }

return 0;
}
