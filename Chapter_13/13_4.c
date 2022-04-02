#include <stdio.h>

#define PI 3.14159
#define VOLUME_OF_SPHERE(x) 4 / 3 * PI * (x) * (x) * (x)

int main(void) {

    float volume;
    int radius = 1;

    printf("%-10s%10s\n\n", "Radius", "Volume");

    for (int i = 0; i <= 10 - 1; i++, radius++)
        printf("%-10d%10.5f\n", radius, VOLUME_OF_SPHERE(radius));

return 0;
}
