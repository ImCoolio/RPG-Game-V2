#include <iostream>
#include <thread>
#include <chrono>
#include <string>
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
      std::cout << "Why are you running this on MacOS...? \n" << std::endl;
    #endif
  }

  void flush() 
  {
  fflush(stdout);
  }

  void menu() 
  {
    int choice; int save; std::vector<std::string> name(1);
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
              std::cout << "\n\nIs " << name[0] << " your name?\nInput 1 if it is, 2 to exit, or anything else to reinput: ";

              if (std::cin >> choice && choice == 1)
              { 
                clear();
                break;
              }
              else if (choice == 2) {
                clear();
                std::cout << "Exiting save creation..." << std::endl; flush();
                sleep_for(0.5s);
                clear();
                break;
              }


              std::cin.clear();
              while (std::cin.get() != '\n');
              clear();
            }

            if (choice == 2) break;

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

            while (true) {
              std::cout << "Please select a savefile from slot 1 through 3. Enter 4 to exit. \n(THIS WILL REPLACE ANY EXISTING SAVE IN THAT SLOT. USE THE \"LOAD SAVE\" MENU TO LOAD SAVES.)\nSave: ";

              if (std::cin >> save && save >= 1 && save <= 3)
              { 
                clear();
                std::vector<std::string> map = generation(choice, save);
                break;
              }
              else if (choice == 4) {
                break;
              }
              else {
                clear();
                std::cout << "Please input an integer value between 1 through 3." << std::endl; flush();
                sleep_for(0.5s);
                clear();
                break;
              }
            }

            break;
          case 2:
            clear();
            std::cout << "Loading saves...\n" << std::endl;
            saveMenu();
            break;
          case 3:
            clear();
            std::cout << "Options test.\n" << std::endl;
            break;
          case 4:
            clear();
            std::cout << "Quitting game... thank you for playing!\n\n(Press ENTER to exit...)";
            sleep_for(1s);
            std::cin.ignore(); std::cin.ignore();
            return;
          default:
            clear();
            std::cout << "Invalid input. Please retry.\n" << std::endl;
            break;
        }
      } 
      else 
      {
        clear();
        std::cout << "Invalid input, be sure you are inputting an integer.\n" << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
      }
    }
  }

}