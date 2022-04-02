#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct queueNode {
    int exactTime;
    struct queueNode *nextPtr;
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, int);
int dequeue(QUEUENODEPTR *, QUEUENODEPTR *);
int isEmpty(QUEUENODEPTR);
void printQueue(QUEUENODEPTR);

int main() {

    QUEUENODEPTR headPtr = NULL, tailPtr = NULL;
    int workMinute, buyer, nextBuyer, minutesForBuyer;
    int counter = 0, maxBuyers = 0, waitingMinutes = 0, maxWaiting = 0;

    srand(time(NULL));

    buyer = rand() % 3 + 1;
    minutesForBuyer = rand() % 4 + 1;
    nextBuyer = buyer + rand() % 4 + 1;

    for (workMinute = 0; workMinute < 720; workMinute++, minutesForBuyer--) {
        if (nextBuyer == workMinute) {
            enqueue(&headPtr, &tailPtr, nextBuyer);
            ++counter;

            if (maxBuyers < counter)
                maxBuyers = counter;

            nextBuyer = workMinute + rand() % 3 + 1;
        }

        if (minutesForBuyer <= 0) {
            if (isEmpty(headPtr))
                ;
            else {
                buyer = dequeue(&headPtr, &tailPtr);
                --counter;
                waitingMinutes = workMinute - buyer;

                if (maxWaiting < waitingMinutes)
                    maxWaiting = waitingMinutes;

                minutesForBuyer = rand() % 4 + 1;
            }
        }
    }

    printf("Maximum of queue is %d people.\n\n", maxBuyers);
    printf("Maximum of waiting time is %d\n\n", maxWaiting);
    printQueue(headPtr);

return 0;
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, int value) {

    QUEUENODEPTR newPtr;

    newPtr = malloc(sizeof(QUEUENODE));

    if (newPtr != NULL) {
        newPtr->exactTime = value;
        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr))
            *headPtr = newPtr;
        else
            (*tailPtr)->nextPtr = newPtr;

        *tailPtr = newPtr;
    }
    else
        printf("There is no memory available.\n");
}

int dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr) {

    QUEUENODEPTR tempPtr;
    int value;

    value = (*headPtr)->exactTime;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL)
        *tailPtr = NULL;

    free(tempPtr);

return value;
}

int isEmpty(QUEUENODEPTR headPtr) {

return headPtr == NULL;
}

void printQueue(QUEUENODEPTR currentPtr) {

    if (currentPtr == NULL)
        printf("Queue is empty.\n\n");
    else {
        printf("The queue is \n");

        while (currentPtr != NULL) {
            printf("%d -> ", currentPtr->exactTime);
            currentPtr = currentPtr->nextPtr;
        }
    }

    printf("NULL\n\n");
}
