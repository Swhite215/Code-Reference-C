#include <iostream>

int main() {

    // Should overflow, 
    short num1 = 32767;

    std::cout<<num1 + 1<<std::endl;

    return 0;
}