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

/*
   Function Description: Generates and Returns a Credit Score
   Parameters: N/A
   Returns: int creditScore
*/
int AccountHolder::getCreditScore() {

    // Generate Random Number as Credit Score
    int creditScore = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    
    // Return Credit Score
    return creditScore;
}

/*
   Function Description: Returns Credit Score
   Parameters: N/A
   Returns: int creditScore
*/
int AccountHolder::getCScore() {
    return creditScore;
}

/*
   Function Description: Displays Account Name and Address
   Parameters: N/A
   Returns: N/A
*/
void AccountHolder::displayInfo() {
    std::cout<<name<<" lives at "<<address<<"."<<std::endl;
}