#include <stdio.h>

int main() {

    unsigned a;
    void printBytes(unsigned);

    printf("Enter some integer: ");
    scanf("%u", &a);
    printBytes(a);

return 0;
}

void printBytes(unsigned z) {

    unsigned mask = 1 << 31;

    printf("%7u = ", z);
    for (int i = 1; i <= 32; i++) {
        putchar(z & mask ? '1' : '0');
        z <<= 1;

        if (i % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}
