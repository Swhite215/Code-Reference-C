#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {

    unsigned seed = time(0);
    srand(seed);

    std::cout<<rand()<<std::endl;
    std::cout<<rand()<<std::endl;
    std::cout<<rand()<<std::endl;

    // Ranged Random Value = rand() % max + 1
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 6;

    for (int i = 1; i < 10; i++) {
        // (MAX_VALUE - MIN_VALUE + 1) is the range, modulus will return values between 0 and 5, add 1 to get 1 to 6
        int dice = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        std::cout<<dice<<std::endl;
    }

    return 0;
}