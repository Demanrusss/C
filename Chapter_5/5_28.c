#include <stdio.h>

int backward(int);

int main() {

    int number;

    printf("Enter an integer (1 - 9999): ");
    scanf("%d", &number);

    printf("The backward of %d is %d\n", number, backward(number));

return 0;
}

int backward(int num) {

    int i, a, x = 0;

    for (i = 10000; i >= 1; i /= 10)
        if ((num / i) != 0) {
            a = i;
            i = 0;
        }

    i = 1;

    for (; a >= 1; a /= 10) {
        x += num / a * i;
        num %= a;
        i *= 10;
    }

return x;
}

/*
x = 9876 / 1000 * 1; 9
x = 9876 % 1000 / 100 * 10; 80
x = 9876 % 1000 % 100 / 10 * 100; 700
x = 9876 % 1000 % 100 % 10 / 1 * 1000; 6000
*/
