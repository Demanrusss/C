#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stackSymbols {
    char symbol;
    struct stackSymbols *nextPtr;
};

typedef struct stackSymbols SYMBOLS;
typedef SYMBOLS *SYMBOLSPTR;

void push(SYMBOLSPTR *, char);
void printStack(SYMBOLSPTR);
int palindrome(SYMBOLSPTR *, int);

int main() {

    SYMBOLSPTR stackPtr = NULL;
    char sentence[100] = {0};
    int elements = 0;

    printf("Enter some sentence (max 100 symbols): ");
    gets(sentence);

    for (int i = 0; sentence[i] != '\0'; i++)
        if (sentence[i] >= 65 && sentence[i] <= 122) {
            push(&stackPtr, sentence[i]);
            ++elements;
        }

    printStack(stackPtr);

    if (palindrome(&stackPtr, elements) == 1)
        printf("\nYour sentence is a palindrome.\n");
    else
        printf("\nYour sentence is not a palindrome.\n");

return 0;
}

void push(SYMBOLSPTR *sPtr, char c) {

    SYMBOLSPTR newPtr;

    newPtr = malloc(sizeof(SYMBOLS));

    if (newPtr != NULL) {
        newPtr->symbol = c;
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
    else
        printf("\nThere is no memory available.\n");
}

void printStack(SYMBOLSPTR sPtr) {

    while (sPtr != NULL) {
        printf("%c -> ", sPtr->symbol);
        sPtr = sPtr->nextPtr;
    }

    printf("NULL\n\n");
}

int palindrome(SYMBOLSPTR *sPtr, int e) {

    SYMBOLSPTR firstPtr = *sPtr, lastPtr = *sPtr, previousPtr = NULL;

    for (int i = 0; i <= e / 2 - 1; i++) {
        firstPtr = *sPtr;

        for (int j = 0; j < i; j++)
            firstPtr = firstPtr->nextPtr;

        lastPtr = *sPtr;

        for (int j = 0; j <= e - i - 2; j++)
            lastPtr = lastPtr->nextPtr;

        if (firstPtr->symbol == lastPtr->symbol)
            ;
        else
            return 0;
    }

return 1;
}
