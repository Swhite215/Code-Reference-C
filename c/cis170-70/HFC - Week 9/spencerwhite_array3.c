/*
   Spencer White
   CIS 170-70 - Array Assignment Three
*/

#include <stdio.h>
#include <string.h>
#define SIZE 80

// Function Prototypes
int testPalindrome(char* name);

int main (void) {

    char sentence[SIZE];
    int isPalindrome;
    int strLen = strlen(sentence);

    printf("%s", "Enter a sentence: ");

    fgets(sentence, SIZE, stdin);

    isPalindrome = testPalindrome(sentence);

    if (isPalindrome == 0) {
        printf("'%s' is not a palindrome!\n", sentence);
    } else {
        printf("'%s' is a palindrome!\n", sentence);
    }

    return 0;
}

/*
   Function Description - Checks if string is palindrome or not
   Parameters: char* sentence
   Returns: int isPalindrome
*/
int testPalindrome (char* sentence) {

    int isPalindrome = 1;

    for (int i = 0; i < (strlen(sentence) / 2); i++) {

        if (isalpha(sentence[i]) && isalpha(sentence[strlen(sentence) - (i + 2)])) {
            if (sentence[i] == sentence[strlen(sentence) - (i + 2)]) {
                continue;
            } else {
                isPalindrome = 0;
                break;
            }
        }
    }

    return isPalindrome;
}