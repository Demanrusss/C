#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct numbers {
    int integer;
    struct numbers *nextPtr;
};

typedef struct numbers NUMBERS;
typedef NUMBERS *NUMBERSPTR;

void insert(NUMBERSPTR *, int);
void printOut(NUMBERSPTR);
NUMBERSPTR merge(NUMBERSPTR, NUMBERSPTR);

int main() {

    NUMBERSPTR node1Ptr = NULL, node2Ptr = NULL;
    int value;

    //Filling in first list
    printf("Enter some integer from 0 to 32000: ");
    for (int i = 0; i <= SIZE - 1; i++) {
        scanf("\n%d", &value);
        insert(&node1Ptr, value);
    }

    //Filling in second list
    printf("Enter some integer from 0 to 32000: ");
    for (int i = 0; i <= SIZE - 1; i++) {
        scanf("\n%d", &value);
        insert(&node2Ptr, value);
    }

    printf("\nFirst list is:\n");
    printOut(node1Ptr);
    printf("\nSecond list is:\n");
    printOut(node2Ptr);

    printf("First list as a union:\n");
    printOut(merge(node1Ptr, node2Ptr));

return 0;
}

void insert(NUMBERSPTR *iPtr, int num) {

    NUMBERSPTR newPtr, currentPtr, previousPtr;

    newPtr = malloc(sizeof(NUMBERS));

    if (newPtr != NULL) {
        newPtr->integer = num;
        newPtr->nextPtr = NULL;

        currentPtr = *iPtr;
        previousPtr = NULL;

        while (currentPtr != NULL && currentPtr->integer < num) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL) {
            newPtr->nextPtr = *iPtr;
            *iPtr = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf("\nThere is no memory for create new node.\n");
}

void printOut(NUMBERSPTR iPtr) {

    while (iPtr != NULL) {
        printf("%d -> ", iPtr->integer);
        iPtr = iPtr->nextPtr;
    }

    printf("\n");
}

NUMBERSPTR merge(NUMBERSPTR iPtr, NUMBERSPTR jPtr) {

    while (jPtr != NULL) {
        insert(&iPtr, jPtr->integer);
        jPtr = jPtr->nextPtr;
    }

return iPtr;
}
