#include <stdio.h>

void displayBytes(unsigned);
unsigned packCharacters(char, char);

int main() {

    char a, b, packed;

    printf("Enter two symbols:\n");
    scanf("%c %c", &a, &b);

    printf("Your first symbol is %c\n", a);
    displayBytes((unsigned) a);
    printf("Your second symbol is %c\n", b);
    displayBytes((unsigned) b);

    printf("Two symbols after packing is %c%c\n", a, b);
    displayBytes(packCharacters(a, b));

return 0;
}

unsigned packCharacters(char x, char y) {

    unsigned packedSymbol = (unsigned) x << 8;

return packedSymbol | y;
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
