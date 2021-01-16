#include <iostream>

int main() {

    bool cold = true;
    bool hot = false;

    if (cold) {
        std::cout<<"It is cold."<<std::endl;
    } else if (hot) {
        std::cout<<"It is hot."<<std::endl;
    } else {
        std::cout<<"It is just right."<<std::endl;
    }

    cold ? std::cout<<"It is cold."<<std::endl : std::cout<<"It is hot."<<std::endl;

    return 0;
}