/*
   Spencer White
   CIS 230-02 - Pizza
   Vector Based Pizza Ordering
*/

#include <iostream>
#include <algorithm>
#include "Order.h"

// Function Prototypes
void getCustomerInfo(std::string &n, std::string &p);
void getPizzaInfo(std::string &t, std::string &s, int &top);
void getCustomerChoice(char &customerChoice);

int main() {

    // Important Variables
    char customerChoice;
    std::string customerName;
    std::string phoneNumber;
    std::string pizzaType;
    std::string pizzaSize;
    int numberOfToppings;

    std::cout<<"---- Welcome to C++ Style Pizzas ----"<<std::endl;

    // Get Customer Information
    getCustomerInfo(customerName, phoneNumber);

    // Create Order
    Order newOrder = Order(customerName, phoneNumber);

    do {

        // Get Pizza Information
        getPizzaInfo(pizzaType, pizzaSize, numberOfToppings);

        // Add Pizza to Order
        newOrder.addPizza(pizzaType, pizzaSize, numberOfToppings);

        // Ask to Add More Pizza
        getCustomerChoice(customerChoice);

    } while (customerChoice != 'N');

    // Log Order
    newOrder.printOrder();

    return 0;
}

/*
   Function Description: Gets Customer Information
   Parameters: std::string &n, std::string &p
   Returns: N/A
*/
void getCustomerInfo(std::string &name, std::string &phoneNumber) {
    // Get Name
    std::cout<<"Please enter your name: ";
    getline(std::cin, name);

    // Get Phone Number
    std::cout<<"Please enter your phone number: ";
    getline(std::cin, phoneNumber);
}

/*
   Function Description: Gets Pizza Information
   Parameters: std::string &t, std::string &s, int &top
   Returns: N/A
*/
void getPizzaInfo(std::string &type, std::string &size, int &toppings) {
    // Get Type
    std::cout<<"Would you like deep dish, pan, or hand tossed? ";
    getline(std::cin, type);

    // Convert to Lowercase
    transform(type.begin(), type.end(), type.begin(), ::tolower);

    while (type != "deep dish" && type != "pan" && type != "hand tossed") {
        std::cout<<"Please enter either deep dish, pan, or hand tossed: ";
        getline(std::cin, type);

        // Convert to Lowercase
        transform(type.begin(), type.end(), type.begin(), ::tolower);
    }

    // Get Size
    std::cout<<"Would you like deep small, medium, or large? ";
    getline(std::cin, size);

    // Convert to Lowercase
    transform(size.begin(), size.end(), size.begin(), ::tolower);

    while (size != "small" && size != "medium" && size != "large") {
        std::cout<<"Please enter either small, medium, or large: ";
        getline(std::cin, size);

         // Convert to Lowercase
        transform(size.begin(), size.end(), size.begin(), ::tolower);
    }

    // Get Number of Toppings
    std::cout<<"How many toppings would you like? [0-N] ";
    std::cin>>toppings;

    while (std::cin.fail() || toppings < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter number of toppings [0-N]: ";
        std::cin>>toppings;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

/*

   Function Description - Receives Input to Add Another Pizza
   Parameters: char &customerChoice
   Returns: N/A
*/
void getCustomerChoice(char &customerChoice) {
    std::cout<<"Would you like add another pizza? [Y/N] ";
    std::cin.get(customerChoice);
    customerChoice = toupper(customerChoice);

    while (customerChoice != 'Y' && customerChoice != 'N') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Plese enter either Y or N: ";
        std::cin.get(customerChoice);
        customerChoice = toupper(customerChoice);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer
}