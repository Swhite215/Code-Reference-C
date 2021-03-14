#include <iostream>
#pragma once

class Transaction {
    private:
        std::string date;
        std::string description;
        float amount;

    public:
        Transaction();
        float getAmount();
        void inputTransaction();
        void display();

};