/*
   Spencer White
   CIS 170-70 - Array Assignment One
*/

#include <stdio.h>
#define SIZE 6

// Function Prototypes
void displayArray(int[], size_t);

int main ( void ) {

    int numArray[SIZE] = { 99, 1, 2, 3, 4, 5};

    displayArray(numArray, SIZE);

    for (int a = 0; a <= SIZE - 2; a++) {
        int swapNumOne = numArray[a];
        int swapNumTwo = numArray[a + 1];
        numArray[a] = swapNumTwo;
        numArray[a + 1] = swapNumOne;

        displayArray(numArray, SIZE);
    }

    return 0;
}

/*
   Function Description - Displays values in array
   Parameters: int array[], size_t size
   Returns: N/A
*/
void displayArray(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);

        if (i == SIZE - 1) {
            puts(" ");
        }
    }
}