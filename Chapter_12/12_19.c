/* Создание двоичного дерева для слов из строки и его обход
 с порядковой, предварительной и отложенной выборкой */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr;
    char *string;
    struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertNode(TREENODEPTR *, char *);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);
int depth(TREENODEPTR);

int main() {

    char array[100];
    char *word;
    TREENODEPTR rootPtr = NULL;

    printf("Enter some sentence.\n? ");
    gets(array);

    word = strtok(array, " ");
    while (word != NULL) {
        insertNode(&rootPtr, word);
        word = strtok(NULL, " ");
    }

    /*обход дерева с предварительной выборкой*/
    printf("\n\nThe preorder traversal is:\n");
    preOrder(rootPtr);

    /*обход дерева с порядковой выборкой*/
    printf("\n\nThe inorder traversal is:\n");
    inOrder(rootPtr);

    /*обход дерева с отложенной выборкой*/
    printf("\n\nThe postorder traversal is:\n");
    postOrder(rootPtr);

    /*Определение глубины двоичного дерева*/
    printf("\n\nThe depth of binary tree is %d", depth(rootPtr));

return 0;
}

void insertNode(TREENODEPTR *treePtr, char *value) {

    if (*treePtr == NULL) {                         /* *treePtr равен NULL */
        *treePtr = malloc(sizeof(TREENODE));

        if (*treePtr != NULL) {
            (*treePtr)->string = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("There is no memory available.\n");
    }
    else
        if ((*treePtr)->leftPtr == NULL)
            insertNode(&((*treePtr)->leftPtr), value);
        else
            if ((*treePtr)->rightPtr == NULL)
                insertNode(&((*treePtr)->rightPtr), value);
            else
                insertNode(&((*treePtr)->leftPtr), value);
}

void inOrder(TREENODEPTR treePtr) {

    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%s ", treePtr->string);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TREENODEPTR treePtr) {

    if (treePtr != NULL) {
        printf("%s ", treePtr->string);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TREENODEPTR treePtr) {

    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%s ", treePtr->string);
    }
}

int depth(TREENODEPTR treePtr) {

    if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL)
        return 1;

    if (treePtr->leftPtr == NULL && treePtr->rightPtr != NULL)
        return depth(treePtr->rightPtr) + 1;

    if (treePtr->rightPtr != NULL && treePtr->leftPtr != NULL)
        return depth(treePtr->leftPtr) + 1;

    if (treePtr->leftPtr != NULL && treePtr->rightPtr != NULL)
        return depth(treePtr->leftPtr) + depth(treePtr->rightPtr) + 1;
}
