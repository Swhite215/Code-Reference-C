/*
   Spencer White
   CIS 170-70 - Student Structure Assignment
*/

#include <stdio.h>

// Globals
struct Student {
    int studentId;
    char name[20];
    int completedCredits;
    float GPA;
};

typedef struct Student STU;
#define STUDENTS 3

// Function Prototypes
void retrieveStudentName(char name[]);
void retrieveStudentID(int *iPtr);
void retrieveStudentCredits(int *cPtr);
void retrieveStudentGPA(float *gPtr);
void gatherClassData(STU students[]);
void displayClassData(STU students[]);

int main (void) {

    struct Student studentOne = {12345678, "Cloud Strife", 32, 4.00};

    printf("The student %s has the ID %d, has completed %d credits, and has a %.2f GPA.\n", studentOne.name, studentOne.studentId, studentOne.completedCredits, studentOne.GPA);

    struct Student studentTwo = {87654321, "Barret Wallace", 24, 3.10};

    printf("The student %s has the ID %d, has completed %d credits, and has a %.2f GPA.\n", studentTwo.name, studentTwo.studentId, studentTwo.completedCredits, studentTwo.GPA);

    struct Student studentThree;

    retrieveStudentID(&studentThree.studentId);
    retrieveStudentName(studentThree.name);
    retrieveStudentCredits(&studentThree.completedCredits);
    retrieveStudentGPA(&studentThree.GPA);

    printf("The student %s has the ID %d, has completed %d credits, and has a %.2f GPA.\n", studentThree.name, studentThree.studentId, studentThree.completedCredits, studentThree.GPA);

    struct Student studentFour, studentFive, studentSix;

    struct Student c_Class[3] = {
        studentFour, studentFive, studentSix
    };

    gatherClassData(c_Class);
    displayClassData(c_Class);

    return 0;
}

/*
   Function Description - Retrives Student's Name
   Parameters: char* name
   Returns: char name[]
*/

void retrieveStudentName(char name[]) {
    printf("%s", "Enter the student's name: ");

    int nameStatus = scanf("%s", name);
    while ((getchar()) != '\n');
    while (nameStatus != 1) {
        puts("Invalid input. Please enter a valid string.");
        printf("%s", "Enter the student's name: ");
        nameStatus = scanf("%s", name);
        while ((getchar()) != '\n');
    }
}

/*
   Function Description - Retrives Student's ID
   Parameters: int *nPtr studentID
   Returns: N/A
*/

void retrieveStudentID(int *iPtr) {
    int id;

    printf("%s", "Enter the student's ID number: ");

    int idStatus = scanf("%d", &id);
    while ((getchar()) != '\n');

    while (idStatus != 1) {
        puts("Invalid input. Please enter a valid number.");
        printf("%s", "Enter the student's ID number: ");
        idStatus = scanf("%d", &id);
        while ((getchar()) != '\n');
    }

    *iPtr = id;
}

/*
   Function Description - Retrives Student's Completed Credits
   Parameters: int *cPtr completedCredits
   Returns: N/A
*/

void retrieveStudentCredits(int *cPtr) {
    int credits;

    printf("%s", "Enter the number of credits the student has completed: ");

    int creditsStatus = scanf("%d", &credits);
    while ((getchar()) != '\n');
    while (creditsStatus != 1) {
        puts("Invalid input. Please enter a valid number.");
        printf("%s", "Enter the number of credits the student has completed: ");
        creditsStatus = scanf("%d", &credits);
        while ((getchar()) != '\n');
    }

    *cPtr = credits;
}

/*
   Function Description - Retrives Student's GPA
   Parameters: int *gPtr GPA
   Returns: N/A
*/

void retrieveStudentGPA(float *gPtr) {
    float GPA;

    printf("%s", "Enter the student's GPA: ");

    int gpaStatus = scanf("%f", &GPA);
    while ((getchar()) != '\n');
    while (gpaStatus != 1) {
        puts("Invalid input. Please enter a valid number.");
        printf("%s", "Enter the student's GPA: ");
        gpaStatus = scanf("%f", &GPA);
        while ((getchar()) != '\n');
    }

    *gPtr = GPA;
}

/*
   Function Description - Gathers Data About Students
   Parameters: STU students[]
   Returns: N/A
*/

void gatherClassData(STU students[]) {

    for (size_t i = 0; i < STUDENTS; i++) {
        retrieveStudentID(&students[i].studentId);
        retrieveStudentName(students[i].name);
        retrieveStudentCredits(&students[i].completedCredits);
        retrieveStudentGPA(&students[i].GPA);
    }
}

/*
   Function Description - Displays Data About the Students
   Parameters: STU students[]
   Returns: N/A
*/

void displayClassData(STU students[]) {

    for (size_t i = 0; i < STUDENTS; i++) {
        printf("The student %s has the ID %d, has completed %d credits, and has a %.2f GPA.\n", students[i].name, students[i].studentId, students[i].completedCredits, students[i].GPA);
    }
}