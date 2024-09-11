#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <cstring>
#include <filesystem>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;
using namespace std::this_thread;
using namespace std::chrono_literals;

void menu();
void clear();
void saveMenu();

int main() 
{
  clear();
  std::cout << "Welcome to the (TBD) RPG! v0.01\n\n";
  std::cout << "This is just a slight project I felt like developing... don't expect it to go anywhere.\n\n";
  std::cout << "PRESS ENTER TO START\n\n";
  std::cin.get();
  menu();
  return 0;
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

void saveMenu() 
{
  // check if any save files exist, go through each 1-3 likely name "save1.txt"
  // if found, list the saves given need is 0
  // if need is 1, return the saves details to load the save.
  // idea is to just use basic file i/o for saving and loading saves.  

  int existing = 0; int saveChoice; std::fstream myfile; std::string yesNo;
  std::string save = "Save "; char dir[] = "./saves"; 
  char* fileNames[3] = {"./saves/save1.txt", "./saves/save2.txt", "./saves/save3.txt"};
  std::string saveDisplay[3];  
  struct stat sb;

  if (stat(dir, &sb) == 0) 
  {
    for (int i = 1; i <= 3; i++) 
    {
      if (stat(fileNames[i-1], &sb) == 0) 
      {
        existing++;
        save = save + std::to_string(i) + "\n";
        saveDisplay[i-1] = save;
        save = "Save ";
      }
      else 
      {
        save = save + std::to_string(i) + " (EMPTY)\n";
        saveDisplay[i-1] = save;
        save = "Save ";
      }
    }

    if (existing == 0) 
    {
      sleep_for(0.3s);
      std::cout << "No saves exist. Please select \"New Game\" in the main menu to begin a new save file.\n\n";
      return;
    }
    else 
    {
      sleep_for(0.3s);
      for (auto string : saveDisplay) 
      {
        std::cout << string;
      }
      std::cout << "\n";
    }
    
    while (true) 
    {
      std::cout << "Select a save or enter 4 to exit: ";
      std::cin >> saveChoice;
      switch (saveChoice) 
      {
        case 1:
          std::cout << "\n\nSave 1 Selected.";
          std::cout << "\nWould you like to load the game with save 1? - ";
          std::cin >> yesNo;
          if (yesNo == "y" || yesNo == "yes") 
          {
            // verify save isn't empty, load save, start game.
            clear();
            std::cout << "Loaded save 1."; fflush(stdout);
            sleep_for(1s);
            clear();
            return;
          }
          else 
          {
            clear();
            std::cout << "Did not load save 1. Returning to menu..."; fflush(stdout);
            sleep_for(1s);
            clear();
            return;
          }

        case 2:
          std::cout << "\n\nSave 2 Selected.";
          std::cout << "\nWould you like to load the game with save 2? - ";
          std::cin >> yesNo;
          if (yesNo == "y" || yesNo == "yes") 
          {
            // verify save isn't empty, load save, start game.
            clear();
            std::cout << "Loaded save 2."; fflush(stdout);
            sleep_for(1s);
            clear();
            return;
          }
          else {
            clear();
            std::cout << "Did not load save 2. Returning to menu..."; fflush(stdout);
            sleep_for(1s);
            clear();
            return;
          }

        case 3:
          std::cout << "\n\nSave 3 Selected.";
          std::cout << "\nWould you like to load the game with save 3? - ";
          std::cin >> yesNo;
          if (yesNo == "y" || yesNo == "yes") 
          {
            // verify save isn't empty, load save, start game.
            clear();
            std::cout << "Loaded save 3."; fflush(stdout);
            sleep_for(1s);
            clear();
            return;
          }
          else 
          {
            clear();
            std::cout << "Did not load save 3. Returning to menu..."; fflush(stdout);
            sleep_for(1s);
            clear();
            return;
          }

        case 4:
          clear();
          std::cout << "Exiting save menu..."; fflush(stdout);
          sleep_for(1s);
          clear();
          return;

        default:
          clear();
          std::cout << "Invalid input. Please retry.";
          std::cin.clear();
          while (std::cin.get() != '\n');
          break;
      }
    }
  }     
  else 
  {
    clear();
    std::cout << "Save folder does not exist. Creating saves folder...\n\n";
    fs::create_directory("saves");
  }
}