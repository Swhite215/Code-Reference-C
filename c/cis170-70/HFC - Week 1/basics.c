/*
   Spencer White
   CIS 170-70 - Lesson 2 - Practice
   Basic Variables, Input, and Printing
*/

#include <stdio.h>
#include <stdbool.h>

/*
   Function Description - 6
   Parameters: N/A
   Returns: N/A
*/

// Symbolic Constants
#define DRINKINGAGE 21;

int main () {
    // printf("Welcome to C!\n");
    // printf("Line with \t a tab!\n");
    // printf("Alert! \a\n");

    int birthYear, currentYear, age;
    char str[50];

    printf("Please enter the current year:\t");
    scanf("%d", &currentYear); // Integer

    printf("Please enter your birth year:\t");
    scanf("%d", &birthYear); // Integer

    printf("Please enter your name:\t");
    scanf("%s", str); // String

    age = currentYear - birthYear;
    bool drinker = age > DRINKINGAGE;

    printf("\nThe current year is %d", currentYear);
    printf("\n%s's birth year is %d", str, birthYear);
    printf("\n%s will be %d years old in the year %d", str, age, currentYear);

    if (drinker) {
        printf("\n%s is able to drink alcohol.\n", str);
    } else {
        printf("\n%s is not able to drink alcohol.\n", str);
    }

    return 0;
}