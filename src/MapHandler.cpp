#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "MapHandler.h"
#include "General.h"

using namespace gen;

namespace mapHand {
    std::vector<std::string> map = std::vector<std::string>{};
    double percent = 0;

    std::vector<std::string> generation(int n, int save) {
        // Idea is to take in a size of n and create a n x n array for each spot.
        // Utilize a vector array to hold the map and use math (ex. mod values)
        // for instance, a map of size 8x8 should be 64 spots.
        // spot 0 (0 indexing) should start at (-4,4) in this case for simplicity to create a easier way to manage the array.
        // To find the x, % mod the current index by n.
        // To find the y, divide the current index by n and round down the float.

        // At first, I'll just program the actual generation with generic locations, disregarding special locations.
        clear();

        for (int i = 0; i < n*n; i++) {
            map.push_back(std::to_string(i));
            percent = (double)(i/(double)(n*n));
            std::cout << "Generating world: " << std::setprecision (6) << percent*100 << "%" << std::endl;
        }

        clear();

        std::cout << "Saving map...\n" << std::endl;

        std::ofstream saveFile("./saves/map" + std::to_string(save) + ".txt");
        saveFile << "{";
        std::ostream_iterator<std::string> output_iterator(saveFile, ", ");
        std::copy(std::begin(map), std::end(map), output_iterator);
        saveFile << "}";

        std::cout << "Generated world and saved map file!\n" << std::endl;

        return map;
    }
}

