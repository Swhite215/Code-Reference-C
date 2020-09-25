/*
   Spencer White
   CIS 170-70 - Loop Examples
   File Description
*/

#include <stdio.h>

// Function Prototypes
char showMainMenu(void);
char showSubMenu(void);
void additionMenu();
void subtractionMenu();
void multiplicationMenu();
float addNumbers(float, float);
float subtractNumbers(float, float);
float multiplyNumbers(float, float);
float askForNumber(float);
void displayAdditionTables(float, float, float);

int main (void ) {

   // Sentinel Loop
   // Display Menu
      // + for Add
      // - for Subtract
      // * for Multiplication
      // -1 to Exit Program

      // Nested Loop
      // 1 for Table of Values
         // Enter Starting Number
         // Enter Ending Number
      // 2 for Single Calculation
         // Enter First Number
         // Enter Second Number
      // -1 to Exit Sub Menu

   char mainMenuOption;
    do {
        mainMenuOption = showMainMenu();
        switch(mainMenuOption){
            case '+':
                additionMenu();
                //call another function to do some stuff
                break;
            case 2:
                //subtractionMenU();
                //call another function to do some stuff
                break;
            case '*':
                //multiplicationMenu();
                //call another function to do some stuff
                break;
            case 0:
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", mainMenuOption);
                break;
        }
    } while (mainMenuOption != '0');
    printf("\nGoodbye...\n\n\n");

   return 0;
}

char showMainMenu(){
   char mainMenuOption;
    printf("+--------------------------------------------+\n");
    printf("|     Arithmetic Tables and Calculations     |\n");
    printf("+--------------------------------------------+\n");
    printf("|                                            |\n");
    printf("|\tEnter + for Addition Menu:\t\t|\n");
    printf("|\tEnter - for Subtraction Menu:\t\t|\n");
    printf("|\tEnter * for Multiplication Menu:\t\t|\n");
    printf("|                               |\n");
    printf("|\tEnter 0 to Exit the Program:\t0\t|\n");
    printf("|                               |\n");
    printf("+-------------------------------+\n\n");

    printf("Enter Your Choice:\t");
    scanf(" %c", &mainMenuOption);
    return mainMenuOption;
}

char showSubMenu(){
   char subMenuOption;
    printf("+--------------------------------------------+\n");
    printf("|                                            |\n");
    printf("|\tEnter 1 to See A Table of Values:\t\t|\n");
    printf("|\tEnter 2 for Single Calculation:\t\t|\n");
    printf("|                               |\n");
    printf("|\tEnter 0 to Exit the Program:\t0\t|\n");
    printf("|                               |\n");
    printf("+-------------------------------+\n\n");

    printf("Enter Your Choice:\t");
    scanf(" %c", &subMenuOption);
    return subMenuOption;
}

void additionMenu() {
   char subMenuOption;
   subMenuOption = showSubMenu();
   float a;
   float b;
   float start;
   float end;
   float c;

   switch(subMenuOption) {
      case '1':
         // Ask For Base Number
         a = askForNumber(3);

         // Ask for Start of Range
         start = askForNumber(4);
      
         // Ask for End of Range
         end = askForNumber(5);

         // Loop and Show Table of Results
         displayAdditionTables(a, start, end);

         // Break
         break;
      case '2':
         // Ask for First Number
         a = askForNumber(1);

         // Ask for Second Number
         b = askForNumber(2);

         // Perform Calculation and Log the Results
         c = addNumbers(a, b);
         printf("The result of %.0f + %.0f = %.0f\n", a, b, c);

         // Break
         break;
      case '0':
         break;
      default:
         printf(" %c is an invalid option, returning to main menu...", subMenuOption);
         break;
   }
}

/*
   Function Description - Add two numbers
   Parameters: float a, float b
   Returns: float sum
*/
float addNumbers(float a, float b) {
    return a + b;
}

/*
   Function Description - Subtract two numbers
   Parameters: float a, float b
   Returns: float difference
*/
float subtractNumbers(float a, float b) {
    return a - b;
}

/*
   Function Description - Multiply two numbers
   Parameters: float a, float b
   Returns: float product
*/
float multiplyNumbers(float a, float b) {
    return a * b;
}

/*
   Function Description - Retrieve a number from the user
   Parameters: float order
   Returns: float num
*/
float askForNumber(float order) {
   float num;

   if (order == 1) {
      printf("%s", "Enter the first number: ");
      scanf("%f", &num);
      return num;
   } else if (order == 2) {
      printf("%s", "Enter the second number: ");
      scanf("%f", &num);
      return num;
   } else if (order == 3) {
      printf("%s", "Enter a number:");
      scanf("%f", &num);
      return num;
   } else if (order == 4) {
      printf("%s", "Enter the starting number in the range of values to display:");
      scanf("%f", &num);
      return num;
   } else if (order == 5) {
      printf("%s", "Enter the ending number in the range of values to display:");
      scanf("%f", &num);
      return num;
   } else {
      puts("An invalid number option as provided. Defaulting to 0.");
      return 0;
   }
}

/*
   Function Description - Prints Addition Table Table
   Parameters: float number, float start, float end
   Returns: N/A
*/
void displayAdditionTables(float a, float start, float end) {

   float smallest;
   float largest;

   if (start > end) {
      largest = start;
      smallest = end;
   } else {
      largest = end;
      smallest = start;
   }

   puts("- - - - - - - - - - - - - - - - - - - -");
   printf("Additional Table for %.0f from %.0f to %.0f\n", a, smallest, largest);
   puts("- - - - - - - - - - - - - - - - - - - -");

   for (int i = smallest; i <= largest; i++) {
      float sum;
      sum = addNumbers(a, i);
      printf("%.0f + %d | %.0f.\n", a, i, sum);
   }
}