#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

#include "Transaction.h"

Transaction::Transaction() {
    date = "";
    description = "";
    amount = 0.0;
}

float Transaction::getAmount() {
    return amount;
}

void Transaction::inputTransaction() {
    // Get Date
    std::cout<<"Please enter the date: ";
    getline(std::cin, date);

    // Get Description
    std::cout<<"Please describe the item: ";
    getline(std::cin, description);

    // Get Amount
    std::cout<<"Plese enter the total cost for the transaction: ";
    std::cin>>amount;

    while (std::cin.fail() || amount < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid cost [0-N]: ";
        std::cin>>amount;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Transaction::display() {
    std::cout<<"Transaction - Date: "<<date<<" Description: "<<description<<" Cost: $"<<std::fixed<<std::setprecision(2)<<amount<<"."<<std::endl;
}
