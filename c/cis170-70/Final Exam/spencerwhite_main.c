/*
   Spencer White
   CIS 170-70 - Final Exam: PS1 Designer
*/

/*
    Opportunities for Growth - Written 12/16/2020:
    1. Write and read more than one prompt from a file. Given that I did not have time to finish this, I dropped the How to Switch functionality.
    2. Don't force spaces between prompt components. Can remove lines 1501 and 1717 if you want to see prompt without lines.
    3. Allow immediate insertion as opposed to append and then move.
    4. Add warning prior to leaving Edit Prompt Menu that the user's prompt will be lost and then ask for confirmation.
    5. Add a user check before returning from Understanding PS1, Understanding PS1 Special Variables, and Setup Prompt on MacOS to give a chance to read without polluting the terminal.
    6. Add ability to generate a random prompt. Sorry, I also ran out of time to finish this. Hopefully I have demonstrated the fundamentals with the functionality that is available.
    7. Separate functions into different files/modules to improve readability.
    8. Use dynamic values for special variable examples when showing the prompt. I am not certain where I would get username, hostname, time, etc, from the terminal in a c program.
*/

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Globals

// Structure of Prompt Component Node
struct PromptComponent {
    char textValue[100];
    char spCode[10];
    char spExample[15];
    char colorName[15];
    char colorCode[15];
    int hasColor;
    int isSpecial;
};

// Struct of Linked List Node
struct node {
    struct PromptComponent data;
    struct node *nextPtr; // IMPORTANT: This should be null if last prompt component
};

// Type Definitions for Nodes
typedef struct node Node;
typedef Node *NodePtr;

// Color Codes For Coloring Print Statements
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Color Constants
const char RED[5] = "RED";
const char GREEN[6] = "GREEN";
const char YELLOW[8] = "YELLOW";
const char BLUE[6] = "BLUE";
const char PURPLE[8] = "PURPLE";
const char TURQUOISE[11] = "TURQUOISE";

// Color Code Constants
const char RED_CODE[13] = "\\[\\e[0;31m\\]";
const char GREEN_CODE[13] = "\\[\\e[0;32m\\]";
const char YELLOW_CODE[13] = "\\[\\e[0;33m\\]";
const char BLUE_CODE[13] = "\\[\\e[0;34m\\]";
const char PURPLE_CODE[13] = "\\[\\e[0;35m\\]";
const char TURQUOISE_CODE[13] = "\\[\\e[0;36m\\]";

// Special Code Constants
const char SP_DATE_CODE[3] = "\\d";
const char SP_HOSTNAME_CODE[3] = "\\h";
const char SP_24HRTIME_CODE[3] = "\\t";
const char SP_12HRTIME_ONE_CODE[3] = "\\T";
const char SP_12HRTIME_TWO_CODE[3] = "\\@";
const char SP_USERNAME_CODE[3] = "\\u";
const char SP_CWD_CODE[3] = "\\w";

// Special Code Constant Examples
const char SP_DATE_EXAMPLE[12] = "Tue Dec 08";
const char SP_HOSTNAME_EXAMPLE[7] = "Host";
const char SP_24HRTIME_EXAMPLE[8] = "19:29";
const char SP_12HRTIME_ONE_EXAMPLE[10] = "19:29:58";
const char SP_12HRTIME_TWO_EXAMPLE[10] = "07:29 PM";
const char SP_USERNAME_EXAMPLE[5] = "user";
const char SP_CWD_EXAMPLE[11] = "/path/dir";

// Function Prototypes
void displayMainMenu(char *mPtr);
void displayEditPromptMenu(char *sPtr);
void displaySavePromptMenu(char *sPtr);
void displayAddContentMenu(char *sPtr);
void displayPromptContentSelectionHeader();
void displayPromptContentFirstSelection();
void displayPromptContentSecondSelection();
void displayUnderstandingPS1Header();
void displayUnderstandingPS1SpecialCharactersHeader();
void displayMoveContentMenu(char *sPtr, int order);
void displayColorSelectMenu(char *sPtr);
void createNewPrompt();
void editExistingPrompt();
void understandingPS1();
void understandingSpecialPromptVariables();
void howToSetupPS1();
void addContent(NodePtr *sPtr);
void removeContent(NodePtr *sPtr);
void moveContent(NodePtr *sPtr);
void colorContent(NodePtr *sPtr);
void writePromptToFile();
void readPromptFromFile();
void addCustomText(NodePtr *sPtr);
void getCustomText(char textValue[]);
void appendToList(NodePtr *sPtr, char value[]);
void appendSPToList(NodePtr *sPtr, char specialVariableCode[], char specialVariableExample[]);
void printLinkedList(NodePtr *sPtr);
void addFeature(NodePtr *sPtr);
void buildAndDisplayDynamicMenu(NodePtr *sPtr, int *cPtr);
void getSelection(int *sPtr, int *cPtr);
void getTargetPromptComponent(NodePtr *sPtr, int *selectionPtr, char targetPromptValue[]);
void deleteFromList(NodePtr *sPtr, char value[]);
void addColor(NodePtr *sPtr);
void addColorToComponent(NodePtr *sPtr, char value[], char color[]);
void removeColor(NodePtr *sPtr);
void removeColorFromComponent(NodePtr *sPtr, char value[]);
void writePromptToFile(NodePtr *sPtr);
void readPromptFromFile(NodePtr *ePtr);
void takeOutAndHoldComponent(NodePtr *sPtr, NodePtr *mPtr, char valueToFind[]);
void insertToList(NodePtr *sPtr, NodePtr *mPtr, char whereToInsert[]);
void buildPrompt(NodePtr *sPtr);

// File Information
const char PATH[] = "";
const char FILENAME[] = "prompt.txt";

// Main Program
int main (void) {

    char mainMenuOption;
    do {
        displayMainMenu(&mainMenuOption);
        switch(mainMenuOption){
            case 'A':
                createNewPrompt();
                break;
            case 'B':
                editExistingPrompt();
                break;
            case 'C':
                understandingPS1();
                break;
            case 'D':
                understandingSpecialPromptVariables();
                break;
            case 'E':
                howToSetupPS1();
                break;
            case 'Q':
                puts("Exiting the program...");
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", mainMenuOption);
                break;
        }
    } while (mainMenuOption != 'Q');

    return 0;
}

// ------------------------------------------------- MENUS -------------------------------------------------
/*
   Function Description - Prints Main Menu and Updates Value at Pointer
   Parameters: char *mPtr
   Returns: N/A
*/
void displayMainMenu(char *mPtr) {
    char mainMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|        PS1 Designer by Spencer White          |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                  Main Menu:                   |\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  A: Create a New Prompt                       |\n");
    printf("%s", "|  B: Edit an Existing Prompt                   |\n");
    printf("%s", "|  C: Understanding PS1                         |\n");
    printf("%s", "|  D: Understanding PS1 Special Variables       |\n");
    printf("%s", "|  E: Setup Prompt on MacOS                     |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);

    while ((getchar()) != '\n');

    mainMenuOption = toupper(mainMenuOption);

    while (mainMenuOption != 'A' && mainMenuOption != 'B' && mainMenuOption != 'C' && mainMenuOption != 'D' && mainMenuOption != 'E' && mainMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, C, D, E, or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &mainMenuOption);

        while ((getchar()) != '\n');
        mainMenuOption = toupper(mainMenuOption);
    }

    *mPtr = mainMenuOption;
}

/*
   Function Description - Prints Edit Prompt Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayEditPromptMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Edit Prompt Menu                |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  A: Add Content                               |\n");
    printf("%s", "|  B: Remove Content                            |\n");
    printf("%s", "|  C: Move Content                              |\n");
    printf("%s", "|  D: Color Content                             |\n");
    printf("%s", "|  E: Save Prompt                               |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    while (subMenuOption != 'A' && subMenuOption != 'B' && subMenuOption != 'C' && subMenuOption != 'D' && subMenuOption != 'E' && subMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, C, D, E, or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &subMenuOption);

        while ((getchar()) != '\n');
        subMenuOption = toupper(subMenuOption);
    }

    *sPtr = subMenuOption;
}

/*
   Function Description - Prints Save Prompt Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displaySavePromptMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Save Prompt Menu                |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  A: Save Prompt                               |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    while (subMenuOption != 'A' && subMenuOption != 'Q') {
        puts("Invalid input. Enter either A or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &subMenuOption);

        while ((getchar()) != '\n');
        subMenuOption = toupper(subMenuOption);
    }

    *sPtr = subMenuOption;
}

/*
   Function Description - Prints Add Content Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayAddContentMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Add Content Menu                |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  A: Add Special Feature                       |\n");
    printf("%s", "|  B: Add Custom Text                           |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    while (subMenuOption != 'A' && subMenuOption != 'B' && subMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &subMenuOption);

        while ((getchar()) != '\n');
        subMenuOption = toupper(subMenuOption);
    }

    *sPtr = subMenuOption;
}

/*
   Function Description - Prints Prompt Component Selection Menu Header
   Parameters: N/A
   Returns: N/A
*/
void displayPromptContentSelectionHeader() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|          Prompt Content Selection Menu        |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
   
}

/*
   Function Description - Prints Component To Move Selection Menu
   Parameters: N/A
   Returns: N/A
*/
void displayPromptContentFirstSelection() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|            Pick Component To Move             |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
}

/*
   Function Description - Prints Where To Move Selection Menu
   Parameters: N/A
   Returns: N/A
*/
void displayPromptContentSecondSelection() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|        Pick Where To Move Component           |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
}

/*
   Function Description - Prints Setup PS1 Instructions Header
   Parameters: N/A
   Returns: N/A
*/
void displaySetupInstructionsHeader() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|   How to Setup the PS1 Environment Variable   |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
}

/*
   Function Description - Prints Understanding PS1 Header
   Parameters: N/A
   Returns: N/A
*/
void displayUnderstandingPS1Header() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|         Understanding the PS1 Variable        |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
}

/*
   Function Description - Prints Understanding PS1 Special Variables Header
   Parameters: N/A
   Returns: N/A
*/
void displayUnderstandingPS1SpecialCharactersHeader() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "| Understanding PS1 Variable Special Characters |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
}

/*
   Function Description - Prints Color Content Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayColorContentMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Color Content Menu              |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  A: Add Color                                 |\n");
    printf("%s", "|  B: Remove Color                              |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    while (subMenuOption != 'A' && subMenuOption != 'B' && subMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &subMenuOption);

        while ((getchar()) != '\n');
        subMenuOption = toupper(subMenuOption);
    }

    *sPtr = subMenuOption;
}

/*
   Function Description - Prints Color Select Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayColorSelectMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Color Select Menu               |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                                               |\n");
    printf("%s", ANSI_COLOR_RED "|  A: Red                                       |\n" ANSI_COLOR_RESET);
    printf("%s", ANSI_COLOR_GREEN "|  B: Green                                     |\n" ANSI_COLOR_RESET);
    printf("%s", ANSI_COLOR_YELLOW "|  C: Yellow                                    |\n" ANSI_COLOR_RESET);
    printf("%s", ANSI_COLOR_BLUE "|  D: Blue                                      |\n" ANSI_COLOR_RESET);
    printf("%s", ANSI_COLOR_MAGENTA "|  E: Purple                                    |\n" ANSI_COLOR_RESET);
    printf("%s", ANSI_COLOR_CYAN "|  F: Turquoise                                 |\n" ANSI_COLOR_RESET);
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    while (subMenuOption != 'A' && subMenuOption != 'B' && subMenuOption != 'C' && subMenuOption != 'D' && subMenuOption != 'E' && subMenuOption != 'F' && subMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, C, D, E, F or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &subMenuOption);

        while ((getchar()) != '\n');
        subMenuOption = toupper(subMenuOption);
    }

    *sPtr = subMenuOption;
}

/*
   Function Description - Prints Add Content Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayAddFeatureMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Add Feature Menu                |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|                                               |\n");
    printf("%s", "|  A: Date e.g. Tue Dec 08                      |\n");
    printf("%s", "|  B: Hostname e.g. Host                        |\n");
    printf("%s", "|  C: 24hr Time e.g. 19:29                      |\n");
    printf("%s", "|  D: 12hr Time with Seconds e.g. 19:29:58      |\n");
    printf("%s", "|  E: 12hr Time AM/PM e.g. 07:29 PM             |\n");
    printf("%s", "|  F: Username e.g. user                        |\n");
    printf("%s", "|  G: Current Working Directory e.g. path/dir   |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    while (subMenuOption != 'A' && subMenuOption != 'B' && subMenuOption != 'C' && subMenuOption != 'D' && subMenuOption != 'E' && subMenuOption != 'F' && subMenuOption != 'G' && subMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, C, D, E, F, G or Q");
        printf("%s", "Enter Your Choice: ");
        scanf(" %c", &subMenuOption);

        while ((getchar()) != '\n');
        subMenuOption = toupper(subMenuOption);
    }

    *sPtr = subMenuOption;
}

/*
   Function Description - Builds and Displays Dynamic Menu Options 
   Parameters: NodePtr *sPtr, int *cPtr
   Returns: N/A
*/

void buildAndDisplayDynamicMenu(NodePtr *sPtr, int *cPtr) {
    NodePtr currentPtr = *sPtr;
    int counter = 1;

    if (currentPtr == NULL) {
        puts("The list is empty. No menu can be printed!");
        return;
    } else {

        while (currentPtr != NULL) {

            if (currentPtr->data.isSpecial == 1) {  
                printf("%d.) %s\n", counter, currentPtr->data.spExample);
            } else {
                printf("%d.) %s\n", counter, currentPtr->data.textValue);
            }

            currentPtr = currentPtr->nextPtr; // Move to Next Item in List
            counter++; // Increment Counter
        }

        printf("%s", "0.) Quit\n");
    
        *cPtr = counter;
    }
}

/*
   Function Description - Gets Acceptable Dynamic Menu Selection 
   Parameters: int *sPtr, int *cPtr
   Returns: N/A
*/
void getSelection(int *sPtr, int *cPtr){
    int status;
    int number;

    printf("%s", "\nPlease Select a Component: ");
    status = scanf("%d", &number);
    while ((getchar()) != '\n'); // Clear Buffer

    while (status != 1 || number < 0 || number >= *cPtr) { // If Not Int, Less Than Zero, or Greater Than or Equal to Counter - Invalid Option
        puts("Invalid input. Please enter a valid number.");
        printf("%s", "\nPlease Select a Component: ");
        status = scanf("%d", &number);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    *sPtr = number;
}

/*
   Function Description - Gets Selected Prompt Component Value
   Parameters: NodePtr *sPtr, int *selectionPtr, char targetPromptValue[]
   Returns: N/A
*/

void getTargetPromptComponent(NodePtr *sPtr, int *selectionPtr, char targetPromptValue[]) {
    NodePtr currentPtr = *sPtr;
    int counter = 1;

    if (currentPtr == NULL) {
        puts("The list is empty. No component can be selected!");
    } else {

        if (*selectionPtr == 1) { // If it is the first element
            if (currentPtr->data.isSpecial == 1) {
                strcpy(targetPromptValue, currentPtr->data.spExample);
            } else {
                strcpy(targetPromptValue, currentPtr->data.textValue);
            }
        } else {
            while (counter != *selectionPtr) {
                currentPtr = currentPtr->nextPtr;
                counter++;
            }

            if (currentPtr->data.isSpecial == 1) {
                strcpy(targetPromptValue, currentPtr->data.spExample);
            } else {
                strcpy(targetPromptValue, currentPtr->data.textValue);
            }
        }
    }
}

// ------------------------------------------------- FLOW FUNCTIONS -------------------------------------------------
/*
   Function Description - Manages the Secondary Flow of Creating a Prompt
   Parameters: N/A
   Returns: N/A
*/
void createNewPrompt() {

    NodePtr startPtr = NULL; // New Prompt Linked List

    char subMenuOption;
    do {
        printLinkedList(&startPtr);

        displayEditPromptMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                addContent(&startPtr);
                break;
            case 'B':
                removeContent(&startPtr);
                break;
            case 'C':
                moveContent(&startPtr);
                break;
            case 'D':
                colorContent(&startPtr);
                break;
            case 'E':
                writePromptToFile(&startPtr);
                break;
            case 'Q':
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", subMenuOption);
                break;
        }
    } while (subMenuOption != 'Q');
}

/*
   Function Description - Manages the Secondary Flow of Selecting and Editing a Prompt
   Parameters: N/A
   Returns: N/A
*/
void editExistingPrompt() {

    NodePtr startPtr = NULL; // New Prompt Linked List - REPLACE WITH READ FROM FILE
    readPromptFromFile(&startPtr);

    int validPromptSelected = 0;

    if (startPtr != NULL) {
        validPromptSelected = 1;
    }

    if (validPromptSelected == 1) {
        char subMenuOption;
        do {
            printLinkedList(&startPtr);

            displayEditPromptMenu(&subMenuOption);
            switch(subMenuOption){
                case 'A':
                    addContent(&startPtr);
                    break;
                case 'B':
                    removeContent(&startPtr);
                    break;
                case 'C':
                    moveContent(&startPtr);
                    break;
                case 'D':
                    colorContent(&startPtr);
                    break;
                case 'E':
                    writePromptToFile(&startPtr);
                    break;
                case 'Q':
                    break;
                default:
                    printf("\n%c is an invalid option, please try again...\n\n", subMenuOption);
                    break;
            }
        } while (subMenuOption != 'Q');
    } else {
        puts("There are no prompts to edit, returning to main menu...");
    }
}

/*
   Function Description - Manages the Display of Information about PS1
   Parameters: N/A
   Returns: N/A
*/
void understandingPS1() {

    displayUnderstandingPS1Header();
    puts("What is PS1?");
    puts("  PS1 stands for Prompt Statement/String 1. It is an environment variable in your terminal.");
    puts("  It is a set of characters and codes that controls what is displayed in the BASH Shell before each command you enter.");
    puts("  Check out 'Understanding PS1 Special Variables' in the main menu to learn more about the special codes/features.");
    puts("");

    puts("Why use PS1?");
    puts("  What folder/path am I in?");
    puts("  What is the current time?");
    puts("  What user am I logged in as?");
    puts("  Your prompt should help you do your work, by providing neat features like the current working directory, time, or your username.");
    puts("  If your work involves only a terminal, no graphical user interface, the PS1 variable is crucial in giving you access to quick and helpful information.");
    puts("  It can also be used just for fun, like having an awesome looking terminal while you are doing your work. You can even add colors!");
    puts("");

    puts("How is PS1 used?");
    puts("  The PS1 environment variable can be set two ways.");
    puts("  For a temporary look, just paste the entire line below in a terminal.");
    puts("  export PS1='\\u: '");
    puts("  You should see your username, followed by a colon and then a space.");
    puts("  For a more permanent solution, check out 'Setup Prompt on MacOS' in the main menu to learn more.");
    puts("");

    puts("Where can I learn more?");
    puts("  Check out these links:");
    puts("      1. https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html");
    puts("      2. https://www.thegeekstuff.com/2008/09/bash-shell-take-control-of-ps1-ps2-ps3-ps4-and-prompt_command/");
    puts("      3. https://ss64.com/bash/syntax-prompt.html");
}

/*
   Function Description - Manages the Display of Information about Special Prompt Variables
   Parameters: N/A
   Returns: N/A
*/
void understandingSpecialPromptVariables() {
    displayUnderstandingPS1SpecialCharactersHeader();
    puts("What are PS1 Special Prompt Variables");
    puts("  PS1 stands for Prompt Statement/String 1. It is an environment variable in your terminal.");
    puts("  It is a set of characters and codes that controls what is displayed in the BASH Shell before each command you enter.");
    puts("  Below is a list of the characters and codes you might see in your prompt and what each one does.");
    puts("");

    puts("Special Prompt Variables:");
    puts("  #1. '\\d' - The date in 'Weekday Month Date' format e.g. 'Tue May 26'");
    puts("  #2. '\\h' - The hostname, up to the first period e.g. deckard.");
    puts("  #3. '\\t' - The time, in 24-hour HH:MM:SS format e.g. 19:29:58.");
    puts("  #4. '\\T' - The time, in 12-hour HH:MM:SS format e.g. 7:29:58.");
    puts("  #5. '\\@' - The time, in 12-hour AM/PM format e.g. 7:29 AM.");
    puts("  #6. '\\u' - The username of the current user e.g. user.");
    puts("  #7. '\\u' - The current working directory e.g. /Users/user/Desktop.");
    puts("");

    puts("Text Color Codes:");
    puts("  You will also see the below codes in your prompt. These are used to give the prompt text color.");
    puts("  #1. '\\e[0;31m' - RED");
    puts("  #2. '\\e[0;32m' - GREEN");
    puts("  #3. '\\e[0;33m' - YELLOW");
    puts("  #4. '\\e[0;34m' - BLUE");
    puts("  #5. '\\e[0;35m' - PURPLE");
    puts("  #6. '\\e[0;36m' - TURQUOISE");
    puts("");

    puts("Even MORE Special Prompt Variables:");
    puts("I didn't add these to the program, but as you get more familair with the prompt, try some of the below out!");
    puts("  #1. '\\j' - The number of jobs currently managed by the shell");
    puts("  #2. '\\H' - The entire hostname e.g. deckard.SS64.com ");
    puts("  #3. '\\l' - The basename of the shell's terminal device name.");
    puts("  #4. '\\s' - The name of the shell, the basename of $0.");
    puts("  #5. '\\v' - The version of Bash e.g. 2.00");
    puts("  #6. '\\V' - The release of Bash i.e. version + patch level e.g. 2.00.1");
    puts("  #7. '\\W' - The basename of $PWD.");
    puts("  #8. '\\!' - The history number of this command.");
    puts("  #9. '\\#' - The command number of this command.");
    puts("  #10. '\\n' - A newline.");
    puts("  #11. '\\n' - A carriage return.");
    puts("  #12. '\\e' - An escape character, typically a color code.");
    puts("  #13. '\\' - A backslash.");
    puts("  #14. '\[' - Begin a sequence of non-printing characters, like color escape sequences.");
    puts("  #15. '\]' - End a sequence of non-printing characters.");
    puts("");

    puts("Even MORE Text Color Codes:");
    puts("I didn't add these to the program, but as you get more familair with the prompt, try some of the below out!");
    puts("  #1. '\\e[1;31m' - Bold RED");
    puts("  #2. '\\e[1;32m' - Bold GREEN");
    puts("  #3. '\\e[1;33m' - Bold YELLOW");
    puts("  #4. '\\e[1;34m' - Bold BLUE");
    puts("  #5. '\\e[1;35m' - Bold PURPLE");
    puts("  #6. '\\e[1;36m' - Bold TURQUOISE");
    puts("  #7. '\\e[0;30m' - DARK GRAY");
    puts("  #8. '\\e[1;30m' - Bold DARK GRAY");
    puts("  #9. '\\e[0;37m' - LIGHT GRAY");
    puts("  #9. '\\e[1;37m' - Bold LIGHT GRAY");
    puts("");

}

/*
   Function Description - Manages the Display of Information about Setting PS1
   Parameters: N/A
   Returns: N/A
*/
void howToSetupPS1() {

        displaySetupInstructionsHeader();

        NodePtr startPtr = NULL;
        readPromptFromFile(&startPtr);

        if (startPtr != NULL) { // If Prompt in File - Use It For Instructions
            buildPrompt(&startPtr);
        } else { // Else, Use Simple One Node List with Username
            NodePtr newPtr = malloc(sizeof(Node)); // Create a New Node

            struct PromptComponent newComponent = {"", "", "", "", "", 0, 1}; // Create a New Prompt Component Struct
            strcpy(newComponent.spCode, SP_USERNAME_CODE);
            strcpy(newComponent.spExample, SP_USERNAME_EXAMPLE); // Update Name Value

            newPtr->data = newComponent; // Place New Prompt Component Struct in Node
            newPtr->nextPtr = NULL; // Set Pointer to Null - Node Will be Insert at End of List

            buildPrompt(&newPtr);
        }

}

/*
   Function Description - Adds Content
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void addContent(NodePtr *sPtr) {

    char subMenuOption;
    do {
        printLinkedList(sPtr);
        displayAddContentMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                addFeature(sPtr);
                break;
            case 'B':
                addCustomText(sPtr);
                break;
            case 'Q':
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", subMenuOption);
                break;
        }
    } while (subMenuOption != 'Q');
}

/*
   Function Description - Adds Custom Text to Prompt
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void addCustomText(NodePtr *sPtr) {
    char textValue[100];

    // Get Text
    getCustomText(textValue);

    // Append to List
    appendToList(sPtr, textValue);

}

/*
   Function Description - Gets User Input
   Parameters: char textValue[]
   Returns: N/A
*/
void getCustomText(char textValue[]) {
    printf("%s", "Enter custom text to add: ");

    int customTextStatus = scanf("%s", textValue);
    while ((getchar()) != '\n');
    while (customTextStatus != 1) {
        puts("Invalid input. Please enter a valid string.");
        printf("%s", "Enter custom text to add: ");
        customTextStatus = scanf("%s", textValue);
        while ((getchar()) != '\n');
    }
}


/*
   Function Description - Adds Special Variables to Prompt
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void addFeature(NodePtr *sPtr) {
    char subMenuOption;
    do {
        printLinkedList(sPtr);
        displayAddFeatureMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                appendSPToList(sPtr, SP_DATE_CODE, SP_DATE_EXAMPLE);
                break;
            case 'B':
                appendSPToList(sPtr, SP_HOSTNAME_CODE, SP_HOSTNAME_EXAMPLE);
                break;
            case 'C':
                appendSPToList(sPtr, SP_24HRTIME_CODE, SP_24HRTIME_EXAMPLE);
                break;
            case 'D':
                appendSPToList(sPtr, SP_12HRTIME_ONE_CODE, SP_12HRTIME_ONE_EXAMPLE);
                break;
            case 'E':
                appendSPToList(sPtr, SP_12HRTIME_TWO_CODE, SP_12HRTIME_TWO_EXAMPLE);
                break;
            case 'F':
                appendSPToList(sPtr, SP_USERNAME_CODE, SP_USERNAME_EXAMPLE);
                break;
            case 'G':
                appendSPToList(sPtr, SP_CWD_CODE, SP_CWD_EXAMPLE);
                break;
            case 'Q':
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", subMenuOption);
                break;
        }
    } while (subMenuOption != 'Q');

}

/*
   Function Description - Removes Content
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void removeContent(NodePtr *sPtr) {

    char subMenuOption;
    do {
        if ((*sPtr) == NULL) {
            subMenuOption = 'Q';
            puts("There are no components to remove. Returning to Edit Prompt Menu.");
            continue;
        } else {
            int counter = 0;
            int selection = 0;
            char targetPromptValue[100];

            printLinkedList(sPtr);
            displayPromptContentSelectionHeader();
            buildAndDisplayDynamicMenu(sPtr, &counter);
            getSelection(&selection, &counter);

            if (selection == 0) {
                subMenuOption = 'Q';
                continue;
            }

            getTargetPromptComponent(sPtr, &selection, targetPromptValue);
            deleteFromList(sPtr, targetPromptValue);
            subMenuOption = 'Q';
        }

    } while (subMenuOption != 'Q');
}

/*
   Function Description - Adds Color to Prompt Component
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void addColor(NodePtr *sPtr) {
    char subMenuOption;
    do {

        if ((*sPtr) == NULL) {
            subMenuOption = 'Q';
            puts("There are no components to color. Returning to Color Content Menu.");
            continue;
        } else {
            int counter = 0;
            int selection = 0;
            char targetPromptValue[100];

            printLinkedList(sPtr);
            displayPromptContentSelectionHeader();
            buildAndDisplayDynamicMenu(sPtr, &counter);
            getSelection(&selection, &counter);

            if (selection == 0) {
                subMenuOption = 'Q';
                continue;
            }

            getTargetPromptComponent(sPtr, &selection, targetPromptValue);
            displayColorSelectMenu(&subMenuOption);

            switch(subMenuOption){
                case 'A':
                    addColorToComponent(sPtr, targetPromptValue, RED);
                    subMenuOption = 'Q';
                    break;
                case 'B':
                    addColorToComponent(sPtr, targetPromptValue, GREEN);
                    subMenuOption = 'Q';
                    break;
                case 'C':
                    addColorToComponent(sPtr, targetPromptValue, YELLOW);
                    subMenuOption = 'Q';
                    break;
                case 'D':
                    addColorToComponent(sPtr, targetPromptValue, BLUE);
                    subMenuOption = 'Q';
                    break;
                case 'E':
                    addColorToComponent(sPtr, targetPromptValue, PURPLE);
                    subMenuOption = 'Q';
                    break;
                case 'F':
                    addColorToComponent(sPtr, targetPromptValue, TURQUOISE);
                    subMenuOption = 'Q';
                    break;
                case 'Q':
                    break;
                default:
                    printf("\n%c is an invalid option, please try again...\n\n", subMenuOption);
                    break;
            }

        }
    } while (subMenuOption != 'Q');

}

/*
   Function Description - Removes Color from Prompt Component
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void removeColor(NodePtr *sPtr) {
    char subMenuOption;
    do {

        if ((*sPtr) == NULL) {
            subMenuOption = 'Q';
            puts("There are no components to remove color from. Returning to Color Content Menu.");
            continue;
        } else {
            int counter = 0;
            int selection = 0;
            char targetPromptValue[100];

            printLinkedList(sPtr);
            displayPromptContentSelectionHeader();
            buildAndDisplayDynamicMenu(sPtr, &counter);
            getSelection(&selection, &counter);

            if (selection == 0) {
                subMenuOption = 'Q';
                continue;
            }

            getTargetPromptComponent(sPtr, &selection, targetPromptValue);
            removeColorFromComponent(sPtr, targetPromptValue);

            subMenuOption = 'Q';

        }
    } while (subMenuOption != 'Q');

}


/*
   Function Description - Moves Content
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void moveContent(NodePtr *sPtr) {

    char subMenuOption;
    NodePtr currentPtr;
    
    currentPtr = *sPtr;

    do {

        if ((*sPtr) == NULL || currentPtr->nextPtr == NULL) {
            subMenuOption = 'Q';
            puts("There are not enough components to move. Returning to Edit Prompt Menu.");
            continue;
        } else {
            
            int counter = 0;
            int firstSelection = 0;
            int secondSelection = 0;
            char targetPromptValueToMove[100];
            char whereToInsert[100];

            // Get Prompt To Move
            printLinkedList(sPtr);
            displayPromptContentSelectionHeader();
            displayPromptContentFirstSelection();
            buildAndDisplayDynamicMenu(sPtr, &counter);
            getSelection(&firstSelection, &counter);

            if (firstSelection == 0) {
                subMenuOption = 'Q';
                continue;
            }

            // Get Where To Move
            displayPromptContentSelectionHeader();
            displayPromptContentSecondSelection();
            buildAndDisplayDynamicMenu(sPtr, &counter);
            getSelection(&secondSelection, &counter);

            if (secondSelection == 0) {
                subMenuOption = 'Q';
                continue;
            }

            // Don't Allow User To Move Component To Same Position
            while (secondSelection == firstSelection) {

                puts("The prompt component already exists in that position.");
                puts("Please choose a different position to move to.");

                displayPromptContentSelectionHeader();
                displayPromptContentSecondSelection();
                buildAndDisplayDynamicMenu(sPtr, &counter);
                getSelection(&secondSelection, &counter);
            }
            
            // Get Component To Move
            getTargetPromptComponent(sPtr, &firstSelection, targetPromptValueToMove);

            // Get Where To Insert
            getTargetPromptComponent(sPtr, &secondSelection, whereToInsert);

            // Take Out and Hold Component To Move
            NodePtr movePtr = NULL;
            takeOutAndHoldComponent(sPtr, &movePtr, targetPromptValueToMove);

            // Insert Component
            insertToList(sPtr, &movePtr, whereToInsert);

            // Exit After Successful Move
            subMenuOption = 'Q';
        }

    }  while (subMenuOption != 'Q');
}

/*
   Function Description - Adds Color to Content
   Parameters: N/A
   Returns: N/A
*/

void colorContent(NodePtr *sPtr) {

    char subMenuOption;
    do {
        printLinkedList(sPtr);
        displayColorContentMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                addColor(sPtr);
                break;
            case 'B':
                removeColor(sPtr);
                break;
            case 'Q':
                break;
            default:
                printf("\n%c is an invalid option, please try again...\n\n", subMenuOption);
                break;
        }
    } while (subMenuOption != 'Q');
}


/*
   Function Description - Writes the Prompt To A Sequential Access File
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void writePromptToFile(NodePtr *sPtr) {
    FILE *fPtr; //File Pointer
    NodePtr currentPtr;

    currentPtr = *sPtr;

    char filePath[100] = "";
    strcat(filePath, PATH);
    strcat(filePath, FILENAME);

    if ((fPtr = fopen(filePath, "w")) == NULL) {
        puts("File could not be opened");
    } else {

        if (currentPtr == NULL) {
            puts("The list is empty. No content can be written!");
            return;
        } else {
            while (currentPtr != NULL) {

                char textValue[100] = "";
                char spCode[10] = "";
                char spExample[15] = "";
                char colorName[15] = "";
                char colorCode[15] = "";

                if (strcmp(currentPtr->data.textValue, "") == 0) {
                    strcpy(textValue, "EMPTY");
                } else {
                    strcpy(textValue, currentPtr->data.textValue);
                }

                if (strcmp(currentPtr->data.spCode, "") == 0) {
                    strcpy(spCode, "EMPTY");
                } else {
                    strcpy(spCode, currentPtr->data.spCode);
                }

                if (strcmp(currentPtr->data.spExample, "") == 0) {
                    strcpy(spExample, "EMPTY");
                } else {
                    strcpy(spExample, currentPtr->data.spExample);
                }

                if (strcmp(currentPtr->data.colorName, "") == 0) {
                    strcpy(colorName, "EMPTY");
                } else {
                    strcpy(colorName, currentPtr->data.colorName);
                }

                if (strcmp(currentPtr->data.colorCode, "") == 0) {
                    strcpy(colorCode, "EMPTY");
                } else {
                    strcpy(colorCode, currentPtr->data.colorCode);
                }

                // Write Component As Line w/ Guillemet Delimeter
                fprintf(fPtr, "%s»%s»%s»%s»%s»%d»%d\n", textValue, spCode, spExample, colorName, colorCode, currentPtr->data.hasColor, currentPtr->data.isSpecial);

                // Move to Next Component
                currentPtr = currentPtr->nextPtr;
            }

            fclose(fPtr); // Close File
            puts("\nYour custom PS1 prompt was successfully saved to the prompts.txt file.");
            puts("\nThis custom PS1 prompt will be loaded when you select 'Edit An Existing Prompt'.");
            puts("\nFor instructions on how to setup your custom prompt, visit 'Setup Prompt on MacOS' in the main menu.");
        }

    }
}

/*
   Function Description - Reads the Prompt From A Sequential Access File and Builds Linked List
   Parameters: NodePtr *sPtr
   Returns: N/A
*/

void readPromptFromFile(NodePtr *ePtr) {
    FILE *fPtr; //File Pointer

    char filePath[100] = "";
    strcat(filePath, PATH);
    strcat(filePath, FILENAME);

    if ((fPtr = fopen(filePath, "r")) == NULL) {
        puts("File could not be opened");
    } else {

        while(!feof(fPtr)) {
            NodePtr newPtr = malloc(sizeof(Node)); // Create a New Node
            struct PromptComponent newComponent = {"", "", "", "", "", 0, 0}; // Create a New Prompt Component Struct

            char textValue[100] = "";
            char spCode[10] = "";
            char spExample[15] = "";
            char colorName[15] = "";
            char colorCode[15] = "";
            int hasColor = 0;
            int isSpecial = 0;

            fscanf(fPtr, "%100[^»]»%5[^»]»%15[^»]»%15[^»]»%15[^»]»%d»%d\n", textValue, spCode, spExample, colorName, colorCode, &hasColor, &isSpecial);

            if (strcmp(textValue, "EMPTY") == 0) {
                strcpy(newComponent.textValue, "");
            } else {
                strcpy(newComponent.textValue, textValue);
            }

            if (strcmp(spCode, "EMPTY") == 0) {
                strcpy(newComponent.spCode, "");
            } else {
                strcpy(newComponent.spCode, spCode);
            }

            if (strcmp(spExample, "EMPTY") == 0) {
                strcpy(newComponent.spExample, "");
            } else {
                strcpy(newComponent.spExample, spExample);
            }

            if (strcmp(colorName, "EMPTY") == 0) {
                strcpy(newComponent.colorName, "");
            } else {
                strcpy(newComponent.colorName, colorName);
            }

            if (strcmp(colorCode, "EMPTY") == 0) {
                strcpy(newComponent.colorCode, "");
            } else {
                strcpy(newComponent.colorCode, colorCode);
            }

            newComponent.hasColor = hasColor;
            newComponent.isSpecial = isSpecial;

            newPtr->data = newComponent; // Place New Prompt Component Struct in Node
            newPtr->nextPtr = NULL;

            NodePtr currentPtr = *ePtr;
            NodePtr previousPtr = NULL;

            if (currentPtr == NULL) { // Start of List
                newPtr->nextPtr = *ePtr;
                *ePtr = newPtr;
            } else {
                while (currentPtr != NULL) { // Go to End of List
                    previousPtr = currentPtr;
                    currentPtr = currentPtr->nextPtr;
                }

                previousPtr->nextPtr = newPtr; // Insert New Node
            }
        }

         fclose(fPtr); // Close File
    }
}

// ------------------------------------------------- LINKED LIST FUNCTIONS -------------------------------------------------
/*
   Function Description - Appends New Prompt Component to Linked List
   Parameters: NodePtr *sPtr, char value[]
   Returns: N/A
*/
void appendToList(NodePtr *sPtr, char value[]) {
    NodePtr newPtr = malloc(sizeof(Node)); // Create a New Node

    struct PromptComponent newComponent = {"", "", "", "", "", 0, 0}; // Create a New Prompt Component Struct
    strcpy(newComponent.textValue, value); // Update Name Value

    newPtr->data = newComponent; // Place New Prompt Component Struct in Node
    newPtr->nextPtr = NULL; // Set Pointer to Null - Node Will be Insert at End of List

    NodePtr previousPtr = NULL; // Initialize Previous Ptr
    NodePtr currentPtr = *sPtr; // Initialize Current Ptr

    if (currentPtr == NULL) { // If Start of List - Just Insert
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    } else { // Else Insert At End of List
        while (currentPtr != NULL) { // Go to End of List
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        previousPtr->nextPtr = newPtr; // Insert New Node
    }
}

/*
   Function Description - Appends New Special Prompt Component to Linked List
   Parameters: NodePtr *sPtr, char specialVariableCode[], char specialVariableExample
   Returns: N/A
*/
void appendSPToList(NodePtr *sPtr, char specialVariableCode[], char specialVariableExample[]) {
    NodePtr newPtr = malloc(sizeof(Node)); // Create a New Node

    // Determine Special Variable Code and Example Needed

    struct PromptComponent newComponent = {"", "", "", "", "", 0, 1}; // Create a New Prompt Component Struct
    strcpy(newComponent.spCode, specialVariableCode);
    strcpy(newComponent.spExample, specialVariableExample); // Update Name Value

    newPtr->data = newComponent; // Place New Prompt Component Struct in Node
    newPtr->nextPtr = NULL; // Set Pointer to Null - Node Will be Insert at End of List

    NodePtr previousPtr = NULL; // Initialize Previous Ptr
    NodePtr currentPtr = *sPtr; // Initialize Current Ptr

    if (currentPtr == NULL) { // If Start of List - Just Insert
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    } else { // Else Insert At End of List
        while (currentPtr != NULL) { // Go to End of List
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        previousPtr->nextPtr = newPtr; // Insert New Node
    }
}

/*
   Function Description - Prints Prompt Components with Colors and Special Variable Examples
   Parameters: NodePtr *sPtr
   Returns: N/A
*/
void printLinkedList(NodePtr *sPtr) {
    NodePtr currentPtr = *sPtr;

    char fullPrompt[1000] = ""; // Holds Entire Prompt String - > 1000...?
    strcat(fullPrompt, "\nPROMPT: ");

    if (currentPtr == NULL) {
        puts("\nPROMPT: NO CONTENT - Add Content to View Example");
        return;
    } else {
        while (currentPtr != NULL) { // Step Through Linked List

            char partialPrompt[100] = "";

            if (currentPtr->data.hasColor == 1) {

                if (currentPtr->data.isSpecial == 1) {

                    if (strcmp(RED, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_RED);
                        strcat(partialPrompt, currentPtr->data.spExample);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    } else if (strcmp(GREEN, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_GREEN);
                        strcat(partialPrompt, currentPtr->data.spExample);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }else if (strcmp(YELLOW, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_YELLOW);
                        strcat(partialPrompt, currentPtr->data.spExample);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }else if (strcmp(BLUE, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_BLUE);
                        strcat(partialPrompt, currentPtr->data.spExample);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }else if (strcmp(PURPLE, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_MAGENTA);
                        strcat(partialPrompt, currentPtr->data.spExample);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    } else {
                        strcat(partialPrompt, ANSI_COLOR_CYAN);
                        strcat(partialPrompt, currentPtr->data.spExample);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }

                } else {

                    if (strcmp(RED, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_RED);
                        strcat(partialPrompt, currentPtr->data.textValue);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    } else if (strcmp(GREEN, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_GREEN);
                        strcat(partialPrompt, currentPtr->data.textValue);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }else if (strcmp(YELLOW, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_YELLOW);
                        strcat(partialPrompt, currentPtr->data.textValue);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }else if (strcmp(BLUE, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_BLUE);
                        strcat(partialPrompt, currentPtr->data.textValue);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }else if (strcmp(PURPLE, currentPtr->data.colorName) == 0) {
                        strcat(partialPrompt, ANSI_COLOR_MAGENTA);
                        strcat(partialPrompt, currentPtr->data.textValue);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    } else {
                        strcat(partialPrompt, ANSI_COLOR_CYAN);
                        strcat(partialPrompt, currentPtr->data.textValue);
                        strcat(partialPrompt, ANSI_COLOR_RESET);
                    }

                }

            } else {
                if (currentPtr->data.isSpecial == 1) {
                    strcat(partialPrompt, currentPtr->data.spExample);
                } else {
                    strcat(partialPrompt, currentPtr->data.textValue);
                }
            }

            strcat(fullPrompt, partialPrompt); // Attach Partial Prompt to Full Prompt
            currentPtr = currentPtr->nextPtr; // Move to Next Item in List

            if (!(currentPtr == NULL)) { // If Not At the End, Add a Space Between Prompt Values
                strcat(fullPrompt, " ");
            }
        }
    }

    printf("%s\n", fullPrompt); // Print the Full Prompt
}

/*
   Function Description - Deletes a Component From the List
   Parameters: NodePtr *sPtr, char value[]
   Returns: N/A
*/
void deleteFromList(NodePtr *sPtr, char value[]) {

    NodePtr previousPtr = NULL;
    NodePtr currentPtr = *sPtr;

    if (currentPtr == NULL) {
        puts("The list is empty. No content can be deleted!");
        return;
    } else {
        while (currentPtr != NULL && (strcmp(currentPtr->data.textValue, value) != 0 && strcmp(currentPtr->data.spExample, value) != 0)) { // Move Through List Until Match is Found
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        NodePtr tempPtr = currentPtr; // Make A Copy of Node to Remove

        if (previousPtr != NULL) {
            previousPtr->nextPtr = currentPtr->nextPtr; // Set Previous Ptr Next Ptr to Node After Current Node
        } else {
            *sPtr = currentPtr->nextPtr;
        }
        free(tempPtr);
    }

}


/*
   Function Description - Adds Color to Component in the List
   Parameters: NodePtr *sPtr, char value[], char color[]
   Returns: N/A
*/
void addColorToComponent(NodePtr *sPtr, char value[], char color[]) {
    NodePtr currentPtr = *sPtr;

    if (currentPtr == NULL) {
        puts("The list is empty. No content can be colored!");
        return;
    } else {
        while (currentPtr != NULL && (strcmp(currentPtr->data.textValue, value) != 0 && strcmp(currentPtr->data.spExample, value) != 0)) { // Move Through List Until Match is Found
            currentPtr = currentPtr->nextPtr;
        }

        // Set hasColor, colorName, and colorCode
        if (strcmp(RED, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, RED_CODE);
        } else if (strcmp(GREEN, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, GREEN_CODE);
        }else if (strcmp(YELLOW, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, YELLOW_CODE);
        }else if (strcmp(BLUE, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, BLUE_CODE);
        }else if (strcmp(PURPLE, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, PURPLE_CODE);
        }else {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, TURQUOISE_CODE);
        }
    }
}

/*
   Function Description - Removes Color from Node in the List
   Parameters: NodePtr *sPtr, char value[]
   Returns: N/A
*/
void removeColorFromComponent(NodePtr *sPtr, char value[]) {
    NodePtr currentPtr = *sPtr;

    if (currentPtr == NULL) {
        puts("The list is empty. No colors can be removed!");
        return;
    } else {
        while (currentPtr != NULL && (strcmp(currentPtr->data.textValue, value) != 0 && strcmp(currentPtr->data.spExample, value) != 0)) { // Move Through List Until Match is Found
            currentPtr = currentPtr->nextPtr;
        }

        currentPtr->data.hasColor = 0; // Set Has Color to Zero
        strcpy(currentPtr->data.colorName, ""); // Set Color Name to Nothing
        strcpy(currentPtr->data.colorCode, ""); // Set Color Code to Nothing
    }
}

/*
   Function Description - Grabs and Holds a Component Prior To Moving
   Parameters: NodePtr *sPtr, NodePtr *mPtr, char valueToFind[]
   Returns: N/A
*/
void takeOutAndHoldComponent(NodePtr *sPtr, NodePtr *mPtr, char valueToFind[]) {
    NodePtr currentPtr = *sPtr;
    NodePtr previousPtr = NULL;

    if (currentPtr == NULL) {
         puts("The list is empty. No content can be moved!");
        return;
    } else {

        // Find Node to Move
        while(currentPtr != NULL && (strcmp(currentPtr->data.textValue, valueToFind) != 0 && strcmp(currentPtr->data.spExample, valueToFind) != 0)) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // Remove It From List and Store Temporarily
        (*mPtr) = currentPtr;


        if (previousPtr == NULL) { // If Taking First Item - Set Start to Next Node
            *sPtr = currentPtr->nextPtr;
        } else { // Else If Taking Any Other item - Connect Previos Node to Next Node
            previousPtr->nextPtr = currentPtr->nextPtr;
        }
    }
}

/*
   Function Description - Inserts Node into Linked List
   Parameters: NodePtr *sPtr, NodePtr *mPtr, char whereToInsert[]
   Returns: N/A
*/
void insertToList(NodePtr *sPtr, NodePtr *mPtr, char whereToInsert[]) {

    NodePtr currentPtr = *sPtr;
    NodePtr previousPtr = NULL;

    if (currentPtr == NULL) {
         puts("The list is empty. No content can be inserted!");
        return;
    } else {

        // Find Where to Insert
        while (currentPtr != NULL && (strcmp(currentPtr->data.textValue, whereToInsert) != 0 && strcmp(currentPtr->data.spExample, whereToInsert) != 0)) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // If At Front Insert Directly
        if (previousPtr == NULL) { // If At Front Insert Directly
            (*mPtr)->nextPtr = *sPtr;
            *sPtr = (*mPtr);
        } else { // Else Insert Between Nodes
            previousPtr->nextPtr = (*mPtr);
            (*mPtr)->nextPtr = currentPtr;
        }

    }
}

/*
   Function Description - Builds Prompt for Understanding PS1
   Parameters: NodePtr *sPtr
   Returns: N/A
*/
void buildPrompt(NodePtr *sPtr) {
    NodePtr currentPtr = *sPtr;

    char fullPrompt[1000] = ""; // Holds Entire Prompt String - > 1000...?

    if (currentPtr == NULL) {
        puts("The list is empty. No content can be printed!");
        return;
    } else {
        
        while (currentPtr != NULL) {
            char partialPrompt[100] = "";

            if (currentPtr->data.hasColor == 1) {

                if (currentPtr->data.isSpecial == 1) {

                    strcat(partialPrompt, currentPtr->data.colorCode); // Add Color First
                    strcat(partialPrompt, currentPtr->data.spCode); // Add Special Variable Next

                } else {

                    strcat(partialPrompt, currentPtr->data.colorCode); // Add Color First
                    strcat(partialPrompt, currentPtr->data.textValue); // Add Custom Content Next

                }

            } else {
                if (currentPtr->data.isSpecial == 1) {
                    strcat(partialPrompt, currentPtr->data.spCode); // Add Special Variable
                } else {
                    strcat(partialPrompt, currentPtr->data.textValue); // Add Custom Content
                }
            }

            strcat(fullPrompt, partialPrompt); // Attach Partial Prompt to Full Prompt
            currentPtr = currentPtr->nextPtr; // Move to Next Item in List

            if (!(currentPtr == NULL)) { // If Not At the End, Add a Space Between Prompt Values - CAN REMOVE TO TEST NO SPACE
                strcat(fullPrompt, " ");
            }
        }
    
    }

    printf("This is the special character string for your saved prompt: %s\n", fullPrompt);
    puts("\nTo immediately see this prompt in action, copy the entire line below and paste it into a new terminal.");
    printf("    export PS1='%s: '\n", fullPrompt); // Display Instructions Code Example
    puts(" ");
    puts("For a long term solution, complete the below steps.");
    puts("  1. Open another terminal and run the following commands.");
    puts("      - cd ~");
    puts("      - vi .bash_profile");
    puts("  2. Copy the entire line below and paste it into that file. Overwrite the existing PS1 line if there is one.");
    printf("        export PS1='%s: '\n", fullPrompt); // Display Instructions Code Example
    puts("  3. To close the vi editor.");
    puts("      - Hit the escape button");
    puts("      - Type :wq and hit enter");
    puts("  4. Now close that terminal and open a new one to see your prompt in action.");
}