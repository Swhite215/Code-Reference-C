#include <stdio.h>

struct Movie {                              
   char name[35];    
   char coding[10];  
   unsigned int minutes;
   float ratingOne;
   float ratingTwo;
   float ratingThree;            
}; 

typedef struct Movie MOV;
#define MOVIES 10

// Function Prototypes
void produceReport(MOV movies[]);
void readDataIntoArray(MOV movies[]);

int main(void) {

    struct Movie movies[10];

    readDataIntoArray(movies);
    produceReport(movies);

    return 0;
}

/*
   Function Description - Reads movies.txt file and updates movie array
   Parameters: MOV movieArray[]
   Returns: N/A
*/

void readDataIntoArray(MOV movieArray[]) {

    FILE *readPtr;

    if ((readPtr = fopen("movies.txt", "rb+")) == NULL) {
        puts("File could not be opened.");
    } else {
        int counter = 0;
        while (!feof(readPtr)) {
            fscanf(readPtr, "%34[^,],%9[^,],%d,%f,%f,%f", movieArray[counter].name, movieArray[counter].coding, &movieArray[counter].minutes, &movieArray[counter].ratingOne, &movieArray[counter].ratingTwo, &movieArray[counter].ratingThree);
            counter++;
        }
    }

    fclose(readPtr);
}

/*
   Function Description - Takes array and writes contents to MovieReport.txt
   Parameters: MOV movieArray[]
   Returns: N/A
*/
void produceReport(MOV movieArray[]) {
    FILE *writePtr;

    if ((writePtr = fopen("MovieReport.txt", "w")) == NULL) {
      puts("File could not be opened.");
    } else {

       fprintf(writePtr, "%-38s%-11s%-14s%-15s\n", "Movie_Name", "Rating", "Total_Minutes", "Average_Rating");

        for (size_t i = 0; i < MOVIES; i++) {
            float averageRating = (movieArray[i].ratingOne + movieArray[i].ratingTwo + movieArray[i].ratingThree) / 3;
            fprintf(writePtr, "%-39s%-11s%-14d%-15.2f\n", movieArray[i].name, movieArray[i].coding, movieArray[i].minutes, averageRating);
        }
   }

   fclose(writePtr);
}