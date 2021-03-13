#include <iostream>
#include <limits>
#include "Character.h"

// Function Prototypes
void getMainMenuOption(char &mainMenuOption);
void getBattleMenuOption(char &battleMenuOption);

int main() {

    // Initialize Heroes
    Character JOXOS = Character("Joxos", 75, 10, 75, 100, 35);
    Character VI = Character("Vi", 10, 75, 30, 50, 100);
    Character ROKH_AEGIS = Character("Rokh and Aegis", 50, 50, 50, 75, 50);

    // Initialize Monster
    Character GAROS = Character("Garos", 10, 15, 75, 3000, 200);

    // Display Main Menu

    // Menu Choice
    char mainMenuOption;

    do {

        getMainMenuOption(mainMenuOption);

        switch(mainMenuOption) {
            case 'A':
                std::cout<<"BATTLE"<<std::endl;
                break;
            case 'Q':
                std::cout<<"EXITING GAME"<<std::endl;
                break;
            default:
                break;
        }

    } while (mainMenuOption != 'Q');

    return 0;
}
/*
   Function Description: Obtains Main Menu Option
   Parameters: char &mainMenuOption
   Returns: N/A
*/
void getMainMenuOption(char &mainMenuOption) {

    std::cout<<"|-----------------------------------------------|"<<std::endl;
    std::cout<<"|               Main Menu                       |"<<std::endl;
    std::cout<<"|-----------------------------------------------|"<<std::endl;
    std::cout<<"|    A) Battle                                  |"<<std::endl;
    std::cout<<"|    Q) Quit                                    |"<<std::endl;
    std::cout<<"|-----------------------------------------------|"<<std::endl;

    // Main Menu Validation
    std::cout<<"Your choice: ";
    std::cin.get(mainMenuOption);
    mainMenuOption = toupper(mainMenuOption);

    while (mainMenuOption != 'A' && mainMenuOption != 'Q') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid choice i.e. (A or Q): ";
        std::cin.get(mainMenuOption);
        mainMenuOption = toupper(mainMenuOption);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

}

/*
   Function Description: Obtains Battle Menu Option
   Parameters: char &battleMenuOption
   Returns: N/A
*/
void getBattleMenuOption(char &battleMenuOption) {

    std::cout<<"|-----------------------------------------------|"<<std::endl;
    std::cout<<"|               Battle Menu                     |"<<std::endl;
    std::cout<<"|-----------------------------------------------|"<<std::endl;
    std::cout<<"|    A) Attack                                  |"<<std::endl;
    std::cout<<"|    B) Heal                                    |"<<std::endl;
    std::cout<<"|    C) Defend                                  |"<<std::endl;
    std::cout<<"|    Q) Quit (Skip Turn)                        |"<<std::endl;
    std::cout<<"|-----------------------------------------------|"<<std::endl;

    // Main Menu Validation
    std::cout<<"Your choice: ";
    std::cin.get(battleMenuOption);
    battleMenuOption = toupper(battleMenuOption);

    while (battleMenuOption != 'A' && battleMenuOption != 'B' && battleMenuOption != 'C' && battleMenuOption != 'Q') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid choice i.e. (A, B, C, or Q): ";
        std::cin.get(battleMenuOption);
        battleMenuOption = toupper(battleMenuOption);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

}