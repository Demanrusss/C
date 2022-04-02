#include <stdio.h>
#include <ctype.h>

int main() {

    char code[4];
    int i;

    printf("Enter some code of ASCII (from 000 to 255): ");
    gets(code);

    printf("Your code %s = %c of ASCII.\n", code, atoi(code));

return 0;
}
