/*
   Spencer White
   CIS 170-70 - Temperature Conversion
   Displays Celsius to Fahrenheit and Fahrenheit to Celsius Conversion Tables
*/

#include <stdio.h>

// Function Prototypes
float toCelsius(float);
float toFahrenheit(float);
void displayCelsiusToFahrenheitTable();
void displayFahrenheitToCelsiusTable();

int main( void ) {

    displayCelsiusToFahrenheitTable();
    puts("                                       ");
    displayFahrenheitToCelsiusTable();

    return 0;
}

/*
   Function Description - Convert Fahrenheit Input to Celsius
   Parameters: float fahrenheit
   Returns: float celsius
*/
float toCelsius(float fahrenheit) {
    return ((fahrenheit - 32) * 5 / 9);
}

/*
   Function Description - Convert Celsius Input to Fahrenheit
   Parameters: float celsius
   Returns: float fahrenheit
*/
float toFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

/*
   Function Description - Prints Celisus to Fahrenheit Conversion Table
   Parameters: N/A
   Returns: N/A
*/
void displayCelsiusToFahrenheitTable() {
    puts("- - - - - - - - - - - - - - - - - - - -");
    puts("Celisus to Fahrenheit Conversion Table");
    puts("- - - - - - - - - - - - - - - - - - - -");
    puts("| Celsius (°C) | Fahrenheit (°F) |");

    for (int i = 0; i <= 100; i++) {
        float fahrenheit;
        fahrenheit = toFahrenheit(i);
        printf("| %d°\t       | %.1f° |\n", i, fahrenheit);
    }

}

/*
   Function Description - Prints Fahrenheit to Celisus Conversion Table
   Parameters: N/A
   Returns: N/A
*/
void displayFahrenheitToCelsiusTable() {
    puts("- - - - - - - - - - - - - - - - - - - -");
    puts("Fahrenheit to Celisus Conversion Table");
    puts("- - - - - - - - - - - - - - - - - - - -");
    puts("| Fahrenheit (°F) | Celisus (°C) |");

    for (int i = 32; i <= 212; i++) {
        float celsius;
        celsius = toCelsius(i);
        printf("| %d°\t\t  | %.1f° |\n", i, celsius);
    }


}

