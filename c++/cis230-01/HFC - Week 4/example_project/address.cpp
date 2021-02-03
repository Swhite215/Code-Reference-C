#include "address.h"
#include <iostream>

Address::Address(string name_in, string street_in, string city_in) {
   name = name_in;
   street = street_in;
   city = city_in;
}

Address::Address()
{
   name = "";
   street = "";
   city = "";

}

void Address::print()
{
   std::cout<<name<<std::endl<<street<<std::endl<<city<<std::endl;
}