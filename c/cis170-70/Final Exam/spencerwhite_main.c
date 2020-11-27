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
void createNewPrompt();
void editExistingPrompt();
void howToSwitchBashPrompts();

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
                puts("call understandingPS1()");
                break;
            case 'E':
                puts("call understandingSpecialPromptVariables()");
                break;
            case 'F':
                puts("call howToSetupPS1()");
                break;
            case 'G':
                puts("call generateRandomPrompt()");
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
    printf("%s", "\n+---------------------------------------------+\n");
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
   Function Description - Prints Main Menu and Updates Value at Pointer
   Parameters: char *mPtr
   Returns: N/A
*/
void displayEditPromptMenu(char *sPtr) {
    char subMenuOption;
    printf("%s", "\n+---------------------------------------------+\n");
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
                puts("ADD CONTENT - call addContentMenu()");
                break;
            case 'B':
                puts("REMOVE CONTENT - call removeContentMenu()");
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
                    puts("ADD CONTENT - call addContentMenu()");
                    break;
                case 'B':
                    puts("REMOVE CONTENT - call removeContentMenu()");
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
                    puts("Exiting the program...");
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

void howToSwitchBashPrompts() {
    // Call readPromptsFromFile()
    // Display prompts
    // Force user to select one or quit
    // call howToSetUpPS1() - passing selected prompt as reference

    puts("There are no prompts to switch to, returning to main menu...");
}