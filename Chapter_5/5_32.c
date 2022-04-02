#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, answer = 1;

    srand(time(NULL));

    while (answer > 0) {

        num1 = rand() % 9 + 1;
        num2 = rand() % 9 + 1;

        printf("How much is %d times %d? Your answer (-1, for END): ", num1, num2);
        scanf("%d", &answer);

        while (answer != num1 * num2 && answer > 0) {
            printf("No, you're wrong! Please, try again (-1, for END): ");
            scanf("%d", &answer);
            }

        if (answer == num1 * num2 && answer > 0)
            printf("Very good!\n");
    }

return 0;
}
