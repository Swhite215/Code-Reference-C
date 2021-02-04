#include <iostream>

class Demo {
    public:
        Demo() {  // Constructor
            std::cout<<"Object is being created."<<std::endl;
        };
        ~Demo() { // Destructor
            std::cout<<"Object is being destroyed."<<std::endl;
        };
};

int main() { 

    Demo demo = Demo();

    return 0;
}