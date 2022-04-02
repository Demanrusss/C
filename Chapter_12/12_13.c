#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

struct stackNode {
    int data;
    struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

int evaluatePostfixExpression(char *);
int calculate(int, int, char);
void push(STACKNODEPTR *, int);
char pop(STACKNODEPTR *);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);

int main() {

    char postf[SIZE] = {0};

    printf("Enter postfix mathematical expression, using simple numbers (50 symbols max):\n");
    gets(postf);

    strcat(postf, "\0");

    printf("The result after calculating is %d\n", evaluatePostfixExpression(postf));

return 0;
}

int evaluatePostfixExpression(char *expr) {

    STACKNODEPTR stackNode;
    int i, x, y;

    for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i]))
            push(&stackNode, ((int)expr[i] - (int)'0'));
        else {
            x = pop(&stackNode);
            y = pop(&stackNode);
            push(&stackNode, calculate(y, x, expr[i]));
        }
    }

return pop(&stackNode);
}

int calculate(int op1, int op2, char operator) {

    if (operator == '+')
        return op1 + op2;
    else
        if (operator == '-')
            return op1 - op2;
        else
            if (operator == '*')
                return op1 * op2;
            else
                if (operator == '/')
                    return op1 / op2;
                else
                    if (operator == '^')
                        return op1 ^ op2;
                    else
                        if (operator == '%')
                            return op1 % op2;
}

void push(STACKNODEPTR *topPtr, int value) {

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
    int popValue;

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
