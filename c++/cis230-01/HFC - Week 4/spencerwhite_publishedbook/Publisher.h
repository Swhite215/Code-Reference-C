#include <iostream>

class Publisher {
    private:
        std::string name;
        std::string city;

    public:
        Publisher(std::string n, std::string c);
        void displayPublisher();
};