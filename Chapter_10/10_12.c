#include <stdio.h>

int main() {

    unsigned number, pow;
    void displayBytes(unsigned, unsigned);

    printf("Enter two integers to calculate by formula a * 2 ^ b\n");
    scanf("%u%u", &number, &pow);

    printf("Formula is %u * 2 ^ %u\n", number, pow);
    printf("Result is:\n");
    displayBytes(number, pow);

return 0;
}

void displayBytes(unsigned n, unsigned p) {

    unsigned mask = 1 << 15;

    n <<= p;

    for (int i = 1; i <= 16; i++) {
        putchar(n & mask ? '1' : '0');
        n <<= 1;

        if (i % 8 == 0)
            putchar(' ');
    }
    putchar('\n');
}
