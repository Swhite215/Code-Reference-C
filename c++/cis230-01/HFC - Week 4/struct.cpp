#include <iostream>

int main() {

    struct Payroll {
        int empNumbers;
        std::string name;
        double hours, payRate, grossPay;
    };

    Payroll engineer, manager, designer;
    
    engineer.empNumbers = 1;
    engineer.name = "Spencer";
    engineer.hours = 40;
    engineer.payRate = 42;
    engineer.grossPay = 87000;

    manager.empNumbers = 2;
    manager.name = "Steiner";
    manager.hours = 50;
    manager.payRate = 40;
    manager.grossPay = 85000;

    return 0;
}