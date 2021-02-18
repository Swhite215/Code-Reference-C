#include <iostream>
#include <vector>
#include "Pizza.h"

class Order {
    private:
        std::vector<Pizza> pizzas;
        std::string name;
        std::string phoneNumber;

    public:
        Order(std::string n, std::string p);

        // Accesssors
        std::string getName();
        std::string getPhoneNumber();

        // Mutators
        void setName(std::string);
        void setPhoneNumber(std::string);

        // Utility
        void addPizza(std::string, std::string, int);
        void printOrder();
        void calculatePrice();
};