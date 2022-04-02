#include <stdio.h>

int even(int);

main() {

    int i, a;

    for (i = 1; i <= 5; i++) {
        printf("Enter an integer: ");
        scanf("%d", &a);

        printf("%d is %s\n", a, even(a) == 0 ? "odd" : "even");
    }

return 0;
}

int even(x) {

    if (x % 2 != 0)
        return 0;
    else
        return 1;
}
