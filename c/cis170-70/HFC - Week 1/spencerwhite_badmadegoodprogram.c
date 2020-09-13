/*
   Spencer White
   CIS 170-70 - Bad Made Good Program
   Loops through an array and prints each value and its square
*/

// Change: Must include the header stdio.h to use printf method
#include <stdio.h>

/*
   Function Description - Loops through an array and prints each value and its square
   Parameters: N/A
   Returns: N/A
*/

// Change: Must change return type of main to int if returning 0
// Change: Fix all indentation for readability
int main() {
    // Declarations
    double A[5] = {
        9.0,
        2.9,
        3.E+25,
        .00007,
    };

    // Change: You can declare and intialize i as part of the for loop initialization
    // Change: A better description of what the for loop is doing
    // Loop through the array and print each value and its square
    for (int i = 0; i < 5; ++i) {
        printf("element %d is %g, \tits square is %g\n", i, A[i], A[i]*A[i]);                               
    }

    return 0;                                           
}
