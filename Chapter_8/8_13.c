#include <stdio.h>
#include <string.h>
#define SIZE 100

void printLatinWord(char []);

int main() {

    char sentence[SIZE] = {0};
    char *sPtr;

    printf("Enter a sentence (no more than %d characters):\n", SIZE);
    gets(sentence);

    sPtr = strtok(sentence, " ");

    while (sPtr != NULL) {
        printLatinWord(sPtr);
        sPtr = strtok(NULL, " ");
    }

return 0;
}

void printLatinWord(char w[]) {

    char result[SIZE] = {0};
    char a;
    int i;

    a = w[0];
    i = 1;
    while (w[i] != NULL) {
        result[i-1] = w[i];
        ++i;
    }

    result[--i] = a;
    printf("%s ", strcat(result, "ay"));
}
