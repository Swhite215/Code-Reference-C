/*
   Spencer White
   CIS 170-70 - Math Functions
   Performs various arithmetic based on user input
*/

#include <stdio.h>

// Function Prototypes
float addNumbers(float, float);
float subtractNumbers(float, float);
float divideNumbers(float, float);
float multiplyNumbers(float, float);
float askForNumber(float);

int main (void) {

    int selection;
    float a;
    float b;
    float result;

    puts("Simple Math");
    puts("+ Add");
    puts("- Subtract");
    puts("/ Divide");
    puts("* Multiply");
    printf("%s", "Enter your choice: ");
    selection = getchar();

    switch (selection) {
        case '+':
            a = askForNumber(1);
            b = askForNumber(2);
            result = addNumbers(a, b);
            printf("The result is %.0f + %.0f = %.0f.\n", a, b, result);
            break;
        case '-':
            a = askForNumber(1);
            b = askForNumber(2);
            result = subtractNumbers(a, b);
            printf("The result is %.0f - %.0f = %.0f.\n", a, b, result);
            break;
        case '/':
            a = askForNumber(1);
            b = askForNumber(2);
            result = divideNumbers(a, b);
            printf("The result is %.0f / %.0f = %.0f.\n", a, b, result);
            break;
        case '*':
            a = askForNumber(1);
            b = askForNumber(2);
            result = multiplyNumbers(a, b);
            printf("The result is %.0f * %.0f = %.0f.\n", a, b, result);
            break;
        default:
            puts("You did not enter a valid operator.");
            break;
    }

    return 0;
}

/*
   Function Description - Add two numbers
   Parameters: float a, float b
   Returns: float sum
*/
float addNumbers(float a, float b) {
    return a + b;
}

/*
   Function Description - Subtract two numbers
   Parameters: float a, float b
   Returns: float difference
*/
float subtractNumbers(float a, float b) {
    return a - b;
}

/*
   Function Description - Divide two numbers
   Parameters: float a, float b
   Returns: float quotient
*/
float divideNumbers(float a, float b) {
    return a / b;
}

/*
   Function Description - Multiply two numbers
   Parameters: float a, float b
   Returns: float product
*/
float multiplyNumbers(float a, float b) {
    return a * b;
}

/*
   Function Description - Retrieve a number from the user
   Parameters: float order
   Returns: float num
*/
float askForNumber(float order) {
    float num;

    if (order == 1) {
        printf("%s", "Enter the first number: ");
        scanf("%f", &num);
        return num;
    } else if (order == 2) {
        printf("%s", "Enter the second number: ");
        scanf("%f", &num);
        return num;
    } else {
        puts("The program only works with binary operators, passing 0 as default.");
        return 0;
    }
}