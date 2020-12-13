// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
const char TURQUOISE_CODE[13] =" \\[\\e[0;36m\\]";

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
void appendToList(NodePtr *sPtr, char value[]);
void appendSPToList(NodePtr *sPtr, char specialVariableCode[], char specialVariableExample[]);
void printLinkedList(NodePtr *sPtr);
void deleteFromList(NodePtr *sPtr, char value[]);
void addColorToComponent(NodePtr *sPtr, char value[], char color[]);
void removeColorFromComponent(NodePtr *sPtr, char value[]);
void takeOutAndHoldComponent(NodePtr *sPtr, NodePtr *mPtr, char valueToFind[]);
void insertToList(NodePtr *sPtr, NodePtr *mPtr, char whereToInsert[]);
void buildPrompt(NodePtr *sPtr);
void buildAndDisplayDynamicMenu(NodePtr *sPtr, int *cPtr);
void getSelection(int *sPtr, int *cPtr);
void getTargetPromptComponent(NodePtr *sPtr, int *selectionPtr, char targetPromptValue[]);
void writePromptToFile(NodePtr *sPtr);
void readPromptFromFile(NodePtr *ePtr);

// File Information
const char PATH[] = "";
const char FILENAME[] = "prompt.txt";

int main(void) {
    NodePtr startPtr = NULL; // Linked List Initialized to Null
    char textValue[100];

    for (int i = 0; i < 4; i++) {
        printf("%s", "Enter a custom string: ");
        scanf("%99s", textValue);

        appendToList(&startPtr, textValue);
    }

    printLinkedList(&startPtr);

    deleteFromList(&startPtr, "not"); // not is third value inserted*

    printLinkedList(&startPtr);

    NodePtr movePtr = NULL;
    takeOutAndHoldComponent(&startPtr, &movePtr, "awesome"); // Grab Node To Move
    insertToList(&startPtr, &movePtr, "Spencer"); // Insert Node

    printLinkedList(&startPtr);

    NodePtr movePtrTwo = NULL;
    takeOutAndHoldComponent(&startPtr, &movePtrTwo, "is"); // Grab Node To Move
    insertToList(&startPtr, &movePtrTwo, "Spencer"); // Insert Node

    printLinkedList(&startPtr);

    NodePtr movePtrThree = NULL;
    takeOutAndHoldComponent(&startPtr, &movePtrThree, "awesome"); // Grab Node To Move
    insertToList(&startPtr, &movePtrThree, "Spencer"); // Insert Node

    printLinkedList(&startPtr);

    appendSPToList(&startPtr, SP_DATE_CODE, SP_DATE_EXAMPLE); // Append Special Variable

    appendSPToList(&startPtr, SP_12HRTIME_TWO_CODE, SP_12HRTIME_TWO_EXAMPLE); // Append Special Variable

    deleteFromList(&startPtr, "Tue Dec 08"); // not is third value inserted*

    NodePtr movePtrFour = NULL;
    takeOutAndHoldComponent(&startPtr, &movePtrFour, "07:29 PM"); // Grab Node To Move
    insertToList(&startPtr, &movePtrFour, "awesome"); // Insert Node

    printLinkedList(&startPtr);

    addColorToComponent(&startPtr, "Spencer", GREEN);
    addColorToComponent(&startPtr, "is", RED);
    addColorToComponent(&startPtr, "awesome", PURPLE);
    addColorToComponent(&startPtr, "07:29 PM", BLUE);

    printLinkedList(&startPtr);

    buildPrompt(&startPtr);

    int counter = 0;
    int selection = 0;
    char targetPromptValue[25];

    buildAndDisplayDynamicMenu(&startPtr, &counter);
    getSelection(&selection, &counter);
    getTargetPromptComponent(&startPtr, &selection, targetPromptValue);

    writePromptToFile(&startPtr);

    NodePtr existingListPtr = NULL;
    readPromptFromFile(&existingListPtr);

    printLinkedList(&startPtr);

    return 0;
}

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

    if (currentPtr == NULL) {
        puts("The list is empty. No content can be printed!");
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

/*
   Function Description - Builds Prompt for PS1
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

    printf("%s\n", fullPrompt); // Print the Full Prompt
    printf("export PS1='%s: '\n", fullPrompt); // Display Instructions Code Example
}

/*
   Function Description - Builds Dynamic Menu Options 
   Parameters: NodePtr *sPtr, int *cPtr
   Returns: N/A
*/

void buildAndDisplayDynamicMenu(NodePtr *sPtr, int *cPtr) {
    NodePtr currentPtr = *sPtr;
    int counter = 0;

    if (currentPtr == NULL) {
        puts("The list is empty. No menu can be printed!");
        return;
    } else {
        puts("--------- Prompt Components --------- ");

        while (currentPtr != NULL) {

            if (currentPtr->data.isSpecial == 1) {  
                printf("%d.)   %s\n", counter, currentPtr->data.spExample);
            } else {
                printf("%d.)   %s\n", counter, currentPtr->data.textValue);
            }

            currentPtr = currentPtr->nextPtr; // Move to Next Item in List
            counter++; // Increment Counter
        }
    
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
    int counter = 0;

    if (currentPtr == NULL) {
        puts("The list is empty. No component can be selected!");
    } else {

        if (*selectionPtr == 0) { // If it is the first element
            if (currentPtr->data.isSpecial == 1) {
                strcpy(targetPromptValue, currentPtr->data.spExample);
            } else {
                strcpy(targetPromptValue, currentPtr->data.textValue);
            }
        } else {
            while (counter != *selectionPtr) {
                currentPtr = currentPtr->nextPtr;
                counter ++;
            }

            if (currentPtr->data.isSpecial == 1) {
                strcpy(targetPromptValue, currentPtr->data.spExample);
            } else {
                strcpy(targetPromptValue, currentPtr->data.textValue);
            }
        }
    }
}

/*
   Function Description - Writes the Prompt To File
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