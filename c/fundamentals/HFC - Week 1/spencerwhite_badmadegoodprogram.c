/*
   Spencer White
   CIS 170-70 - Hello World
   Prints "Hello, Spencer!" to the console
*/

// Change: Must include the header stdio.h to use printf
#include <stdio.h>

/*
   Function Description - Prints "Hello, Spencer!" to the console
   Parameters: N/A
   Returns: N/A
*/

// Change: Must change return type of main to int if returning 0
int main() {
    // Declarationss
    double A[5] = {
    9.0,
    2.9,
    3.E+25,
    .00007,
    };

    // Change: You can declare and intialize i as part of the for loop initialization
    // Change: A better description of what the for loop is doing
    // Loop through the A array and print each number and its square
    for (int i = 0; i < 5; ++i) {
        printf("element %d is %g, \tits square is %g\n", i, A[i], A[i]*A[i]);                               
    }

    return 0;                                           
}
