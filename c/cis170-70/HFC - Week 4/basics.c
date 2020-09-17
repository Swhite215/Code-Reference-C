/*
   Spencer White
   CIS 170-70 - Chapter 5 Notes: Functions
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>


// Enumeration Constant
enum Status { CONTINUE, WON, LOST };

// Function Prototypes
int square(int y);

int main (void) {
    // Math Librsary Functions
    double result = sqrt(10); //square root
    double result2 = cbrt(10); //cubed root
    double result3 = exp(10); // exponential root e^x
    double result4 = log(10); // natural logarithm root
    double result5 = log10(10); // logarithm of base 10
    double result6 = fabs(10); // absolute value of x as a floating point number
    double result7 = ceil(10); // round x to the smallet integer not less than x
    double result8 = floor(10); // round x to the largest integer not greater than x
    double result9 = pow(3, 2); // x raised to power y
    double result10 = fmod(10, 20); // remainder of x / y as a floating point number
    double result11 = sin(30); // trig sine of x in radians
    double result12 = cos(30); // trig cosine of x in radians
    double result13 = tan(30); // trig tangent of x in radians


    printf("%lf\n", result);
    printf("%lf\n", result2);
    printf("%lf\n", result3);
    printf("%lf\n", result4);
    printf("%lf\n", result5);
    printf("%lf\n", result6);
    printf("%lf\n", result7);
    printf("%lf\n", result8);
    printf("%lf\n", result9);
    printf("%lf\n", result10);
    printf("%lf\n", result11);
    printf("%lf\n", result12);
    printf("%lf\n", result13);

    //assert(3 == 5);

    printf("%d\n", 1 + rand() % 10); // Print a Psuedo Random Number from 1 to 10 - Uses Scaling - 10 is Scaling Factor - Should be 8
    srand(time(NULL)); // Seed Random Number Generator with Number from Computer Clock
    printf("%d\n", 1 + rand() % 10); // Print a Random Number from 1 to 10 - Uses Scaling - 10 is Scaling Factor
    // n = a + rand() % b - n is random number, a is starting number in range and b is the width, or the number of consecutive numbers in the range

    return 0;
}

// Function Definition
int square(int y) {
    return y * y;
}

/* 
    Conversion Rules:
        1. If one of the values is a long double, the other is converted to a long double.
        2. If one of the values is a double, the other is converted to a double.
        3. If one of the values is a float, the other is converted to a float.

*/