#include <stdio.h>
#include <stdlib.h>

main() {

    int i;

    for (i = 1; i <= 10; i++)
        printf("%d ", (rand() % 5) * 2 + 2);

    printf("\n");

    for (i = 1; i <= 10; i++)
        printf("%d ", (rand() % 5) * 2 + 3);

    printf("\n");

    for (i = 1; i <= 10; i++)
        printf("%d ", (rand() % 5) * 4 + 6);

    printf("\n");

return 0;
}
