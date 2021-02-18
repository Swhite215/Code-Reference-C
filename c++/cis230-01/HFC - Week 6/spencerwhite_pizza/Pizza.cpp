#include <iostream>
#include "Pizza.h"

// Constructor
Pizza::Pizza(std::string t, std::string s, int top) {
    type = t;
    size = s;
    toppings = top;
}

// Accessors
std::string Pizza::getType() { return type; }
std::string Pizza::getSize() { return size; }
int Pizza::getToppings() { return toppings; }

// Mutators
void Pizza::setType(std::string t) { type = t; }
void Pizza::setSize(std::string s) { size = s; }
void Pizza::setToppings(int t) { toppings = t; }

// Utility
float Pizza::calculatePrice() {
    float price = 0;

    // Determine Size Price
    if (size == "small") {
        price += 10.00;
    } else if (size == "medium") {
        price += 14.00;
    } else {
        price += 17;
    }

    // Add Toppings Charge
    price += (toppings * 2.00);

    return price;
}

void Pizza::displayPizza() {
    std::cout<<"    - A "<<size<<" "<<type<<" with "<<toppings<<" topping"<<(toppings > 1 || toppings == 0 ? "s." : ".")<<std::endl; 
}