#include <iostream>

int main()  {

    // Type Conversion
    long double num1 = 121.1982192;
    double num2 = 12.14331;
    float num3 = 88.444;
    unsigned long long int num4 = 1212121212;
    long long int num5 = 45635465;
    unsigned long int num6 = 98090;
    long int num7 = 1000;
    unsigned int num8 = 90;
    int num9 = 34;

    std::cout<<"The int is promoted to a double: "<<(num9 * num2)<<std::endl;
    std::cout<<"The float is promoted to a double: "<<(num3 * num2)<<std::endl;
    std::cout<<"The unsignd int is promoted to a long long int: "<<(num8 * num5)<<std::endl;

    // Type Casting
    double number = 3.7;
    int val;
    val = static_cast<int>(number);
    std::cout<<"The double 3.7 casted to an int is: "<<val<<std::endl;
    
    // Prevent Integer Division From Taking Place
    double booksPerMonth = static_cast<double>(30) / 7;
    std::cout<<"Preventing integer division of 30/7 results in: "<<booksPerMonth<<std::endl;

    // C-Style Type Cast - booksPerMonth = (double)books / month
    // Prestandard C++ Type Cast - booksPerMonth = double(books) / month

    return 0;
}