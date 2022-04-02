#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void addition(int, int);
void subtraction(int, int);
void product(int, int);
void ratio(int, int);
void mixed(int, int);
void answerComment(int);

int count = 0, i;

int main() {

    int num1, num2, answer, comment, difficulty, type;

    srand(time(NULL));

    printf("Enter your desired difficulty (1 or 2): ");
    scanf("%d", &difficulty);

    printf("Enter your desired type of arithmetic actions.\n");
    printf("1 - additions, 2 - subtractions, 3 - products, 4 - ratios, 5 - mixed: ");
    scanf("%d", &type);

    for (i = 1; i <= 10; i++) {

        num1 = rand() % (int) (9 * pow(10, difficulty - 1)) + 1;
        num2 = rand() % (int) (9 * pow(10, difficulty - 1)) + 1;

        switch (type) {
            case 1:
                addition(num1, num2);
                break;
            case 2:
                subtraction(num1, num2);
                break;
            case 3:
                product(num1, num2);
                break;
            case 4:
                ratio(num1, num2);
                break;
            case 5:
                mixed(num1, num2);
                break;
            default:
                break;
        }


    }

    if (count <= 7)
        printf("Please, ask your teacher to repeat the subject.\n");

return 0;
}

void addition(int x, int y) {

    int answer;

    printf("How much is %d plus %d? Your answer: ", x, y);
    scanf("%d", &answer);

    while (answer != x + y && i <= 10) {
            i++;
            answerComment(0);
            scanf("%d", &answer);
    }

    if (answer == x + y && i <= 10) {
        answerComment(1);
        count++;
    }
}

void subtraction(int x, int y) {

    int answer, temp;

    if (x < y) {
        temp = x;
        x = y;
        y = temp;
    }

    printf("How much is %d minus %d? Your answer: ", x, y);
    scanf("%d", &answer);

    while (answer != x - y && i <= 10) {
            i++;
            answerComment(0);
            scanf("%d", &answer);
    }

    if (answer == x - y && i <= 10) {
        answerComment(1);
        count++;
    }
}

void product(int x, int y) {

    int answer;

    printf("How much is %d * %d? Your answer: ", x, y);
    scanf("%d", &answer);

    while (answer != x * y && i <= 10) {
            i++;
            answerComment(0);
            scanf("%d", &answer);
    }

    if (answer == x * y && i <= 10) {
        answerComment(1);
        count++;
    }
}

void ratio(int x, int y) {

    int answer, temp;

    if (x < y) {
        temp = x;
        x = y;
        y = temp;
    }

    printf("How much is %d / %d? Your answer: ", x, y);
    scanf("%d", &answer);

    while (answer != x / y && i <= 10) {
            i++;
            answerComment(0);
            scanf("%d", &answer);
    }

    if (answer == x / y && i <= 10) {
        answerComment(1);
        count++;
    }
}

void mixed(int x, int y) {

    int choice;

    choice = rand() % 4 + 1;

    switch(choice) {
        case 1:
            addition(x, y);
            break;
        case 2:
            subtraction(x, y);
            break;
        case 3:
            product(x, y);
            break;
        case 4:
            ratio(x, y);
            break;
    }
}

void answerComment(int a) {

    int comment;

    comment = rand() % 4 + 1;

    if (a == 0)
        switch(comment) {
            case 1:
                printf("No. Please try again: ");
                break;
            case 2:
                printf("Wrong. Try once more: ");
                break;
            case 3:
                printf("Don't give up: ");
                break;
            case 4:
                printf("No. Keep trying: ");
                break;
        }
    else
        switch(comment) {
                case 1:
                    printf("Very good!\n");
                    break;
                case 2:
                    printf("Excellent!\n");
                    break;
                case 3:
                    printf("Nice work!\n");
                    break;
                case 4:
                    printf("Keep up the good work!\n");
                    break;
            }
}
