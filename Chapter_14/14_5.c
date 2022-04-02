#include <stdio.h>

int main() {

    FILE *filePtr, *tempFilePtr;
    int c;
    char fileName[30];

    printf("This program puts space between symbols.\n"
           "Enter a file to be modified: ");
    scanf("%s", fileName);

    if ((filePtr = fopen(fileName, "r+")) != NULL) {
        if ((tempFilePtr = tmpfile()) != NULL) {
            printf("The file before modification is:\n");

            while ((c = getc(filePtr)) != EOF) {
                putchar(c);
                putc(c, tempFilePtr);
                putc(' ', tempFilePtr);
            }

            rewind(tempFilePtr);
            rewind(filePtr);
            printf("\n\nThe file after modification is:\n");

            while ((c = getc(tempFilePtr)) != EOF) {
                putchar(c);
                putc(c, filePtr);
            }
        }
        else
            printf("Unable to open temporary file.\n");
    }
    else
        printf("Unable to open %s\n", fileName);

return 0;
}
