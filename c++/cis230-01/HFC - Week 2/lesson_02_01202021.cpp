#include <iostream>
#include <string>
#include <limits>
#include <sstream>

int main() {


  int temp[3] = {35, 41, 29}; // Array Option #1 - C++11
  int count[10]{}; // Initialize Array to Zero

  char name[10] = "Joe"; // C-String

  std::string myName;
  myName = "Spencer";

  std::cout << "Hello "<<myName<<"!"<<std::endl;

  // Deal with Invalid Numeric Input
  int num;
  std::cout<<"Enter a number: ";
  std::cin>>name;

  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"Please enter a valid number: ";
    std::cin>>name;
  }

  // Print Array Values - for loop
  for (int x = 0; x < 3; x++) {
    std::cout<<temp[x]<<std::endl;
  }

  // Print Array Values - range loop
  for (int x : temp) {
    std::cout<<x<<std::endl;
  }

  float tempTwo[3] = {35.11, 41.22, 29.33};

  for (int x : tempTwo) {
    std::cout<<x<<std::endl; // Prints INTs
  }

  for (float x : tempTwo) {
    std::cout<<x<<std::endl; // Prints Floats
  }

  // Get String Input
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string today;
  std::cout<<"Enter a Day: ";
  getline(std::cin, today); // Removes enter key

  std::cout<<"Today is "<<today<<std::endl;

  // Get C String Input
  char tomorrow[20];
  std::cout<<"Enter a Day: ";
  std::cin.getline(tomorrow, 20);

  std::cout<<"Today is "<<tomorrow;

}