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

int main(void) {
    NodePtr startPtr = NULL; // Linked List Initialized to Null
    char textValue[100];

    printf("%s", "Enter a custom string: ");
    scanf("%99s", textValue);

    append(&startPtr, textValue);

    printf("%s", "Enter another custom string: ");
    scanf("%99s", textValue);

    append(&startPtr, textValue);

    printf("%s", "Enter another custom string: ");
    scanf("%99s", textValue);

    append(&startPtr, textValue);

    return 0;
}

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