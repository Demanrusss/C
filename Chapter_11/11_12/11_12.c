/*Inventory*/
#include <stdio.h>

struct hardware {
    int number;
    char name[30];
    int quantity;
    float price;
};

int enterChoice(void);
void newRecord(FILE *);
void printOut(FILE *);
void updateRecord(FILE *);
void deleteRecord(FILE *);

int main() {

    struct hardware blankInstrument = {0, " ", 0, 0.0};
    FILE *hardwarePtr;
    int choice;

    if ((hardwarePtr = fopen("hardware.dat", "w")) == NULL)
        printf("File hardware.dat could not be opened.\n");
    else {
        for (int i = 1; i <= 100; i++)
            fwrite(&blankInstrument, sizeof(struct hardware), 1, hardwarePtr);

        fclose(hardwarePtr);
    }

    if ((hardwarePtr = fopen("hardware.dat", "r+")) == NULL)
        printf("File hardware.dat could not be opened.\n");
    else {
        while ((choice = enterChoice()) != 5)
            switch(choice) {
                case 1:
                    newRecord(hardwarePtr);
                    break;
                case 2:
                    printOut(hardwarePtr);
                    break;
                case 3:
                    updateRecord(hardwarePtr);
                    break;
                case 4:
                    deleteRecord(hardwarePtr);
                    break;
                default:
                    printf("You entered wrong choice. Try again\n? ");
                    break;
            }

        fclose(hardwarePtr);
    }

return 0;
}

int enterChoice(void) {

    int menuChoice;

    printf("\nPlease enter your choice\n"
           "1 - add a new instrument\n"
           "2 - print out all instruments\n"
           "3 - update information about instrument\n"
           "4 - delete an instrument\n"
           "5 - end program\n? ");
    scanf("%d", &menuChoice);

return menuChoice;
}

void newRecord(FILE *fhPtr) {

    struct hardware instrument;
    int num;

    printf("Enter new number record: ");
    scanf("%d", &num);

    fseek(fhPtr, (num - 1) * sizeof(struct hardware), SEEK_SET);
    fread(&instrument, sizeof(struct hardware), 1, fhPtr);

    if (instrument.number != 0)
        printf("Record number %d has already contained some information.\n", instrument.number);
    else {
        printf("Enter name of instrument, quantity and price: ");
        scanf("%s%d%f", instrument.name, &instrument.quantity, &instrument.price);
        instrument.number = num;
        fseek(fhPtr, (num - 1) * sizeof(struct hardware), SEEK_SET);
        fwrite(&instrument, sizeof(struct hardware), 1, fhPtr);
    }
}

void printOut(FILE *fhPtr) {

    struct hardware instrument;
    int counter = 0; /*Just for testing*/

    rewind(fhPtr);

    printf("%-10s%-30s%-10s%-10s\n", "Record #", "Name of instrument", "Quantity", "Price");

    while (!feof(fhPtr)) {
        ++counter;

        fread(&instrument, sizeof(struct hardware), 1, fhPtr);

        if (instrument.number != 0)
            printf("%-10d%-30s%-10d%-10.2f%10d\n", instrument.number, instrument.name, instrument.quantity, instrument.price, counter);
    }
}

void updateRecord(FILE *fhPtr) {

    struct hardware instrument;
    int num;

    printf("Enter record number you want to update: ");
    scanf("%d", &num);

    fseek(fhPtr, (num - 1) * sizeof(struct hardware), SEEK_SET);
    fread(&instrument, sizeof(struct hardware), 1, fhPtr);

    if (instrument.number == 0)
        printf("Record number %d has no information.\n", instrument.number);
    else {
        printf("Enter new quantity of instrument: ");
        scanf("%d", &instrument.quantity);

        fseek(fhPtr, (num - 1) * sizeof(struct hardware), SEEK_SET);
        fwrite(&instrument, sizeof(struct hardware), 1, fhPtr);
    }
}

void deleteRecord(FILE *fhPtr) {

    struct hardware instrument;
    struct hardware blankInstrument = {0, "", 0, 0.0};;
    int num;

    printf("Enter record you are going to delete: ");
    scanf("%d", &num);
    fseek(fhPtr, (num - 1) * sizeof(struct hardware), SEEK_SET);
    fread(&instrument, sizeof(struct hardware), 1, fhPtr);

    if (instrument.number == 0)
        printf("Record number %d has already contained some information.\n", instrument.number);
    else {
        fseek(fhPtr, (num - 1) * sizeof(struct hardware), SEEK_SET);
        fwrite(&blankInstrument, sizeof(struct hardware), 1, fhPtr);
    }
}
