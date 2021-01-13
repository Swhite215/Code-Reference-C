/*
   Spencer White
   CIS 230-02 - Project Name
   Description of the Program
*/

#include <iostream> // Used for I/O
#include <iomanip> // Use for I/O Manipulation
#include <string> // Use for String Manipulations

//using std::cout; // Use standard for cout
//using std::cin; // Use standard for cin
//using namespace std; // Takes away the need to use std::___

int main()
{

  // OUTPUT
  std::cout<<"Hello World!"; // << is insertion operator
  std::cout<<"\n"; // newline
  
  std::cout<<"This is Spencer!";
  std::cout<<std::endl; // stream manipulator, newline

  //cout<<"\nHow are you??"; // requires line 10 namespace

  int age = 27;
  std::cout<<"I am "<<age<<" years old\n";

  // Data Types - Numeric
  short int sint; // 2 Bytes | -32,768 to 32,768
  std::cout<<"The min value of a short int is "<<-32768<<" and the max value is "<<32768;
  std::cout<<std::endl;

  unsigned short int usint; // 2 | Bytes 0 to 65535
  std::cout<<"The min value of a unsigned short int is "<<0<<" and the max value is "<<65535;
  std::cout<<std::endl;

  int myInt; // 4 Bytes | -2,147,483,648 to 2,147,483,648
  std::cout<<"The min value of a int is "<<-2147483648<<" and the max value is "<<-2147483648;
  std::cout<<std::endl;

  unsigned int uint; // 4 Bytes | 0 to 4,294,967,295
  std::cout<<"The min value of a unsigned int is "<<0<<" and the max value is "<<4294967295;
  std::cout<<std::endl;

  long int lint; // 4 Bytes | -2,147,483,648 to 2,147,483,648
  std::cout<<"The min value of a long int is "<<-2147483648<<" and the max value is "<<-2147483648;
  std::cout<<std::endl;

  unsigned long int ulint; // 4 Bytes | 0 to 4,294,967,295
  std::cout<<"The min value of a unsigned long int is "<<0<<" and the max value is "<<4294967295;
  std::cout<<std::endl;

  float myFloat = 3.145F;

  double myDouble;

  long double myLongDouble = 3.145L;

  // Casting - Convert Numbers From One Type to Another
  int myNum = static_cast<int>(10.12); // truncates, removes decimal
  std::cout<<"My number is "<<myNum;
  std::cout<<std::endl;

  int mySecondFloat = static_cast<float>(10);
   std::cout<<"My float is "<<mySecondFloat;
  std::cout<<std::endl;

  // Data Types - Strings
  char myChar = static_cast<char>(66);
  std::cout<<"My character is "<<myChar;
  std::cout<<std::endl;

  // Constants
  // C - #define PI 3.14
  const double PI = 3.14159265;
  std::cout<<"PI is: "<<PI; // displays six digits
  std::cout<<std::endl;

  std::cout<<"PI is: "<<std::setw(10)<<PI; // setw(), sets width of output - Single Use Manip
  std::cout<<std::endl;

  std::cout<<"PI is: "<<std::setprecision(20)<<PI; // setprecision(), sets number of digits - Toggle Manip*
  std::cout<<std::endl;

  std::cout<<"PI is: "<<std::setprecision(20)<<std::fixed<<PI; // fixed, sets decimal accuracy - Toggle Manip*
  std::cout<<std::endl;

  // INPUT
  int num1, num2;
  std::cout<<"Enter a number: ";
  std::cin>>num1; // >> = extraction operator
  std::cout<<"Your name is "<<num1;
  std::cout<<std::endl;

 std::string myName; // string is used as a class here
 std::cout<<"Enter your name: ";
 std::cin>>myName; // stop at space or enter key
 std::cout<<"Your name is "<<myName;
 std::cout<<std::endl;

 std::cin.ignore(10000, '\n'); // IMPORTANT: whatever is in buffer, ignore first number of characters or up to '\n'
 std::string address; // string is used as a class here
 std::cout<<"Enter your address: ";
 std::getline(std::cin, address); // will take entire input, including enter key if not ignored like on line 103
 std::cout<<"Your address is "<<address;
 std::cout<<std::endl;

 std::string flavors[5];
 flavors[0] = "Blue";

 std::cout<<"The first flavor is "<<flavors[0];


 // Data Type
 bool hungry = false;

 if (hungry) {
   std::cout<<"Order Pizza!";
   std::cout<<std::endl;
 }

 if (!hungry) {
    std::cout<<"Keep Working!";
    std::cout<<std::endl;
 }


  return 0;
}