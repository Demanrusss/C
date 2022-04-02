#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, answer = 1, comment;

    srand(time(NULL));

    while (answer > 0) {

        num1 = rand() % 9 + 1;
        num2 = rand() % 9 + 1;

        printf("How much is %d times %d? Your answer (-1, for END): ", num1, num2);
        scanf("%d", &answer);

        while (answer != num1 * num2 && answer > 0) {
            comment = rand() % 4 + 1;

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

            scanf("%d", &answer);
        }

        if (answer == num1 * num2 && answer > 0) {
            comment = rand() % 4 + 1;

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
    }

return 0;
}
