#include <iostream>
#include <vector>
#include <iomanip>
#include "Order.h"

// Constructor
Order::Order(std::string n, std::string p) {
    name = n;
    phoneNumber = p;
}

// Accessors
std::string Order::getName() { return name; }
std::string Order::getPhoneNumber() { return phoneNumber; }

// Mutators
void Order::setName(std::string n) { name = n; }
void Order::setPhoneNumber(std::string p) { phoneNumber = p; }

// Utility
void Order::addPizza(std::string t, std::string s, int top) {
    Pizza newPizza = Pizza(t, s, top);
    pizzas.push_back(newPizza);
}

// Utility
void Order::printOrder() {
    float total = 0;

    std::cout<<"\nPizza Order Receipt for: "<<name<<std::endl;

    for (Pizza x : pizzas) {
        x.displayPizza();
        total += x.calculatePrice();
    }

    std::cout<<"Total Price: $"<<std::fixed<<std::setprecision(2)<<total<<"."<<std::endl;
}