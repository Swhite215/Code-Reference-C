#include <iostream>
#include "Book.h"

int main() {

    Book book = Book("Jacob", "Jones", 'D', "Pearson", "New York", " A Simple Guide to Building Bookshelves", "3rd ed", "123-45-678910", 2019);
    book.displayBook();

    return 0;
}