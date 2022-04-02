#include <stdio.h>
#define SIZE 10

int main() {

    int array[SIZE] = {0};
    int i, j, integer, quantity = 0;

    for (i = 0; i <= SIZE - 1; i++) {
        printf("Enter some integer between 10 and 100: ");
        scanf("%d", &integer);

        if (integer >= 10 && integer <= 100) {
            for (j = 0; j <= i; j++)
                if (array[j] == integer)
                    j = SIZE + 10;

            if (j < SIZE + 10) {
                array[quantity] = integer;
                ++quantity;
            }
        }
        else
            --i;
    }

    printf("\n...Array of integers...\n\n");
    for (i = 0; i <= quantity - 1; i++)
        printf("%d  ", array[i]);

return 0;
}
