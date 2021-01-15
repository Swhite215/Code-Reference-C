#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

int main () {

    // Chars and Strings
    char letter1 = 'A';
    std::string name1 = "Spencer";
    std::cout<<letter1<<". "<<name1<<std::endl;

    // Reading in a String
    char letter2 = 'B';
    std::string name2;
    std::cout<<"What is your name? ";
    getline(std::cin, name2);
    std::cout<<letter2<<". "<<name2<<std::endl;

    // Read Char
    char ch;

    std::cout<<"Enter a character and press enter: ";
    std::cin>>ch;
    std::cout<<"You entered: "<<ch<<std::endl;

    std::cin.ignore(10000, '\n');

    // Read Char with .get()
    std::cout<<"Enter another character and press enter: ";
    std::cin.get(ch);
    std::cout<<"You entered: "<<ch<<std::endl;

    std::cin.ignore(10000, '\n');

    std::cout<<"Press Enter to Continue..."<<std::endl;
    std::cin.get();

    // Useful string Functions and Operators
    std::string state = "New Jersey";
    int size = state.length();

    std::string spaces;
    spaces.assign(22, 'a');
    std::cout<<"Spaces/Repeated Characters: "<<spaces<<std::endl;

    std::string firstName = "Spencer ";
    std::string lastName = "White";

    std::cout<<firstName + lastName<<std::endl;

    char word[10] = "Hello";
    char name[20];

    strcpy(name, "Spencer White");

    std::cout<<name<<std::endl;

    char idea[5];
    std::cout<<"Enter a word: ";
    std::cin>>std::setw(5)>>idea; // Limit input to four characters plus terminating null
    std::cout<<"You entered: "<<idea<<std::endl;

    std::cin.ignore(10000, '\n');

    const int SIZE = 81;
    char sentence[SIZE];

    std::cout<<"Enter a sentence: ";
    std::cin.getline(sentence, SIZE);
    std::cout<<"You entered: "<<sentence<<std::endl;


    return 0;
}