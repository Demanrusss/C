/*Creating file of mainBook and file of transactions*/
#include <stdio.h>

struct clientData {
    int accountNumber;
    char firstName[10];
    char lastName[15];
    float balance;
};

int main() {

    FILE *mainBookPtr;
    FILE *transactionasPtr;
    struct clientData client;
    int acc;
    float transaction;

/*Creating file of mainBook*/

    if ((mainBookPtr = fopen("newmast.dat", "w")) == NULL)
        printf("File oldmast.dat could not be opened.\n");
    else {
        printf("Please, enter Account number, First name, Last Name and Balance (EOF, for ending)\n?");
        scanf("%d%s%s%f", &client.accountNumber, &client.firstName, &client.lastName, &client.balance);

        while (!feof(stdin)) {
            fprintf(mainBookPtr, "%d %s %s %.2f\n", client.accountNumber, client.firstName, client.lastName, client.balance);
            printf("?");
            scanf("%d%s%s%f", &client.accountNumber, &client.firstName, &client.lastName, &client.balance);
        }
    }

    fclose(mainBookPtr);

/*Creating file of transactions*/

    if ((transactionasPtr = fopen("trans.dat", "w")) == NULL)
        printf("File oldmast.dat could not be opened.\n");
    else {
        printf("Please, enter Account number and transaction (EOF, for ending)\n?");
        scanf("%d%f", &acc, &transaction);

        while (!feof(stdin)) {
            fprintf(transactionasPtr, "%d %.2f\n", acc, transaction);
            printf("?");
            scanf("%d%f", &acc, &transaction);
        }
    }

    fclose(transactionasPtr);

return 0;
}
