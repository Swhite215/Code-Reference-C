#include <iostream>

class AccountHolder {
    private:
        std::string name;
        std::string address;
        std::string city;
        std::string state;
        int zip;
        long int ssn;
        int creditScore;

    public:
        AccountHolder(std::string n, std::string a, std::string c, std::string s, int z, long int ss);
        int getCreditScore();
        void displayInfo();

        int getCScore();

};