#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertNode(TREENODEPTR *, int);
int binaryTreeSearch(TREENODEPTR, int);

int main(void) {

    int i, item;
    TREENODEPTR rootPtr = NULL, pointerResult = NULL;

//    srand(time(NULL));

    /*Trying to create a tree with 10 occasional numbers*/
    printf("The numbers being placed in the tree are:\n");

    printf("%3d", 7);
    insertNode(&rootPtr, 7);
    printf("%3d", 4);
    insertNode(&rootPtr, 4);
    printf("%3d", 2);
    insertNode(&rootPtr, 2);
    printf("%3d", 6);
    insertNode(&rootPtr, 6);
    printf("%3d", 1);
    insertNode(&rootPtr, 1);
    printf("%3d", 3);
    insertNode(&rootPtr, 3);
    printf("%3d", 5);
    insertNode(&rootPtr, 5);
    printf("%3d", 10);
    insertNode(&rootPtr, 10);
    printf("%3d", 8);
    insertNode(&rootPtr, 8);
    printf("%3d", 13);
    insertNode(&rootPtr, 13);
    printf("%3d", 9);
    insertNode(&rootPtr, 9);
    printf("%3d", 12);
    insertNode(&rootPtr, 12);
    printf("%3d", 14);
    insertNode(&rootPtr, 14);

 /*   for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    } */

    printf("\n\nEnter some value to find in the tree: ");
    scanf("%d", &item);

    pointerResult = binaryTreeSearch(rootPtr, item);

    if (pointerResult == NULL)
        printf("\n\n Your item %d is not found\n", item);
    else
        printf("\n\n Your item %d is found in address: %p", item, pointerResult);


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

int binaryTreeSearch(TREENODEPTR treePtr, int value) {

    TREENODEPTR resultPtr = NULL;

    while (treePtr != NULL && treePtr->data != value) {

        if (treePtr->data < value)
            treePtr = treePtr->rightPtr;
        else
            treePtr = treePtr->leftPtr;
    }

    if (treePtr != NULL && treePtr->data == value)
        resultPtr = treePtr;

return resultPtr;
}
