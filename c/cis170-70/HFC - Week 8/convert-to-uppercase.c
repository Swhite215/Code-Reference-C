#include <stdio.h>
#include <ctype.h>

void convertToUppercase(char *sPtr);

int main (void) {
    char string = "cHaRaCters and $32.98";

    printf("The string before conversion is: %s", string);
    convertToUppercase(string);
    printf("The string after conversion is: %s", string);
}

void convertToUppercase(char *sPtr) {
    while (*sPtr != '\0') {
        *sPtr = toupper(*sPtr);
        ++sPtr;
    }
}