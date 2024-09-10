#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void clear();

int main() {
  cout << "\033c";
  cout << "Welcome to the (TBD) RPG! v0.01\n\n";
  cout << "This is just a slight project I felt like developing... don't expect it to go anywhere.\n\n";
  cout << "PRESS ENTER TO START";
  getchar();
  return 0;
}