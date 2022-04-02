#include <stdio.h>

#define SUMARRAY(array, n)  int sum = 0;                 \
                            for(int i = 0; i < n; i++)   \
                                sum += array[i];         \
                            printf("%d\n", sum);

int main(void) {

    int newArray[10] = {9, 7, 5, 3, 1, 0, 8, 6, 4, 2};

    SUMARRAY(newArray, 10)

return 0;
}
