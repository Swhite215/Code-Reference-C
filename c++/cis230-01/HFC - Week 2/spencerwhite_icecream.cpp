/*
   Spencer White
   CIS 230-02 - Ice Cream Progam
   Reports on ice cream sold this month
*/

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

int getScoops(std::string &flavor);
int calculateTotalScoops(int[], int);
void logBestSelling(int, std::string[]);
void logWorstSelling(int, std::string[]);

int main() {

    std::cout<<"\n----Ice Cream Scoop Tracker----"<<std::endl;

    // Declare Flavor Array
    std::string flavors[5] = {"Vanilla", "Butter Pecan", "Superman", "Chocolate Fudge", "Strawberry"};

    // Declare Scoops Sold Array
    int numberSold[5]{};

    // One By One - Collect Scoops Sold for Each Flavor
    for (int i = 0; i < 5; i++) {
        numberSold[i] = getScoops(flavors[i]);
    }

    // Calculate Total Scoops Sold
    int totalSold = calculateTotalScoops(numberSold, 5);

    // Log Total Scoops Scold
    std::cout<<"The total number of scoops sold this month is: "<<totalSold<<std::endl;

    // One By One - Print Scoops Sold For Each Flavor
    for (int i = 0; i < 5; i++) {
        std::cout<<flavors[i]<<" sold "<<numberSold[i]<<" scoops this month."<<std::endl;
    }

    // Worst Selling Flavors
    std::string worstSelling[5];
    int numberOfWorst = 0;

    // Best Selling Flavors
    std::string bestSelling[5];
    int numberOfBest = 0;

    int min = 0;
    int max = 0;

    // For flavor, determine if it is best, worst, or in the middle
    for (int i = 0; i < 5; i++) {

        // If first item, set best and worst
        if (i == 0) {
            min = numberSold[i];
            worstSelling[0] = flavors[i];
            numberOfWorst++;
            max = numberSold[i];
            bestSelling[0] = flavors[i];
            numberOfBest++;
        } else if (numberSold[i] < min) {
            min = numberSold[i];
            worstSelling[0] = flavors[i];
            numberOfWorst = 1;
        } else if (numberSold[i] == min) {
            worstSelling[numberOfWorst] = flavors[i];
            numberOfWorst++;
        } else if (numberSold[i] > max) {
            max = numberSold[i];
            bestSelling[0] = flavors[i];
            numberOfBest = 1;
        } else if (numberSold[i] == max) {
            bestSelling[numberOfBest] = flavors[i];
            numberOfBest++;
        }
    }

    // Log Results
    if (min == 0 && max == 0) {
        std::cout<<"There were no best or worst flavors for this month. Nothing was sold!"<<std::endl;
    } else if (min == max) {
        std::cout<<"There were no best or worst flavors for this month. All flavors sold an equal amount!"<<std::endl;
    }else {
        // Log Best Selling Flavors
        logBestSelling(numberOfBest, bestSelling);

        // Log Worst Selling Flavors
        logWorstSelling(numberOfWorst, worstSelling);
    }

    return 0;
}

/*
   Function Description - Calculates Total Scoops
   Parameters: int[] numberSold
   Returns: int totalSold
*/
int calculateTotalScoops(int arr[], int size) {
    int totalSold = 0;

    for (int i = 0; i < size; i++) {
        totalSold += arr[i];
    }

    return totalSold;
}

/*

   Function Description - Receives number of scoops from user
   Parameters: std::string &flavor
   Returns: int numberOfScoops
*/
int getScoops(std::string &flavor) {

    int numberOfScoops;

    std::cout<<"How many scoops of "<<flavor<<" were sold? ";
    std::cin>>numberOfScoops;

    while (std::cin.fail() || numberOfScoops < 0) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid number of "<<flavor<<" scoops sold: ";
        std::cin>>numberOfScoops;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

    return numberOfScoops;
}

/*
   Function Description - Logs Best Selling Flavor(s)
   Parameters: int numberOfBest, std::string bestSelling[]
   Returns: N/A
*/
void logBestSelling(int numberOfBest, std::string bestSelling[]) {

    if (numberOfBest == 1) {
        std::cout<<"The best selling flavor was "<<bestSelling[0]<<"."<<std::endl;
    } else if (numberOfBest > 1) {
        std::cout<<"The best selling flavors were ";
        for (int i = 0; i < numberOfBest; i++) {
            std::cout<<bestSelling[i];

            if (i + 1 != numberOfBest) {
                std::cout<<", ";
            }

            if (i == numberOfBest - 2) {
                std::cout<<"and ";
            }

        }
        std::cout<<"."<<std::endl;
    }

}

/*
   Function Description - Logs Worst Selling Flavor(s)
   Parameters: int numberOfWorst, std::string worstSelling[]
   Returns: N/A
*/
void logWorstSelling(int numberOfWorst, std::string worstSelling[]) {

    if (numberOfWorst == 1) {
        std::cout<<"The worst selling flavor was "<<worstSelling[0]<<"."<<std::endl;
    } else if (numberOfWorst > 1) {
        std::cout<<"The worst selling flavors were ";
        for (int i = 0; i < numberOfWorst; i++) {
            std::cout<<worstSelling[i];

            if (i + 1 != numberOfWorst) {
                std::cout<<", ";
            }

            if (i == numberOfWorst - 2) {
                std::cout<<"and ";
            }
        }
        std::cout<<"."<<std::endl;
    }

}