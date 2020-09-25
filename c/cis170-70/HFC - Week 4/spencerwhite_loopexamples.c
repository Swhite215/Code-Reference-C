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
void displaySubtractionTables(float, float, float);
void displayMultiplicationTables(float, float, float);

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
                puts("\n-------------------Addition Module------------------");
                additionMenu();
                break;
            case '-':
                puts("\n-----------------Subtraction Module-----------------");
                subtractionMenu();
                break;
            case '*':
                puts("\n----------------Multiplication Module---------------");
                multiplicationMenu();
                break;
            case '0':
                puts("Exiting the program...");
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", mainMenuOption);
                break;
        }
    } while (mainMenuOption != '0');

   return 0;
}

char showMainMenu(){
   char mainMenuOption;
    printf("%s", "+--------------------------------------------+\n");
    printf("%s", "|     Arithmetic Tables and Calculations     |\n");
    printf("%s", "+--------------------------------------------+\n");
    printf("%s", "|                                            |\n");
    printf("%s", "|\tEnter + for Addition Module:\t     |\n");
    printf("%s", "|\tEnter - for Subtraction Module:\t     |\n");
    printf("%s", "|\tEnter * for Multiplication Module:   |\n");
    printf("%s", "|\tEnter 0 to Exit the Program:\t     |\n");
    printf("%s", "|                                            |\n");
    printf("%s", "+--------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);
    return mainMenuOption;
}

char showSubMenu(){
   char subMenuOption;
    printf("%s", "+--------------------------------------------------+\n");
    printf("%s", "|                                                  |\n");
    printf("%s", "|\tEnter 1 to See A Table of Values:\t   |\n");
    printf("%s", "|\tEnter 2 to Perform A Single Calculation:   |\n");
    printf("%s", "|\tEnter 0 to Exit this Module: \t\t   |\n");
    printf("%s", "|                                                  |\n");
    printf("%s", "+--------------------------------------------------+\n\n");

    printf("Enter Your Choice: ");
    scanf(" %c", &subMenuOption);
    return subMenuOption;
}

/*
   Function Description - Prints Addition Menu And Triggers Table or Calculation Functionality
   Parameters: N/A
   Returns: N/A
*/
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
         printf("The result of %.0f + %.0f = %.0f\n\n", a, b, c);

         // Break
         break;
      case '0':
         puts("Exiting the module...\n");
         break;
      default:
         printf(" %c is an invalid option, returning to main menu...", subMenuOption);
         break;
   }
}

/*
   Function Description - Prints Subtraction Menu And Triggers Table or Calculation Functionality
   Parameters: N/A
   Returns: N/A
*/
void subtractionMenu() {
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
         displaySubtractionTables(a, start, end);

         // Break
         break;
      case '2':
         // Ask for First Number
         a = askForNumber(1);

         // Ask for Second Number
         b = askForNumber(2);

         // Perform Calculation and Log the Results
         c = subtractNumbers(a, b);
         printf("The result of %.0f - %.0f = %.0f\n\n", a, b, c);

         // Break
         break;
      case '0':
         puts("Exiting the module...\n");
         break;
      default:
         printf(" %c is an invalid option, returning to main menu...", subMenuOption);
         break;
   }
}

/*
   Function Description - Prints Multiplication Menu And Triggers Table or Calculation Functionality
   Parameters: N/A
   Returns: N/A
*/
void multiplicationMenu() {
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
         displayMultiplicationTables(a, start, end);

         // Break
         break;
      case '2':
         // Ask for First Number
         a = askForNumber(1);

         // Ask for Second Number
         b = askForNumber(2);

         // Perform Calculation and Log the Results
         c = multiplyNumbers(a, b);
         printf("\nThe result of %.0f * %.0f = %.0f\n\n", a, b, c);

         // Break
         break;
      case '0':
         puts("Exiting the module...\n");
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
      printf("%s", "\nEnter the first number: ");
      scanf("%f", &num);
      return num;
   } else if (order == 2) {
      printf("%s", "Enter the second number: ");
      scanf("%f", &num);
      return num;
   } else if (order == 3) {
      printf("%s", "\nEnter a number: ");
      scanf("%f", &num);
      return num;
   } else if (order == 4) {
      printf("%s", "Enter the starting number in the range of values to display: ");
      scanf("%f", &num);
      return num;
   } else if (order == 5) {
      printf("%s", "Enter the ending number in the range of values to display: ");
      scanf("%f", &num);
      return num;
   } else {
      puts("An invalid number option as provided. Defaulting to 0.");
      return 0;
   }
}

/*
   Function Description - Prints Addition Table
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

   puts("\n- - - - - - - - - - - - - - - - - - - -");
   printf("Addition Table for %.0f from %.0f to %.0f\n", a, smallest, largest);
   puts("- - - - - - - - - - - - - - - - - - - -");

   for (int i = smallest; i <= largest; i++) {
      float sum;
      sum = addNumbers(a, i);
      printf("%.0f + %d | %.0f\n", a, i, sum);
   }
}

/*
   Function Description - Prints Subtraction Table
   Parameters: float number, float start, float end
   Returns: N/A
*/
void displaySubtractionTables(float a, float start, float end) {

   float smallest;
   float largest;

   if (start > end) {
      largest = start;
      smallest = end;
   } else {
      largest = end;
      smallest = start;
   }

   puts("\n- - - - - - - - - - - - - - - - - - - -");
   printf("Subtraction Table for %.0f from %.0f to %.0f\n", a, smallest, largest);
   puts("- - - - - - - - - - - - - - - - - - - -");

   for (int i = smallest; i <= largest; i++) {
      float difference;
      difference = subtractNumbers(a, i);
      printf("%.0f - %d | %.0f\n", a, i, difference);
   }
}

/*
   Function Description - Prints Multiplication Table
   Parameters: float number, float start, float end
   Returns: N/A
*/
void displayMultiplicationTables(float a, float start, float end) {

   float smallest;
   float largest;

   if (start > end) {
      largest = start;
      smallest = end;
   } else {
      largest = end;
      smallest = start;
   }

   puts("\n- - - - - - - - - - - - - - - - - - - -");
   printf("Multiplication Table for %.0f from %.0f to %.0f\n", a, smallest, largest);
   puts("- - - - - - - - - - - - - - - - - - - -");

   for (int i = smallest; i <= largest; i++) {
      float product;
      product = multiplyNumbers(a, i);
      printf("%.0f * %d | %.0f\n", a, i, product);
   }
}