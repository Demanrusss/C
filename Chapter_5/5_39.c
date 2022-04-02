#include <stdio.h>

int hanoi(int, int, int, int);

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

    hanoi(disks, standMain, standTarget, standTemp);

return 0;
}

int hanoi(int d, int sMain, int sTarget, int sTemp) {

    if (d > 1)
        return hanoi(d - 1, sMain, sTemp, sTarget) + hanoi(1, sMain, sTarget, sTemp) + hanoi(d - 1, sTemp, sTarget, sMain);

    printf("%d -> %d\n", sMain, sTarget);

return 0;
}
