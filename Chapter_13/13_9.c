#include <stdio.h>

#define PRINTARRAY(array, n) for(int i = 0; i < n; i++)  \
                                printf("%d ", array[i]); \
                             printf("\n");

int main(void) {

    int newArray[10] = {9, 7, 5, 3, 1, 0, 8, 6, 4, 2};

    PRINTARRAY(newArray, 10)

return 0;
}
