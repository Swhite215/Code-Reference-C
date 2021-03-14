#include "CreditCard.h"
#include "Transaction.h"
#include <vector>
#include <iomanip>
#include <iostream>

CreditCard::CreditCard(std::string n, std::string a, std::string c , std::string s, int z, long int ss): customer(n, a, c , s, z, ss) {

    // Get Credit Score
    int creditScore = customer.getCreditScore();

    if (creditScore < 580) {
        std::cout<<"You have been denied credit. The account number will be set to 0."<<std::endl;
        accountNumber = 0;
    } else {
        std::cout<<"You have been approved for a credit card."<<std::endl;
        accountNumber = newAccountNumber;

        std::cout<<"Your account number is: "<<newAccountNumber<<"."<<std::endl;
        balance = 0;
        determineLimitAndInterest();
    }
}

/*
   Function Description: Determines Limit and Interest Based on Credit Score
   Parameters: N/A
   Returns: N/A
*/
void CreditCard::determineLimitAndInterest() {

    // Get Credit Score
    int creditScore = customer.getCScore();

    // Set Limit and Interest
    if (creditScore >= 580 && creditScore <= 669) {
        creditLimit = 5000;
        interestPercentage = .295;
    } else if (creditScore >= 670 && creditScore <= 739) {
        creditLimit = 10000;
        interestPercentage = .225;
    } else if (creditScore >= 740 && creditScore <= 799) {
        creditLimit = 15000;
        interestPercentage = .155;
    } else if (creditScore >= 800) {
        creditLimit = 20000;
        interestPercentage = .085;
    }

}

/*
   Function Description: Returns Account Number
   Parameters: N/A
   Returns: long int accountNumber
*/
long int CreditCard::getAccountNumber() {
    return accountNumber;
}

/*
   Function Description: Handles Adding a Transaction
   Parameters: N/A
   Returns: long int accountNumber
*/
void CreditCard::addTransaction(Transaction tx) {
    // Get Transaction Amount
    float amount = tx.getAmount();

    // Get Current Balance
    double amountAvailable = creditLimit - balance;

    if (amountAvailable >= amount) {
        balance += amount;
        transactions.push_back(tx);
    } else {
        std::cout<<"Transaction declined. You don't have enough remaining balance."<<std::endl;
    }
}

/*
   Function Description: Displays Credit Card Account Information
   Parameters: N/A
   Returns: N/A
*/
void CreditCard::displayInfo() {
    double amountAvailable = creditLimit - balance;
    std::cout<<"Credit Card - Account Number: "<<accountNumber<<" Balance: $"<<balance<<" Available Credit: $"<<std::fixed<<std::setprecision(2)<<amountAvailable<<"."<<std::endl;
}

/*
   Function Description: Displays Credit Card Statement
   Parameters: N/A
   Returns: N/A
*/
void CreditCard::printStatement() {

    std::cout<<"Credit Card - Account Statement"<<std::endl;

    // Display Account Holder Information
    std::cout<<"Account Holder: ";
    customer.displayInfo();

    // Display Transactions
    std::cout<<"Transactions: "<<std::endl;

    for (Transaction tx : transactions) {
        tx.display();
    }

    // Display Total Interest Due
    double interestDue = balance * interestPercentage;
    std::cout<<"Total Interest Due: $"<<std::fixed<<std::setprecision(2)<<interestDue<<"."<<std::endl;

    // Display Total Balance Due
    double totalBalanceDue = balance += interestDue;
    std::cout<<"Total Balance Due: $"<<std::fixed<<std::setprecision(2)<<totalBalanceDue<<"."<<std::endl;
}


long int CreditCard::newAccountNumber = 100200;