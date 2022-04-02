#include <stdio.h>
#include <math.h>

void hanoi(int, int, int, int);

int main() {

    int disks, standMain, standTarget, standTemp;

    printf("Enter quantity of disks: ");
    scanf("%d", &disks);
    printf("Enter number of stand where they are: ");
    scanf("%d", &standMain);
    printf("Enter number of stand to move to: ");
    scanf("%d", &standTarget);
    printf("Enter number of temporary stand: ");
    scanf("%d", &standTemp);

    if (disks % 2 == 0)
        hanoi(disks, standMain, standTemp, standTarget);
    else
        hanoi(disks, standMain, standTarget, standTemp);

    printf("%d -> %d\n", standMain, standTarget);

    if (disks % 2 == 0)
        hanoi(disks, standTemp, standMain, standTarget);
    else
        hanoi(disks, standTemp, standTarget, standMain);

return 0;
}

void hanoi(int d, int sMain, int sTarget, int sTemp) {

    int i, aux;
    long int moves = 0;

    moves = pow(2, d) - 1;

    for (i = 1; i <= moves / 2; i++) {
        if (i % 3 == 1)
            printf("%d -> %d\n", sMain, sTarget);

        if (i % 3 == 2)
            printf("%d -> %d\n", sMain, sTemp);

        if (i % 3 == 0) {
            printf("%d -> %d\n", sTarget, sTemp);

            aux = sMain;
            sMain = sTarget;
            sTarget = sMain;
        }
    }
}
