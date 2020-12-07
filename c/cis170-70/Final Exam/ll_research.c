// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of Prompt Component Node
struct PromptComponent {
    char textValue[100];
    char colorName[15];
    char colorCode[15];
    int hasColor;
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
const char GRAY[6] = "GRAY";
const char DARK_GRAY[11] = "DARK_GRAY";

// Color Code Constants
const char RED_CODE[13] = "\\[\\e[0;31m\\]";
const char GREEN_CODE[13] = "\\[\\e[0;32m\\]";
const char YELLOW_CODE[13] = "\\[\\e[0;33m\\]";
const char BLUE_CODE[13] = "\\[\\e[0;34m\\]";
const char PURPLE_CODE[13] = "\\[\\e[0;35m\\]";
const char TURQUOISE_CODE[13] =" \\[\\e[0;36m\\]";
const char GRAY_CODE[13] = "\\[\\e[0;37m\\]";
const char DARK_GRAY_CODE[13] = "\\[\\e[0;30m\\]";

// Function Prototypes
void appendToList(NodePtr *sPtr, char value[]);
void printLinkedList(NodePtr *sPtr);
void deleteFromList(NodePtr *sPtr, char value[]);
void addColorToComponent(NodePtr *sPtr, char value[], char color[]);
void removeColorFromComponent(NodePtr *sPtr, char value[]);
void takeOutAndHoldComponent(NodePtr *sPtr, NodePtr *mPtr, char valueToFind[]);
void insertToList(NodePtr *sPtr, NodePtr *mPtr, char whereToInsert[]);

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

    addColorToComponent(&startPtr, "Spencer", GREEN);

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

    return 0;
}

/*
   Function Description - Appends New Prompt Component to Linked List
   Parameters: NodePtr *sPtr, char value[]
   Returns: N/A
*/
void appendToList(NodePtr *sPtr, char value[]) {
    NodePtr newPtr = malloc(sizeof(Node)); // Create a New Node

    struct PromptComponent newComponent = {"", "", 0}; // Create a New Prompt Component Struct
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
   Function Description - Prints Prompt Component Text Valus as a Single String
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
            strcat(fullPrompt, currentPtr->data.textValue); // Concatenate Into Full Prompt
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
        while (currentPtr != NULL && strcmp(currentPtr->data.textValue, value) != 0) { // Move Through List Until Match is Found
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
        while (currentPtr != NULL && strcmp(currentPtr->data.textValue, value) != 0) { // Move Through List Until Match is Found
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
        }else if (strcmp(TURQUOISE, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, TURQUOISE_CODE);
        }else if (strcmp(GRAY, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, GRAY_CODE);
        }else if (strcmp(DARK_GRAY, color) == 0) {
            currentPtr->data.hasColor = 1;
            strcpy(currentPtr->data.colorName, color);
            strcpy(currentPtr->data.colorCode, DARK_GRAY_CODE);
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
        while (currentPtr != NULL && strcmp(currentPtr->data.textValue, value) != 0) { // Move Through List Until Match is Found
            currentPtr = currentPtr->nextPtr;
        }

        currentPtr->data.hasColor = 0; // Set Has Color to Zero
        strcpy(currentPtr->data.colorName, ""); // Set Color Name to Nothing
        strcpy(currentPtr->data.colorCode, ""); // Set Color Code to Nothing
    }
}

void takeOutAndHoldComponent(NodePtr *sPtr, NodePtr *mPtr, char valueToFind[]) {
    NodePtr currentPtr = *sPtr;
    NodePtr previousPtr = NULL;

    if (currentPtr == NULL) {
         puts("The list is empty. No content can be moved!");
        return;
    } else {

        // Find Node to Move
        while(currentPtr != NULL && strcmp(currentPtr->data.textValue, valueToFind) != 0) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // Remove It From List and Store Temporarily
        *mPtr = currentPtr;


        if (previousPtr == NULL) { // If Taking First Item - Set Start to Next Node
            *sPtr = currentPtr->nextPtr;
        } else { // Else If Taking Any Other item - Connect Previos Node to Next Node
            previousPtr->nextPtr = currentPtr->nextPtr;
        }
    }
}

void insertToList(NodePtr *sPtr, NodePtr *mPtr, char whereToInsert[]) {

    NodePtr currentPtr = *sPtr;
    NodePtr previousPtr = NULL;

    if (currentPtr == NULL) {
         puts("The list is empty. No content can be inserted!");
        return;
    } else {

        // Find Where to Insert
        while (currentPtr != NULL && strcmp(currentPtr->data.textValue, whereToInsert) != 0) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // If At Front Insert Directly
        if (previousPtr == NULL) { // If At Front Insert Directly
            (*mPtr)->nextPtr = *sPtr;
            *sPtr = (*mPtr);
            return;
        } else { // Else Insert Between Nodes
            previousPtr->nextPtr = (*mPtr);
            (*mPtr)->nextPtr = currentPtr;
        }

    }
}