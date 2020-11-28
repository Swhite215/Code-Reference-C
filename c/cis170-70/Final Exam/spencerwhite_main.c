/*
   Spencer White
   CIS 170-70 - Final Exam: PS1 Designer
*/

// Headers
#include <stdio.h>

// Globals

// Function Prototypes
void displayMainMenu(char *mPtr);
void displayEditPromptMenu(char *sPtr);
void displaySavePromptMenu(char *sPtr);
void displayAddContentMenu(char *sPtr);
void displayRemoveContentMenu(char *sPtr);
void displayMoveContentMenu(char *sPtr, int order);
void createNewPrompt();
void editExistingPrompt();
void howToSwitchBashPrompts();
void understandingPS1();
void understandingSpecialPromptVariables();
void howToSetupPS1();
void generateRandomPrompt();
void addContent();
void removeContent();
void moveContent();

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
    printf("%s", "|  G: Generate Random prompt                    |\n");
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
    printf("%s", "|  A: Add Default Feature                       |\n");
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
   Function Description - Prints Add Content Menu and Updates Value at Pointer
   Parameters: char *sPtr
   Returns: N/A
*/
void displayRemoveContentMenu(char *sPtr) {
    char subMenuOption;
    //  MENU NEEDS TO BE DYNAMIC BASED ON NUMBER OF PARTS OF PROMPT
    printf("%s", "\n+-----------------------------------------------+\n");
    printf("%s", "|               Remove Content Menu             |\n");
    printf("%s", "+-----------------------------------------------+\n");
    printf("%s", "|               FAKE PROMPT HERE                |\n");
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
   Function Description - Prints Add Content Menu and Updates Value at Pointer
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
        printf("%s", "|                   Portion to Move             |\n");
        printf("%s", "|                                               |\n");
    } else if (order == 1) {
        printf("%s", "|                   Destination                 |\n");
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

// ------------------------------------------------- FUNCTIONS -------------------------------------------------
/*
   Function Description - Manages the Secondary Flow of Creating a Prompt
   Parameters: N/A
   Returns: N/A
*/
void createNewPrompt() {
    // Create prompt variable i.e. string, array, etc.
    // Pass prompt to sub functions where appropriate
    char subMenuOption;
    do {
        displayEditPromptMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                addContent();
                break;
            case 'B':
                removeContent();
                break;
            case 'C':
                moveContent();
                break;
            case 'D':
                puts("COLOR CONTENT - call colorHandlingMenu() - PART ONE");
                break;
            case 'E':
                puts("SAVE PROMPT - call writePromptToFile()");
                break;
            case 'Q':
                puts("Exiting the program...");
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

    // Call readPromptsFromFile()
    // Display prompts
    // Force user to select one or quit
    // Display Edit Prompt Menu
    // Pass prompt to sub functions where appropriate

    int validPromptSelected = 0;

    if (validPromptSelected == 1) {
        char subMenuOption;
        do {
            displayEditPromptMenu(&subMenuOption);
            switch(subMenuOption){
                case 'A':
                    addContent();
                    break;
                case 'B':
                    removeContent();
                    break;
                case 'C':
                    puts("MOVE CONTENT - call moveContentMenu() - PART ONE");
                    break;
                case 'D':
                    puts("COLOR CONTENT - call colorHandlingMenu() - PART ONE");
                    break;
                case 'E':
                    puts("SAVE PROMPT - call writePromptToFile()");
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

void addContent() {
    // Receive Prompt from above
    // Pass prompt to be edited
    char subMenuOption;
    do {
        displayAddContentMenu(&subMenuOption);
        switch(subMenuOption){
            case 'A':
                puts("ADD FEATURE - call addFeature()");
                break;
            case 'B':
                puts("ADD TEXT - call addCustomText()");
                break;
            case 'Q':
                puts("Exiting the program...");
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

void removeContent() {
    // Receive Prompt from above
    // Parse Prompt
    // Show Dynamic Menu of Prompt Parts that Can be Deleted
    // User Selects One
    // Part is Deleted and Menu is Reshown with new prompt

    char subMenuOption;
    do {
        displayRemoveContentMenu(&subMenuOption);
        // SWITCH NEEDS TO BE DYNAMIC BASED ON NUMBER OF PARTS OF PROMPT
        switch(subMenuOption){
            case 'A':
                puts("REMOVE FEATURE ONE - call deleteFeature(0)");
                break;
            case 'B':
                puts("REMOVE FEATURE TWO - call deleteFeature(1)");
                break;
            case 'N':
                puts("REMOVE FEATURE N - call deleteFeature(N-1)");
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