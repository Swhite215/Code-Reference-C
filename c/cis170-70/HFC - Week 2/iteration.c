/*
   Spencer White
   CIS 170-70 - CHTP: Book - Practice
*/
#include <stdio.h>

// Determien the Class Average for the Quiz
int main (void) {

    int integer = 1;

    while (integer <= 100) {
        printf("The number is: %d \n", integer);
        integer = integer + 1;
    }

    // Intialize Variables
    unsigned int counter; // number of grades to be entered
    int grade, total;
    float average;

    total = 0; // Initalize Total to Zero
    counter = 0; // Intialize Counter to Zero

    // Input the first grade (possibly the sentinel)
    printf("%s", "Enter grade. Enter -1 to end: ");
    scanf("%d", &grade);

    // Input, sum, and count the quiz grades while user has not yet entered the sentinel
    while (grade != -1) {
        // Add this grade to the running total
        total = total + grade;
        // Add one to the grade counter
        counter = counter + 1;

        // Input the next grade (possibly the sentinel)
        printf("%s", "Enter grade. Enter -1 to end: ");
        scanf("%d", &grade);
    }

    // Calculate and print the class average
    // If the counter is not equal to zero
    if (counter != 0) {
        // Calculate the Average - Casting to float to avoid integer division, explicit conversion
        average = (float) total / counter;

        // Print the average - with two digits to the right precision
        printf("Class average is %.2f\n", average);

        // Print the average - with two digits to the right precision
        printf("Class average is %.5f\n", average);

        // Assignment Operators
        printf("Average plus 1 is: %.2f", average += 1);
        printf("Average minus 1 is: %.2f", average -= 1);
        printf("Average divided by 5 is: %.2f", average /= 5);
        printf("Average multiplied by 5 is: %.2f", average *= 5);

        // Increment and Decrement
        printf("Average incremented is: %.2f", average++);
        printf("Average decremented is: %.2f", average--);
    } else {
        // Print "No grades were entered"
        puts("No grades were entered.");
    }

    return 0;
}