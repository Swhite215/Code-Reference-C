/*
   Spencer White
   CIS 170-70 - Vehicle Cost Calculation
   Uses the vehicle price to calculate sales tax and total cost to purchase the vehicle
*/

#include <stdio.h>

// Function Prototypes
float calculateSalesTax(float);
void displayVehicleCost(float, float, float);

int main (void) {
    
    float vehicePrice;
    float salesTax;
    float totalCost;

    puts("Let me calculate the cost of a vehicle for you!");
    printf("%s", "Enter the price of the vehicle: ");
    scanf("%f", &vehicePrice);

    salesTax = calculateSalesTax(vehicePrice);
    totalCost = vehicePrice + salesTax;

    displayVehicleCost(vehicePrice, salesTax, totalCost);

    return 0;
}

/*
   Function Description - Calculates Sales Tax of Vehicle
   Parameters: float vehiclePrice
   Returns: float salesTax
*/
float calculateSalesTax(float vehiclePrice) {
    return vehiclePrice * .06;
}

/*
   Function Description - Prints the Vehicle Price, Sales Tax, and Total Cost of the Vehicle
   Parameters: float vehiclePrice, float salesTax, float totalCost
   Returns: N/A
*/
void displayVehicleCost(float vehiclePrice, float salesTax, float totalCost) {
    printf("The vehicle price is $%.0f.\n", vehiclePrice);
    printf("The sales tax for a vehicle of that price is $%.2f.\n", salesTax);
    printf("The total cost to purchase this vehicle is $%.2f.\n", totalCost);
}