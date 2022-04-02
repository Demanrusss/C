#include <stdio.h>

long int sumSeconds(int, int, int);

int main() {

    int hours, minutes, seconds;

    printf("What time is it now (format: hh mm ss)?\n");
    scanf("%d%d%d", &hours, &minutes, &seconds);

    printf("Total is %ld seconds after 12:00:00\n", sumSeconds(hours, minutes, seconds));

return 0;
}

long int sumSeconds(int h, int m, int s) {

return (long int)(h % 12) * 3600 + m * 60 + s;
}
