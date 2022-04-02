#include <stdio.h>

union floatingPoint {
    float f;
    double d;
    long double l;
};

int main() {

    union floatingPoint value;

    scanf("%f", &value.f);
    scanf("%lf", &value.d);
    scanf("%Lf", &value.l);

    printf("%f\n", value.f);
    printf("%lf\n", value.d);
    printf("%Lf\n", value.l);

return 0;
}
