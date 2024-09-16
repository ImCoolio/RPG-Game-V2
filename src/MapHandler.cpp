#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <cstdint>
#include "MapHandler.h"
#include "General.h"
#include "RandomHandler.h"

using namespace gen;

namespace mapHand {
    std::vector<uint8_t> map = std::vector<uint8_t>{};
    double percent = 0;

    std::vector<uint8_t> generation(int n, int save) {
        // Idea is to take in a size of n and create a n+1 x n+1 array.
        // Utilize a vector array to hold the map and use math (ex. mod values)
        // for instance, a map of size 8 should be 81 (Need to include x = 0) spots.
        // spot 0 (0 indexing) should start at (-4,4) in this case for simplicity to create a easier way to manage the array.
        //

        // At first, I'll just program the actual generation with generic locations, disregarding special locations.
        clear();

        if (n%2 == 0) // Maps must be balanced, so we will have to generate a map that's odd to allow it to be balanced.
            n++;

        for (int i = 0; i < (n)*(n); i++) {
            map.push_back(0);
            percent = (double)(i/(double)(n*n));
            std::cout << "Generating world: " << std::setprecision (6) << percent*100 << "%" << std::endl;
        }

        clear();

        std::cout << "Saving map...\n" << std::endl;

        std::ofstream saveFile("./saves/map" + std::to_string(save) + ".txt", std::ios::binary);
        saveFile.write((char*)map.data(), map.size());
        saveFile.close();

        std::ifstream other("./saves/map" + std::to_string(save) + ".txt", std::ios::binary);
        other.seekg(0, std::ios::end);
        size_t size = other.tellg();
        other.seekg(0, std::ios::beg);

        std::vector<uint8_t> read_map = std::vector<uint8_t>(size);
        other.read((char*)read_map.data(), size);
        other.close();

        std::cout << "Generated world and saved map file!\n" << std::endl;

        return map;
    }
}

