/* Пример применения  битовых полей*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bitCard {
    unsigned face : 4;
    unsigned suit : 2;
    unsigned colour : 1;
};

typedef struct bitCard Card;

void fillDeck(Card *);
void shuffle(Card *);
void deal(Card *);

int main() {

    Card deck[52];

    srand(time(NULL));

    fillDeck(deck);
    shuffle(deck);
    deal(deck);

return 0;
}

void fillDeck(Card *wDeck) {

    for (int i = 0; i < 52; i++) {
        wDeck[i].face = i % 13;
        wDeck[i].suit = i / 13;
        wDeck[i].colour = i / 26;
    }
}

void shuffle(Card *wDeck) {

    int j;
    Card temp;

    for (int i = 0; i < 52; i++) {
        j = rand() % 52;

        temp = wDeck[j];
        wDeck[j] = wDeck[i];
        wDeck[i] = temp;
    }
}

void deal(Card *wDeck) {

    int k1, k2;

    for (k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++) {
        printf("Colour:%2d  Card:%3d  Suit:%2d    ",
               wDeck[k1].colour, wDeck[k1].face, wDeck[k1].suit);
        printf("Colour:%2d  Card:%3d  Suit:%2d\n",
               wDeck[k2].colour, wDeck[k2].face, wDeck[k2].suit);
    }
}
