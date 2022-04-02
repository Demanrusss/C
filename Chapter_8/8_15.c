#include <stdio.h>
#include <string.h>
#define SIZE 100

void reverse(char *);

int main() {

    char sentence[SIZE] = {0};

    printf("%s:\n", "Enter a sentence (100 symbols is max)");
    gets(sentence);

    reverse(sentence);

return 0;
}

void reverse(char *s) {

    char *sPtr;

    if ((sPtr = strtok(s, " ")) == NULL)
        return;
    else {
        reverse(NULL);
        printf("%s ", sPtr);
    }
}
