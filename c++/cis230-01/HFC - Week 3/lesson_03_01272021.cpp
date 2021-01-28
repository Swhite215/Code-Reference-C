#include <iostream>

// Overloaded Examples
// void displayCone(void);
// void displayCone(std::string);
// void displayCone(std::string, int);

// Default Arguments - NOTE: EVERYTHING TO THE RIGHT NEEDS DEFAULT
void displayCone(std::string="Vanilla", int=1);

// Reference Arguments
void askData(std::string &flavor, int &scoops);

int main(){

 	std::string flavor;
 	int scoops, choice;
 	float price;

 	do
  {
	 	std::cout<<"\nIce Cream Selection Menu\n";
	 	std::cout<<"\n\t1 : Daily Special";
	 	std::cout<<"\n\t2 : Single Special";
	 	std::cout<<"\n\t3 : Create your own";
	 	std::cout<<"\n\t4 : Quit\n";
    std::cout<<"\nWhat would you like? ";
	 	std::cin>>choice;
    std::cin.ignore(10000, '\n');

	 	switch (choice)
    {
	 		case 1:
        displayCone();
	 			break;
	 		case 2:
	 			std::cout<<"Enter your favorite flavor : ";
	 			getline(std::cin, flavor);
        displayCone(flavor);
	 			break;
	 		case 3:
	 			askData(flavor, scoops);
        displayCone(flavor, scoops);
	 			break;
		 }

  }while (choice != 4);

 	return 0;

 }

// Default Arguments
void displayCone(std::string flavor, int scoops) {
  static int customers = 0; // Stays in memory
  float price = 1 + (.75 * scoops);

  std::cout<<"\nThe price of your "<<flavor<<" cone is "<<price<<std::endl;

  customers++;

  std::cout<<"\nYou are customer number "<<customers;
}

// References
void askData(std::string &flavor, int &scoops) {
  	std::cout<<"Enter your favorite flavor : ";
	 	getline(std::cin, flavor);
	 	std::cout<<"How many scoops would you like? ";
	 	std::cin>>scoops;
}

// Overloading 
// void displayCone() {
//   float price = 1.75;
//   std::cout<<"\nThe price of your Vanilla cone is "<<price<<std::endl;
// }

// // Overloading - Create Multiple Functions w/ Same Name
// void displayCone(std::string flavor) {
//   float price = 1.75;
//   std::cout<<"\nThe price of your "<<flavor<<" cone is "<<price<<std::endl;
// }

// // Overloading - Create Multiple Functions w/ Same Name
// void displayCone(std::string flavor, int scoops) {
//   float price = 1 + (.75 * scoops);

//   std::cout<<"\nThe price of your "<<flavor<<" cone is "<<price<<std::endl;
// }