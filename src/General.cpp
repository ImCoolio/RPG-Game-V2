#include <iostream>
#include <thread>
#include <chrono>
#include "General.h"
#include "SaveHandler.h"
#include "MapHandler.h"

using namespace saveHand;
using namespace mapHand;
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace gen {
  void clear() 
  {
    #if defined(WIN32) && !defined(__linux__)
      system("cls");
    #elif defined(__linux__) && !defined(WIN32)
      system("clear");
    #else
      std::cout << "Why are you running this on MacOS...? \n\n";
    #endif
  }

  void flush() 
  {
  fflush(stdout);
  }

  void menu() 
  {
    int x;
    clear();
    while (true) 
    {
      std::cout << "1 - New Game\n2 - Load Save\n3 - Options\n4 - Quit\n\nSelection: ";
      if (std::cin >> x) 
      {
        switch (x) 
        {
          case 1:
            clear(); 
            std::cout << "New game test.\n\n";
            break;
          case 2:
            clear();
            std::cout << "Loading saves...\n\n";
            saveMenu();
            break;
          case 3:
            clear();
            std::cout << "Options test.\n\n";
            break;
          case 4:
            clear();
            std::cout << "Quitting game... thank you for playing!\n\n(Press any key to exit...)";
            sleep_for(1s);
            std::cin.ignore(); std::cin.ignore();
            return;
          default:
            clear();
            std::cout << "Invalid input. Please retry.\n\n";
            break;
        }
      } 
      else 
      {
        clear();
        std::cout << "Invalid input, be sure you are inputting an integer.\n\n";
        std::cin.clear();
        while (std::cin.get() != '\n');
      }
    }
  }

}