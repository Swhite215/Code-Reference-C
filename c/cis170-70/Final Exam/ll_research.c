#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PromptComponent {
    char textValue[100];
    char colorValue[10];
    int hasColor;
};

struct node {
    struct PromptComponent data;
    struct node *nextPtr; // IMPORTANT: This should be null if last prompt component
};

typedef struct node Node;
typedef Node *NodePtr;

// Function Prototypes
void append(NodePtr *sPtr, char value[]);
void printLinkedList(NodePtr *sPtr);

int main(void) {
    NodePtr startPtr = NULL; // Linked List Initialized to Null
    char textValue[100];

    for (int i = 0; i < 3; i++) {
        printf("%s", "Enter a custom string: ");
        scanf("%99s", textValue);

        append(&startPtr, textValue);
    }

    printLinkedList(&startPtr);

    puts("");

    return 0;
}

/*
   Function Description - Appends New Prompt Component to Linked List
   Parameters: NodePtr *sPtr, char value[]
   Returns: N/A
*/
void append(NodePtr *sPtr, char value[]) {
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

    char fullPrompt[1000];

    if (currentPtr == NULL) {
        puts("The list is empty.");
        return;
    } else {
        while (currentPtr != NULL) {
            strcat(fullPrompt, currentPtr->data.textValue); // Concatenate Into Full Prompt
            currentPtr = currentPtr->nextPtr; // Move to Next Item in List

            if (!(currentPtr == NULL)) { // If Not At the End, Add a Space Between Prompt Values
                strcat(fullPrompt, " ");
            }
        }
    }

    printf("%s", fullPrompt); // Print the Full Prompt
}