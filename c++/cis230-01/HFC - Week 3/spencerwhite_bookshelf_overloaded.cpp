/*
   Spencer White
   CIS 230-02 - Bookshelf with Overloaded Functions
   Calculates cost of building a bookshelf
*/

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

// Function Prototypes
void getUserInput(std::string &woodType, int &numberOfShelves, char &wantGlassWindows, int &numberOfGlassWindows);
float calculateCost(std::string woodType, int numberOfShelves, int numberOfGlassWindows);
float calculateCost(std::string woodType, int numberOfShelves);
void logCost(float totalCost);

int main() {

    std::cout<<"\n----Book Shelf Cost Calculator----"<<std::endl;

    // Needed Variables for User Input
    std::string woodType;
    int numberOfShelves;
    char wantGlassWindows;
    int numberOfGlassWindows;

    // Derived Value
    float totalCost;

    // Get User Input
    getUserInput(woodType, numberOfShelves, wantGlassWindows, numberOfGlassWindows);

    // Calculate Cost
    if (wantGlassWindows == 'Y') {  
        totalCost = calculateCost(woodType, numberOfShelves, numberOfGlassWindows);
    } else {
        totalCost = calculateCost(woodType, numberOfShelves);
    }

    // Log Cost
    logCost(totalCost);

    return 0;
}

/*

   Function Description - Receives input from user
   Parameters: std::string &woodType, int &numberOfShelves, int &wantGlassWindows, int &numberOfGlassWindows
   Returns: N/A
*/
void getUserInput(std::string &woodType, int &numberOfShelves, char &wantGlassWindows, int &numberOfGlassWindows) {
    // Get Wood Types
    std::cout<<"Would you like Mahogany, Oak, or Pine wood? ";
    getline(std::cin, woodType);

    while(woodType != "Mahogany" && woodType != "Oak" && woodType != "Pine") {
        std::cout<<"Please enter either Mahoghany, Oak, or Pine: ";
        getline(std::cin, woodType);
    }

    // Get Number of Shelves
    std::cout<<"How many shelves would you like? [1-N] ";
    std::cin>>numberOfShelves;

    while (std::cin.fail() || numberOfShelves < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter number of shelves [1-N]: ";
        std::cin>>numberOfShelves;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get If User Wants Windows
    std::cout<<"Would you like to have glass windowed doors? [Y/N] ";
    std::cin.get(wantGlassWindows);
    wantGlassWindows = toupper(wantGlassWindows);

    while (wantGlassWindows != 'Y' && wantGlassWindows != 'N') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Plese enter either Y or N: ";
        std::cin.get(wantGlassWindows);
        wantGlassWindows = toupper(wantGlassWindows);
    }

    // Get Number of Windows if User Wants Windows
    if (wantGlassWindows == 'Y') {
        std::cout<<"How many glass windowed doors would you like? [1-"<<numberOfShelves<<"] ";
        std::cin>>numberOfGlassWindows;

        while (std::cin.fail() || numberOfGlassWindows < 1 || numberOfGlassWindows > numberOfShelves) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"Please enter a valid number of glass windowed doors [1-"<<numberOfShelves<<"]: ";
            std::cin>>numberOfGlassWindows;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return;
    } else {
        numberOfGlassWindows = 0;
        return;
    }
}

/*

   Function Description - Calculates bookshelf cost without glass windowed doors
   Parameters: std::string &woodType, int &numberOfShelves
   Returns: float totalCost
*/
float calculateCost(std::string woodType, int numberOfShelves) {

    // Constants
    const float pineCost = 150.00;
    const float oakCost = 190.00;
    const float mahoganyCost = 230.00;
    const float shelfCost = 55.00;
    const float windowDoorCost = 45.00;

    // Total Cost
    float totalCost = 0;;

    // Determine Cost of Wood
    if (woodType == "Pine") {
        totalCost += pineCost;
    } else if (woodType == "Oak") {
        totalCost += oakCost;
    } else {
        totalCost += mahoganyCost;
    }

    // Calcualte Shelf Cost
    float costForShelves = numberOfShelves * shelfCost;
    totalCost += costForShelves;

    return totalCost;

}

/*
   Function Description - Calculates bookshelf cost with glass windowed doors
   Parameters: std::string &woodType, int &numberOfShelves
   Returns: float totalCost
*/
float calculateCost(std::string woodType, int numberOfShelves, int numberOfGlassWindows) {

    // Constants
    const float pineCost = 150.00;
    const float oakCost = 190.00;
    const float mahoganyCost = 230.00;
    const float shelfCost = 55.00;
    const float windowDoorCost = 45.00;

    // Total Cost
    float totalCost = 0;;

    // Determine Cost of Wood
    if (woodType == "Pine") {
        totalCost += pineCost;
    } else if (woodType == "Oak") {
        totalCost += oakCost;
    } else {
        totalCost += mahoganyCost;
    }

    // Calcualte Shelf Cost
    float costForShelves = numberOfShelves * shelfCost;
    totalCost += costForShelves;

    // Calcualte Additional Door Cost
    float costForDoors = numberOfGlassWindows * windowDoorCost;
    totalCost += costForDoors;

    return totalCost;

}

/*
   Function Description - Logs cost of bookshelf
   Parameters: float totalCost
   Returns: N/A
*/

void logCost(float totalCost) {
    std::cout<<"The total cost of your bookshelf is $"<<totalCost<<"."<<std::endl;
}