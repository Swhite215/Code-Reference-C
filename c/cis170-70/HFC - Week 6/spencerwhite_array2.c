/*
   Spencer White
   CIS 170-70 - Array Assignment Two
*/

#include <stdio.h>
#define SIZE 6

// Function Prototypes
void displayArray(float[], size_t);
void displayMaxAndMin(float[], size_t);

int main ( void ) {

    float numArray[SIZE] = { 15.75, 22.00, 18.75, 20.45, 6.25, 12.52};

    displayArray(numArray, SIZE);
    displayMaxAndMin(numArray, SIZE);

    return 0;
}

/*
   Function Description - Displays values in array
   Parameters: float array[], size_t size
   Returns: N/A
*/
void displayArray(float array[], size_t size) {
    puts("Array Contents: ");
    for (int i = 0; i < size; i++) {
        printf("Position %d: %.2f \n", i, array[i]);
    }
}

/*
   Function Description - Displays max and min value of the array
   Parameters: float array[], size_t size
   Returns: N/A
*/
void displayMaxAndMin(float array[], size_t size) {
    int minIndex, maxIndex;
    float minValue = array[0];
    float maxValue = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            maxIndex = i;
        }

        if (array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    }

    printf("Smallest value is %.2f at position %d\n", minValue, minIndex);
    printf("Largest value is %.2f at position %d\n", maxValue, maxIndex);

}