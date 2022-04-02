#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROLLSIZE 21

int counter;

int rollDice(void);
int set(void);

int main() {

    int i, wins = 0;
    int winsArray[ROLLSIZE] = {0};
    int losesArray[ROLLSIZE] = {0};

    srand(time(NULL));

    for (i = 1; i <= 1000; i++) {
        if (set() == 1) {
            ++wins;
            ++winsArray[counter];
        }
        else
            ++losesArray[counter];
    }

    printf("\n\nWins per rolls.\n");
    printf("   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20+\n");
    for (i = 1; i <= ROLLSIZE - 1; i++)
        printf("%4d", winsArray[i]);

    printf("\n\nLoses per rolls.\n");
    printf("   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20+\n");
    for (i = 1; i <= ROLLSIZE - 1; i++)
        printf("%4d", losesArray[i]);

    printf("\n\nThe percentage of wins is %.2f.\n", (float) wins / 1000);

return 0;
}

int set(void) {

    int gameStatus, sum, myPoint;

    counter = 0;
    sum = rollDice();

    switch(sum) {
        case 7: case 11:
            gameStatus = 1;
            break;
        case 2: case 3: case 12:
            gameStatus = 2;
            break;
        default:
            gameStatus = 0;
            myPoint = sum;
            printf("Point is %d\n", myPoint);
            break;
    }

    while (gameStatus == 0) {
        sum = rollDice();

        if (sum == myPoint)
            gameStatus = 1;
        else
            if (sum == 7)
                gameStatus = 2;
    }

    if (counter >= 21)
        counter = 20;

    if (gameStatus == 1) {
        printf("Player wins!\n");
        return 1;
    }
    else {
        printf("Player loses...\n");
        return 0;
    }
}

int rollDice(void) {

    int die1, die2, workSum;

    ++counter;

    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    workSum = die1 + die2;
    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);

return workSum;
}
