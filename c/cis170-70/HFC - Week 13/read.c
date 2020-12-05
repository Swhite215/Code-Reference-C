
// Headers
#include <stdio.h>

// Function Prototypes

// Constants

int main (void) {

    FILE *fPtr; //File Pointer

    if ((fPtr = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be opened");
    } else {
        unsigned int account;
        char name[30];
        float balance;

        printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
        fscanf(fPtr, "%d%29s%f", &account, name, &balance);

        while (!feof(fPtr)) {
            printf("%-10d%-13s%7.2f\n", account, name, balance);
            fscanf(fPtr, "%d%29s%f", &account, name, &balance);
        }

        fclose(fPtr);
    }

    return 0;
}

// Functions