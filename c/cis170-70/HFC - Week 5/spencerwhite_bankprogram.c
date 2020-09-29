/*
   Spencer White
   CIS 170-70 - Bank Program
   Interactive Simulation of Bank Transactions
*/

#include <stdio.h>

// Function Prototypes
char showMainMenu();
float inputDeposit(float);
float inputWithdrawal(float);
void displayBalance(float);

int main ( void ) {

    float balance = 0;

    char mainMenuOption;
    do {
        mainMenuOption = showMainMenu();
        switch(mainMenuOption){
            case 'D':
            case 'd':
                puts("\n-------------------Deposit Module------------------");
                balance = inputDeposit(balance);
                break;
            case 'W':
            case 'w':
                puts("\n-----------------Withdrawal Module-----------------");
                balance = inputWithdrawal(balance);
                break;
            case 'B':
            case 'b':
                puts("\n----------------Balance Module---------------");
                displayBalance(balance);
                break;
            case 'Q':
            case 'q':
                puts("Thank you!");
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", mainMenuOption);
                break;
        }
    } while (mainMenuOption != 'Q' && mainMenuOption != 'q');

    return 0;
}


/*
   Function Description - Prints Main Menu and Returns User Selection
   Parameters: N/A
   Returns: char mainMenuOption
*/
char showMainMenu(){
    char mainMenuOption;
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|     Welcome to the HFC Federal Credit Union!   |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|     Please select from the following menu:    |\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|\tD: Make a Deposit\t\t        |\n");
    printf("%s", "|\tW: Make a Withdrawal\t\t        |\n");
    printf("%s", "|\tB: Check Your Acccount Balance\t        |\n");
    printf("%s", "|\tQ: Quit\t\t\t\t        |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);
    return mainMenuOption;
}

/*
   Function Description - Deposits money into account
   Parameters: float balance
   Returns: float newBalance
*/
float inputDeposit(float balance) {
    float deposit;
    int inputCheck;

    printf("%s", "Enter the amount to deposit: ");
    scanf("%f", &deposit);

    return balance + deposit;
}

/*
   Function Description - Withdraws money from the account
   Parameters: float balance
   Returns: float newBalance
*/
float inputWithdrawal(float balance) {
    float withdraw;

    printf("%s", "Enter the amount to withdraw: ");
    scanf("%f", &withdraw);

    if (withdraw > balance) {
        puts("You don't have enough money to withdraw that amount.");
        return '0';
    } else {
        return balance - withdraw;
    }

}

/*
   Function Description - Prints current balance
   Parameters: float balance
   Returns: N/A
*/
void displayBalance(float balance) {
    printf("Your current balance is $%.2f.\n", balance);
}
