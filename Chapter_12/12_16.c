/* �������� ��������� ������ � ��� �����
 � ����������, ��������������� � ���������� �������� */

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

int main() {

    int i, item;
    TREENODEPTR rootPtr = NULL;

    srand(time(NULL));

    /*������� ���������� � ������ 10 ��������� �����
      �� 0 �� 14 */
    printf("The numbers being placed in the tree are:\n");

    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    /*����� ������ � ��������������� ��������*/
    printf("\n\nThe preorder traversal is:\n");
    preOrder(rootPtr);

    /*����� ������ � ���������� ��������*/
    printf("\n\nThe inorder traversal is:\n");
    inOrder(rootPtr);

    /*����� ������ � ���������� ��������*/
    printf("\n\nThe postorder traversal is:\n");
    postOrder(rootPtr);

return 0;
}

void insertNode(TREENODEPTR *treePtr, int value) {

    if (*treePtr == NULL) { /* *treePtr ����� NULL */
        *treePtr = malloc(sizeof(TREENODE));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("There is no memory available.\n");
    }
    else
        if (value <= (*treePtr)->data)
            insertNode(&((*treePtr)->leftPtr), value);
        else
            if (value > (*treePtr)->data)
                insertNode(&((*treePtr)->rightPtr), value);
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
