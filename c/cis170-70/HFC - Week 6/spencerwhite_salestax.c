/*
   Spencer White
   CIS 170-70 - Monthly Sales Tax
   Program to report sales tax paid
*/

#include <stdio.h>

// Function Prototypes
float inputTotalSales();
float calculateTaxes(float, int);
void displayTaxes(float, float, float);

int main ( void ) {

    float totalSales = inputTotalSales();
    float stateTaxes = calculateTaxes(totalSales, 0);
    float countyTaxes  = calculateTaxes(totalSales, 1);
    displayTaxes(totalSales, stateTaxes, countyTaxes);

    return 0;
}

/*
   Function Description - Receives the total sales from the user
   Parameters: N/A
   Returns: float totalSales
*/

float inputTotalSales() {
    float totalSales;

    printf("What was the total sales for the month? ");
    scanf("%f", &totalSales);

    return totalSales;
}

/*
   Function Description - Calculates state and county taxes
   Parameters: float totalSales, int
   Returns: float stateTaxes || float countyTaxes
*/

float calculateTaxes(float totalSales, int type) {
    if (type == 0) {
        return totalSales * .04;
    } else if (type == 1) {
        return totalSales * .02;
    }
}

/*
   Function Description - Displays state and county sales tax
   Parameters: float totalSales, float stateTaxes, float countyTaxes
   Returns: 
*/

void displayTaxes(float totalSales, float stateTaxes, float countyTaxes) {
   printf("For $%.2f in sales:\n You must pay $%.2f in state sales taxes. \n You must pay $%.2f in county sales taxes. \n Combined, this is a total of $%.2f in sales tax.\n", totalSales, stateTaxes, countyTaxes, stateTaxes + countyTaxes);
}