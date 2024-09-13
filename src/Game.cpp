// created by coolius 2024. RPG Game V2 (name tbd)
#include <iostream>
#include "MapHandler.h"
#include "General.h"
#include "SaveHandler.h"

using namespace gen;

int main() 
{
  clear();
  std::cout << "Welcome to the (TBD) RPG! v0.03\n" << std::endl;
  std::cout << "This is just a slight project I felt like developing... don't expect it to go anywhere.\n" << std::endl;
  std::cout << "Press ENTER to start\n" << std::endl;
  std::cin.get();
  menu();
  return 0;
}
