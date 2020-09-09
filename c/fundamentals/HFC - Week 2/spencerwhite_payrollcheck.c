/*
   Spencer White
   CIS 170-70 - Payroll Check
   Calculates and Prints Gross Pay, Payroll Tax, and Net Pay
*/

#include <stdio.h>

// Function Prototypes
float askForHours();
float askForHourlyRate();
float calculateGrossPay(float, float);
float calculatePayrollTax(float);
float calculateNetPay(float, float);
void displayPay(float, float, float, float, float);

int main (void) {

    float hoursWorked;
    float hourlyRate;
    float grossPay;
    float payrollTax;
    float netPay;

    hoursWorked = askForHours();
    hourlyRate = askForHourlyRate();

    grossPay = calculateGrossPay(hoursWorked, hourlyRate);
    payrollTax = calculatePayrollTax(grossPay);
    netPay = calculateNetPay(grossPay, payrollTax);

    displayPay(hoursWorked, hourlyRate, grossPay, payrollTax, netPay);
}

/*
   Function Description - Retrieves hours worked from the user
   Parameters: N/A
   Returns: float hoursWorked
*/
float askForHours() {
    float hoursWorked;

    printf("%s", "Please enter the number of hours worked this week: ");
    scanf("%f", &hoursWorked);

    return hoursWorked;
}

/*
   Function Description - Retrieves hourly rate from the user
   Parameters: N/A
   Returns: float hourlyRate
*/
float askForHourlyRate() {
    float hourlyRate;

    printf("%s", "Please enter your hourly payrate: ");
    scanf("%f", &hourlyRate);

    return hourlyRate;
}

/*
   Function Description - Calculates Gross Pay
   Parameters: float hoursWorked, float hourlyRate
   Returns: float grossPay
*/
float calculateGrossPay (float hoursWorked, float hourlyRate) {
    return hoursWorked * hourlyRate;
}

/*
   Function Description - Calculates Payroll Tax
   Parameters: float hoursWorked, float hourlyRate
   Returns: float payrollTax
*/
float calculatePayrollTax (float grossPay) {
    return grossPay * .22;
}

/*
   Function Description - Calculates Net Pay
   Parameters: float grossPay, float payrollTax
   Returns: float netPay
*/
float calculateNetPay (float grossPay, float payrollTax) {
    return grossPay - payrollTax;
}

/*
   Function Description - Prints Pay Information
   Parameters: float hoursWorked, float hourlyRate, float grossPay, float payrollTax, float netPay
   Returns: N/A
*/
void displayPay (float hoursWorked, float hourlyRate, float grossPay, float payrollTax, float netPay) {
    printf("You have worked %.2f hours this week.\n" , hoursWorked);
    printf("You are payed $%.2f per hour.\n", hourlyRate);
    printf("Your gross pay is $%.2f.\n", grossPay);
    printf("Your payroll tax is $%.2f.\n", payrollTax);
    printf("Your take home pay, after taxes, is $%.2f.\n", netPay);
}