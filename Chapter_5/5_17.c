#include <stdio.h>

int multiple(int, int);

main() {

    int i, a, b;

    for (i = 1; i <= 5; i++) {
        printf("Enter two integers to find out if the first can be divided by the second: ");
        scanf("%d%d", &a, &b);

        if (multiple(a, b) == 0)
            printf("%d can't be divided by %d\n", a, b);
        else
            printf("%d can be diveded by %d\n", a, b);
    }

return 0;
}

int multiple(int x, int y) {

    if (x % y != 0)
        return 0;
    else
        return 1;
}
