#include <iostream>
#include <ctype.h>

int main() {

    char menuOption;

    do {

        std::cout<<"Enter a character (A, B, C, or Q): ";
        std::cin.get(menuOption);
        menuOption = toupper(menuOption);
        std::cin.clear(); // Clear Error If Exists
        std::cin.ignore(10000, '\n'); // Clear the Buffer

        while (menuOption != 'A' && menuOption != 'B' && menuOption != 'C' && menuOption != 'Q') {

            std::cout<<"Please enter a valid option i.e. (A, B, C, or Q): ";
            std::cin.get(menuOption);
            menuOption = toupper(menuOption);
            
            std::cin.clear(); // Clear Error If Exists
            std::cin.ignore(10000, '\n'); // Clear the Buffer
        }

        switch(menuOption) {
            case 'A':
                std::cout<<"You have selected A!"<<std::endl;
                break;
            case 'B':
                std::cout<<"You have selected B!"<<std::endl;
                break;
            case 'C':
                std::cout<<"You have selected C!"<<std::endl;
                break;
            case 'Q':
                std::cout<<"Exiting the program..."<<std::endl;
                break;
            default:
                break;
        }

    } while (menuOption != 'Q');

    return 0;
}