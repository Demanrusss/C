#include <stdio.h>

float minimum(float, float, float);

int main() {

    float num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%f%f%f", &num1, &num2, &num3);

    printf("The minimum numer of above is %f\n", minimum(num1, num2, num3));

return 0;
}

float minimum(float x, float y, float z) {

    float min = x;

    if (y < min)
        min = y;

    if (z < min)
        min = z;

return min;
}
