#include <iostream>
#include "Author.h"
#include "Publisher.h"

class Book {
    private:
        Author author;
        Publisher publisher;
        std::string name;
        std::string edition;
        std::string isbn;
        int copyright;

    public:
        Book(std::string fn, std::string ln, char mi, std::string n, std::string c, std::string bn, std::string e, std::string i, int cr); 
        void displayBook();

};