#include "CreditCard.h"
#include <iostream>
#include <vector>

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

long int CreditCard::newAccountNumber = 100200;