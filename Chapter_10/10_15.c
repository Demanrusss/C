#include <stdio.h>

void displayBytes(unsigned);
unsigned packCharacters(char, char, char, char);

int main() {

    char a, b, c, d, packed;

    printf("Enter two symbols:\n");
    scanf("%c %c %c %c", &a, &b, &c, &d);

    printf("Your first symbol is %c\n", a);
    displayBytes((unsigned) a);
    printf("Your second symbol is %c\n", b);
    displayBytes((unsigned) b);
    printf("Your third symbol is %c\n", c);
    displayBytes((unsigned) c);
    printf("Your fourth symbol is %c\n", d);
    displayBytes((unsigned) d);


    printf("Four symbols after packing is %c%c%c%c\n", a, b, c, d);
    displayBytes(packCharacters(a, b, c, d));

return 0;
}

unsigned packCharacters(char w, char x, char y, char z) {

    unsigned packedSymbol = (unsigned) w << 8;

    packedSymbol = (packedSymbol | (unsigned) x) << 8;
    packedSymbol = (packedSymbol | (unsigned) y) << 8;

return packedSymbol | (unsigned) z;
}

void displayBytes(unsigned x) {

    unsigned mask = 1 << 31;

    printf("%7u = ", x);

    for (int i = 1; i <= 32; i++) {
        putchar(x & mask ? '1' : '0');
        x <<= 1;

        if (i % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}
