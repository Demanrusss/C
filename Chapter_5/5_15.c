#include <stdio.h>
#include <math.h>

double hypotenuse(double, double);

main() {

    int i;
    double side1, side2;

    for (i = 1; i <= 3; i++) {
        printf("Enter side one of triangle: ");
        scanf("%lf", &side1);
        printf("Enter side two of triangle: ");
        scanf("%lf", &side2);

        printf("Side 1 - %f, side 2 - %f, hypotenuse - %f\n", side1, side2, hypotenuse(side1, side2));
    }

return 0;
}

double hypotenuse(double a, double b) {

return sqrt(a * a + b * b);
}
