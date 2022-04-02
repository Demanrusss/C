#include <stdio.h>

int main() {

    int i = 1, j = 1;

    first:
        if (i++ <= 5) {
            printf("*");
            goto first;
        }
        else
            printf("\n");

    secondToLast:
        if (j++ <= 3) {
            printf("*");

            i = 1;
            spaces:
                if (i++ <= 3) {
                    printf(" ");
                    goto spaces;
                }

            printf("*");
            printf("\n");
            goto secondToLast;
        }

    i = 1;

    last:
        if (i++ <= 5) {
            printf("*");
            goto last;
        }
        else
            printf("\n");

return 0;
}
