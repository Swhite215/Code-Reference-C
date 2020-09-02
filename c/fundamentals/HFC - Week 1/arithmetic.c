/*
   Spencer White
   CIS 170-70 - Lesson 2 - Arithmetic
   Basic Arithmetic
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    int a, b;

    printf("\nPlease enter a number:\t");
    scanf("%d", &a);

    printf("\nPlease enter another number:\t");
    scanf("%d", &b);

    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;

    printf("\nThe sum of these two numbers is: %d", sum);
    printf("\nThe difference of these two numbers is: %d", difference);
    printf("\nThe product of these two numbers is: %d", product);
    printf("\nThe quotient of these two numbers is: %d", quotient);
    printf("\nThe remainder after division of these two numbers is: %d\n", remainder);
    
    /*
        OOO - Parentheses, Multiplication, Division, Remainder, Addition, Substraction, Assignment
    */

    return 0;
}