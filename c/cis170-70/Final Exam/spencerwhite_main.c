/*
   Spencer White
   CIS 170-70 - Final Exam: PS1 Designer
*/

/*
    Opportunities for Growth:
    1. Write and read more than one prompt from a file.
    2. Don't force spaces between prompt components by figuring out bettern patterns of features, text and delimters like -, >>, :, etc.
    3. Allow immediate insertion as opposed to append and then move.
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
void addContent(NodePtr *sPtr); // appendToList() and appendSPToList()
void removeContent(NodePtr *sPtr); // buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> deleteFromList()
void moveContent(); // buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> takeOutAndHoldComponent() -> buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> insertToList()
void colorContent(NodePtr *sPtr); // ADD OR REMOVE; buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> getColorSelection() -> addColorToComponent() || buildAndDisplayDynamicMenu() -> getSelection() -> getTargetPromptComponent() -> removeColorFromComponent()
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
                howToSwitchBashPrompts();
                break;
            case 'D':
                understandingPS1();
                break;
            case 'E':
                understandingSpecialPromptVariables();
                break;
            case 'F':
                howToSetupPS1();
                break;
            case 'G':
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
    printf("%s", "|  C: Switch Prompt                             |\n");
    printf("%s", "|  D: Understanding PS1                         |\n");
    printf("%s", "|  E: Understanding PS1 Special Variables       |\n");
    printf("%s", "|  F: Setup Prompt on MacOS                     |\n");
    printf("%s", "|  G: Generate Random Prompt                    |\n");
    printf("%s", "|  Q: Quit                                      |\n");
    printf("%s", "+-----------------------------------------------+\n");

    printf("%s", "Enter Your Choice: ");
    scanf(" %c", &mainMenuOption);

    while ((getchar()) != '\n');

    mainMenuOption = toupper(mainMenuOption);

    while (mainMenuOption != 'A' && mainMenuOption != 'B' && mainMenuOption != 'C' && mainMenuOption != 'D' && mainMenuOption != 'E' && mainMenuOption != 'F' && mainMenuOption != 'G' && mainMenuOption != 'Q') {
        puts("Invalid input. Enter either A, B, C, D, E, F, G, or Q");
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
    printf("%s", "|  A: Red                                       |\n");
    printf("%s", "|  B: Green                                     |\n");
    printf("%s", "|  C: Yellow                                    |\n");
    printf("%s", "|  D: Blue                                      |\n");
    printf("%s", "|  E: Purple                                    |\n");
    printf("%s", "|  F: Turquoise                                 |\n");
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

    printf("%s", "Please Select a Component: ");
    status = scanf("%d", &number);
    while ((getchar()) != '\n'); // Clear Buffer

    while (status != 1 || number < 0 || number >= *cPtr) { // If Not Int, Less Than Zero, or Equal to Counter - Unnacceptable Option
        puts("Invalid input. Please enter a valid number.");
        printf("%s", "Please Select a Component: ");
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
                moveContent();
                break;
            case 'D':
                colorContent(&startPtr);
                break;
            case 'E':
                writePromptToFile();
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

    printLinkedList(&startPtr);

    // Call readPromptsFromFile()
    // Display prompts
    // Force user to select one or quit
    // Display Edit Prompt Menu
    // Pass prompt to sub functions where appropriate

    int validPromptSelected = 1;

    if (validPromptSelected == 1) {
        char subMenuOption;
        do {
            displayEditPromptMenu(&subMenuOption);
            switch(subMenuOption){
                case 'A':
                    addContent(&startPtr);
                    break;
                case 'B':
                    removeContent(&startPtr);
                    break;
                case 'C':
                    moveContent();
                    break;
                case 'D':
                    colorContent(&startPtr);
                    break;
                case 'E':
                    writePromptToFile();
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
   Function Description - Manages the Secondary Flow of Instructing How to Switch Prompts
   Parameters: N/A
   Returns: N/A
*/
void howToSwitchBashPrompts() {
    // Call readPromptsFromFile()
    // Display prompts
    // Force user to select one or quit
    // call howToSetUpPS1() - passing selected prompt as reference

    puts("There are no prompts to switch to, returning to main menu...");
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
   Function Description - Adds Special Variables to Prompt
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
        }

    } while (subMenuOption != 'Q');
}

/*
   Function Description - Moves Content
   Parameters: N/A
   Returns: N/A
*/

void moveContent() {
    // Receive Prompt from above
    // Parse Prompt
    // Show Dynamic Menu of Prompt Parts that Can be Moved
    // User Selects Source
    // User Selects Destination
    // Portions are switched
    // Repeat until Quit

    char itemToBeMoved;
    char whereToMoveItem;
    do {

        displayMoveContentMenu(&itemToBeMoved, 0);

        if (itemToBeMoved == 'Q') {
            continue;
        }

        displayMoveContentMenu(&whereToMoveItem, 1);

        if (whereToMoveItem == 'Q') {
            continue;
        }

        puts("SWITCH CONTENT - call switchContent()");

    } while (itemToBeMoved != 'Q' && whereToMoveItem != 'Q');
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
                puts("REMOVE COLOR - call removeColor()");
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
   Function Description - Saves(Appends) Prompt to File
   Parameters: N/A
   Returns: N/A
*/

void writePromptToFile() {

    puts("No prompt receieved! Returning...");

    // Receive Prompt from above
    // Append Prompt to File (Duplicates can happen)
    // Show Error if Error, Say Successful if Successful
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
        previousPtr->nextPtr = currentPtr->nextPtr; // Set Previous Ptr Next Ptr to Node After Current Node
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