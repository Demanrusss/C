#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15

int main() {

    char telNumber[SIZE], numbers[] = "1234567890";
    char *telPtr;
    int regionCode;
    long number;

    printf("Enter number (form: (xxx) xxx-xxxx): ");
    gets(telNumber);

    regionCode = atoi(strpbrk(strtok(telNumber, " "), numbers));
    telPtr = strtok(NULL, "-");
    number = atol(strcat(telPtr, strtok(NULL, " ")));

    printf("Country code - %d\nPhone number - %ld", regionCode, number);

return 0;
}
