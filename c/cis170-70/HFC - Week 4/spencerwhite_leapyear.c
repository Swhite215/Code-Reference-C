/*
   Spencer White
   CIS 170-70 - Leap Year
   Calculates the day of the year, taking into consideration leap years
*/

#include <stdio.h>

// Function Prototypes
int isLeap(int);
int validateDay(int, int, int);
int determineDay(int, int, int);
void displayDate(int, int, int, int);

// Constants - Days in Each Month
const int JAN = 31;
const int FEB = 28;
const int LEAP_FEB = 29;
const int MAR = 31;
const int APR = 30;
const int MAY = 31;
const int JUN = 30;
const int JUL = 31;
const int AUG = 31;
const int SEP = 30;
const int OCT = 31;
const int NOV = 30;
const int DEC = 31;

int main ( void ) {

    // Variables
    int day, month, year;
    int isLeapYear;
    int isValidDate;
    int dayOfYear;

    // Receive Date from User
    printf("%s", "Please enter the date using numerical values in the following format MM/DD/YYYY: ");
    scanf("%d/%d/%d", &month, &day, &year);

    // Determine if Year is Leap Year
    isLeapYear = isLeap(year);

    // Using Leap Year, Determine if Date is Valid
    isValidDate = validateDay(month, day, isLeapYear);

    // If Valid, Determine the Day, Else Exit the Program
    if (isValidDate == 1) {
        dayOfYear = determineDay(month, day, isLeapYear);
        displayDate(month, day, year, dayOfYear);
        return 0;
    } else {
        puts("You entered an invalid date, exiting the program.");
        return 0;
    }
}

/*
   Function Description - Determines if the year is a leap year
   Parameters: int year
   Returns: int isLeap
*/
int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

/*
   Function Description - Determines if a valid date has been entered
   Parameters: int month, int day, int isLeapYear
   Returns: int isValidDate
*/
int validateDay(int month, int day, int isLeapYear) {

    int isValidDate;
    int februaryDays;

    if (isLeapYear == 1) {
        februaryDays = LEAP_FEB;
    } else if (isLeapYear == 0) {
        februaryDays = FEB;
    }

    switch(month) {
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
        case 12: // December
            if (day <= 0 || day > 31) {
                isValidDate = 0;
            } else {
                isValidDate = 1;
            }
            break;
        case 2: // February
            if (day <= 0 || day > februaryDays) {
                isValidDate = 0;
            } else {
                isValidDate = 1;
            }
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            if (day <= 0 || day > 30) {
                isValidDate = 0;
            } else {
                isValidDate = 1;
            }
            break;
        default:
            puts("You entered an invalid month.");
            return 0;
            break;
    }

    return isValidDate;
}

/*
   Function Description - Determines the day number in the year
   Parameters: int month, int day, int isLeapYear
   Returns: int sumOfDays
*/
int determineDay(int month, int day, int isLeapYear) {

    int sumOfDays;
    int februaryDays;

    if (isLeapYear == 1) {
        februaryDays = LEAP_FEB;
    } else if (isLeapYear == 0) {
        februaryDays = FEB;
    }

    // Sum Preceeding Months Date Count and Add Current Day
    switch(month) {
        case 1: // January - Day Number is Day Entered
            return day;
        case 2: // February
            sumOfDays = JAN;
            sumOfDays += day;
            break;
        case 3: // March
            sumOfDays = JAN + februaryDays;
            sumOfDays += day;
            break;
        case 4: // April
            sumOfDays = JAN + februaryDays + MAR;
            sumOfDays += day;
            break;
        case 5: // May
            sumOfDays = JAN + februaryDays + MAR + APR;
            sumOfDays += day;
            break;
        case 6: // June
            sumOfDays = JAN + februaryDays + MAR + APR + MAY;
            sumOfDays += day;
            break;
        case 7: // July
            sumOfDays = JAN + februaryDays + MAR + APR + MAY + JUN;
            sumOfDays += day;
            break;
        case 8: // August
            sumOfDays = JAN + februaryDays + MAR + APR + MAY + JUN + JUL;
            sumOfDays += day;
            break;
        case 9: // September
            sumOfDays = JAN + februaryDays + MAR + APR + MAY + JUN + JUL + AUG;
            sumOfDays += day;
            break;
        case 10: // October
            sumOfDays = JAN + februaryDays + MAR + APR + MAY + JUN + JUL + AUG + SEP;
            sumOfDays += day;
            break;
        case 11: // November
            sumOfDays = JAN + februaryDays + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT;
            sumOfDays += day;
            break;
        case 12: // December
            sumOfDays = JAN + februaryDays + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT + NOV;
            sumOfDays += day;
            break;
        default:
            puts("You entered an invalid month.\n");
            return 0;
            break;
    }

    return sumOfDays;
}

/*
   Function Description - Displays the date and the day number
   Parameters: int month, int day, int year, int dayOfYear
   Returns: N/A
*/
void displayDate(int month, int day, int year, int dayOfYear) {

    // Print Result Depending on Month
    switch(month) {
        case 1: // January
            printf("Your day, January %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 2: // February
            printf("Your day, February %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 3: // March
            printf("Your day, March %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 4: // April
            printf("Your day, April %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 5: // May
            printf("Your day, May %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 6: // June
            printf("Your day, June %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 7: // July
            printf("Your day, July %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 8: // August
            printf("Your day, August %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 9: // September
            printf("Your day, September %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 10: // October
            printf("Your day, October %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 11: // November
            printf("Your day, November %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        case 12: // December
            printf("Your day, December %d, %d is day number %d.\n", day, year, dayOfYear);
            break;
        default:
            puts("You entered an invalid month.\n");
            break;
    }
}

/*
Test Cases:
    1. 12/31/2002 - NOT LEAP - 365 Days
    2. 12/31/2004 - LEAP - 366 Days
    3. 01/12/2001 - NOT LEAP - 12 Days
    4. 01/16/2004 - LEAP - 16 DAYS
    5. 02/29/2004 - LEAP - 60 DAYS
    6. 02/28/2003 - NOT LEAP - 59 DAYS
    7. 02/29/2004 - NOT LEAP - INVALID DATE
    8. 06/35/2001 - NOT LEAP - INVALID DATE
    9. 05/22/2004 - LEAP - 143
    10. 05/22/2003 - NOT LEAP - 142
*/