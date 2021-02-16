#include <iostream>

int linearSearch(const int array[], int size, int value);

int main() {

    // Define Size
    const int SIZE = 10;
    int value = 7;

    // Define Array
    int arr[SIZE] = {1, 2, 3, 4, 5, 10, 7, 3, 9090, 11};

    // Get Position Using Linear Search
    int position = linearSearch(arr, SIZE, value);

    // Log Position
    if (position >= 0) {
        std::cout<<"The value "<<value<<" is located at position "<<position<<"."<<std::endl;
    } else {
        std::cout<<"The value "<<value<<" is not within the array."<<std::endl;
    }

    return 0;
}

int linearSearch(const int array[], int size, int value) {
    int position = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            position = i;
            break;
        }
    }

    return position;
}