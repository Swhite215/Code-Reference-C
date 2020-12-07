// Linked List - Key Data Structure

// PromptComponent Structure
struct PromptComponent {
    char textValue[100];
    char colorValue[10];
    int hasColor;
};

// Linked List Node - w/ PromptComponent Structure and Pointer to Next PromptComponent
struct Node {
    struct PromptComponent data;
    struct PromptComponent *nextPtr; // IMPORTANT: This should be null if last prompt component
};


//ListNodePtr newPtr = malloc(sizeof(Node));

// Building the Linked List Order of Operations
// #1A - Append Only - Make the List ANY Length, Always Adding On To the End - DONE
// #1B - Print Linked List - DONE
// #2 - Delete  - Remove Any Content Based on Data Value (textValue)
// #3 - Move - Change Content Positions At Will
// #4 - Update - Add Color - Set colorValue = "Choice"
// #5 - Update - Remove Color - set colorValue = ""
