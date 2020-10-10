/*
   Spencer White
   CIS 170-70 - Miller Apartments
   Apartment Search
*/

#include <stdio.h>

// Function Prototypes
char displayMenu();
void millerMain();
int inputNumberBedrooms();
int inputNumberBathrooms();
int includeUtilities();
int determineRent(int, int, int);
int inputMaxRent();

int main ( void ) {

    char mainMenuOption;
    do {
        mainMenuOption = displayMenu();
        switch(mainMenuOption){
            case '1':
                millerMain();
                break;
            case '0':
                puts("Exiting the program...");
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", mainMenuOption);
                break;
        }
    } while (mainMenuOption != '0');

    return 0;
}

/*
   Function Description - Prints Menu and Returns User Selection
   Parameters: N/A
   Returns: char mainMenuOption
*/
char displayMenu(){
    char mainMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|     Welcome to Miller Apartments!  \t\t|\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "| Menu:    \t\t\t\t\t|\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|\tNew Search:    1\t\t        |\n");
    printf("%s", "|\tExit Program:  0\t\t        |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);
    return mainMenuOption;
}

/*
   Function Description - Main Logic Function for Miller Apartments
   Parameters: N/A
   Returns: char mainMenuOption
*/
void millerMain() {
    char searching = 'Y';

    do {

        int bedrooms = inputNumberBedrooms();
        int bathrooms = inputNumberBathrooms();
        int utilities = includeUtilities();
        int rent = determineRent(bedrooms, bathrooms, utilities);
        int maxRent = inputMaxRent();

        if (rent > maxRent) {
            printf("The rent is $%.2d more than you are be willing to pay.\n", rent - maxRent);
            printf("\nWould you like to continue searching? Y/N: ");
            scanf(" %c", &searching);
        } else if (maxRent >= rent) {

            searching = 'N';

            puts("Congratulations! We have an apartment for you to rent!");

            if (utilities == 1) {
                printf("Your total rent will be $%.2d which includes utilities.\n", rent);
            } else {
                printf("Your total rent will be $%.2d which does NOT includes utilities.\n", rent);
            }

        }

    } while (searching == 'Y' || searching == 'y');

    return;

}

/*
   Function Description - Receives number of bedrooms from user
   Parameters: N/A
   Returns: int bedrooms
*/
int inputNumberBedrooms() {
    int bedrooms = -1;
    char choice;

    do {
        printf("%s", "\nHow any bedrooms would you like? 1 - 4: ");
        scanf(" %c", &choice);
        switch(choice){
                case '1':
                    bedrooms = 1;
                    break;
                case '2':
                    bedrooms = 2;
                    break;
                case '3':
                    bedrooms = 3;
                    break;
                case '4':
                    bedrooms = 4;
                    break;
                default:
                    printf("\n%c is an invalid option, please try again...\n\n", bedrooms);
                    break;
        }
    } while ( bedrooms == -1);

    return bedrooms;
}

/*
   Function Description - Receives number of bathrooms from user
   Parameters: N/A
   Returns: int bathrooms
*/
int inputNumberBathrooms() {
    int bathrooms = -1;
    char choice;

    do {
        printf("%s", "How any bathrooms would you like? 1 - 2: ");
        scanf(" %c", &choice);
        switch(choice){
                case '1':
                    bathrooms = 1;
                    break;
                case '2':
                    bathrooms = 2;
                    break;
                default:
                    printf("\n%c is an invalid option, please try again...\n\n", bathrooms);
                    break;
        }
    } while ( bathrooms == -1);

    return bathrooms;
}

/*
   Function Description - Asks if user would like utilities included in rent
   Parameters: N/A
   Returns: int utilities
*/
int includeUtilities() {
    int utilities = -1;
    char choice;

    do {
        printf("%s", "Would you like utilities included in the rent? Y/N: ");
        scanf(" %c", &choice);
        switch(choice){
                case 'Y':
                case 'y':
                    utilities = 1;
                    break;
                case 'N':
                case 'n':
                    utilities = 0;
                    break;
                default:
                    printf("\n%c is an invalid option, please try again...\n\n", utilities);
                    break;
        }
    } while ( utilities == -1);

    return utilities;
}

/*
   Function Description - Calculates rent owed
   Parameters: int bedrooms, int bathrooms, int utilities
   Returns: int rent
*/
int determineRent(int bedrooms, int bathrooms, int utilities) {
    int rent = 0;

    switch(bedrooms) {
        case 1:
            rent = 600;
            break;
        case 2:
            rent = 750;
            break;
        case 3:
            rent = 900;
            break;
        case 4:
            rent = 1050;
            break;
        default:
            puts("An invalid number of bedrooms was input. Setting rent to $0.");
            break;
    }

    if (bathrooms == 2) {
        rent += 50;
    }

    if (utilities == 1) {
        rent += (bedrooms * 50);
    }

    return rent;
}

/*
   Function Description - Receives max rent user is willing to pay
   Parameters: N/A
   Returns: int maxRent
*/

int inputMaxRent() {
    int maxRent;

    printf("%s", "Enter the maximum amount of rent you are willing to pay: ");
    scanf("%d", &maxRent);

    return maxRent;
}