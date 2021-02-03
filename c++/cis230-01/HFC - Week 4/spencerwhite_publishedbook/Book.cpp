#include <iostream>
#include "Book.h"

Book::Book(std::string fn, std::string ln, char mi, std::string n, std::string c, std::string bn, std::string e, std::string i, int cr): author(fn, ln, mi), publisher(n, c) {
    name = bn;
    edition = e;
    isbn = i;
    copyright = cr;
}
void Book::displayBook() {
    author.displayAuthor();
    std::cout<<name<<", "<<edition<<". ";
    publisher.displayPublisher();
    std::cout<<copyright<<". ISBN: "<<isbn<<"."<<std::endl;
}

