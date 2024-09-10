#include <iostream>
#include <stdlib.h>
#include <limits>

void menu();
void clear();

int main() {
  clear();
  std::cout << "Welcome to the (TBD) RPG! v0.01\n\n";
  std::cout << "This is just a slight project I felt like developing... don't expect it to go anywhere.\n\n";
  std::cout << "PRESS ENTER TO START\n\n";
  getchar();
  menu();
  return 0;
}

void menu() {
  int x;
  clear();
  while (true) {
    std::cout << "1 - Play\n2 - Options\n3 - Quit";
    if (std::cin >> x) {
      switch (x) {
        case 1:
          clear();
          std::cout << "1 Test\n\n";
          break;
        case 2:
          clear();
          std::cout << "2 Test\n\n";
          break;
        case 3:
          clear();
          std::cout << "3 Test\n\n";
          break;
        default:
          clear();
          std::cout << "Invalid input. Please retry.\n\n";
          break;
      }
    } else {
      clear();
      std::cout << "Invalid input, be sure you are inputting an integer.\n\n";
      std::cin.clear();
      while (std::cin.get() != '\n');
    }
  }
}

void clear() {
  #if defined(WIN32) && !defined(__linux__)
    system("cls");
  #elif defined(__linux__) && !defined(WIN32)
    system("clear");
  #else
    std::cout << "Why are you running this on apple...? \n\n";
  #endif
}