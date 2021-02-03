#include <iostream>

// Class Example
class Pet { // Name - Capital Letter

  // Access Specifier - Public Example
  // public:
  //   std::string name;
  //   std::string petType;
  //   int month;
  //   int day;
  //   int year;

 // Access Specifier - Private
  private: // Members - Private By Default - Way it Should Be
    std::string name;
    std::string petType;
    int month;
    int day;
    int year;

  public: // Functions Should be Public
    
    Pet() { // Constructor - Default - No Return Type
      std::cout<<"I am creating a Pet!"<<std::endl;

      name = "Unknown";
      petType = "Unknown";
      month = 1;
      day = 1;
      year = 1999;
    }

    Pet(std::string n) { // Non-Default Constructor i.e. Requires Arguments
      std::cout<<"I am creating a Pet with a name!"<<std::endl;

      name = n;
      petType = "Unknown";
      month = 1;
      day = 1;
      year = 1999;
    }

    // Accessor Functions (GETTERS)
    std::string getPetType() { return petType; }
    std::string getName() { return name; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }

    // Mutator Functions (SETTERS)
    void setPetType(std::string petType) { this->petType = petType; }
    void setName(std::string name) { this->name = name; }
    void setMonth(int month) { this->month = month; }
    void setDay(int day) { this->day = day; }
    void setYear(int year) { this->year = year; }


};

int main() {
  Pet myPet;
  Pet thatPet("Hank");

  myPet.setName("Draven");
  myPet.setPetType("Snake");
  myPet.setMonth(01);
  myPet.setDay(12);
  myPet.setYear(1993);
  
  std::cout<<"My pet "<<myPet.getPetType()<<" is named "<<myPet.getName()<<"."<<std::endl;
  std::cout<<myPet.getName()<<" was born on "<<myPet.getMonth()<<"/"<<myPet.getDay()<<"/"<<myPet.getYear()<<"."<<std::endl;

  // Array of Classes
  Pet myPets[20];

  myPets[0] = myPet;

}