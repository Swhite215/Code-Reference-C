#include <string>
using namespace std;

class Address {
    private:
        string name;
        string street;
        string city;
    public:
        Address(string name, string street, string city);
        Address();
        void print();
};