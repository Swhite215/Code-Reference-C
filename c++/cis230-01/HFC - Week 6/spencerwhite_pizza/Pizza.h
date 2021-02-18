#include <iostream>

class Pizza {
    private:
        std::string type;
        std::string size;
        int toppings;

    public:
        // Constructor
        Pizza(std::string t, std::string s, int top);

        // Accessors
        std::string getType();
        std::string getSize();
        int getToppings();

        // Mutators
        void setType(std::string t);
        void setSize(std::string s);
        void setToppings(int t);

        //Utility
        float calculatePrice();
        void displayPizza();

};