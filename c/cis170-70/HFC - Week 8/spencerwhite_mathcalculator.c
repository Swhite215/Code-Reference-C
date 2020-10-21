/*
   Spencer White
   CIS 170-70 - Math Calculator
   Performing mathematic calculations using pointers
*/

#include <stdio.h>

// Function Prototypes
void getValues(float *aPtr, char *oPtr, float *bPtr);
float performOperation(float *aPtr, char *oPtr, float *bPtr, float *rPtr);

int main (void) {

    float a;
    float b;
    float result;
    char operator;
    int calculate = -1;

    do {
        getValues(&a, &operator, &b);
        
        if (operator == '/') {
            if (b == 0 || a == 0) {
                puts("Detected a division by zero error. Asking for new values.");
                continue;
            }
        }

        performOperation(&a, &operator, &b, &result);

        printf("The result of %.2f %c %.2f = %.2f.\n", a, operator, b, result);
        calculate = 1;

    } while (calculate != 1);

    return 0;
}

/*
   Function Description - Gets values for calculation
   Parameters: float *aPtr, char *oPtr, float *bPtr
   Returns: N/A
*/
void getValues(float *aPtr, char *oPtr, float *bPtr) {
    float num1, num2;
    char operation;

    printf("%s", "Please enter an expression like the followng AxB: ");
    scanf(" %f%c%f", &num1, &operation, &num2);

    *aPtr = num1;
    *bPtr = num2;
    *oPtr = operation;

}

/*
   Function Description - Performs calculation
   Parameters: float *aPtr, char *oPtr, float *bPtr
   Returns: N/A
*/
float performOperation(float *aPtr, char *oPtr, float *bPtr, float *rPtr) {

    switch (*oPtr) {
        case '+':
            *rPtr = *aPtr + *bPtr;
            break;
        case '-':
            *rPtr = *aPtr - *bPtr;
            break;
        case '/':
            *rPtr = *aPtr / *bPtr;
            break;
        case '*':
            *rPtr = *aPtr * *bPtr;
            break;
        default:
            puts("You did not enter a valid operator.");
            break;
    }

}