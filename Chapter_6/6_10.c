#include <stdio.h>
#define SIZE 9

int main() {

    int counters[SIZE] = {0};
    int income = 0, salary, i;

    while (income != -1) {
        printf("Enter income of a salesman (-1, for END): ");
        scanf("%d", &income);

        if (income != -1) {
            salary = 200 + income * .09;
            printf("Salary = %d\n", salary);

            if (salary / 100 >= 10)
                ++counters[8];
            else
                ++counters[salary / 100 - 2];
        }
    }

    for (i = 0; i <= SIZE - 2; i++)
        printf("%d. $%d - $%d   %d\n", i + 1, i * 100 + 200, i * 100 + 299, counters[i]);

    printf("%d. $%d - more  %d\n", i, i * 100 + 200, counters[i]);

return 0;
}
