/*
   Spencer White
   CIS 170-70 - Number Bases Program
   Displays equivalent numbers in different bases
*/

#include <stdio.h>

int main (void) {

    int favoriteNumber;
    char firstInitial;
    char lastInitial;

    printf("%s", "What is your favorite number? ");
    scanf("%d", &favoriteNumber);

    printf("Your favorite number is %d\n" , favoriteNumber, favoriteNumber);
    printf("%d as a char is: %c", favoriteNumber, favoriteNumber);
    printf("%d in octal is: %o\n", favoriteNumber, favoriteNumber);
    printf("%d in hexadecimal is: %x\n", favoriteNumber, favoriteNumber);

    printf("%s", "What is your first initial? ");
    scanf(" %c", &firstInitial);

    printf("Your first initial is %c\n" , firstInitial);
    printf("%c as a number is: %d\n", firstInitial, firstInitial);

    printf("%s", "What is your last initial? ");
    scanf(" %c", &lastInitial);

    printf("Your last initial is %c\n" , lastInitial);
    printf("%c as a number is: %d\n", lastInitial, lastInitial);

    return 0;
}