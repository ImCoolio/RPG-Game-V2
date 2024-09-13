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
    int choice; std::vector<std::string> name(1);
    clear();
    while (true) 
    {
      std::cout << "1 - New Game\n2 - Load Save\n3 - Options\n4 - Quit\n\nSelection: ";
      if (std::cin >> choice) 
      {
        switch (choice) 
        {
          case 1:
            clear();

            while (true) {
              std::cout << "Enter your name: ";
              std::cin >> name[0];
              std::cout << "\n\nIs " << name[0] << " your name?\nInput 1 if it is, anything else if it isn't: ";

              if (std::cin >> choice && choice == 1)
              { 
                clear(); 
                break;
              }

              std::cin.clear();
              while (std::cin.get() != '\n');
              clear();
            }

            // class selection goes here

            std::cout << "Hello, " << name[0] << ", please input the map size of the world for this character (minimum 5).";
            std::cout << "\n(This will create a nxn sized square map where n is the size you input.)\n\nSize: ";

            while (true) {
              if (std::cin >> choice || choice >= 5)
                break;
              std::cin.clear();
              while (std::cin.get() != '\n');
              clear();
              std::cout << "Please input an integer greater than 5.\n\nSize: ";
            }

            generation(choice);

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
            std::cout << "Quitting game... thank you for playing!\n\n(Press ENTER to exit...)";
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