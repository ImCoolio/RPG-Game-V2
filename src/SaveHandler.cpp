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

      int existing = 0; int saveChoice; std::fstream myfile; std::string yesNo;
      std::vector<std::string> save = {"Save "}; 
      std::vector<fs::path> fileNames{"./saves", "./saves/save1.txt", "./saves/save2.txt", "./saves/save3.txt"};
      std::vector<std::string> saveDisplay(3); 

      if (fs::exists(fileNames[0])) 
      {
        for (int i = 1; i <= 3; i++) 
        {
          if (fs::exists(fileNames[i])) 
          {
            existing++;
            save[0] = save[0] + std::to_string(i) + "\n";
            saveDisplay[i-1] = save[0];
            save[0] = "Save ";
          }
          else 
          {
            save[0] = save[0] + std::to_string(i) + " (EMPTY)\n";
            saveDisplay[i-1] = save[0];
            save[0] = "Save ";
          }
        }

        while (true) 
        {
          if (existing == 0) 
          {
            sleep_for(0.3s);
            std::cout << "No saves exist. Please select \"New Game\" in the main menu to begin a new save file.\n\n";
            return;
          }
          else 
          {
            sleep_for(0.3s);
            clear();
            for (auto string : saveDisplay) 
            {
              std::cout << string;
            }
            std::cout << "\n";
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
        std::cout << "Save folder does not exist. Creating saves folder...\n\n";
        sleep_for(0.3s);
        fs::create_directory("saves");
      }
    }
}