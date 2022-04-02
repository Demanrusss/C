#include <stdio.h>
#include <string.h>
#define QUANTITY 5
#define SIZEOFSYMBOLS 20

int main() {

    char string[SIZEOFSYMBOLS], text[QUANTITY][SIZEOFSYMBOLS] = {0};
    char *textPtr;
    int i;

    printf("Enter %d sentences:\n", QUANTITY);

    for (i = 0; i <= QUANTITY - 1; i++) {
        gets(string);
        strncat(text[i], string, 19);
    }

    printf("\nBelow are sentences contain ED at the ending:\n");
    for (i = 0; i <= QUANTITY - 1; i++) {
        textPtr = strrchr(text[i], 'E');

        if (strcmp(textPtr, "ED") == 0)
            printf("%s\n", text[i]);

/*        textPtr = strstr(text[i], "ED");

        if (strcmp(textPtr, "ED") == 0)
            printf("%s\n", text[i]);*/
    }

return 0;
}
