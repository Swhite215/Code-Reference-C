#include <iostream>
#include <cctype>

int main() {

    char letter1 = 'A';
    std::string word1;
    std::string word2;

    // 1 for true or 0 for false
    std::cout<<(isalpha(letter1))<<std::endl; // letter
    std::cout<<(isalnum(letter1))<<std::endl; // letter or digit
    std::cout<<(isdigit(letter1))<<std::endl; // digit
    std::cout<<(islower(letter1))<<std::endl; // lowercase
    std::cout<<(isprint(letter1))<<std::endl; // printable
    std::cout<<(ispunct(letter1))<<std::endl; // printable other than digit, letter, or space
    std::cout<<(isupper(letter1))<<std::endl; // uppercase
    std::cout<<(isspace(letter1))<<std::endl; // space

    return 0;
}