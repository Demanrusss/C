#include <stdio.h>
#include <math.h>

float roundToInteger(float);
float roundToTenths(float);
float roundToHundredths(float);
float roundToThousandths(float);

main() {

    float x = 1;

    while (x != -1) {
        printf("Enter a number (-1, for end): ");
        scanf("%f", &x);

        printf("Your number %f after rounding to Integer is %.0f\n", x, roundToInteger(x));
        printf("Your number %f after rounding to Tenths is %.1f\n", x, roundToTenths(x));
        printf("Your number %f after rounding to Hundredths is %.2f\n", x, roundToHundredths(x));
        printf("Your number %f after rounding to Thousandths is %.3f\n", x, roundToThousandths(x));
    }

return 0;
}

float roundToInteger(float number) {

    float y;

    y = floor(number + .5);

return y;
}

float roundToTenths(float number) {

    float y;

    y = floor(number * 10 + .5) / 10;

return y;
}

float roundToHundredths(float number) {

    float y;

    y = floor(number * 100 + .5) / 100;

return y;
}

float roundToThousandths(float number) {

    float y;

    y = floor(number * 1000 + .5) / 1000;

return y;
}
