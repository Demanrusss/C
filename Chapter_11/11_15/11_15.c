#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usingStandard(void);
void usingFiles(void);

int main() {

    int choice;

    printf("You have two options: 1 - for using standard input/output device.\n"
           "2 - for using files.");
    printf("What's your choice? ");
    scanf("%d", &choice);

    while (choice != 1 && choice != 2) {
        printf("You entered wrong number. Try again? ");
        scanf("%d", &choice);
    }

    if (choice == 1)
        usingStandard();
    else
        usingFiles();

return 0;
}

void usingStandard(void) {

    char c, sentence[80];
    int i = 0;

    fputs("Enter line of text:", stdout);

    while ((c = fgetc(stdin)) != '\n')
        sentence[i++] = c;

    sentence[i] = '\0';
    fputs("\nThe line entered was:", stdout);
    fputs(sentence, stdout);
}

void usingFiles(void) {

    char fileName[14];
    char sentence[80];
    FILE *fileNamePtr;

    fputs("You should write down the name of input file: ", stdout);
    fgets(fileName, 10, stdin);

    strcat(fileName, ".dat");

    fputs("Enter your sentence: ", stdout);
    fgets(sentence, 80, stdin);

    if ((fileNamePtr = fopen(fileName, "w")) == NULL)
        fputs("File could not be opened.\n", stdout);
    else
        fputs(sentence, fileNamePtr);
}
