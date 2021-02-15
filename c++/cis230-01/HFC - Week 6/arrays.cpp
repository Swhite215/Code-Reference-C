#include <iostream>
#include <iomanip>

const int MAX_COLS = 5;
const int NUM_SECTIONS = 3;
const int ROWS_IN_SECTION = 5;
const int SEATS_IN_ROW = 8;

typedef double seatTable[][ROWS_IN_SECTION][SEATS_IN_ROW];

// Function Prototypes
void showArray(const int array[][MAX_COLS], int numRows);
void displaySeats(double [][5][8], int);

int main() {

    // Initializing
    int items[6]{};

    for (int i = 0; i < 6; i++) {
        items[i] = i + 1;
    }

    const int NUM_MONTHS = 12;
    int days[NUM_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int values{5};

    // Range Based For Loop
    for (int x : days) {
        std::cout<<x<<std::endl;
    }

    // Copying Array
    const int SIZE = 6;
    int arrayA[SIZE] = {10, 20, 30, 40, 50, 60};
    int arrayB[SIZE] = { 2,  4,  6,  8, 10, 12};

    for (int index = 0; index < SIZE; index++) {
        arrayA[index] = arrayB[index];
    }

    // Comparing - Compare Each Element
    // Maximum - Set Highest and then Compare
    // Minimum - Set Lowest and then Compare

    // Two Dimensional
    int scores[3][MAX_COLS];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            scores[i][j] = i * j;
        }
    }

    showArray(scores, 3);

    int hours[3][2] = {{8,5}, {7,9}, {6,3}};

    // Three Dimensional Arrays - Three Sets of Five Rows, with Each Row Having Eight Elements

    double seats[NUM_SECTIONS][ROWS_IN_SECTION][SEATS_IN_ROW];

    for (int section = 0; section < NUM_SECTIONS; section++) {
        for (int rows = 0; rows < ROWS_IN_SECTION; rows++) {
            for (int seat = 0; seat < SEATS_IN_ROW; seat++) {
                seats[section][rows][seat] = section * rows * seat;
            }
        }
    }

    
    return 0;
}

void showArray(int const array[][MAX_COLS], int numRows) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            std::cout<<std::setw(5)<<array[row][col]<<std::endl;
        }
    }
}

void displaySeats(double array[][5][8], int numGroups) {

}