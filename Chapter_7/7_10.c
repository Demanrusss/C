#include <stdio.h>

int main(void) {

    long value1 = 200000, value2;
    long *lPtr;

    lPtr = &value1;

    printf("%d\n", *lPtr);

    value2 = *lPtr;

    printf("%d\n", value2);

    printf("%p\n", &value1);

    printf("%p\n", lPtr);

return 0;
}
