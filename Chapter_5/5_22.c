#include <stdio.h>

void row(int, int);

int main() {

    int integer, i, rank;

    printf("Enter an integer between 1 and 32767: ");
    scanf("%d", &integer);

    for (i = 10000; i >= 10; i /= 10)
        if (integer / i != 0) {
            rank = i;
            i = 0;
        }

    row(integer, rank);

return 0;
}

void row(int num, int rank) {

    for (; rank >= 1; rank /= 10) {
        printf("%d ", num / rank);

        num %= rank;
    }

}
