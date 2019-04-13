//
// Created by jp on 4/12/19.
//

#include <tuple>
#include "nearestneighbor.h"
#incoude "readcorpus.h"

int main() {
    uint8_t *neighbors[1000];
    unittest::cv140::readCorpus("../reviews.txt", neighbors, 1000, 6);

    uint8_t neighbor[] = {0, 1, 0, 2, 0, 3};
    auto result = edu::sbcc::cs140::findNearestNeighbor(neighbor, neighbors, 1000, 6);
    std::cout << "nearest distance: " << std::get<0>(result) << std::endl; // Access the first member of a tuple

    return 0;
}