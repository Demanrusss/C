#include <stdio.h>
#include <string.h>
#define SIZE 1000
#define SENTENCES 5

int main() {

    char text[SIZE];
//    char *textPtr;
    int counter = 0;

    printf("Enter 5 sentences:\n");

    gets(text);

    strtok(text, " ");
    ++counter;

    while (strtok(NULL, " ") != NULL)
        ++counter;

    printf("Words = %d\n", counter);

return 0;
}
