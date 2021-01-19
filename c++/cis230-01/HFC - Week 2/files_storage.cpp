#include <iostream>
#include <fstream>

int main() {

    // Sequential File Read Here
    std::string name;

    // Open the Input File
    std::ifstream inputFile; // Create file stream object - Reading
    inputFile.open("musicians.txt"); // Open the file and link to the file stream object

    if (inputFile) { // Check For Error
        std::cout<<"Here are the musicians stored in musicians.txt"<<std::endl;

        while (inputFile >> name) { // If a value was read, execute the code
            std::cout<<name<<std::endl;
        }

        inputFile.close();
    } else {
        std::cout<<"Error opening file for reading!"<<std::endl;
    }

    // Sequential File Write Here
    std::ofstream outputFile;

    // Open the Output File
    outputFile.open("friends.txt");

    if (outputFile) { // Check For Error
        std::cout<<"Now writing data to the file."<<std::endl;

        // Write Names to the File
        outputFile<<"Iron Man\n"; // you SHOULD add newline
        outputFile<<"Thor\n";
        outputFile<<"Black Widow\n";
        outputFile<<"Hawkeye\n";
        outputFile<<"Captain America\n";

        // Close the File
        outputFile.close();
    } else {
        std::cout<<"Error opening file for writing!"<<std::endl;
    }

    return 0;
}