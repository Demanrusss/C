#include <stdio.h>
#include <stdarg.h>

int product(int, ...);

int main(void) {

    int a = 1, b = 2, c = 3, d = 4, e = 5;

    printf("Sum of 2 integers (%d, %d) = %d\n", a, b, product(2, a, b));
    printf("Sum of 2 integers (%d, %d, %d) = %d\n", a, b, c,
           product(3, a, b, c));
    printf("Sum of 2 integers (%d, %d, %d, %d) = %d\n", a, b, c, d,
           product(4, a, b, c, d));
    printf("Sum of 2 integers (%d, %d, %d, %d, %d) = %d\n", a, b, c, d, e,
           product(5, a, b, c, d, e));

return 0;
}

int product(int i, ...) {

    int result = 0;

    va_list list;
    va_start(list, i);

    for (int j = 1; j <= i; j++)
        result += va_arg(list, int);

    va_end(list);

return result;
}
