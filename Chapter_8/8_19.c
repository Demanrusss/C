#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
#define SENTENCES 5

int main() {

    char sentence[SIZE], text[SIZE];
    int tableResults[2][2] = {0};
    char *searchLowPtr, *searchUpPtr;
    int symbol;
    int i;

    printf("Enter 5 sentences and something to search:\n");

    for (i = 0; i <= SENTENCES - 1; i++) {
        gets(sentence);
        strcat(text, sentence);
    }

    symbol = getchar();

    tableResults[0][0] = toupper(symbol);
    tableResults[1][0] = tolower(symbol);

    searchUpPtr = strchr(text, tableResults[0][0]);
    searchLowPtr  = strchr(text, tableResults[1][0]);

    if (searchUpPtr != NULL)
        ++tableResults[0][1];
    if (searchLowPtr != NULL)
        ++tableResults[1][1];

    while (searchUpPtr != NULL) {
        searchUpPtr = strchr(searchUpPtr + 1, tableResults[0][0]);

        if (searchUpPtr != NULL)
            ++tableResults[0][1];
    }

    while (searchLowPtr != NULL) {
        searchLowPtr = strchr(searchLowPtr + 1, tableResults[1][0]);

        if (searchLowPtr != NULL)
            ++tableResults[1][1];
    }

    printf("Results are:\n%5c%5c\n%5d%5d\n", tableResults[0][0], tableResults[1][0], tableResults[0][1], tableResults[1][1]);

return 0;
}
