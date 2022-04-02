#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    FILE *dictionaryPtr;
    char sentence[9], *temp;
    char *setAlphabet = "000000ABCDEFGHIJKLMNOPRSTUVXYZ";
    char temp1[2] = {0, '\0'};
    int j;

    if ((dictionaryPtr = fopen("dictionary.dat", "w")) == NULL)
        printf("File dictionary.dat could not be opened.\n");
    else {
        printf("Enter phone number (format xxx-xxxx only): ");
        scanf("%s", sentence);

        temp = strtok(sentence, "-");
        strcat(temp, strtok(NULL, " "));

        for (int i = 0; i <= 2187 - 1; i++) {
            char word[8] = {0};

            for (j = 0; j <= 6 - 1; j++) {
                temp1[0] = sentence[j];

                word[j] = setAlphabet[atoi(temp1) * 3 + ((int) i / (729 / (int) pow(3, j))) % 3];
            }

            temp1[0] = sentence[j];

            word[6] = setAlphabet[atoi(temp1) * 3 + (int) i % 3];
            word[7] = '\0';

            fprintf(dictionaryPtr, "%s ", word);
        }
    }

return 0;
}
