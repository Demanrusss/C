#include <stdio.h>
#define SELLERS 6       //Plus 1 for sellers overals, plus 1 for starting from 1
#define PRODUCTS 7      //Plus 1 for product overals, plus 1 for starting from 1

void overals(float [SELLERS][PRODUCTS], int, int);
void printTable(float [SELLERS][PRODUCTS], int, int);

int main() {

    float sales[SELLERS][PRODUCTS] = {0};
    float sumTotal = 0;
    int numSeller = 0, numProduct = 0;

    while (numSeller != -1) {
        printf("\nEnter information from your card.\n");
        printf("1. ID number of seller (-1, for END): ");
        scanf("%d", &numSeller);

        if (numSeller != -1) {
            printf("2. ID number of product: ");
            scanf("%d", &numProduct);
            printf("3. Sum total: ");
            scanf("%f", &sumTotal);
        }

        if (numSeller > 0 && numSeller < SELLERS - 1)
            if (numProduct > 0 && numProduct < PRODUCTS - 1)
                if (sumTotal > 0)
                    sales[numSeller][numProduct] += sumTotal;
    }

    overals(sales, SELLERS - 1, PRODUCTS - 1);
    printTable(sales, SELLERS - 1, PRODUCTS - 1);

return 0;
}

void overals(float s[][PRODUCTS], int sel, int prod) {

    int i, j;

    for (i = 1; i <= sel - 1; i++)
        for (j = 1; j <= prod - 1; j++) {
            s[i][prod] += s[i][j];
            s[sel][j]  += s[i][j];
        }
}

void printTable(float s[][PRODUCTS], int sel, int prod) {

    int i, j;

    printf("\nThe table of sellers&products.\n");
    printf("%10s%10d%10d%10d%10d%10d%10s\n", " ", 1, 2, 3, 4, 5, "Total");

    for (i = 1; i <= sel; i++) {
        if (i != sel)
            printf("%10d", i);
        else
            printf("%10s", "Total");

        for (j = 1; j <= prod; j++) {
            if (i != sel || j != prod)
                printf("%10.2f", s[i][j]);
            else
                ;
        }

        printf("\n");
    }
}
