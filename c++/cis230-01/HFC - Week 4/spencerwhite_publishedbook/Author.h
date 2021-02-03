#include <iostream>

class Author {
    private:
        std::string firstName;
        std::string lastName;
        char middleInitial;

    public:
        Author(std::string f, std::string l, char m);
        void displayAuthor();
};