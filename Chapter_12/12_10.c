#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct symbols {
    char symbol;
    struct symbols *nextPtr;
};

typedef struct symbols SYMBOLS;
typedef SYMBOLS *SYMBOLSPTR;

void insert(SYMBOLSPTR *, char);
void printOut(SYMBOLSPTR);

int main() {

    SYMBOLSPTR startPtr = NULL;
    char sentence[SIZE] = {0}, character;

    printf("Enter some sentence (less than 100 symbols): ");
    gets(sentence);

    for (int i = 0; sentence[i] != '\0'; i++)
        insert(&startPtr, sentence[i]);

    printOut(startPtr);

return 0;
}

void insert(SYMBOLSPTR *sPtr, char c) {

    SYMBOLSPTR newPtr, currentPtr, prevoiusPtr;

    newPtr = malloc(sizeof(SYMBOLS));

    if (newPtr != NULL) {
        newPtr->symbol = c;
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
    else
        printf("\nThere is no memory available.\n");
}

void printOut(SYMBOLSPTR sPtr) {

    while (sPtr != NULL) {
        printf("%c", sPtr->symbol);
        sPtr = sPtr->nextPtr;
    }
}
