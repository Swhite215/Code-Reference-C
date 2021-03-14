#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include "CreditCard.h"
#include "Transaction.h"

// Prototypes
void getMainMenuOption(char &mainMenuOption);
CreditCard createAccount();
void getAccountNumber(long int &accountNumber);
void checkAndDisplayAccountDetails(long int accountNumber, std::vector<CreditCard> creditCards);
void checkAndAddTransaction(long int accountNumber, std::vector<CreditCard> &creditCards);

int main() {

    char mainMenuOption;
    std::vector<CreditCard> creditCards;
    int creditCardAccounts = 0;

    do {

        getMainMenuOption(mainMenuOption);

        switch(mainMenuOption) {
            case 'A':
                {
                    CreditCard newAccount = createAccount();

                    if (newAccount.getAccountNumber() != 0) {
                        creditCards.push_back(newAccount);
                        creditCardAccounts++;
                    }
                }
                break;
            case 'B':
                {
                    long int accountNumber;
                    getAccountNumber(accountNumber);
                    checkAndDisplayAccountDetails(accountNumber, creditCards);
                }
                break;
            case 'C':
                {
                    long int accountNumber;
                    getAccountNumber(accountNumber);
                    checkAndAddTransaction(accountNumber, creditCards);
                }
                break;
            case 'D':
                // PRINT MONTHLY STATEMENTS
                break;
            case 'Q':
                std::cout<<"Exiting the program..."<<std::endl;
                break;
        }

    } while(mainMenuOption != 'Q');


    return 0;
}

/*
   Function Description: Get Main Menu Choice
   Parameters: char &mainMenuOption
   Returns: N/A
*/
void getMainMenuOption(char &mainMenuOption) {

    std::cout<<"|-----------------------------------------------------------------|"<<std::endl;
    std::cout<<"|               HFC Credit Company                                |"<<std::endl;
    std::cout<<"|-----------------------------------------------------------------|"<<std::endl;
    std::cout<<"|    A) Create and Account and Apply for a Credit Card            |"<<std::endl;
    std::cout<<"|    B) See Balance and Available Credit for an Existing Account  |"<<std::endl;
    std::cout<<"|    C) Input a Transaction                                       |"<<std::endl;
    std::cout<<"|    D) Print All Monthly Statements                              |"<<std::endl;
    std::cout<<"|    Q) Quit                                                      |"<<std::endl;
    std::cout<<"|-----------------------------------------------------------------|"<<std::endl;

    // Main Menu Validation
    std::cout<<"Your choice: ";
    std::cin.get(mainMenuOption);
    mainMenuOption = toupper(mainMenuOption);

    while (mainMenuOption != 'A' && mainMenuOption != 'B' && mainMenuOption != 'C' && mainMenuOption != 'D' && mainMenuOption != 'Q') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid choice i.e. (A, B, C, D, or Q): ";
        std::cin.get(mainMenuOption);
        mainMenuOption = toupper(mainMenuOption);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

}

/*
   Function Description: Creates a Credit Card Account
   Parameters: N/A
   Returns: CreditCard newCreditCardAccount
*/
CreditCard createAccount() {

    std::string name;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    long int ssn;

    // Get Name
    std::cout<<"Please enter your name: ";
    getline(std::cin, name);

    // Get Address
    std::cout<<"Please enter your address: ";
    getline(std::cin, address);

    // Get City
    std::cout<<"Please enter your city: ";
    getline(std::cin, city);

    // Get City
    std::cout<<"Please enter your state: ";
    getline(std::cin, state);

    // Get Zip
    std::cout<<"Please enter your zip: ";
    std::cin>>zip;

    while (std::cin.fail() || zip < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid zip [XXXXX]: ";
        std::cin>>zip;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // Get Social Security Number
    std::cout<<"Please enter your social security number: ";
    std::cin>>ssn;

    while (std::cin.fail() || ssn < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid social security number [XXXXXXXXXX]: ";
        std::cin>>ssn;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    CreditCard newCreditCardAccount = CreditCard(name, address, city, state, zip, ssn);

    return newCreditCardAccount;
}

/*
   Function Description: Get Account Number to Search
   Parameters: long int &accountNumber
   Returns: N/A
*/
void getAccountNumber(long int &accountNumber) {
    // Get Account Number
    std::cout<<"Please enter an account number: ";
    std::cin>>accountNumber;

    while (std::cin.fail() || accountNumber < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid account number [XXXXX]: ";
        std::cin>>accountNumber;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
   Function Description: Check Account and Display Account Details
   Parameters: long int &accountNumber, std::vector<CreditCard> creditCards
   Returns: N/A
*/
void checkAndDisplayAccountDetails(long int accountNumber, std::vector<CreditCard> creditCards) {
    int foundFlag = 0;

    for (CreditCard accounts : creditCards) {
        if (accounts.getAccountNumber() == accountNumber) {
            accounts.displayInfo();
            foundFlag = 1;
            break;
        }
    }

    if (foundFlag == 0) {
        std::cout<<"No account with account number "<<accountNumber<<" exists."<<std::endl;
    }

}

/*
   Function Description: Check Account and Add a Transaction
   Parameters: long int &accountNumber, std::vector<CreditCard> creditCards
   Returns: N/A
*/
void checkAndAddTransaction(long int accountNumber, std::vector<CreditCard> &creditCards) {
    int foundFlag = 0;

    // PASS VECTOR BY REFERENCE AND THEN PASS VECTOR CLASS BY REFERENCE TO MODIFY VECTOR VALUE
    for (CreditCard &accounts : creditCards) {
        if (accounts.getAccountNumber() == accountNumber) {
            Transaction newTransaction = Transaction();
            newTransaction.inputTransaction();
            accounts.addTransaction(newTransaction);
            foundFlag = 1;
            break;
        }
    }

    if (foundFlag == 0) {
        std::cout<<"No account with account number "<<accountNumber<<" exists."<<std::endl;
    }

}