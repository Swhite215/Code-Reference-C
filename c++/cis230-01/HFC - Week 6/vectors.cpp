#include <iostream>
#include <vector>

int main() {

    // Vector
    //      - Holds a sequence of values, or elements.
    //      - Stores its elements in contiguous memory locations.
    //      - You can use the array subscript operator to access individual elements in the vector.
    //      - You do not have to declare the number of elements that the vector will have
    //      - If you add a value to a full vector, the vector will automatically increase its size to accommodate the new value
    //      - Vectors can report the number of elements they contain

    // Define and initialize
    std::vector<int> numbers(10);
    std::vector<int> numbersTwo(10, 2);
    std::vector<int> numbersThree {10, 20, 30, 40};

    std::vector<std::string> names;
    std::vector<char> letters;
    std::vector<double> scores;

    // Storing and Retrieving
    for (int i = 0; i < 10; i++) {
        numbers[i] = i + 1;
    }

    for (int x : numbers) {
        std::cout<<x<<std::endl;
    }

    // Adding Elements to End - push_back()
    numbers.push_back(11);
    numbers.push_back(12);

    // Size
    int numValues = numbers.size();

    // Removing Elements from End - pop_back()
    numbers.pop_back();

    // Clearing a Vector
    numbers.clear();

    // Checking for Empty Vector
    if (numbers.empty()) {
        std::cout<<"There is nothing inside of the vectors array"<<std::endl;
    }

    return 0;
}