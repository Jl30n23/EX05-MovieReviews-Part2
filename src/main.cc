//
// Created by aknight on 2/19/19.
//
#include "nearestneighbor.h"
#include <fstream>
#include <iostream>

void readMovieReviews(const std::string &filename, uint8_t **reviews, size_t neighborCount, size_t neighborSize) {
    std::ifstream in(filename);

    size_t count = 0;
    for (; !in.eof() && count < neighborCount; count++) {
        reviews[count] = new uint8_t[neighborSize];
        for (size_t j = 0; j < neighborSize; j++) {
            uint32_t value;
            in >> value;
            reviews[count][j] = static_cast<uint8_t >(value);
        }
    }
}

int main(int argc, char *argv[]) {
    uint8_t *neighbors[1000];
    readMovieReviews("../reviews.txt", neighbors, 1000, 6);

    uint8_t neighbor[] = {1, 4, 4, 4, 1, 1};
    auto result = edu::vcccd::vc::csv13::findNearestNeighbor(neighbor, neighbors, 100, 6);
    std::cout << "nearest distance: " << result.first << std::endl;
    return 0;
}