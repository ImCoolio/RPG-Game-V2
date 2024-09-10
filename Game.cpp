#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void clear();

int main() {
  clear();
  cout << "Welcome to the (TBD) RPG! v0.01\n\n";
  cout << "This is just a slight project I felt like developing... don't expect it to go anywhere.\n";
  cout << "PRESS ENTER TO START";
  return 0;
}

void clear() {
  #if defined _WIN32
    system("cls");
  #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
  #elif defined (__APPLE__)
    system("clear");
  #endif
}