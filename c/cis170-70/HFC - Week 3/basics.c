/*
   Spencer White
   CIS 170-70 - Chapter 4 Notes: Program Control
*/

#include <stdio.h>
#include <math.h>

// Function Prototypess
int main (void) {

    // Counter Controlled Iteration - While Loop
    unsigned counter = 1;
    
    while (counter <= 10) {
        printf("%u\n", counter);
        ++counter; // Increment
    }

    // Counter variable here only exists until the loop terminates
    for (unsigned int counter = 1; counter <= 10; ++counter) {
        printf("%u\n", counter);
    }

    for (unsigned int counter = 10; counter > 0; counter--) {
        printf("%d\n", counter);
    }
    
    double principal = 10000; //starting principal
    double rate = .05; // annual interest rate

    printf("%4s%21s\n", "Year", "Amount on deposit");

    for (unsigned int year = 1; year <= 10; ++year) {
        double amount = principal * pow(1.0 + rate, year);
         printf("%4u%21.2f\n", year, amount);
    }

    unsigned int aCount = 0;
    unsigned int bCount = 0;
    unsigned int cCount = 0;
    unsigned int dCount = 0;
    unsigned int fCount = 0;

    puts("Enter the letter grades.");
    puts("Enter the EOF character to end input.");
    int grade;

    while ((grade = getchar()) != EOF) {
        switch(grade) { //controlling expression

            case 'A':
            case 'a':
                ++aCount;
                break;

            case 'B':
            case 'b':
                ++bCount;
                break;

            case 'C':
            case 'c':
                ++cCount;
                break;

            case 'D':
            case 'd':
                ++dCount;
                break;

            case 'F':
            case 'f':
                ++fCount;
                break;

            // The below is needed, two loops actually occur, 
            //the character loop, and then the loop with the newline character caused by hitting enter
            case '\n': 
            case '\t': 
            case ' ': 
                break;

            default:
                printf("%s", "Incorrect letter grade entered.");
                puts("Enter a new grade.");
                break;
        }
    }

    puts("\nTotals for each letter grade are:"); 
    printf("A: %u\n", aCount); 
    printf("B: %u\n", bCount); 
    printf("C: %u\n", cCount); 
    printf("D: %u\n", dCount); 
    printf("F: %u\n", fCount);

    int cheers = 3;

    do {
        printf("%s", "Hip, hip, hooray!\n");
        cheers--;
    } while (cheers > 0);

    // Increment Options
        // counter = counter + 1
        // counter += 1
        // ++counter
        // counter++

    // Logical Operators: ||, &&, !

    return 0;
}