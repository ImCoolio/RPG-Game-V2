#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <thread>
#include <chrono>
#include "General.h"

namespace fs = std::filesystem;
using namespace gen;
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace saveHand 
{
    void saveMenu() 
    {
      // check if any save files exist, go through each 1-3 likely name "save1.txt"
      // if found, list the saves given need is 0
      // if need is 1, return the saves details to load the save.
      // idea is to just use basic file i/o for saving and loading saves.  

      bool existing = false, check = false; int saveChoice = -1; std::fstream saveFile; std::string yesNo;
      std::vector<std::string> save = {"Save "}; 
      std::vector<fs::path> fileNames{
        "./saves", 
        "./saves/save1.txt", "./saves/map1.txt", 
        "./saves/save2.txt", "./saves/map2.txt", 
        "./saves/save3.txt", "./saves/map3.txt"};
      std::vector<std::string> saveDisplay(3); 

      if (fs::exists(fileNames[0])) 
      { /* optimize save system at some point to just 
           check for the fs exists/is empties then 
           choose what to print at the end */

        for (int i = 1; i <= 3; i++) 
        {
          if ((fs::exists(fileNames[i*2-1]) && fs::exists(fileNames[i*2])) && (!fs::is_empty(fileNames[i*2-1]) || !fs::is_empty(fileNames[i*2]))) 
          {
            check = true; existing = true;
            save[0] = save[0] + std::to_string(i) + "\n";
            saveDisplay[i-1] = save[0];
            save[0] = "Save ";
          }
          else if (check == false && fs::exists(fileNames[i*2-1]) && !fs::exists(fileNames[i*2])) 
          {
            check = true; existing = true;
            save[0] = save[0] + std::to_string(i) + " (MISSING MAP FILE)\n";
            saveDisplay[i-1] = save[0];
            save[0] = "Save ";
          }
          else if (check == false && !fs::exists(fileNames[i*2-1]) && fs::exists(fileNames[i*2])) 
          {
            existing = true;
            save[0] = save[0] + std::to_string(i) + " (MISSING PLAYER FILE)\n";
            saveDisplay[i-1] = save[0];
            save[0] = "Save ";
          }
          else
          {
            save[0] = save[0] + std::to_string(i) + " (EMPTY)\n";
            saveDisplay[i-1] = save[0];
            save[0] = "Save ";
          }

          check = false;
        }

        while (true) 
        {
          if (!existing) 
          {
            sleep_for(0.3s);
            std::cout << "No saves exist. Please select \"New Game\" in the main menu to begin a new save file.\n" << std::endl;
            return;
          }
          else 
          {
            sleep_for(0.3s);
            clear();
            for (std::string string : saveDisplay) 
            {
              std::cout << string;
            }
            std::cout << std::endl;
          }

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
                std::cout << "Loaded save 1."; flush();
                sleep_for(1s);
                clear();
                return;
              }
              else 
              {
                clear();
                std::cout << "Did not load save 1. Returning to save selection..."; flush();
                sleep_for(1s);
                clear();
              }
              break;

            case 2:
              std::cout << "\n\nSave 2 Selected.";
              std::cout << "\nWould you like to load the game with save 2? - ";
              std::cin >> yesNo;
              if (yesNo == "y" || yesNo == "yes") 
              {
                // verify save isn't empty, load save, start game.
                clear();
                std::cout << "Loaded save 2."; flush();
                sleep_for(1s);
                clear();
                return;
              }
              else {
                clear();
                std::cout << "Did not load save 2. Returning to save selection..."; flush();
                sleep_for(1s);
                clear();
              }
              break;

            case 3:
              std::cout << "\n\nSave 3 Selected.";
              std::cout << "\nWould you like to load the game with save 3? - ";
              std::cin >> yesNo;
              if (yesNo == "y" || yesNo == "yes") 
              {
                // verify save isn't empty, load save, start game.
                clear();
                std::cout << "Loaded save 3."; flush();
                sleep_for(1s);
                clear();
                return;
              }
              else 
              {
                clear();
                std::cout << "Did not load save 3. Returning to save selection..."; flush();
                sleep_for(1s);
                clear();
              }
              break;

            case 4:
              clear();
              std::cout << "Exiting save menu..."; flush();
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
        std::cout << "Save folder does not exist. Please select new game to create a save.\n" << std::endl;
      }
    }
}