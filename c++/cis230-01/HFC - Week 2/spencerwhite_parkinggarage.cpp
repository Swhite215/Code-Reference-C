/*
   Spencer White
   CIS 230-02 - Parking Garage Assignment
   Calculates parking garage fee
*/

// Potential Issue: I am allowing a user to enter 0 hours to simulate the scenario they entered and immediately left parking garage

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

// Function Prototypes
char getContinueChoice();
float getHoursParked();
float calculateTotalCharge(float);

int main() {

    char continueChoice;

    do {

        std::cout<<"\n----Parking Garage Fee Calculator----"<<std::endl;

        float hoursParked = getHoursParked();

        float totalCharge = calculateTotalCharge(hoursParked);

        std::cout<<"Your total parking charge for today is: $"<<totalCharge<<std::endl;

        continueChoice = getContinueChoice();

    } while(continueChoice != 'N');

    return 0;
}

/*
   Function Description - Receives choice to continue from user
   Parameters: N/A
   Returns: char continueChoice
*/
char getContinueChoice() {
    char continueChoice;
    std::cout<<"Would you like to calculate another fee? (Y, N): ";
    std::cin.get(continueChoice);
    continueChoice = toupper(continueChoice);

    while (continueChoice != 'Y' && continueChoice != 'N') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

        std::cout<<"Please enter either Y or N: ";
        std::cin.get(continueChoice);
        continueChoice = toupper(continueChoice);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

    return continueChoice;
}

/*
   Function Description - Receives number of hours from user
   Parameters: N/A
   Returns: float hoursParked
*/
float getHoursParked() {
    float hoursParked;

    std::cout<<"Enter Total Time Parked: ";
    std::cin>>hoursParked;

    while (std::cin.fail() || hoursParked > 24 || hoursParked < 0) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid number of hours (0 - 24): ";
        std::cin>>hoursParked;
    }

    std::cin.ignore(10000, '\n'); // Clear the Buffer

    return hoursParked;
}

/*
   Function Description - Calculates total parking charge
   Parameters: float hoursParked
   Returns: float totalCharge
*/
float calculateTotalCharge(float hoursParked) {

    float totalCharge;

    if (hoursParked == 24) {
        totalCharge = 20.00;
    } else if (hoursParked <= 3) {
        totalCharge = 2.50;
    } else {
        // Handle if hours are greater than 3 and less than 24
        float initialCharge = 2.50;

        int hours = static_cast<int>(hoursParked); // Get Base Hours
        int extraHoursToCharge = hours - 3; // Get Extra Hours to Charge

        if (hoursParked > hours) {
            extraHoursToCharge++; // Add Partial Hour as Chargeable Hour
        }
        
        float additionalCharge = extraHoursToCharge * 1.00; // Calculate Additional Charge

        totalCharge = initialCharge + additionalCharge; // Calculate Total Charge

        if (totalCharge > 20) { // If charge is over 20, then set totalCharge to the maximum charge of $20
            totalCharge = 20.00;
        }
    }

    return totalCharge;

}
