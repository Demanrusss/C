#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct symbolNode {
    char symbol;
    struct symbolNode *nextPtr;
};

typedef struct symbolNode SYMBOLNODE;
typedef SYMBOLNODE *SYMBOLNODEPTR;

void insert(SYMBOLNODEPTR *, char);
void concatenate(SYMBOLNODEPTR *, SYMBOLNODEPTR *);
void printNode(SYMBOLNODEPTR);
void printListBackwards(SYMBOLNODEPTR);
int searchList(SYMBOLNODEPTR);

int main() {

    SYMBOLNODEPTR node1Ptr = NULL, node2Ptr = NULL;
    char letter;

    printf("Enter %d letters in overall for node 1: ", SIZE);
    for (int i = 0; i <= SIZE - 1; i++) {
        scanf("\n%c", &letter);

        insert(&node1Ptr, letter);
    }

    printf("Enter %d letters in overall for node 2: ", SIZE);
    for (int i = 0; i <= SIZE - 1; i++) {
        scanf("\n%c", &letter);

        insert(&node2Ptr, letter);
    }

    printf("\nWhat we have in a node 1: ");
    printNode(node1Ptr);

    printf("\nWhat we have in a node 2: ");
    printNode(node2Ptr);

    concatenate(&node1Ptr, &node2Ptr);
    printf("\nAfter concatenation we have a node 1: ");
    printNode(node1Ptr);

    printf("\nNode1 in backwards is: ");
    printListBackwards(node1Ptr);

    printf("\nEnter a char to seek: ");
    printf("The position of your char has been found in %d", searchList(node1Ptr));

return 0;
}

void insert(SYMBOLNODEPTR *sPtr, char value) {

    SYMBOLNODEPTR newNodePtr, previousPtr, currentPtr;

    newNodePtr = malloc(sizeof(SYMBOLNODE));

    if (newNodePtr != NULL) {
        newNodePtr->symbol = value;
        newNodePtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while (currentPtr != NULL && currentPtr->symbol < value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL) {
            newNodePtr->nextPtr = currentPtr;
            *sPtr = newNodePtr;
        }
        else {
            previousPtr->nextPtr = newNodePtr;
            newNodePtr->nextPtr = currentPtr;
        }
    }
    else
        printf("No memory available.\n");
}

void printNode(SYMBOLNODEPTR sPtr) {

    while (sPtr != NULL) {
        printf("%c -> ", sPtr->symbol);
        sPtr = sPtr->nextPtr;
    }
}

void concatenate(SYMBOLNODEPTR *destinationPtr, SYMBOLNODEPTR *sourcePtr) {

    SYMBOLNODEPTR currentPtr, previousPtr, newPtr;
    SYMBOLNODEPTR sPtr = *sourcePtr;

    while (sPtr != NULL) {
        newPtr = malloc(sizeof(SYMBOLNODE));

        if (newPtr != NULL) {
            currentPtr = *destinationPtr;
            previousPtr = NULL;

            while (currentPtr != NULL) {
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
            }

            newPtr->symbol = sPtr->symbol;
            newPtr->nextPtr = NULL;

            previousPtr->nextPtr = newPtr;
            sPtr = sPtr->nextPtr;
        }
        else
            printf("\nSorry. There is no memory.\n");
    }
}

void printListBackwards(SYMBOLNODEPTR sPtr) {

    if (sPtr == NULL)
        ;
    else {
        printListBackwards(sPtr->nextPtr);
        printf("%c -> ", sPtr->symbol);
    }
}
