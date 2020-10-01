/*
   Spencer White
   CIS 170-70 - SizeOf Program
   Using sizeof and understanding sizes in C
*/

#include <stdio.h>

int main (void) {

    printf("Integer \t\t%d\n", sizeof(int));
    printf("Long Integer \t\t%d\n", sizeof(long));
    printf("Short Integer \t\t%d\n", sizeof(short));
    printf("Unsigned Integer \t%d\n", sizeof(unsigned int));
    printf("Unsigned Short Integer  %d\n", sizeof(unsigned short));
    printf("Character \t\t%d\n", sizeof(char));
    printf("Floating Point \t\t%d\n", sizeof(float));
    printf("Double Precision \t%d\n", sizeof(double));

    return 0;
}