#include <stdio.h>
#include <string.h>
#define SIZE 100
#define SENTENCES 5

int main() {

    char sentence[SIZE], text[SIZE];
    char search[SIZE];
    char *searchPtr;
    int i, counter = 0;

    printf("Enter 5 sentences and something to search:\n");

    for (i = 0; i <= SENTENCES - 1; i++) {
        gets(sentence);
        strcat(text, sentence);
    }

    gets(search);

    searchPtr = strstr(text, search);

    if (searchPtr != NULL)
        ++counter;

    while (searchPtr != NULL) {
        searchPtr = strstr(searchPtr + 1, search);

        if (searchPtr != NULL)
            ++counter;
    }

    printf("Overall %d are founded in the text\n", counter);

return 0;
}
