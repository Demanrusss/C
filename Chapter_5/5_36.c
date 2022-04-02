#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int number, answer = 0, tries;

    srand(time(NULL));

    while (answer >= 0) {
        number = rand() % 1000 + 1;

        tries = 0;

        printf("I've got a number between 1 and 1000.\n");
        printf("Can you guess what it is?\n");
        printf("Please, text me your answer(-1, for END): ");
        scanf("%d", &answer);

        while (answer != number && answer > 0) {
            if (answer < number)
                printf("Your answer a little bit smaller. Try again (-1, for END): ");
            else
                printf("Your answer a little bit larger. Try again (-1, for END): ");

            tries++;

            scanf("%d", &answer);
        }

        if (tries < 10)
            printf("You know the secret or just have luck!\n");
        else
            if (tries == 10)
                printf("You know the secret!\n");
            else
                printf("You could guess faster!\n");

        if (answer > 0)
            printf("Great! You have guessed it! Would you like to play again?\n");
    }

    printf("Game over!\n");

return 0;
}
