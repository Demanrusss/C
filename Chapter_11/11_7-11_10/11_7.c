#include <stdio.h>

struct clientData {
    int accountNumber;
    char firstName[10];
    char lastName[15];
    float balance;
};

void updatingMainFile(FILE *);

/*Copying from new main book to old main book before updating*/

int main() {

    FILE *newBookPtr;
    FILE *oldBookPtr;
    struct clientData client;

    if ((newBookPtr = fopen("newmast.dat", "r")) == NULL)
        printf("File could not be opened.\n");
    else {
        if ((oldBookPtr = fopen("oldmast.dat", "w")) == NULL)
            printf("File could not be opened.\n");
        else {
            while (!feof(newBookPtr)) {
                fscanf(newBookPtr, "%d%s%s%f", &client.accountNumber, client.firstName, client.lastName, &client.balance);

                if (!feof(newBookPtr))
                    fprintf(oldBookPtr, "%d %s %s %.2f\n", client.accountNumber, client.firstName, client.lastName, client.balance);
            }

            fclose(oldBookPtr);
        }

        fclose(newBookPtr);
    }

    updatingMainFile(oldBookPtr);

return 0;
}

/*Updating balances using file of transactions*/

void updatingMainFile(FILE *oldMainBookPtr) {

    FILE *mainBookPtr;
    FILE *cfPtr;
    struct clientData client;
    int acc, counter;
    float trans;

    if ((cfPtr = fopen("trans.dat", "r")) == NULL)
        printf("File of transactions could not be opened.\n");
    else {
        if ((oldMainBookPtr = fopen("oldmast.dat", "r")) == NULL)
            printf("File of previous main book could not be opened.\n");
        else {
            if ((mainBookPtr = fopen("newmast.dat", "w")) == NULL)
                printf("File of new main book could not be opened.\n");
            else {
                while (!feof(oldMainBookPtr)) {
                    fscanf(oldMainBookPtr, "%d%s%s%f", &client.accountNumber, client.firstName, client.lastName, &client.balance);

                    if (!feof(oldMainBookPtr)) {
                        while (!feof(cfPtr)) {
                            fscanf(cfPtr, "%d%f", &acc, &trans);

                            if (!feof(cfPtr))
                                if (acc == client.accountNumber)
                                    client.balance += trans;
                        }

                        fprintf(mainBookPtr, "%d %s %s %.2f\n", client.accountNumber, client.firstName, client.lastName, client.balance);
                    }

                    rewind(cfPtr);
                }

                fclose(mainBookPtr);
            }

            fclose(oldMainBookPtr);
        }

        fclose(cfPtr);
    }

    /*Searching for unmatched account number*/

    if ((cfPtr = fopen("trans.dat", "r")) == NULL)
        printf("File of transactions could not be opened.\n");
    else {
        if ((oldMainBookPtr = fopen("oldmast.dat", "r")) == NULL)
            printf("File of transactions could not be opened.\n");
        else {
            while (!feof(cfPtr)) {
                fscanf(cfPtr, "%d%f", &acc, &trans);

                if (!feof(cfPtr)) {
                    counter = 0;

                    while (!feof(oldMainBookPtr)) {
                        fscanf(oldMainBookPtr, "%d%s%s%f", &client.accountNumber, client.firstName, client.lastName, &client.balance);

                        if (acc == client.accountNumber)
                            ++counter;
                    }

                    if (counter == 0)
                        printf("Unmatched transaction record for account number %d\n", acc);

                    rewind(oldMainBookPtr);
                }
            }

            fclose(oldMainBookPtr);
        }

        fclose(cfPtr);
    }
}
