#include <stdio.h>

int isDigit(int);
int isAlpha(int);
int isAlnum(int);
int isXdigit(int);
int isLower(int);
int isUpper(int);
int toLower(int);
int toUpper(int);
int isSpace(int);
int isCntrl(int);
int isPunct(int);
int isPrint(int);
int isGraph(int);

int main() {

    int symbol, result;

    printf("Enter some symbol: ");
    symbol = getchar();

    result = isDigit(symbol);
    printf("Result of isDigit(int) = %d\n", result);
    result = isAlpha(symbol);
    printf("Result of isAlpha(int) = %d\n", result);
    result = isAlnum(symbol);
    printf("Result of isAlnum(int) = %d\n", result);
    result = isXdigit(symbol);
    printf("Result of isXdigit(int) = %d\n", result);
    result = isLower(symbol);
    printf("Result of isLower(int) = %d\n", result);
    result = isUpper(symbol);
    printf("Result of isUpper(int) = %d\n", result);
    result = toLower(symbol);
    printf("Result of toLower(int) = %d\n", result);
    result = toUpper(symbol);
    printf("Result of toUpper(int) = %d\n", result);

return 0;
}

int isDigit(int c) {

    if (c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

int isAlpha(int c) {

    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else
        return 0;
}

int isAlnum (int c) {

    if ((c >= 48 && c <= 57) || (c >= 65 || c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else
        return 0;
}

int isXdigit(int c) {

    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70))
        return 1;
    else
        return 0;
}

int isLower(int c) {

    if (c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}

int isUpper(int c) {

    if (c >= 65 && c <= 70)
        return 1;
    else
        return 0;
}

int toLower(int c) {

    if (c >= 97 && c <= 122)
        return c - 32;
    else
        return c;
}

int toUpper(int c) {

    if (c >= 65 && c <= 70)
        return c + 32;
    else
        return c;
}
