#include <iostream>
#include <string>

int main() {

    // Number/Float Validation
    int num1, status;

    std::cout<<"Enter a number: ";
    std::cin>>num1;

    while (std::cin.fail()) {

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout<<"Please enter a valid number"<<std::endl;
        std::cin>>num1;
    }

    std::cout<<"You entered: "<<num1<<std::endl;

    std::cin.ignore(10000, '\n'); // Clear the Buffer

    // Char Validation
    char letter1;
    std::cout<<"Enter a character (A, B, or C): ";
    std::cin.get(letter1);

    while (letter1 != 'A' && letter1 != 'B' && letter1 != 'C') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout<<"Please enter a valid character i.e. (A, B, or C): ";
        std::cin.get(letter1);
    }

    std::cin.ignore(10000, '\n'); // Clear the Buffer

    std::cout<<"You entered: "<<letter1<<std::endl;

    // String Validation - Unnecessary?
    std::string name1;
    std::cout<<"What is your name? ";
    getline(std::cin, name1);
    std::cout<<"Your name is "<<name1<<std::endl;



    return 0;
}