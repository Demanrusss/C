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
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);
void deleteNode(TREENODEPTR, int);

int main(void) {

    int i, item;
    TREENODEPTR rootPtr = NULL;

    srand(time(NULL));

    /*Trying to create a tree with 10 occasional numbers*/
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

    printf("\n\nEnter some value to find in the tree: ");
    scanf("%d", &item);
    deleteNode(rootPtr, item);

    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);

    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);

    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);

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

void deleteNode(TREENODEPTR treePtr, int value) {

    TREENODEPTR tempNodeForDeleting = NULL; //temporary node
    TREENODEPTR parentNode = NULL, childNode = NULL; // parenting node

/*Finding node to delete*/

    while (treePtr != NULL && treePtr->data != value) {
        parentNode = treePtr;

        if (treePtr->data < value)
            treePtr = treePtr->rightPtr;
        else
            treePtr = treePtr->leftPtr;
    }

    if (treePtr != NULL) {
        tempNodeForDeleting = treePtr;

        if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL) /* Just a lief */
            childNode = NULL;
        else
            if (treePtr->leftPtr != NULL && treePtr->rightPtr != NULL) {
                /* Looking for the node or lief with max value but less than parental*/
                TREENODEPTR tempForExchangeParent = treePtr;

                treePtr = treePtr->leftPtr;

                while (treePtr->rightPtr != NULL) {
                    tempForExchangeParent = treePtr;
                    treePtr = treePtr->rightPtr;
                }

                childNode = treePtr;

                childNode->rightPtr = tempNodeForDeleting->rightPtr;
                tempForExchangeParent->rightPtr = childNode->leftPtr;

                if (tempForExchangeParent != tempNodeForDeleting)
                    childNode->leftPtr = tempNodeForDeleting->leftPtr;
            }
            else {
                if (treePtr->leftPtr != NULL)
                    childNode = treePtr->leftPtr;
                else
                    childNode = treePtr->rightPtr;
            }

        if (parentNode->leftPtr == tempNodeForDeleting)
            parentNode->leftPtr = childNode;
        else
            parentNode->rightPtr = childNode;
    }

    free(tempNodeForDeleting);
}
