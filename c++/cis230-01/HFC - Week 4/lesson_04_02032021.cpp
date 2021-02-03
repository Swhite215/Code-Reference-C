#include <iostream>

class Shirt {
  private:
    double collarSize;
    int sleeveLength;

  public:
    Shirt(double cs = 14.5, int sl = 32) {
        collarSize = cs;
        sleeveLength = sl;
    }

    void displayShirt() {
      std::cout<<"Shirt: "<<collarSize<<" inch collar and "<<sleeveLength<<" inch sleeve"<<std::endl;
    }

};

class Pants {
  private:
    double waistSize;
    int inseam;

  public:
    Pants(double ws = 20, int is = 30) {
      waistSize = ws;
      inseam = 30;
    }

    void displayPants() {
      std::cout<<"Pants: "<<waistSize<<" inch waist and "<<inseam<<" inch inseam"<<std::endl;
    }
};

class Outfit {
  private:
    Pants pants;
    Shirt shirt;

  public:
    void displayOutfit() {
      shirt.displayShirt();
      pants.displayPants();
    }
};


int main() {
  Outfit outfit;
  outfit.displayOutfit();
}