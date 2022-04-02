#include <stdio.h>
#define BYTESSYSTEM 4

void displayBytes(unsigned);
void unpackCharacters(unsigned);

int main() {

    unsigned packed;

    printf("Enter packed characters: ");
    scanf("%u", &packed);

    printf("Your packed characters in BIN is\n");
    displayBytes(packed);

    printf("After unpacking we have:\n");
    unpackCharacters(packed);

return 0;
}

void unpackCharacters(unsigned x) {

    char letter;
    unsigned mask = 255;

    for (int i = 0; i <= BYTESSYSTEM - 1; i++) {
        letter = (char) ((x & (mask << ((BYTESSYSTEM - 1 - i) * 8))) >> ((BYTESSYSTEM - 1 - i) * 8));
        printf("Your letter is %c\n", letter);
        displayBytes((unsigned) letter);
    }
}

void displayBytes(unsigned z) {

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
