/*
   Spencer White
   CIS 170-70 - Chapter 6 Notes: Arrays
*/

#include <stdio.h>

// Symbolic Constants
#define SIZE 100
#define HOURS_IN_A_DAY 24

// Enumeration Constant

// Function Prototypes
void displayArray(int[], size_t);
void displayNumber(int);
void tryToModifyArray(const int[], size_t);
size_t linearSearch(const int array[], int key, size_t size);

int main (void) {

    // Defining Arrays
    int c[12];

    // Loop Initializer
    for (size_t i = 0; i < 5; ++i) {
        c[i] = 0;
    }

    // Intializer
    int n[5] = { 32, 27, 64, 18, 95};

    // Zero Intializer
    int g[10] = { 0 };

    // Five Characters plus NUll Character (String Termination)
    char string[] = "first";

    char string2[20];

    // Character Array for storing at most 19 charactes and a terminating null character
    scanf("%19s", string2);

    int hourlyTemperatures[HOURS_IN_A_DAY];

    // Passes Array by Reference
    displyaArray(hourlyTemperatures, HOURS_IN_A_DAY);

    // Passes by Value
    displayNumber(hourlyTemperatures[1]);

    // Searching Arrays - Linear Search
    int a[SIZE];

    for (size_t x = 0; x < SIZE; ++x) {
        a[x] = 2 * x;
    }

    printf("Enter the integer search ley: ");
    int searchKey;
    scanf("%d", &searchKey);

    size_t index = linearSearch(a, searchKey, SIZE);

    if (index != -1) {
        printf("Found value at index %d\n", index);
    } else {
        puts("Value not found");
    }

    // Multidimensional Arrays
    int f[2][2] = {{1, 2}, {3,4}};
    
    // Variable Length Arrays - Get Something, Measure Length, Create Array of That Length


    return 0;
}

// Function Definition
void displayArray(int b[], size_t size) {

}

void displayNumber(int temp) {
    printf("%d", temp);
}

// Will NOT allow array to be modified if parameter is set to const
void tryToModifyArray(const int b[], size_t size) {
    b[0] = 1;
}

size_t linearSearch(const int array[], int key, size_t size) {
    for (size_t n = 0; n < size; ++n) {
        if (array[n] == key) {
            return n;
        }
    }

    return -1;
}