/*
   Spencer White
   CIS 170-70 - Final Exam: PS1 Designer
*/

/*
    Opportunities for Growth - Written Morning of 12/16/2020:
    1. Write and read more than one prompt from a file. Given that I did not allow this, I also dropped the How to Switch functionality.
    2. Don't force spaces between prompt components. Can remove lines 
    3. Allow immediate insertion as opposed to append and then move.
    4. Add warning prior to leaving Edit Prompt Menu that the user's prompt will be lost.
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
void displayMoveContentMenu(char *sPtr, int order);
void displayColorContentMenu(char *sPtr);
void displayColorSelectMenu(char *sPtr);
void createNewPrompt();
void editExistingPrompt();
void howToSwitchBashPrompts();
void understandingPS1();
void understandingSpecialPromptVariables();
void howToSetupPS1();
void generateRandomPrompt(); // REMOVE IF RUNNING OUT OF TIME
void addContent(NodePtr *sPtr);
void removeContent(NodePtr *sPtr);
void moveContent(NodePtr *sPtr); // buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> takeOutAndHoldComponent() -> buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> insertToList()
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
            case 'F':
                generateRandomPrompt();
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
    printf("%s", "|  F: Generate Random Prompt                    |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);

    while ((getchar()) != '\n');

    mainMenuOption = toupper(mainMenuOption);

    while (mainMenuOption != 'A' && mainMenuOption != 'B' && mainMenuOption != 'C' && mainMenuOption != 'D' && mainMenuOption != 'E' && mainMenuOption != 'F' && mainMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, C, D, E, F or Q");
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
   Function Description - Prints Color Content Menu Header
   Parameters: char *sPtr
   Returns: N/A
*/
void displayPromptContentSelectionHeader() {
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|          Prompt Content Selection Menu        |\n");
    printf("%s", "+-----------------------------------------------+\n");
    puts("");
   
}

/*
   Function Description - Prints Color Content Menu Header
   Parameters: char *sPtr
   Returns: N/A
*/
void displayPromptContentFirstSelection() {
    printf("%s", "            Pick Component To Move               \n");
    puts("");
}

/*
   Function Description - Prints Color Content Menu Header
   Parameters: char *sPtr
   Returns: N/A
*/
void displayPromptContentSecondSelection() {
    printf("%s", "            Pick Where To Move Component         \n");
    puts("");
}

/*
   Function Description - Prints Move Content Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayMoveContentMenu(char *sPtr, int order) {
    char subMenuOption;
    //  MENU NEEDS TO BE DYNAMIC BASED ON NUMBER OF PARTS OF PROMPT
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Move Content Menu               |\n");
    printf("%s", "+-----------------------------------------------+\n");

    if (order == 0) {
        printf("%s", "|                   Portion to Move?             |\n");
        printf("%s", "|                                               |\n");
    } else if (order == 1) {
        printf("%s", "|                   Destination?                 |\n");
        printf("%s", "|                   (Content after insert will be pushed to the right)                |\n");
    }

    printf("%s", "|                                               |\n");
    printf("%s", "|  A: PORTION ONE                               |\n");
    printf("%s", "|  B: PORTION TWO                               |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &subMenuOption);

    while ((getchar()) != '\n');

    subMenuOption = toupper(subMenuOption);

    // OPTIONS NEED TO BE DYNAMIC BASED ON NUMBER OF PARTS OF PROMPT
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
   Function Description - Builds Dynamic Menu Options 
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

    while (status != 1 || number < 0 || number >= *cPtr) { // If Not Int, Less Than Zero, or Equal to Counter - Unnacceptable Option
        puts("Invalid input. Please enter a valid number.");
        printf("%s", "\nPlease Select a Component: ");
        status = scanf("%d", &number);
        while ((getchar()) != '\n'); // Clear Buffer
    }

    *sPtr = number;
}

/*
   Function Description - Gets Selected Prompt Component Value
   Parameters: Node *sPtr, int *sPtr, char targetPromptValue[]
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
    // Detailed information about PS1 from - Project Design references
     puts("No information to share about PS1...");
}

/*
   Function Description - Manages the Display of Information about Special Prompt Variables
   Parameters: N/A
   Returns: N/A
*/
void understandingSpecialPromptVariables() {
    // Detailed information about Special Variables from - Project Design references
     puts("No information to share about special prompt variables...");
}

/*
   Function Description - Manages the Display of Information about Setting PS1
   Parameters: N/A
   Returns: N/A
*/
void howToSetupPS1() {

    // Check if Prompt is Passed - If So Use It, Else Use Example/Random Prompt
    // Detailed information about setting PS1 using Option 1 - editing .bash_profile
    // Detailed information about setting PS1 using Option 2 - terminal echo
     puts("No directions on setting PS1 to share...");
}

/*
   Function Description - Generates Random Prompts
   Parameters: N/A
   Returns: DEFINE DATA TYPE OF PROMPT
*/
void generateRandomPrompt() {

    // Call generateRandomFeatures() - generates a prompt compose of random number special prompt variables
    // Call generateRandomColors() - uses random colors to color a random number of the features in the prompt generated above
    // Call displayPromptResults() - will display the prompt, the features that make it up, and the color codes usesd
    // Call displaySavePromptMenu() - displays Save Prompt Menu - choose to save or quit and abandon prompt
    
     puts("No prompts can currently be generated...");

    char subMenuOption;
    do {
        displaySavePromptMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                puts("SAVE PROMPT - call writePromptToFile()");
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
   Function Description - Adds Content
   Parameters: N/A
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
   Parameters: N/A
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
   Parameters: N/A
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
    // Receive Prompt from above
    // Parse Prompt
    // Choose to Add or Remove Color
        // Add - Choose Content -> Choose Color
        // Remove - Choose Content -> Removed IF color exists

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
   Function Description - Writes the Prompt To A File
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
        }

    }
}

/*
   Function Description - Reads the Prompt From File and Builds Linked List
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
   Parameters: NodePtr *sPtr, char value[]
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
   Function Description - Adds Color to Node in the List
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
   Function Description - Grabs and Holds a Node in Anticipation of Moving
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