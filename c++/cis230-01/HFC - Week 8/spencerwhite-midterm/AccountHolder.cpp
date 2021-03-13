#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AccountHolder.h"

const int MIN_VALUE = 300;
const int MAX_VALUE = 850;

AccountHolder::AccountHolder(std::string n, std::string a, std::string c, std::string s, int z, long int ss) {
    name = n;
    address = a;
    city = c;
    state = s;
    zip = z;
    ssn = ss;
}

int AccountHolder::getCreditScore() {

    // Generate Random Number as Credit Score
    int creditScore = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    
    // Return Credit Score
    return creditScore;
}

int AccountHolder::getCScore() {
    return creditScore;
}

void AccountHolder::displayInfo() {
    std::cout<<name<<" lives at "<<address<<"."<<std::endl;
}