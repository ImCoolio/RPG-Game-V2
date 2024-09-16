#ifndef MAPHANDLER
#define MAPHANDLER
#include <vector>

namespace mapHand {
    extern std::vector<uint8_t> map;
    std::vector<uint8_t> generation(int n, int save);   
}

#endif