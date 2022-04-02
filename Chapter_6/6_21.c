#include <stdio.h>
#define SIZE 11

void printArray(int [], int);

int main() {

    int airplane[SIZE] = {0};
    int i, j, k, option;
    char answer[4] = {0};

    printf("\nThis is a terminal for buying tickets for flight.\n");

    for (i = 0; i <= SIZE - 2; i++) {
        printArray(airplane, SIZE);

        printf("Please, choose 1 for smoking area.\n");
        printf("Please, choose 2 for non-smoking area.\n");
        scanf("%d", &option);

        if (option == 1 || option == 2) {
            if (option == 1)
                j = 1;
            else
                j = SIZE / 2 + 1;

            k = j + SIZE / 2 - 1;

            for (; j <= k; j++)
                if (airplane[j] == 0) {
                    ++airplane[j];
                    printf("Your room is %d in the %s area.\n", j, (j > SIZE / 2) ? "non-smoking" : "smoking");
                    j = j + SIZE;
                }

            if (j == k + 1) {
                printf("There is no place in the %s area.\n", (j > SIZE / 2 + 1) ? "non-smoking" : "smoking");
                printf("Would you like to change the area (yes or no): ");
                scanf("%s", answer);

                if (answer[0] == 'y' || answer[0] == 'n') {
                    if (answer[0] == 'y') {
                        if (j == SIZE / 2 + 1)
                            ;
                        else
                            j = 1;

                        k = j + SIZE / 2 - 1;

                        for (; j <= k; j++)
                            if (airplane[j] == 0) {
                                ++airplane[j];
                                printf("Your room is %d in the %s area.\n", j, (j > SIZE / 2) ? "non-smoking" : "smoking");
                                j = j + SIZE;
                            }

                        if (j == k + 1) {
                                printf("I'm sorry. There is no place either.\n");
                                printf("The next flight will be in 3 hours.\n");
                            }
                    }
                    else {
                        printf("The next flight will be in three hours.\n");
                        --i;
                    }
                }
                else {
                    printf("Sorry. There is a mistake in your answer.\n");
                    --i;
                }
            }
        }
        else {
            printf("There was a mistake when you chose the option.\n");
            --i;
        }
    }

return 0;
}

void printArray(int array[], int size) {

    int i;

    printf("Places on our plane.\n");

    for (i = 1; i <= size - 1; i++)
        printf("%d   ", i);

    printf("\n");

    for (i = 1; i <= size - 1; i++)
        printf("%d   ", array[i]);

    printf("\n");
}
