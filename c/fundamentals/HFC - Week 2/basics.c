/*
   Spencer White
   CIS 170-70 - CHTP: Book - Practice
*/
#include <stdio.h>
#include <stdbool.h>

int main (void) {
    printf("Hello World!\n"); // New Line
    printf("Hello World!\t\n"); // Horizontal Tab
    printf("Hello World!\a\n"); // Alert
    printf("Hello World!\\\n"); // Backslash
    printf("Hello World!\"\n"); // Double Quote

    int integer1;
    int integer2;

    printf("Enter first integer: ");
    scanf("%d", &integer1); // destructive - new value replaces the old value

    printf("Enter second integer: ");
    scanf("%d", &integer2);

    int sum = integer1 + integer2; // nondestructive for integer1 and integer2

    printf("Sum is %d \n", sum);

    int integerQuotient = integer1 / integer2; // 10 / 3 = 3

    printf("Integer Quotient is %d \n", integerQuotient);

    int remainder = integer1 % integer2; // 10 % 3 = 1 - % is for INTEGER DIVISION
    int remainderTwo = integer1 % 12; // 10 % 12 = 10 because 12 goes into 10 zero times with 10 remaining
    int remainderThree = integer1 % 9; //10 % 9 = 1

    printf("Int Remainder One is %d \n", remainder);
    printf("Int Remainder Two is %d \n", remainderTwo);
    printf("Int Remainder Three is %d \n", remainderThree);

    int y = 10 * 9 * 5 + 1 * 12 + 6; // 10 * 9, 90 * 5, 1 * 12, 450 + 12, 462 + 6, y = 468
    printf("Order of Operations: %d", y);

    if (y > 500) {
        puts("Y is greater than 500");
    }

    if (y < 1000) {
        puts("Y is less than 1000");
    }

    if (y >= 2000) {
        puts("Y is greater than or equal to 2000");
    }

    if (y <= 10000) {
        puts("Y is less than or equal to 10000");
    }

    if (y == 468) {
        puts("Y is 468");
    }

    if (y != 0) {
        puts("Y is not zeros"); // Secure C Programming Lesson 3
    }

    printf("%s", "Hello World!"); // Secure C Programming Lesson 2

    if (y < 1) {
        puts("Y is less than 1");
    } else if (y > 1) {
        puts("Y is greater than 1");
    } else {
        puts("Y is one");
    }

    // Conditional Operator - ternary
    puts(y >= 0 ? "Y is greater than or equal to 0" : "Y is a negative number");

    y >= 1000000 ? puts("Y is greater than or equal to 1 million") : puts("Y is not bigger than 1 million");

    return 0;

}