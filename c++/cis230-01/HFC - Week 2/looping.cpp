#include <iostream>

int main() {
    
    // While
    bool spin = true;
    int counter = 0;

    while(spin) {
        std::cout<<"Spin me right round, baby right round..."<<std::endl;
        spin = false;
        counter++;
        counter--;
    }

    // Sentinel
    int sentinel;

    std::cout<<"Enter 1 to Go or -1 to Stop: ";
    std::cin>>sentinel;

    while(sentinel != -1) {
        std::cout<<"Going!"<<std::endl;

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout<<"Enter 1 to GO or -1 to STOP: ";
        std::cin>>sentinel;
    }

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    // Do While
    int goFlag = 0;

    do {
        std::cout<<"Keep Going!"<<std::endl;
    } while (goFlag != 0);
    

    // For
    for (int i = 10; i > 0; i--) {
        std::cout<<"Countdown: "<<i<<std::endl;
    }

    for (int j = 0; j < 2; j++) {
        for (int d = 0; d < 3; d++) {

            if (d == 2) {
                break;
            } else if (d == 1) {
                continue;
            }
            
            std::cout<<"J is: "<<j<<" and D is: "<<d<<std::endl;
        }
    }

    return 0;
}