#include <stdio.h>
#include <string.h>
#define SIZE 100
#define SENTENCES 5

int main() {

    char sentence[SIZE], text[SIZE];
    char *searchPtr;
    int symbol;
    int i, counter = 0;

    printf("Enter 5 sentences and something to search:\n");

    for (i = 0; i <= SENTENCES - 1; i++) {
        gets(sentence);
        strcat(text, sentence);
    }

    symbol = getchar();

    searchPtr = strchr(text, symbol);

    if (searchPtr != NULL)
        ++counter;

    while (searchPtr != NULL) {
        searchPtr = strchr(searchPtr + 1, symbol);

        if (searchPtr != NULL)
            ++counter;
    }

    printf("Overall %d are founded in the text\n", counter);

return 0;
}
