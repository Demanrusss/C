#include <stdio.h>

int main(void) {

    float number1 = 7.3, number2;
    float *fPtr;

    fPtr = &number1;

    printf("%.1f\n", *fPtr);

    number2 = *fPtr;

    printf("%.1f\n", number2);

    printf("%p\n", &number1);
    printf("%p\n", fPtr);

return 0;
}
