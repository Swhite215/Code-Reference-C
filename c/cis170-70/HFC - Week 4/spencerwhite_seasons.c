/*
   Spencer White
   CIS 170-70 - Seasons
   Displays a message depending on the season selected.
*/

#include <stdio.h>

int main ( void ) {

    puts("Choose your favorite season!");
    puts("\t Enter 1 for winter.");
    puts("\t Enter 2 for spring.");
    puts("\t Enter 3 for summer.");
    puts("\t Enter 4 for fall.");
    printf("%s", "Your choice: ");

    int season = getchar();

    switch (season) {
        case '1':
            puts("Your favorite season is winter!");
            break;
        case '2':
            puts("Your favorite season is spring!");
            break;
        case '3':
            puts("Your favorite season is summer!");
            break;
        case '4':
            puts("Your favorite season is fall!");
            break;
        default:
            puts("You entered an invalid number.");
            break;
    }

    return 0;
}