#include <iostream>
#include <vector>

class Pet {
  private:
    std::string name;

  public:
    Pet(std::string n) {
      name = n;
    }
    std::string getName() {return name; }

};

class Pets {
  private:
    std::vector<Pet> petList;

  public:
    void addPet(Pet p) {petList.push_back(p); }
    void displayPets() {
      for (Pet x : petList) {
        std::string name = x.getName();
        std::cout<<name<<std::endl; 
      }
    }
};

int main() {

  // Define Pets
  Pet dog = Pet("Draven");
  Pet cat = Pet("Taz");

  // Define Pet Store
  Pets petStore;
  petStore.addPet(dog);
  petStore.addPet(cat);
  
  // Display Pets
  petStore.displayPets();
  
  // Array Example
  int gradesArray[5];

  // Vector Example
  std::vector<int> gradesVector; // Default Constructor
  int grade;

  // Vector Declarations
  std::vector<int> vector1(10); // 10 Elements
  std::vector<int> vector2{10}; // 1 Element Value of 10
  std::vector<int> vector3{1,2,3}; // 3 Elements

  // Vector Sizes
  std::cout<<"Size 1: "<<vector1.size()<<std::endl;
  std::cout<<"Size 2: "<<vector2.size()<<std::endl;
  std::cout<<"Size 3: "<<vector3.size()<<std::endl;
  std::cout<<"Size Grades: "<<gradesVector.size()<<std::endl;

  // Vector Capacities
  std::cout<<"Capacity 1: "<<vector1.capacity()<<std::endl;
  std::cout<<"Capacity 2: "<<vector2.capacity()<<std::endl;
  std::cout<<"Capacity 3: "<<vector3.capacity()<<std::endl;
  std::cout<<"Capacity Grades: "<<gradesVector.capacity()<<std::endl;

  if (gradesVector.empty()) {
    std::cout<<"There is nothing inside of the gradesVector array"<<std::endl;
  }

  // Assigning Values
  vector1.at(2) = 3;

  return 0;

  std::cout<<"Enter a grade or -1 to quit: ";
  std::cin>>grade;

  // Gather Data for Vector
  while (grade != -1) {
    gradesVector.push_back(grade);
    std::cout<<"Enter a grade or -1 to quit: ";
    std::cin>>grade;
  }

  // Print Vector Data
  for (int x : gradesVector) {
    std::cout<<x<<std::endl;
  }

  // // Gather Data for Array
  // for (int x = 0; x < 5; x++) {
  //   std::cout<<"Enter a grade: ";
  //   std::cin>>gradesArray[x];
  // }

  // // Print Array Data
  // for (int x : gradesArray) {
  //   std::cout<<x<<std::endl;
  // }



}