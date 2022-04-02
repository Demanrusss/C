#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

struct queueNode {
    int data;
    struct queueNode *nextPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

void insertNode(TREENODEPTR *, int);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);
void levelOrder(TREENODEPTR);
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, int);
int dequeue(QUEUENODEPTR *, QUEUENODEPTR *);

int main(void) {

    int i, item;
    TREENODEPTR rootPtr = NULL;

//    srand(time(NULL));

    printf("The numbers being placed in the tree are:\n");

    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);

    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);

    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);

    printf("\n\nThe traversal by levels is:\n");
    levelOrder(rootPtr);

return 0;
}

void insertNode(TREENODEPTR *treePtr, int value) {

    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TREENODE));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("%d not inserted. There is no memory available.\n", value);
    }
    else {
        if (value < (*treePtr)->data)
            insertNode(&((*treePtr)->leftPtr), value);
        else
            if (value > (*treePtr)->data)
                insertNode(&((*treePtr)->rightPtr), value);
            else
                printf("dup");
    }
}

void inOrder(TREENODEPTR treePtr) {

    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TREENODEPTR treePtr) {

    if (treePtr != NULL) {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TREENODEPTR treePtr) {

    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}

void levelOrder(TREENODEPTR treePtr) {

    QUEUENODEPTR headPtr = NULL, tailPtr = NULL;
    int value;

    if (treePtr != NULL) {
        enqueue(&headPtr, &tailPtr, treePtr->data);

        while (headPtr != NULL) {
            value = dequeue(&headPtr, &tailPtr);
            printf("%3d", value);

            if (treePtr->leftPtr != NULL)
                enqueue(&headPtr, &tailPtr, (treePtr->leftPtr)->data);

            if (treePtr->rightPtr != NULL)
                enqueue(&headPtr, &tailPtr, (treePtr->rightPtr)->data);
        }
    }
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, int value) {

    QUEUENODEPTR newPtr;

    newPtr = malloc(sizeof(QUEUENODE));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if (*headPtr == NULL)
            *headPtr = newPtr;
        else
            (*tailPtr)->nextPtr = newPtr;

        *tailPtr = newPtr;
    }
    else
        printf("%d is not inserted. No memory available.\n", value);
}

int dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr) {

    int value;
    QUEUENODEPTR tempPtr;

    value = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL)
        *tailPtr = NULL;

    free(tempPtr);

return value;
}
