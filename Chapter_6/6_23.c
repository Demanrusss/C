#include <stdio.h>
#define SIZE 50

void printArray(int [SIZE][SIZE], int);
void readingCommands(float [], int);

int main() {

    float array[SIZE] = {0};
    float command = 0;
    int i = 0;

    printf("Please, enter your program for turtle language.\n");
    printf("1 - Pen up\n"
           "2 - Pen down\n"
           "3 - Turn right\n"
           "4 - Turn left\n"
           "5,10 - Move 10 steps forward\n"
           "6 - Print array 50x50\n"
           "9 - End of commands\n");
    printf("Now enter your commands below, please (maximum is %d):\n", SIZE);

    while (((int)command != 9) && (i != SIZE - 1)) {
        scanf("%f", &command);
        array[i] = command;
        ++i;
    }

    readingCommands(array, SIZE);

return 0;
}

void readingCommands(float a[], int size) {

    int floor[SIZE][SIZE] = {0}, turtle[4] = {0};
    int i, j;

    for (i = 0; i <= size - 1; i++)
        switch ((int)a[i] / 1) {
            case 1:
                turtle[3] = 0;
                break;
            case 2:
                turtle[3] = 1;
                break;
            case 3:
                ++turtle[2];
                turtle[2] %= 4;
                break;
            case 4:
                if (turtle[2] == 0)
                    turtle[2] = 4;

                --turtle[2];
                break;
            case 5:
                for (j = 0; j <= (a[i] - 5) * 100 - 1; j++) {
                    switch (turtle[2]) {
                        case 0:
                            (turtle[0] == 50) ? turtle[0] = 50 : ++turtle[0];
                            break;
                        case 1:
                            (turtle[1] == 50) ? turtle[1] = 50 : ++turtle[1];
                            break;
                        case 2:
                            (turtle[0] == 0) ? turtle[0] = 0 : --turtle[0];
                            break;
                        case 3:
                            (turtle[1] == 0) ? turtle[1] = 0 : --turtle[1];
                            break;
                        default:
                            break;
                    }

                    floor[turtle[0]][turtle[1]] = turtle[3];
                }
                break;
            case 6:
                printArray(floor, SIZE);
                break;
            case 9:
                i = ++size;
                break;
            default:
                break;
        }
}

void printArray(int f[SIZE][SIZE], int size) {

    int i, j;

    for (i = 0; i <= size - 1; i++) {
        for (j = 0; j <= size - 1; j++)
            if (f[j][i] == 0)
                printf(" ");
            else
                printf("*");

        printf("\n");
    }
}
