/*
   Spencer White
   CIS 170-70 - Making Change
   Calculates the change returned when paying a bill
*/

#include <stdio.h>

// Function Prototypes
float askForBill();
float askForPayment();
float calculateChange(float, float);
void determineDenominations(float);

int main (void) {

    float bill;
    float payment;
    float change;

    bill = askForBill();
    payment = askForPayment();
    change = calculateChange(bill, payment);

    printf("The change to be given back is $%.2f.\n", change);

    determineDenominations(change);

    return 0;
}

/*
   Function Description - Retrieves bill from user
   Parameters: N/A
   Returns: float bill
*/
float askForBill() {
    float bill;

    printf("%s", "Enter the bill amount in dollars and cents:\t");
    scanf("%f", &bill);

    return bill;
}

/*
   Function Description - Retrieves payment from user
   Parameters: N/A
   Returns: float payment
*/
float askForPayment() {
    float payment;

    printf("%s", "Enter the amount tendered:\t");
    scanf("%f", &payment);

    return payment;
}

/*
   Function Description - Calculates the amount of change to return
   Parameters: float bill, float payment
   Returns: float change
*/
float calculateChange(float bill, float payment) {
    float change;
    change = payment - bill;

    return change;
}
/*
   Function Description - Determines the coin denominations needed to meet change
   Parameters: float change
   Returns: N/A
*/
void determineDenominations(float change) {

    // Easier to convert to an int (pennies) rather than work with floating point numbers
    int changeInPennies = change * 100;

    int dollars;
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    dollars = changeInPennies / 100;
    changeInPennies = changeInPennies - (dollars * 100);

    quarters = changeInPennies / 25;
    changeInPennies = changeInPennies - (quarters * 25);

    dimes = changeInPennies / 10;
    changeInPennies = changeInPennies - (dimes * 10);

    nickels = changeInPennies / 5;
    changeInPennies = changeInPennies - (nickels * 5);

    pennies = changeInPennies / 1;
    changeInPennies = changeInPennies - pennies;

    printf("(%d dollars, %d quarters, %d dimes, %d nickels, and %d pennies) \n", dollars, quarters, dimes, nickels, pennies);

}