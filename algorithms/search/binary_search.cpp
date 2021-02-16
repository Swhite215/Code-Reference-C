#include <iostream>

int binarySearch(const int array[], int size, int value);

int main() {

    // Define SIZE
    const int SIZE = 20;

    // Define Array
    int randomNums[SIZE] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // Define Value
    int value = 5;

    // Get Position Using Binary Search
    int position = binarySearch(randomNums, SIZE, value);

    // Log Position
    if (position >= 0) {
        std::cout<<"The value "<<value<<" is located at position "<<position<<"."<<std::endl;
    } else {
        std::cout<<"The value "<<value<<" is not within the array."<<std::endl;
    }

    return 0;
}

int binarySearch(const int array[], int size, int value) {
    int first = 0; // First Array Element
    int last = size - 1; // Last Array Element
    int middle; // Midpoint of Search
    int position = -1; // Position of Search Value
    bool found = false;

    // LOOP
    while (first <= last && !found) {
        // Calculate Midpoint
        middle = (first + last) / 2;

        // Check Value - Create New Boundaries If Not Found
        if (array[middle] == value) {
            found = true;
            position = middle;
        } else if (array[middle] > value) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }

    return position;
}