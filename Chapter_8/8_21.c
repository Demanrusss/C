#include <stdio.h>
#include <string.h>
#define QUANTITY 5
#define SIZEOFSYMBOLS 15

void sorting(char [QUANTITY][SIZEOFSYMBOLS]);

int main() {

    char city[SIZEOFSYMBOLS], text[QUANTITY][SIZEOFSYMBOLS] = {0};
    int i;

    printf("Enter %d cities:\n", QUANTITY);

    for (i = 0; i <= QUANTITY - 1; i++) {
        gets(city);
        strcat(text[i], city);
    }

    sorting(text);

    printf("\nAfter sorting:\n");
    for (i = 0; i <= QUANTITY - 1; i++)
        printf("%s\n", text[i]);

return 0;
}

void sorting(char t[QUANTITY][SIZEOFSYMBOLS]) {

    char temp[SIZEOFSYMBOLS] = {0};
    int i, j, min;

    for (i = 0; i <= QUANTITY - 1; i++) {
        min = i;

        for (j = i + 1; j <= QUANTITY - 1; j++) {
            if (strcmp(t[min], t[j]) > 0)
                min = j;
        }

        strcpy(temp, t[i]);
        strcpy(t[i], t[min]);
        strcpy(t[min], temp);
    }
}
