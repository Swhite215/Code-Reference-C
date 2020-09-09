/*
   Spencer White
   CIS 170-70 - Gallons to Liters
   Converts Gallons to Liters and Print the Result
*/

#include <stdio.h>

// Function Prototypes
void displayLiters(float, float);

int main (void) {
    
    float gallons;
    float liters;
    puts("Let me convert gallons to liters for you!");
    printf("%s", "Enter the number of gallons: ");
    scanf("%f", &gallons);

    liters = gallons * 3.785;
    displayLiters(gallons, liters);

    return 0;
}

/*
   Function Description - Prints the Conversion Result of Gallons to Liters
   Parameters: float gallons, float liters
   Returns: N/A
*/
void displayLiters(float gallons, float liters) {
    printf("%.0f gallons is %.5f liters.\n", gallons, liters);
}