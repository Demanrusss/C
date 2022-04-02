#include <stdio.h>
#define SIZE 5

int main(void) {

    int i;
    int values[SIZE] = {2, 4, 6, 8, 10};
    unsigned int *vPtr;

    for (i = 0; i <= SIZE - 1; i++)
        printf("%d   ", values[i]);

    vPtr = values;
    vPtr = &values[0];

    printf("\n");
    for (i = 0; i <= SIZE - 1; i++)
        printf("%d   ", *(vPtr + i));

    printf("\n");
    for (i = 0; i <= SIZE - 1; i++)
        printf("%d   ", *(values + i));

    printf("\n");
    for (i = 0; i <= SIZE - 1; i++)
        printf("%d   ", vPtr[i]);

    printf("\n%p", vPtr + 3);
    printf("\n%d", *(vPtr + 3));

return 0;
}
