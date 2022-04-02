#include <stdio.h>
#include <math.h>

float distance(float, float, float, float);

int main() {

    float x1, y1, x2, y2;

    printf("Enter coordinates of the first point: ");
    scanf("%f%f", &x1, &y1);
    printf("Enter coordinates of the second point: ");
    scanf("%f%f", &x2, &y2);

    printf("Distance between two points is %f.\n", distance(x1, y1, x2, y2));

return 0;
}

float distance(float x1, float y1, float x2, float y2) {

return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
