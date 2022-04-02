#include <stdio.h>
#define SIZE 10

int main() {

    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    int i, pass, hold, change;

    printf("Data items in original order\n");

    for (i = 0; i <= SIZE - 1; i++)
        printf("%4d", a[i]);

    for (pass = 1; pass <= SIZE - 1; pass++) {
        change = 0;

        for (i = 0; i <= SIZE - pass - 1; i++)
            if (a[i] > a[i + 1]) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
                ++change;
            }
        if (change == 0)
            pass = SIZE;
    }

    printf("\nData items in ascending order\n");

    for (i = 0; i <= SIZE - 1; i++)
        printf("%4d", a[i]);

    printf("\n");

return 0;
}
