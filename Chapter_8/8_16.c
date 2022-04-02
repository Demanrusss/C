#include <stdio.h>
#include <string.h>
#define SIZE 100

int main() {

    char sentence[SIZE];
    char search[SIZE];
    char *searchPtr;

    printf("Enter some sentence and something to search: ");
    gets(sentence);
    gets(search);

    searchPtr = strstr(sentence, search);

    printf("%s\n", searchPtr);
    printf("%s\n", strstr(searchPtr + 1, search));

return 0;
}
