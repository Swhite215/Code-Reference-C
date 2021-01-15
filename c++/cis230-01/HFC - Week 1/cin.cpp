#include <iostream>

int main() {

    // Single Value
    int length;

    std::cout<<"Enter a length value: ";
    std::cin>>length; // >> - stream extraction operator

    std::cout<<"The length you entered is "<<length<<std::endl;

    // Multiple Values - Same Type
    int x, y;
    std::cout<<"Enter two numbers, separated by a space: ";
    std::cin>>x>>y;

    std::cout<<"X is "<<x<<" Y is "<<y<<std::endl;

    // Multiple Values - Different Type
    int whole;
    double fractional;
    char letter;

    std::cout<<"Enter an integer, a double, and a character: ";
    std::cin>>whole>>fractional>>letter;

    std::cout<<"You entered "<<whole<<" and "<<fractional<<" and "<<letter<<std::endl;

    return 0;
}