#include <iostream>
#include <vector>
#include "AccountHolder.h"
#include "Transaction.h"

class CreditCard {
    private:
        long int accountNumber;
        AccountHolder customer;
        double creditLimit;
        double balance;
        double interestPercentage;
        std::vector<Transaction> transactions;
        static long int newAccountNumber;

    public:
        CreditCard(std::string n, std::string a, std::string c , std::string s, int z, long int ss);
        void determineLimitAndInterest();
        long int getAccountNumber();
        void addTransaction(Transaction tx);
        void displayInfo();
        void printStatement();

};