/*
   Spencer White
   CIS 230-02 - Person
   Simple Person Class
*/

#include <iostream>

class Person {
    private:
        std::string lastName;
        std::string firstName;

    public:
        Person() {
            lastName = " ";
            firstName = " ";
        }

        Person(std::string l, std::string f) {
            lastName = l;
            firstName = f;
        }

        void displayPerson() {
            std::cout<<lastName<<", "<<firstName<<std::endl;
        }
};

int main() {

    Person p1 = Person("White", "Spencer");
    p1.displayPerson();

    return 0;
}