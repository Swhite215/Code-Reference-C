#include <iostream>
#include <iomanip>

int main () {

    // setw() manipulator
    int num1 = 2897, num2 = 5, num3 = 837;
    std::cout << std::setw(6) << num1 << std::setw(6) << num2 << std::setw(6) << num3 << std::endl;

    // setprecision() manipulator - total number of digits that appear before or after the decimal point
    double number1 = 132.364;
    double number2 = 26.91;

    double quotient = number1 / number2;

    std::cout<<quotient<<std::endl;
    std::cout<<std::setprecision(5)<<quotient<<std::endl;
    std::cout<<std::setprecision(4)<<quotient<<std::endl;
    std::cout<<std::setprecision(3)<<quotient<<std::endl;
    std::cout<<std::setprecision(2)<<quotient<<std::endl;
    std::cout<<std::setprecision(1)<<quotient<<std::endl;

    // SET PRECISION STILL APPLIES!
    std::cout<<3.111212212<<std::endl;

    // fixed manipulator - indicates that floating point output should be printed in fixed-point, or decimal notation
    double number3 = 121221.83745987348;
    std::cout<<number3<<std::endl;
    std::cout<<std::fixed<<std::setprecision(20)<<number3<<std::endl;

    // showpoint manipulator - indicates that a decimal point and decimal digits should be printed for a floating-point number, even if the value being displayed has no decimal digits
    double x = 456.0;
    std::cout<<std::setprecision(4)<<x<<std::endl;
    std::cout<<std::showpoint<<std::setprecision(4)<<x<<std::endl;

    // left manipulator
    std::cout<<std::left<<x<<std::endl;

    // right manipulator
    std::cout<<std::right<<x<<std::endl;

    return 0;
}