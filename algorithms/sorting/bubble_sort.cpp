#include <iostream>

void swap(int *xp, int *yp);
void bubbleSort(int arr[], int size);
void printArray(int arr[], int size);

int main() {

    // Define Size
    const int SIZE = 7;

    // Define Array
    int arr[SIZE] = {64, 34, 25, 12, 22, 11, 90};
    std::cout<<"Unsorted Array: ";
    printArray(arr, SIZE);

    // Sort Array
    bubbleSort(arr, SIZE);

    // Print Array
    std::cout<<"Sorted Array: ";
    printArray(arr, SIZE);

    return 0;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[], int size) {
    // Decreases Number of Comparisons After Each Loops
    for (int maxElement = size - 1; maxElement > 0; maxElement--) {

        // Perform Next Loop of Comparisons Up to Last Placed Item
        for (int index = 0; index < maxElement; index++) {

            // Print Array to See Update
            printArray(array, 7);

            // Compare Value and Swap if Necessary
            if (array[index] > array[index + 1]) {
                swap(&array[index], &array[index+1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}