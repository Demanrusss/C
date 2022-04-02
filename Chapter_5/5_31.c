#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);

int main() {

    int i, heads = 0, tails = 0;

    srand(time(NULL));

    for (i = 1; i <= 100; i++)
        if (flip() == 1) {
            printf("Heads ");
            heads++;
        }
        else {
            printf("Tails ");
            tails++;
        }

        if (i % 10 == 0)
            printf("\n");

    printf("Heads - %d\n", heads);
    printf("Tails - %d\n", tails);

return 0;
}

int flip() {

    if (rand() % 2 == 1)
        return 1;
    else
        return 0;
}
