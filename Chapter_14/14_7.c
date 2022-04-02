#include <stdio.h>
#include <stdlib.h>

int main() {

    int arraySize;
    int *array;

    printf("Enter quantity of items in array: ");
    scanf("%d", &arraySize);

    array = calloc(arraySize, sizeof(int));

    if (array == NULL)
        printf("Could not create an array. No memory available.\n");
    else {
        printf("Enter integer to fill in the array:\n");

        for (int i = 0; i <= arraySize - 1; i++) {
            printf("? ");
            scanf("%d", &array[i]);
        }

        for (int i = 0; i <= arraySize - 1; i++)
            printf("%d ", array[i]);

        printf("\n");

        realloc(array, sizeof(int) / 2);

        for (int i = 0; i <= arraySize - 1; i++)
            printf("%d ", array[i]);
    }

return 0;
}
