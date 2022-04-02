#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned x;
    void displayBytes(unsigned);

    printf("Enter an unsigned integer: ");
    scanf("%u", &x);

    displayBytes(x);

return 0;
}

void displayBytes(unsigned value) {

    unsigned displayMask = 1 << ((sizeof(value) * 8) - 1);

    printf("%7u = ", value);

    for (int i = 1; i <= (sizeof(value) * 8); i++) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1;

        if (i % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}
