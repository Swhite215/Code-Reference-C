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
                // SET BALANCE
                break;
            case 'C':
                // INPUT A TRANSACTION
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
    std::cout<<"|    B) Set Balance and Available Credit for an Existing Account  |"<<std::endl;
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