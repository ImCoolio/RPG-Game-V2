#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <limits>
using namespace std;

void menu();

int main() {
  cout << "\033c";
  cout << "Welcome to the (TBD) RPG! v0.01\n\n";
  cout << "This is just a slight project I felt like developing... don't expect it to go anywhere.\n\n";
  cout << "PRESS ENTER TO START\n\n";
  getchar();
  menu();
  return 0;
}

void menu() {
  int x;
  cout << "\033c";
  while (true) {
    cout << "1 - Play\n2 - Options\n3 - Quit";
    if (cin >> x) {
      switch (x) {
        case 1:
          cout << "\033c";
          cout << "1 Test\n\n";
          break;
        case 2:
          cout << "\033c";
          cout << "2 Test\n\n";
          break;
        case 3:
          cout << "\033c";
          cout << "3 Test\n\n";
          break;
        default:
          cout << "\033c";
          cout << "Invalid input. Please retry.\n\n";
          break;
      }
    } else {
      cout << "\033c";
      cout << "Invalid input, be sure you are inputting an integer.\n\n";
      cin.clear();
      while (cin.get() != '\n');
    }
  }
}