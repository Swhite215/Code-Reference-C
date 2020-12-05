
// Headers
#include <stdio.h>

// Function Prototypes

// Constants

int main (void) {

    FILE *fPtr; //File Pointer

    if ((fPtr = fopen("./clients.txt", "w")) == NULL) {
        puts("File could not be opened");
    } else {
        puts("Enter the Account, Name, and Balance.");
        puts("Enter EOF to end input");
        printf("%s", "? ");

        unsigned int account;
        char name[30];
        float balance;

        scanf("%d%29s%f", &account, name, &balance);

        while (!feof(stdin)) {
            fprintf(fPtr, "%d %s %.2f\n", account, name, balance);
            printf("%s", "? ");
            scanf("%d%29s%f", &account, name, &balance);
        }

        fclose(fPtr);
    }

    return 0;
}

// Functions