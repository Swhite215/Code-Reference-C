/*
   Spencer White
   CIS 170-70 - Vowel Counter
   Counts the number of vowels in a string
*/

#include <stdio.h>
#define SIZE 80

// Function Prototypes
void countVowels(char *sPtr, int[], int *tPtr);

int main (void) {

    char sentence[SIZE];

    int vowelCount[5] = {0, 0, 0, 0, 0};
    int totalCount = 0;

    printf("%s", "Enter a sentence: ");

    fgets(sentence, SIZE, stdin);

    countVowels(sentence, vowelCount, &totalCount);

    printf("Total A's: %d\n", vowelCount[0]);
    printf("Total E's: %d\n", vowelCount[1]);
    printf("Total I's: %d\n", vowelCount[2]);
    printf("Total O's: %d\n", vowelCount[3]);
    printf("Total U's: %d\n", vowelCount[4]);

    printf("Total Vowels: %d\n", totalCount);

    return 0;
}

/*
   Function Description - Calculates the count of each vowel and total count
   Parameters: char *sPtr sentence, int arr[] vowelCount, int *tPtr totalCount
   Returns: N/A
*/
void countVowels(char *sPtr, int arr[], int *tPtr) {

    while (*sPtr != '\0') {
        switch(*sPtr) {
            case 'A':
            case 'a':
                arr[0]++;
                *tPtr = *tPtr + 1;
                break;
            case 'E':
            case 'e':
                arr[1]++;
                *tPtr = *tPtr + 1;
                break;
            case 'I':
            case 'i':
                arr[2]++;
                *tPtr = *tPtr + 1;
                break;
            case 'O':
            case 'o':
                arr[3]++;
                *tPtr = *tPtr + 1;
                break;
            case 'U':
            case 'u':
                arr[4]++;
                *tPtr = *tPtr + 1;
                break;
            default:
                break;
        }
        ++sPtr;
    }
}