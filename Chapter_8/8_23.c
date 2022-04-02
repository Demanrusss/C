#include <stdio.h>
#include <string.h>
#define QUANTITY 5
#define SIZEOFSYMBOLS 20

int main() {

    char string[SIZEOFSYMBOLS], text[QUANTITY][SIZEOFSYMBOLS] = {0};
    int i;

    printf("Enter %d sentences:\n", QUANTITY);

    for (i = 0; i <= QUANTITY - 1; i++) {
        gets(string);
        strcat(text[i], string);
    }

    printf("\nBelow are sentences contain b at the very beginning:\n");
    for (i = 0; i <= QUANTITY - 1; i++) {
        if (text[i][0] == 66 || text[i][0] == 98)
            printf("%s\n", text[i]);
    }

return 0;
}
