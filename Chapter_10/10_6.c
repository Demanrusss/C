#include <stdio.h>

struct customer {
    char lastName[15];
    char firstName[15];
    int customerNumber;
    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;

int main() {

    customerPtr = &customerRecord;

    customerRecord.lastName[0] = 'Y';
    (*customerPtr).lastName[1] = 'e';
    customerRecord.firstName[0] = 'D';
    (*customerPtr).firstName[1] = 'm';
    customerRecord.customerNumber = 17;
    (*customerPtr).customerNumber += 1;
    customerRecord.personal.phoneNumber[0] = '+';
    customerPtr->personal.phoneNumber[1] = '7';
    customerRecord.personal.address[0] = 'A';
    customerPtr->personal.address[1] = 'l';
    customerRecord.personal.city[0] = 'A';
    customerPtr->personal.city[1] = 'l';
    customerRecord.personal.state[0] = 'A';
    customerPtr->personal.state[1] = 'l';
    customerRecord.personal.zipCode[0] = '0';
    customerPtr->personal.zipCode[1] = '5';

return 0;
}
