#include <iostream>
#include "MapHandler.h"
#include "General.h"

using namespace gen;

namespace mapHand {
    std::vector<int> map = std::vector<int>{};

    void generation(int n) {
        // Idea is to take in a size of n and create a n x n array for each spot.
        // Utilize a vector array to hold the map and use math (ex. mod values)
        // for instance, a map of size 8x8 should be 64 spots.
        // spot 0 (0 indexing) should start at (-4,4) in this case for simplicity to create a easier way to manage the array.
        // To find the x, % mod the current index by n.
        // To find the y, divide the current index by n and round down the float.

        // At first, I'll just program the actual generation with generic locations, disregarding special locations. 

        for (int i; i < n*n; i++) {
            map.push_back(0);
            std::cout << "Loading " << (i/n) << "%...";
        }

        gen::clear();
        std::cout << "Success! No errors.";
    }
}

