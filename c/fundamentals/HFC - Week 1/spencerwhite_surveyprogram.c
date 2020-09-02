/*
   Spencer White
   CIS 170-70 - High School Programming Survey
   Reads and Displays Data About Which Programming Languages Students Know
*/

#include <stdio.h>

/*
   High School Survey Program
   Parameters: N/A
   Returns: N/A
*/

int main() {
    int html, java, cPlusPlus, cSharp, javascript, PHP, python;
    int totalStudents, webLanguages, objectOrientedLanguages;

    printf("\nWelcome to the Comstock High School Programming Survey\n");

    printf("\nPlease enter the total number of students who know:\n");

    printf("\n\r\tHTML: ");
    scanf("%d", &html);

    printf("\r\tJava: ");
    scanf("%d", &java);

    printf("\r\tC++: ");
    scanf("%d", &cPlusPlus);

    printf("\r\tC#: ");
    scanf("%d", &cSharp);

    printf("\r\tJavaScript: ");
    scanf("%d", &javascript);

    printf("\r\tPHP: ");
    scanf("%d", &PHP);

    printf("\r\tPython: ");
    scanf("%d", &python);

    totalStudents = html + java + cPlusPlus + cSharp + javascript + PHP + python;
    webLanguages = javascript + PHP + html;
    objectOrientedLanguages = java + cPlusPlus + cSharp + python;

    printf("\nTotal Students: %d", totalStudents);
    printf("\nTotal who know Web Languages: %d", webLanguages);
    printf("\nTotal who know Object Oriented Languages: %d\n", objectOrientedLanguages);

    return 0;
}