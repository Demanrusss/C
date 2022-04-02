#include <stdio.h>

float sumCharges = 0;

float calculateCharges (float);

main() {

    float   hoursFirst = 0, hoursSecond = 0, hoursThird = 0, sumHours = 0;

    printf("Enter quantity hours for the first car: ");
    scanf("%f", &hoursFirst);
    printf("Enter quantity hours for the second car: ");
    scanf("%f", &hoursSecond);
    printf("Enter quantity hours for the third car: ");
    scanf("%f", &hoursThird);

    sumHours = hoursFirst + hoursSecond + hoursThird;

    printf("%s%10s%10s\n", "Car", "Hours", "Charge");
    printf("1%12.1f%10.2f\n", hoursFirst, calculateCharges(hoursFirst));
    printf("2%12.1f%10.2f\n", hoursSecond, calculateCharges(hoursSecond));
    printf("3%12.1f%10.2f\n", hoursThird, calculateCharges(hoursThird));
    printf("%s%8.1f%10.2f\n", "TOTAL", sumHours, sumCharges);

return 0;
}

float calculateCharges (float hours) {

    float charges = 0;

    if (hours <= 3)
        charges = 2.00;
    else
        charges = 2.00 + (hours - 3) * 0.50;

    if (hours >= 24)
        charges = 10.00;

    sumCharges += charges;

return charges;
}
