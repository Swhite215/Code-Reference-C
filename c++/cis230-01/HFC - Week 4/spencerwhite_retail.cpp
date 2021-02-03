/*
   Spencer White
   CIS 230-02 - Retail
   Retail Store Program
*/

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

// Retail Item Class
class RetailItem {

    // Members
    std::string name;
    std::string description;
    int unitsOnHand;
    double price;
    int reorderQuantity;
    bool isValid;

    public:
        // Default Constructor
        RetailItem() {
            name = "";
            description = "";
            unitsOnHand = 0;
            price = 0;
            reorderQuantity = 0;
            isValid = 0;
        }


        // Non-Default Constructor
        RetailItem(std::string n, std::string d, int u, double p, int r, bool v) {
            name = n;
            description = d;
            unitsOnHand = u;
            price = p;
            reorderQuantity = r;
            isValid = v;
        }

        // Accessor Functions
        std::string getName() { return name; }
        std::string getDescription() { return description; }
        int getUnits() { return unitsOnHand; }
        double getPrice() { return price; }
        int getReorderQuantity() { return reorderQuantity; }
        bool getValid() { return isValid; }

        // Mutator Functions
        void setName(std::string n) { this->name = n; }
        void setDescription(std::string d) { this->description = d; }
        void setUnits(int u) { this->unitsOnHand = u; }
        void setPrice(double p) { this->price = p; }
        void setReorderQuantity(int r) { this->reorderQuantity = r; }
        void setIsValid(bool v) { this->isValid = v; }

};

// Function Prototypes
void getMainMenuOption(char &mainMenuOption);
void addItemToInventory(int &itemCount, RetailItem items[]);
void getItemData(std::string &n, std::string &d, int &u, double &p, int &r);
void displayAllItems(RetailItem items[], int itemCount);
void checkForItem(RetailItem items[], int itemCount);
void displayReorderItems(RetailItem items[], int itemCount);
void displayItemNames(RetailItem items[]);
void updateItem(RetailItem items[], int itemCount);

int main() {

    // Max Number of Items and Item Count
    const int maxItems = 20;
    int itemCount = 0;
    
    // Retail Item Array
    RetailItem retailItems[maxItems];

    char mainMenuOption;

    do {

        getMainMenuOption(mainMenuOption);

        switch(mainMenuOption) {
            case 'A':
                if (itemCount != 20) {
                    addItemToInventory(itemCount, retailItems);
                } else {
                    std::cout<<"You are at the maximum number of items allowed."<<std::endl;
                }
                break;
            case 'B':
                displayAllItems(retailItems, itemCount);
                break;
            case 'C':
                checkForItem(retailItems, itemCount);
                break;
            case 'D':
                displayReorderItems(retailItems, itemCount);
                break;
            case 'E':
                updateItem(retailItems, itemCount);
                break;
            case 'Q':
                std::cout<<"Exiting the program..."<<std::endl;
                break;
        }

    } while(mainMenuOption != 'Q');


    return 0;
}

/*
   Function Description: Get Main Menu Choice
   Parameters: char &mainMenuOption
   Returns: N/A
*/
void getMainMenuOption(char &mainMenuOption) {

    std::cout<<"|-----------------------------------------------|"<<std::endl;
    std::cout<<"|               Retail Store Options            |"<<std::endl;
    std::cout<<"|-----------------------------------------------|"<<std::endl;
    std::cout<<"|    A) Add an item to inventory                |"<<std::endl;
    std::cout<<"|    B) Display all items in inventory          |"<<std::endl;
    std::cout<<"|    C) Check to see if an item is in inventory |"<<std::endl;
    std::cout<<"|    D) Display the items to be re-ordered      |"<<std::endl;
    std::cout<<"|    E) Update an item in inventory             |"<<std::endl;
    std::cout<<"|    Q) Quit                                    |"<<std::endl;
    std::cout<<"|-----------------------------------------------|"<<std::endl;

    // Main Menu Validation
    std::cout<<"Your choice: ";
    std::cin.get(mainMenuOption);
    mainMenuOption = toupper(mainMenuOption);

    while (mainMenuOption != 'A' && mainMenuOption != 'B' && mainMenuOption != 'C' && mainMenuOption != 'D' && mainMenuOption != 'E' && mainMenuOption != 'Q') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid choice i.e. (A, B, C, D, E, or Q): ";
        std::cin.get(mainMenuOption);
        mainMenuOption = toupper(mainMenuOption);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the Buffer

}

/*
   Function Description: Adds an Item to Retail Item Array
   Parameters: int &itemCount, RetailItems[]
   Returns: N/A
*/
void addItemToInventory(int &itemCount, RetailItem items[]) {
    // Declare Variables
    std::string name;
    std::string description;
    int unitsOnHand;
    double price;
    int reorderQuantity;
    bool isValid = true;

    // Get User Input
    getItemData(name, description, unitsOnHand, price, reorderQuantity);

    // Create New Retail Item
    RetailItem newItem = RetailItem(name, description, unitsOnHand, price, reorderQuantity, isValid);

    // Add Retail item and Increase Count
    items[itemCount] = newItem;
    itemCount++;
}

/*
   Function Description: Gets Information About Item
   Parameters: std::string name, std::string description, int unitsOnHand, double price, int reorderQuantity
   Returns: N/A
*/
void getItemData(std::string &n, std::string &d, int &u, double &p, int &r) {
    // Get Name
    std::cout<<"Please enter the name of the item: ";
    getline(std::cin, n);

    // Get Description
    std::cout<<"Please describe the item: ";
    getline(std::cin, d);

    // Get Units On Hand
    std::cout<<"Plese enter the number of these items currently in inventory [0-N]: ";
    std::cin>>u;

    while (std::cin.fail() || u < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid number [0-N]: ";
        std::cin>>u;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get Price
    std::cout<<"Please enter the price of the item [0-N]: ";
    std::cin>>p;

    while (std::cin.fail() || p < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid price [0-N]: ";
        std::cin>>p;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get Reorder Quantity
    std::cout<<"Please enter the item's reorder quantity [0-N]: ";
    std::cin>>r;

    while (std::cin.fail() || r < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Please enter a valid number [0-N]: ";
        std::cin>>r;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
   Function Description: Display All Items in Inventory
   Parameters: RetailItem items[], int itemCount
   Returns: N/A
*/
void displayAllItems(RetailItem items[], int itemCount) {
    std::cout<<std::endl;
    std::cout<<"Start of Store Inventory List"<<std::endl;

    if (itemCount == 0) {
        std::cout<<"There are no items in inventory to display..."<<std::endl;
    } else {
        for (int i = 0; i < 20; i++) {
            if (items[i].getValid()) {
                std::cout<<i<<"). "<<items[i].getName()<<std::endl;
                std::cout<<"    Description: "<<items[i].getDescription()<<std::endl;
                std::cout<<"    Available Units: "<<items[i].getUnits()<<std::endl;
                std::cout<<"    Price: $"<<items[i].getPrice()<<std::endl;
                std::cout<<"    Reorder Quantity: "<<items[i].getReorderQuantity()<<std::endl;
            }
        }
    }

    std::cout<<"End of Store Inventory List"<<std::endl;
}

/*
   Function Description: Checks if Item is in Inventory
   Parameters: RetailItem items[], int itemCount
   Returns: N/A
*/
void checkForItem(RetailItem items[], int itemCount) {

    if (itemCount == 0) {
        std::cout<<"There are no items in inventory to search..."<<std::endl;
    } else {
        // Get Name
        std::string name;
        std::cout<<"Please enter the name of the item: ";
        getline(std::cin, name);

        for (int i = 0; i < 20; i++) {
            if (name == items[i].getName()) {
                if (items[i].getUnits() > 0) {
                    std::cout<<name<<" is inside the store and "<<items[i].getUnits()<<(items[i].getUnits() == 1 ? " is " : " are ")<<"available."<<std::endl;
                    break;
                } else {
                    std::cout<<name<<" is inside the store but no stock is available."<<std::endl;
                    break;
                }
            } else if (i == 19) {
                std::cout<<name<<" is not currently available at this store."<<std::endl;
                break;
            }
        }
    }
}

/*
   Function Description: Display Items to Reorder
   Parameters: RetailItem items[], int itemCount
   Returns: N/A
*/
void displayReorderItems(RetailItem items[], int itemCount) {
    std::cout<<std::endl;
    std::cout<<"Start of Inventory to Reorder List"<<std::endl;

    if (itemCount == 0) {
        std::cout<<"There are no items in inventory to reorder..."<<std::endl;
    } else {
        for (int i = 0; i < 20; i++) {
            if (items[i].getValid() && (items[i].getUnits() <= items[i].getReorderQuantity())) {
                std::cout<<i<<"). "<<items[i].getName()<<std::endl;
            }
        }
    }

    std::cout<<"End of Inventory to Reorder List"<<std::endl;
}

/*
   Function Description: Display Item Names
   Parameters: RetailItem items[], int itemCount
   Returns: N/A
*/
void displayItemNames(RetailItem items[]) {
    std::cout<<std::endl;
    std::cout<<"Current Inventory Items"<<std::endl;

    for (int i = 0; i < 20; i++) {
        if (items[i].getValid()) {
            std::cout<<i<<"). "<<items[i].getName()<<std::endl;
        }
    }
}

/*
   Function Description: Updates an Inventory Item
   Parameters: RetailItem items[], int itemCount
   Returns: N/A
*/
void updateItem(RetailItem items[], int itemCount) {

    int indexOfItemToUpdate = 0;

    if (itemCount == 0) {
        std::cout<<"There are no items to update..."<<std::endl;
    } else {
        // Get Item to Update
        displayItemNames(items);

        std::cout<<"Please enter the number of the item you wish to update [0-"<<itemCount - 1<<"]: ";
        std::cin>>indexOfItemToUpdate;

        while (std::cin.fail() || indexOfItemToUpdate < 0 || indexOfItemToUpdate >= itemCount) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"Please enter a valid number [0-"<<itemCount - 1<<"]: ";
            std::cin>>indexOfItemToUpdate;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Get New Inputs
        std::string name;
        std::string description;
        int unitsOnHand;
        double price;
        int reorderQuantity;
        bool isValid = true;

        getItemData(name, description, unitsOnHand, price, reorderQuantity);

        // Set New Value
        RetailItem newItem = RetailItem(name, description, unitsOnHand, price, reorderQuantity, isValid);
        items[indexOfItemToUpdate] = newItem;

    }
}