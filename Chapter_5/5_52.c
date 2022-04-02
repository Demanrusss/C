#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int set(void);
int rollDice(void);

int main() {

    int bankBalance = 1000, bet = 1, comment;

    srand(time(NULL));

    while (bankBalance != 0 && bet != 0) {
        printf("Your balance is %d.\n", bankBalance);
        printf("Enter your bet (0, for end): ");
        scanf("%d", &bet);

        while (bet > bankBalance) {
            printf("Your bet is more than you can allow.\n");
            scanf("%d", &bet);
        }

        if (bet == bankBalance)
            printf("Oh! You're trying to fight the tiger!\n");

        if (set() == 1)
            bankBalance += bet;
        else
            bankBalance -= bet;

        comment = rand() % 2 + 1;

        switch(comment) {
            case 1:
                printf("Let's get the ball rolling!\n");
                break;
            case 2:
                printf("Maybe it's time to get the money?!\n");
                break;
        }
    }

    if (bankBalance == 0)
        printf("Sorry, but you spent all your money...\n");
    else
        printf("Your balance is %d\n See you next time.\n", bankBalance);

return 0;
}

int set(void) {

    int gameStatus, sum, myPoint;

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

    while(gameStatus == 0) {
        sum = rollDice();

        if (sum == myPoint)
            gameStatus = 1;
        else
            if (sum == 7)
                gameStatus = 2;
    }

    if (gameStatus == 1) {
        printf("Player wins\n");
        return 1;
    }
    else {
        printf("Player loses\n");
        return 0;
    }
}

int rollDice(void) {

    int die1, die2, workSum;

    die1 = 1 + (rand() % 6);
    die2 = 1 + (rand() % 6);

    workSum = die1 + die2;

    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);

return workSum;
}
