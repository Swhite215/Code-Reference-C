#include <iostream>
#include "Author.h"

Author::Author(std::string f, std::string l, char m) {
            firstName = f;
            lastName = l;
            middleInitial = m;
        }

void Author::displayAuthor() {
    std::cout<<lastName<<", "<<firstName<<" "<<middleInitial<<".";
}