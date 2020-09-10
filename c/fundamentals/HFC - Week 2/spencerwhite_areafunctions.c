/*
   Spencer White
   CIS 170-70 - Area Functions
   Calculates and returns the areas for a triangle, rectangle/square, and a oval
*/

#include <stdio.h>

// Function Prototypes
float askForLength();
float askForHeight();
float calculateAreaOfTriangle(float, float);
float calculateAreaOfSquareAndRectangle(float, float);
float calculateAreaOfOval(float, float);
void displayAreas(float, float, float);

int main (void) {

    float length;
    float height;
    float areaOfTriangle;
    float areaOfSquareAndRectangle;
    float areaOfOval;

    length = askForLength();
    height = askForHeight();

    areaOfTriangle = calculateAreaOfTriangle(length, height);
    areaOfSquareAndRectangle = calculateAreaOfSquareAndRectangle(length, height);
    areaOfOval = calculateAreaOfOval(length, height);

    displayAreas(areaOfTriangle, areaOfSquareAndRectangle, areaOfOval);

    return 0;
}

/*
   Function Description - Retrieves length from user
   Parameters: N/A
   Returns: float length
*/

float askForLength() {
    float length;

    printf("%s", "What is the length of the shape? ");
    scanf("%f", &length);

    return length;
}

/*
   Function Description - Retrieves height from user
   Parameters: N/A
   Returns: float height
*/

float askForHeight() {
    float height;

    printf("%s", "What is the height of the shape? ");
    scanf("%f", &height);

    return height;
}

/*
   Function Description - Calculates the area of a triangle
   Parameters: float length, float height
   Returns: float areaOfTriangle
*/

float calculateAreaOfTriangle(float length, float height) {
    return .5 * length * height;
}

/*
   Function Description - Calculates the area of a square/rectangle
   Parameters: float length, float height
   Returns: float areaOfSquareAndRectangle
*/

float calculateAreaOfSquareAndRectangle(float length, float height) {
    return length * height;
}

/*
   Function Description - Calculates the area of a oval
   Parameters: float length, float height
   Returns: float areaOfOval
*/

float calculateAreaOfOval(float length, float height) {
    return length * height * .8;
}

/*
   Function Description - Prints areas of shapes
   Parameters: float areaOfTriangle, float areaOfSquareAndRectangle, float areaOfOval
   Returns: N/A
*/

void displayAreas(float areaOfTriangle, float areaOfSquareAndRectangle, float areaOfOval) {
    printf("If you entered the dimensions of a Triangle, then your area is %.2f square feet.\n", areaOfTriangle);
    printf("If you entered the dimensions of a Rectangle/Square, then your area is %.2f square feet.\n", areaOfSquareAndRectangle);
    printf("If you entered the dimensions of a Oval, then your area is %.2f square feet.\n", areaOfOval);
}