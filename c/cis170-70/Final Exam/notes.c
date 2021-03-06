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
// #2 - Delete  - Remove Any Content Based on Data Value (textValue) - DONE
// #3A - Move - Change Content Position - DONE
// #3B - Move - Free the Memory When Appropriate - DONE
// #4 - Update - Add Color - Set colorName, colorCode, and hasColor - DONE     
// #5 - Update - Remove Color - set colorValue, colorCode, and hasColor - DONE
// #8 - Append Special Variable Content - set isSpecial, spCode, and spExample - DONE
// #9 - Print Linked List with Colors and Special Variable Content (Custom Content + COLORS + Special Variable Examples) - DONE
// #10 - Form Prompt That Renders Correct as PS1= (Custom Content + COLORS + Special Variables) - DONE
// #11 - Write Prompt to File - DONE
// #12 - Load Prompt from File - DONE
// #13 - Build Dynamic Selection Menu (Options) - DONE
// #14 - Get Dynamic Prompt Selection Based on Menu (Input) - DONE
// #15 - Get Target Prompt Component textValue or spExample (Selection) - DONE