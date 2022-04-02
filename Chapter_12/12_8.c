#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

struct numbers {
    int integer;
    struct numbers *nextPtr;
};

typedef struct numbers NUMBERS;
typedef NUMBERS *NUMBERSPTR;

void insert(NUMBERSPTR *, int);
void printOut(NUMBERSPTR);
void sumAndAverage(NUMBERSPTR);

int main() {

    NUMBERSPTR listPtr = NULL;
    int value;

    srand(time(NULL));

    for (int i = 0; i <= SIZE - 1; i++) {
        value = rand() % 101;
        insert(&listPtr, value);
    }

    printf("Our list containing of 25 random integers is:\n");
    printOut(listPtr);

    sumAndAverage(listPtr);

return 0;
}

void insert(NUMBERSPTR *iPtr, int num) {

    NUMBERSPTR currentPtr = *iPtr, previousPtr = NULL, newPtr;

    newPtr = malloc(sizeof(NUMBERS));

    if (newPtr != NULL) {
        newPtr->integer = num;

        while (currentPtr != NULL && currentPtr->integer < num) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL) {
            newPtr->nextPtr = currentPtr;
            *iPtr = newPtr;
        }
        else {
            newPtr->nextPtr = currentPtr;
            previousPtr->nextPtr = newPtr;
        }
    }
    else
        printf("\nThere is no memory available.\n");
}

void printOut(NUMBERSPTR iPtr) {

    while (iPtr != NULL) {
        printf("%d -> ", iPtr->integer);
        iPtr = iPtr->nextPtr;
    }
}

void sumAndAverage(NUMBERSPTR iPtr) {

    int sum = 0;
    float average = 0;

    while (iPtr != NULL) {
        sum += iPtr->integer;
        iPtr = iPtr->nextPtr;
    }

    average = (float) sum / SIZE;

    printf("\nSum of 25 elements above is %d.\n", sum);
    printf("Average of 25 elements is %.2f.\n", average);
}
