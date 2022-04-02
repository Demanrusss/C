#include <stdio.h>

void displayBytes(unsigned);
void reverseBytes(unsigned);

int main() {

    unsigned a;

    printf("Enter an unsigned integer: ");
    scanf("%u", &a);

    printf("Before reversing your integer is\n");
    displayBytes(a);
    printf("After reversing your integer is\n");
    reverseBytes(a);

return 0;
}

void displayBytes(unsigned x) {

    unsigned mask = 1 << 15;

    printf("%7u = ", x);

    for (int i = 1; i <= 16; i++) {
        putchar(x & mask ? '1' : '0');

        x <<= 1;

        if (i % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}

void reverseBytes(unsigned x) {

    unsigned reversed = 0, mask = 1;

    for (int i = 1; i <= 16; i++) {
        if (i == 1)
            ;
        else
            reversed <<= 1;

        reversed |= ((x & (mask << (i - 1))) >> (i - 1));
    }

    displayBytes(reversed);
}
