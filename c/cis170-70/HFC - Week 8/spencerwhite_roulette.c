/*
   Spencer White
   CIS 170-70 - Roulette
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function Prototypes
void showInstructions(void);
void makeBet(char *bPtr);
void dealWithBet(char *bPtr, int *kPtr);
void betOnNumber();
void betOnOddOrEven();
void betOnDozen();
void getNumber(int *nPtr);
void getOddOrEven(int *ePtr);
void getDozen(int *dPtr);
void getBetAmount(float *aPtr);
void spinWheel(int *rPtr, char betType);
void figureWinnings(char b, int *nPtr, float *aPtr, int *rPtr, float *wPtr);

int main (void) {

   char betType;
   int keepBetting = -1;

   do {
        showInstructions();
        makeBet(&betType);
        dealWithBet(&betType, &keepBetting);
   } while (keepBetting != 1);

   return 0;

}

/*
   Function Description - Prints Instructions
   Parameters: N/A
   Returns: N/A
*/
void showInstructions(){
    printf("%s", "+------------------------------------------------------------------------------------------+\n");
    printf("%s", "|               The Roulette Game - Rules                                                  |\n");
    printf("%s", "+------------------------------------------------------------------------------------------+\n");
    printf("%s", "| You can place your bet in one of three ways:                                             |\n");
    printf("%s", "|                                                                                          |\n");
    printf("%s", "| 1. Bet on a number (payout is 36 times the bet)                                          |\n");
    printf("%s", "| 2. Bet on an odd or even (payout is 2 times the bet)                                     |\n");
    printf("%s", "| 3. Bet on a dozen (first 1-12, second 13-24, third 25-36 payout is 3 times the bet)      |\n");
    printf("%s", "| The number zero does not coutn for odd or even or dozen, but can count as a number bet.  |\n");
    printf("%s", "+------------------------------------------------------------------------------------------+\n");
}

/*
   Function Description - Prints Main Menu and Updates Value at Pointer
   Parameters: char *bPtr
   Returns: N/A
*/
void makeBet(char *bPtr){
    char mainMenuOption;
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|               The Roulette Game               |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "| Please select from the below betting options: |\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  N: Bet On a Number                           |\n");
    printf("%s", "|  E: Bet On Odd or Even                        |\n");
    printf("%s", "|  D: Bet On A Dozen                            |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);
    while ((getchar()) != '\n'); // Clear Buffer

    while (mainMenuOption != 'N' && mainMenuOption != 'n' && mainMenuOption != 'E' && mainMenuOption != 'e' && mainMenuOption != 'D' && mainMenuOption != 'd' && mainMenuOption != 'Q' && mainMenuOption != 'q') {
        puts("Invalid input. Enter either a N, E, D, or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &mainMenuOption);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    *bPtr = mainMenuOption;
}

/*
   Function Description - Manages bet choice
   Parameters: char *bPtr betType, int *kPtr keepBetting
   Returns: N/A
*/
void dealWithBet(char *bPtr, int *kPtr) {

        switch(*bPtr){
            case 'N':
            case 'n':
                betOnNumber();
                break;
            case 'E':
            case 'e':
                betOnOddOrEven();
                break;
            case 'D':
            case 'd':
                betOnDozen();
                break;
            case 'Q':
            case 'q':
                puts("Exiting the program...");
                *kPtr = 1;
                break;
        }
}

/*
   Function Description - Manages a bet on a specific number
   Parameters: N/A
   Returns: N/A
*/

void betOnNumber() {

    int number;
    float amount;
    int randomNumber;
    float winnings;

    getNumber(&number);
    getBetAmount(&amount);
    spinWheel(&randomNumber, 'N');
    figureWinnings('N', &number, &amount, &randomNumber, &winnings);
}

/*
   Function Description - Manages a bet on odd or even
   Parameters: N/A
   Returns: N/A
*/

void betOnOddOrEven() {

    int oddOrEven; // 1 = Even, 0 = Odd
    float amount;
    int randomNumber;
    float winnings;

    getOddOrEven(&oddOrEven);
    getBetAmount(&amount);
    spinWheel(&randomNumber, 'E');
    figureWinnings('E', &oddOrEven, &amount, &randomNumber, &winnings);
}

/*
   Function Description - Manages a bet on a dozen
   Parameters: N/A
   Returns: N/A
*/

void betOnDozen() {

    int dozen; // 1 = 1-12, 2 = 13-24, 3 = 25-36
    float amount;
    int randomNumber;
    float winnings;

    getDozen(&dozen);
    getBetAmount(&amount);
    spinWheel(&randomNumber, 'D');
    figureWinnings('D', &dozen, &amount, &randomNumber, &winnings);
}

/*
   Function Description - Receives a number from the user
   Parameters: char *nPtr number
   Returns: N/A
*/
void getNumber(int *nPtr) {
    int status, number;

    printf("%s", "Enter a number to bet on: ");
    status = scanf("%d", &number);
    while ((getchar()) != '\n'); // Clear Buffer

    while (status != 1 || number < 0 || number > 36) {
        puts("Invalid input. Please enter a number between 0 and 36.");\
        printf("%s", "Enter a number to bet on: ");
        status = scanf("%d", &number);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    *nPtr = number;
}

/*
   Function Description - Receives a choice of odd or even from user
   Parameters: char *nPtr number
   Returns: N/A
*/
void getOddOrEven(int *ePtr) {
    char oddOrEven;
    int status, number;

    printf("%s", "Choose Odds (O) or Evens (E): ");
    scanf(" %c", &oddOrEven);
    while ((getchar()) != '\n'); // Clear Buffer

    while (oddOrEven != 'O' && oddOrEven != 'o' && oddOrEven != 'E' && oddOrEven != 'e') {
        puts("Invalid input. Please enter either an O or an E.");
        printf("%s", "Choose Odds (O) or Evens (E): ");
        status = scanf(" %c", &oddOrEven);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    switch(oddOrEven) {
        case 'E':
        case 'e':
            *ePtr = 1;
            break;
        case 'O':
        case 'o':
            *ePtr = 0;
            break;
    }
}

/*
   Function Description - Receives a choice of odd or even from user
   Parameters: char *nPtr number
   Returns: N/A
*/
void getDozen(int *dPtr) {
    int dozen;

    puts("Which group would you like to bet on?");
    puts("Enter 1 for numbers 1 through 12");
    puts("Enter 2 for numbers 13 through 24");
    puts("Enter 3 for numbers 25 through 36");
    printf("You choice: ");
    scanf("%d", &dozen);
    while ((getchar()) != '\n'); // Clear Buffer

    while (dozen != 1 && dozen != 2 && dozen != 3) {
        puts("Invalid input. Please enter either a 1, 2, or 3.");
        puts("Which group would you like to bet on?");
        puts("Enter 1 for numbers 1 through 12");
        puts("Enter 2 for numbers 13 through 24");
        puts("Enter 3 for numbers 25 through 36");
        printf("You choice: ");
        scanf("%d", &dozen);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    *dPtr = dozen;
}

/*
   Function Description - Receives a bet amount from the user
   Parameters: char *aPtr amount
   Returns: N/A
*/
void getBetAmount(float *aPtr) {
    int status;
    float number;

    printf("%s", "Enter an amount to bet: ");
    status = scanf("%f", &number);
    while ((getchar()) != '\n'); // Clear Buffer

    while (status != 1) {
        puts("Invalid input. Please enter a valid number.");\
        printf("%s", "Enter an amount to bet: ");
        status = scanf("%f", &number);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    *aPtr = number;
}

/*
   Function Description - Spins the wheel to generate a random number between 0 and 36
   Parameters: int *rPtr randomNumber, char betType
   Returns: N/A
*/
void spinWheel(int *rPtr, char betType) {
    int randomNumber;

    if (betType == 'E' || betType == 'D') {
        do {
            time_t t;
            srand((unsigned) time(&t));
            randomNumber = 0 + rand() % 36;
            *rPtr = randomNumber;
        } while (randomNumber == 0);
    } else {
        time_t t;
        srand((unsigned) time(&t));
        randomNumber = 0 + rand() % 36;
        *rPtr = randomNumber;
    }

}

/*
   Function Description - Determines Winnings
   Parameters: char betType, int *nPtr number, float *aPtr amount, int *rPtr randomNumber, float *wPtr winnings
   Returns: N/A
*/
void figureWinnings(char betType, int *nPtr, float *aPtr, int *rPtr, float *wPtr) {
         switch(betType){
            case 'N':
                if (*nPtr == *rPtr) {
                    *wPtr = 36 * *aPtr;
                    printf("You have won $%.2f, congratulations!\n", *wPtr);
                } else {
                    *wPtr = 36 * *aPtr;
                    printf("You have lost $%.2f!\n", *wPtr);
                }
                break;
            case 'E':
                if (*nPtr == 1 && (*rPtr % 2 == 0)) {
                    *wPtr = 2 * *aPtr;
                    printf("You have won $%.2f, congratulations!\n", *wPtr);
                } else if (*nPtr == 0 && (*rPtr % 2 != 0)) {
                    *wPtr = 2 * *aPtr;
                    printf("You have won $%.2f, congratulations!\n", *wPtr);
                } else {
                    *wPtr = 2 * *aPtr;
                    printf("You have lost $%.2f!\n", *wPtr);
                }
                break;
            case 'D':
                if (*nPtr == 1 && (*rPtr >= 1 && *rPtr <= 12)) {
                    *wPtr = 3 * *aPtr;
                    printf("You have won $%.2f, congratulations!\n", *wPtr);
                } else if (*nPtr == 2 && (*rPtr >= 13 && *rPtr <= 24)) {
                    *wPtr = 3 * *aPtr;
                    printf("You have won $%.2f, congratulations!\n", *wPtr);
                } else if (*nPtr == 3 && (*rPtr >= 25 && *rPtr <= 36)) {
                    *wPtr = 3 * *aPtr;
                    printf("You have won $%.2f, congratulations!\n", *wPtr);
                } else {
                    *wPtr = 3 * *aPtr;
                    printf("You have lost $%.2f!\n", *wPtr);
                }
                break;
        }

}