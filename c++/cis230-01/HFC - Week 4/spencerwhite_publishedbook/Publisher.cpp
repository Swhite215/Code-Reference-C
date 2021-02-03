#include <iostream>
#include "Publisher.h"

Publisher::Publisher(std::string n, std::string c) {
            name = n;
            city = c;
        }

void Publisher::displayPublisher() {
    std::cout<<name<<", "<<city<<". ";
}