#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

struct stackNode {
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void convertToPostfix(char [], char []);
int isOperator(char);
int precedence(char, char);
void push(STACKNODEPTR *, char);
char pop(STACKNODEPTR *);
char stackTop(STACKNODEPTR);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);

int main() {

    char inf[SIZE] = {0}, postf[SIZE] = {0};

    printf("Enter mathematical expression, using simple numbers (50 symbols max):\n");
    gets(inf);

    strcat(inf, ")\0");

    convertToPostfix(inf, postf);

    for (int i = 0; postf[i] != '\0'; i++)
        printf("%c", postf[i]);

return 0;
}

void convertToPostfix(char inflix[], char postfix[SIZE]) {

    STACKNODEPTR node1Ptr = NULL;
    int i, j = 0;

    push(&node1Ptr, '(');

//    for (i = 0; inflix[i] != '\0'; i++)
//        ;
//    inflix[i] = ')';
//    inflix[++i] = '\0';

    if (isEmpty(node1Ptr) == 0) {
        for (i = 0; inflix[i] != '\0'; i++) {
            if (isdigit(inflix[i])) {
                postfix[j] = inflix[i];
                ++j;
            }
            else
                if (inflix[i] == '(')
                    push(&node1Ptr, inflix[i]);
                else
                    if (isOperator(inflix[i])) {
                        while (precedence(stackTop(node1Ptr), inflix[i]) != -1) {
                            postfix[j] = pop(&node1Ptr);
                            ++j;
                        }

                        push(&node1Ptr, inflix[i]);
                    }
                    else
                        if (inflix[i] == ')')
                            while (stackTop(node1Ptr) != '(') {
                                postfix[j] = pop(&node1Ptr);
                                ++j;
                            }
        }

        pop(&node1Ptr);
    }
}

int isOperator(char c) {

    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return 1;
    else
        return 0;
}

int precedence(char operator1, char operator2) {

    int a = 0, b = 0;

    if (operator1 == '*' || operator1 == '/' || operator1 == '%')
        a = 100;
    else
        if (operator1 == '+' || operator1 == '-')
            a = 10;

    if (operator2 == '*' || operator2 == '/' || operator2 == '%')
        b = 100;
    else
        if (operator2 == '+' || operator2 == '-')
            b = 10;

    if (a < b)
        return -1;
    else
        if (a = b)
            return 0;
        else
            return 1;
}

void push(STACKNODEPTR *topPtr, char value) {

    STACKNODEPTR newPtr = NULL;

    newPtr = malloc(sizeof(STACKNODE));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
        printf("\nThere is no memory available.\n");
}

char pop(STACKNODEPTR *topPtr) {

    STACKNODEPTR tempPtr;
    char popValue;

    tempPtr = *topPtr;
    popValue = tempPtr->data;
    *topPtr = tempPtr->nextPtr;
    free(tempPtr);

return popValue;
}

char stackTop(STACKNODEPTR topPtr) {

return topPtr->data;
}

int isEmpty(STACKNODEPTR topPtr) {

return topPtr == NULL;
}

void printStack(STACKNODEPTR topPtr) {

    if (topPtr == NULL)
        printf("Stack is empty.\n");
    else {
        printf("Stack is:\n");

        while (topPtr != NULL) {
            printf("%c", topPtr->data);
            topPtr = topPtr->nextPtr;
        }

        printf("\n\n");
    }
}
