//Ashley
//Spencer


#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <stdlib.h>
using namespace std;

int getIceCreamFlavor();
int getScoops();
void displayMenu(string icecreamdisplay);

int getIceCreamFlavor() {
  int flavorIndex = 0;

  cout<<"\nPlease choose flavor of Ice Cream: ";
  cin>>flavorIndex;

  while (cin.fail() || flavorIndex < 0 || flavorIndex > 4) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"Please enter a valid number [0-4]"<<std::endl;
    cin>>flavorIndex;
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return flavorIndex;

}

int getScoops() {
  int scoops = 0;

  cout<<"\nPlease enter a number of scoops: ";
  cin>>scoops;

  while (cin.fail() || scoops < 0) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"Please enter a valid number of scoops sold [0-N]"<<std::endl;
    cin>>scoops;
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return scoops;

}

void displayMenu(string icecreamdisplay)
{
  for(int i=0;i<5;i++) 
  {
  cout<<"."<<icecreamdisplay[i];
  }
}

int main() {

  int totalScoops = 0;
  int scoopsPerFlavor[5]{};
  string icecreamdisplay[5] = {"Vanilla", "Butter Pecan", "Superman", "Chocolate Fudge", "Strawberry"};

  char answer;
  do {

    // Ask to Buy
    cout<<"\nWould you like to buy some ice cream? "<<flush;
    cin>>answer;

  // Display the Menu
    void displayMenu();

    // Get Flavor Index
    int flavorIndex = getIceCreamFlavor();

    // Get Scoops
    int scoops = getScoops();

    // Increase Flavor Count
    scoopsPerFlavor[flavorIndex] += scoops;

    // Increase Total Count
    totalScoops += scoops;
 

  } while(answer != 'N' || answer != 'n');

  cout<<"\nVanilla sold: "<<setw(40)<<"Total Vanilla Scoops: "<<scoopsPerFlavor[0]<<endl;
  cout<<"Butter Pecan sold: "<<setw(40)<<"Total Butter Pecan Scoops: "<<scoopsPerFlavor[1]<<endl;
  cout<<"Superman sold: "<<setw(40)<<"Total Superman Scoops: "<<scoopsPerFlavor[2]<<endl;
  cout<<"Chocolate Fudge sold: "<<setw(40)<<"Total Chocolate Fudge Scoops: "<<scoopsPerFlavor[3]<<endl;
  cout<<"Strawberry sold: "<<setw(40)<<"Total Strawberry Scoops: "<<scoopsPerFlavor[4]<<endl;

  cout<<"Total Scoops sold:"<<setw(40)<<totalScoops<<endl;

  return 0;

}
