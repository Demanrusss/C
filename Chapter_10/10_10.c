#include <stdio.h>

void printBits(unsigned);

int main() {

    unsigned x;

    printf("Enter some integer: ");
    scanf("%u", &x);

    printf("Your integer in bits:\n");
    printBits(x);
    printf("\nYour integer after shifting:\n");
    printBits(x >> 4);

return 0;
}

void printBits(unsigned value) {

    unsigned mask = 1 << 15;

    printf("%7u = ", value);

    for (int i = 1; i <= 16; i++) {
        putchar(value & mask ? '1' : '0');
        value <<= 1;

        if (i % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}
