/*
   Spencer White
   CIS 170-70 - Shipping Charge
   Calculates the shipping charge based on the weight of the package
*/

#include <stdio.h>

// Function Prototypes
float askForWeight();

int main (void) {

    float weight;
    float shippingCharge;

    weight = askForWeight();

    if (weight <= 2) {
        shippingCharge = weight * 1.10;
        printf("The total cost of shipping is $%.2f.\n", shippingCharge);
    } else if (weight > 2 && weight <= 6) {
        shippingCharge = weight * 2.20;
        printf("The total cost of shipping is $%.2f.\n", shippingCharge);
    } else if (weight > 6 && weight <= 10) {
        shippingCharge = weight * 3.70;
        printf("The total cost of shipping is $%.2f.\n", shippingCharge);
    } else if (weight > 10) {
        shippingCharge = weight * 4.10;
        printf("The total cost of shipping is $%.2f.\n", shippingCharge);
    }

    return 0;
}

/*
   Function Description - Retrieves weight from user
   Parameters: N/A
   Returns: float weight
*/
float askForWeight() {
    float weight;

    printf("%s", "What is the weight of the package? ");
    scanf("%f", &weight);

    return weight;
}