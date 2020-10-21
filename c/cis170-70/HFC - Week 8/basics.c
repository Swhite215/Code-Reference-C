/*
   Spencer White
   CIS 170-70 - Chapter 7 Notes: Pointers
*/

#include <stdio.h>

// Function Prototypes

int main ( void ) {

    // Declaring Point
    int *countPtr, count; // countPrt is a pointer to an int, or countPtr points to an object of type int
    int y = 5;
    int *yPtr;

    yPtr = &y; // assigns the address of the variable y to the pointer yPtr
    
    printf("%d\n", *yPtr); // prints the variable

    return 0;
}
