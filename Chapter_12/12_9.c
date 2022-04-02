#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct symbols {
    char letter;
    struct symbols *nextPtr;
};

typedef struct symbols SYMBOLS;
typedef SYMBOLS *SYMBOLSPTR;

void insert(SYMBOLSPTR *, char);
void printOut(SYMBOLSPTR);

int main() {

    SYMBOLSPTR startPtr = NULL;
    char a;

    printf("Please, enter 10 symbols for creating a list: ");

    for (int i = 0; i <= SIZE - 1; i++) {
        scanf("\n%c", &a);
        insert(&startPtr, a);
        }

    printOut(startPtr);

return 0;
}

void insert(SYMBOLSPTR *sPtr, char c) {

    SYMBOLSPTR newPtr, previousPtr = NULL, currentPtr = *sPtr;

    newPtr = malloc(sizeof(SYMBOLS));

    if (newPtr != NULL) {
        while (currentPtr != NULL) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        newPtr->letter = c;
        newPtr->nextPtr = NULL;

        if (previousPtr == NULL) {
            newPtr->nextPtr = currentPtr;
            (*sPtr) = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf("There is no memory available.\n");
}

void printOut(SYMBOLSPTR sPtr) {

    while (sPtr != NULL) {
        printf("%c -> ", sPtr->letter);
        sPtr = sPtr->nextPtr;
    }
}
